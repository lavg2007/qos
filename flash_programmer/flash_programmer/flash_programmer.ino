#define SHIFT_SER_PIN 10
#define SHIFT_SRCLK_PIN 12
#define SHIFT_DONE_PIN 11
#define WRITE_ENABLE 13
#define READ_ENABLE 14
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

    setup_pins(OUTPUT);
}

void setup_pins(int mode)
{
    pinMode(SHIFT_SER_PIN, OUTPUT);
    pinMode(SHIFT_SRCLK_PIN, OUTPUT);
    pinMode(SHIFT_DONE_PIN, OUTPUT);
    pinMode(WRITE_ENABLE, OUTPUT);
    pinMode(READ_ENABLE, OUTPUT);

    pinMode(D0, mode);
    pinMode(D1, mode);
    pinMode(D2, mode);
    pinMode(D3, mode);
    pinMode(D4, mode);
    pinMode(D5, mode);
    pinMode(D6, mode);
    pinMode(D7, mode);

    digitalWrite(SHIFT_SER_PIN, LOW);
    digitalWrite(SHIFT_SRCLK_PIN, LOW);
    digitalWrite(SHIFT_DONE_PIN, LOW);
    digitalWrite(WRITE_ENABLE, HIGH);
    digitalWrite(READ_ENABLE, HIGH);
}

void loop() 
{
    String command = Serial.readString();
    if (command.length() > 0)
    {
        command.trim();
        if(command == "read")
        {
            Serial.print("Reading from flash");
            read_test_data();
            Serial.print("READING done");
        }
        else if(command == "write")
        {
            Serial.print("Writing to flash");
            write_test_data();
            Serial.print("Writing done");
        }
    }
    
}

void write_test_data()
{
    int percent = 0;
    for(unsigned int i = 0x00; i < 0xFFFF; i++)
    {
        set_address(i);
        set_data(0xec);
        send_data();
    }  
}

void read_test_data()
{
    for(unsigned int i = 0; i < 0xFFFF; i++)
    {
        set_address(i);
        read_data();
    }
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

void send_data()
{
    digitalWrite(WRITE_ENABLE, LOW);
    digitalWrite(WRITE_ENABLE, HIGH);
}

byte read_data()
{
    digitalWrite(READ_ENABLE, LOW);
    delayMicroseconds(1);
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
    Serial.print(data,HEX);
    Serial.print('\n');   
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
