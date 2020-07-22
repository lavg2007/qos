#define SHIFT_SER_PIN 10
#define SHIFT_SRCLK_PIN 12
#define SHIFT_DONE_PIN 11
#define WRITE_ENABLE 13
#define READ_ENABLE 14
#define CHIP_ENABLE 15
#define BAUDRATE 115200
#define D0 2
#define D1 3
#define D2 4
#define D3 5
#define D4 6
#define D5 7
#define D6 8
#define D7 9




void setup() 
{
    Serial.begin(BAUDRATE)  ;
    pinMode(SHIFT_SER_PIN, OUTPUT);
    pinMode(SHIFT_SRCLK_PIN, OUTPUT);
    pinMode(SHIFT_DONE_PIN, OUTPUT);
    pinMode(WRITE_ENABLE, OUTPUT);
    pinMode(READ_ENABLE, OUTPUT);
    pinMode(CHIP_ENABLE, OUTPUT);
    digitalWrite(SHIFT_SER_PIN, LOW);
    digitalWrite(SHIFT_SRCLK_PIN, LOW);
    digitalWrite(SHIFT_DONE_PIN, LOW);
    digitalWrite(WRITE_ENABLE, HIGH);
    digitalWrite(READ_ENABLE, HIGH);
    
}

void setup_pins(int mode)
{


    pinMode(D0, mode);
    pinMode(D1, mode);
    pinMode(D2, mode);
    pinMode(D3, mode);
    pinMode(D4, mode);
    pinMode(D5, mode);
    pinMode(D6, mode);
    pinMode(D7, mode);


}

void loop() 
{
    String command = Serial.readString();
    if (command.length() > 0)
    {
        command.trim();
        if(command == "read")
        {
            Serial.print("Reading from flash\n");
            setup_pins(INPUT);
            read_test_data();
            Serial.print("READING done\n");
        }
        else if(command == "write")
        {
            Serial.print("Writing to flash\n");
            setup_pins(OUTPUT);
            write_test_data();
            set_data(0);
            Serial.print("Writing done\n");
        }
        else if(command == "erase")
        {
            Serial.print("Erasing chip\n");
            setup_pins(OUTPUT);
            chip_erase();
            Serial.print("Chip erased\n");
        }
        else
        {
            Serial.print("Invalid command\n");
        }
    }
    
}

void pulse_write_enable(unsigned int address, byte data)
{
    set_address(address);
    digitalWrite(WRITE_ENABLE, LOW);
    set_data(data);
    delayMicroseconds(1);
    digitalWrite(WRITE_ENABLE, HIGH);
}

void chip_erase()
{
    digitalWrite(CHIP_ENABLE, LOW);
    digitalWrite(READ_ENABLE, HIGH);
    pulse_write_enable(0x5555, 0xAA);
    pulse_write_enable(0x2AAA, 0x55);
    pulse_write_enable(0x5555, 0x80);
    pulse_write_enable(0x5555, 0xAA);
    pulse_write_enable(0x2AAA, 0x55);
    pulse_write_enable(0x5555, 0x10);
    delay(100);
}

void write_test_data()
{
    int percent = 0;
    digitalWrite(READ_ENABLE, HIGH);
    digitalWrite(CHIP_ENABLE, LOW);
    bool c = true;
    unsigned int i = 0;
    int p = 0;
    send_data(0xFFFC, 0x14);
    send_data(0xFFFD, 0x13);
    send_data(0x1315, 0x8C);
    send_data(0x1316, 0xCD);
    send_data(0x1317, 0xAB);
    while(c)
    {
        
        if (i % 655 == 0)
        {
            Serial.print(p);
            Serial.print("%\n");  
            p++;
        }
        if (i != 0xFFFC && i != 0xFFFD && (i < 0x1315 || i > 0x1320) )
          send_data(i, 0xea);
        if (i >= 0xFFFF) c = false;
        i++;
    }

}

void read_test_data()
{
    digitalWrite(WRITE_ENABLE, HIGH);
    digitalWrite(CHIP_ENABLE, LOW);
    char buf[50];
    for(unsigned int i = 0x0; i < 0xFFFF; i++)
    {
        set_address(i);
        byte data = read_data();
        sprintf(buf, "%04X %02X\n", i, data);
        Serial.print(buf);
        delayMicroseconds(1);
    }
    set_address(0xFFFF);
    byte data = read_data();
    sprintf(buf, "%04X %02X\n", 0xFFFF, data);
    Serial.print(buf);
    delayMicroseconds(1);
}

void set_data(byte data)
{
    digitalWrite(D0, data&1);
    digitalWrite(D1, (data >> 1)&1);
    digitalWrite(D2, (data >> 2)&1);
    digitalWrite(D3, (data >> 3)&1);
    digitalWrite(D4, (data >> 4)&1);
    digitalWrite(D5, (data >> 5)&1);
    digitalWrite(D6, (data >> 6)&1);
    digitalWrite(D7, (data >> 7)&1);
}

void set_address(unsigned int address)
{
    shiftOut(SHIFT_SER_PIN, SHIFT_SRCLK_PIN, MSBFIRST, (address >> 8));
  	shiftOut(SHIFT_SER_PIN, SHIFT_SRCLK_PIN, MSBFIRST, address);
    digitalWrite(SHIFT_DONE_PIN, HIGH);
    digitalWrite(SHIFT_DONE_PIN, LOW);
}

void send_data(unsigned int addr, byte data)
{
    pulse_write_enable(0x5555, 0xAA);
    pulse_write_enable(0x2AAA, 0x55);
    pulse_write_enable(0x5555, 0xA0);
    pulse_write_enable(addr, data);
//    set_address(0x5555);
//    digitalWrite(WRITE_ENABLE, LOW);
//    set_data(0xAA);
//    delayMicroseconds(1);
//    digitalWrite(WRITE_ENABLE, HIGH);
//
//    set_address(0x2AAA);
//    digitalWrite(WRITE_ENABLE, LOW);
//    set_data(0x55);
//    delayMicroseconds(1);
//    digitalWrite(WRITE_ENABLE, HIGH);
//
//    set_address(0x5555);
//    digitalWrite(WRITE_ENABLE, LOW);
//    set_data(0xA0);
//    delayMicroseconds(1);
//    digitalWrite(WRITE_ENABLE, HIGH);
//
//    set_address(addr);
//    digitalWrite(WRITE_ENABLE, LOW);
//    set_data(data);
//    delayMicroseconds(1);
//    digitalWrite(WRITE_ENABLE, HIGH);
    
    delayMicroseconds(20);
}

byte read_data()
{
    digitalWrite(READ_ENABLE, LOW);
    delayMicroseconds(10);
    byte data = 0;
    data += digitalRead(D7) << 7;
    data += digitalRead(D6) << 6;
    data += digitalRead(D5) << 5;
    data += digitalRead(D4) << 4;
    data += digitalRead(D3) << 3;
    data += digitalRead(D2) << 2;
    data += digitalRead(D1) << 1;
    data += digitalRead(D0);
    digitalWrite(READ_ENABLE, HIGH);
    return data;
}


void send_address_to_serial()
{
    char bits[16];
    for (char i = 0; i < 8; i++)
    {
        bits[8+i] = digitalRead(i + 2) + 48;
    }
    for (char i = 0; i < 8; i++)
    {
        bits[i] = digitalRead(21 - i) + 48;
    }



    Serial.write(bits, 16);
    Serial.print(" : \n");
}
