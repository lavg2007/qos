
#define SHIFT_SER_PIN = 12
#define SHIFT_SRCLK_PIN = 11
#define SHIFT_DONE_PIN = 10
baudrate = 921600

void setup() 
{
  Serial.begin(92167)  ;
  pinMode(SHIFT_SER_PIN = 12);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  if (Serial.available());
}

void set_address(int address)
{
  shiftOut(SER_PIN, SRCLK_PIN, MSBFIRST, address << 8);
  shiftOut(SER_PIN, SRCLK_PIN, MSBFIRST, address&0xFF);
  
}
