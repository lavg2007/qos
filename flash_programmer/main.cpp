#include <iostream>
#ifdef __linux__
#include <termios.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#endif


int main()
{


    int serial_port = open("/dev/ttyACM1", O_RDWR);

    if (serial_port < 0)
    {
        std::cout << "Error " << errno << " opening serial port : " << std::endl;
    }

    return 0;
}
