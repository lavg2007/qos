#define SHIFT_SER_PIN 12
#define SHIFT_SRCLK_PIN 11
#define SHIFT_DONE_PIN 10
#define BAUDRATE 115200
#define READPIN 2

void setup() 
{
    Serial.begin(BAUDRATE)  ;
	  pinMode(SHIFT_SER_PIN, OUTPUT);
	  pinMode(SHIFT_SRCLK_PIN, OUTPUT);
	  pinMode(SHIFT_DONE_PIN, OUTPUT);
	  pinMode(READPIN, INPUT);
}

void loop() 
{
    for(unsigned int i = 0; i < 30000; i++)
    {
        set_address(i);
        delay(100);
        send_address_to_serial();
    }
    
}

void set_address(int address)
{
    shiftOut(SHIFT_SER_PIN, SHIFT_SRCLK_PIN, MSBFIRST, address << 8);
  	shiftOut(SHIFT_SER_PIN, SHIFT_SRCLK_PIN, MSBFIRST, address&0xFF);
    digitalWrite(SHIFT_DONE_PIN, HIGH);
    digitalWrite(SHIFT_DONE_PIN, LOW);
}

void send_address_to_serial()
{
    char bits[9];
    for (char i = 0; i < 8; i++)
    {
        bits[i] = digitalRead(i + 2) + 48;
    }
    bits[9] = '\n';
    Serial.write(bits, 9);
    Serial.print('\n');
}
