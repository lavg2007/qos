#include <iostream>
#include <string.h>
#include <fstream>
#ifdef __linux__
#include <termios.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#endif


int
set_interface_attribs (int fd, int speed, int parity)
{
        struct termios tty;
        if (tcgetattr (fd, &tty) != 0)
        {
                return -1;
        }

        cfsetospeed (&tty, speed);
        cfsetispeed (&tty, speed);

        tty.c_cflag = (tty.c_cflag & ~CSIZE) | CS8;     // 8-bit chars
        // disable IGNBRK for mismatched speed tests; otherwise receive break
        // as \000 chars
        tty.c_iflag &= ~IGNBRK;         // disable break processing
        tty.c_lflag = 0;                // no signaling chars, no echo,
                                        // no canonical processing
        tty.c_oflag = 0;                // no remapping, no delays
        tty.c_cc[VMIN]  = 0;            // read doesn't block
        tty.c_cc[VTIME] = 5;            // 0.5 seconds read timeout

        tty.c_iflag &= ~(IXON | IXOFF | IXANY); // shut off xon/xoff ctrl

        tty.c_cflag |= (CLOCAL | CREAD);// ignore modem controls,
                                        // enable reading
        tty.c_cflag &= ~(PARENB | PARODD);      // shut off parity
        tty.c_cflag |= parity;
        tty.c_cflag &= ~CSTOPB;
        tty.c_cflag &= ~CRTSCTS;

        if (tcsetattr (fd, TCSANOW, &tty) != 0)
        {
                return -1;
        }
        return 0;
}

void
set_blocking (int fd, int should_block)
{
        struct termios tty;
        memset (&tty, 0, sizeof tty);
        if (tcgetattr (fd, &tty) != 0)
        {
                return;
        }

        tty.c_cc[VMIN]  = should_block ? 1 : 0;
        tty.c_cc[VTIME] = 5;            // 0.5 seconds read timeout

}


int main(int argc, char** argv)
{
    int i = 0;
    int option;
    std::string port_name;
    std::string file_name;
    while ((option = getopt(argc, argv, "p:f:")) != -1) 
    {
        switch (option) 
        {
            case 'p':
                port_name = std::string(optarg);
                break;
            case 'f':
                file_name = std::string(optarg);
            default:
                break;
        }    
    }

    std::fstream file;
    file.open(file_name);
    
    if (!file.is_open())
    {
        std::cout << "Error opening file" << std::endl;
        return 1;
    }
    
    int arduino = open(port_name.c_str(), O_RDWR | O_NOCTTY | O_SYNC);
    set_interface_attribs(arduino, B115200, 0);
    set_blocking(arduino, 0);
    
    char buffer[65536];
    char bin_file[65536];
    file.read(bin_file, 65536);


    int written_bytes = write(arduino, "erase\n", 5);
    int read_bytes = 0;
    bool done = false;
    while(!done)
    {
        usleep(1000000);
        int b = read(arduino, buffer + read_bytes, 65536);
        if(b == 0)
            break;
        read_bytes += b;
        std::cout << read_bytes << std::endl;
    }
    std::string msg(buffer);
    std::cout << msg;
    
    return 0;
}
