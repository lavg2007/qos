#define BAUDRATE 115200
#define LSB_PIN 3
#define MSB_PIN 18
#define CLK_PIN 2
#define RATE 500

unsigned char input_pins[16] = {3,4,5,6,7,8,9,10,11,12,A0,A1,A2,A3,A4, A5};
void setup()
{
    Serial.begin(BAUDRATE);
    pinMode(CLK_PIN, OUTPUT);
    for (int i = 0; i < 16; i++)
    {
        pinMode(input_pins[i], INPUT);
    }
    //attachInterrupt(digitalPinToInterrupt(CLK_PIN), interrupt_handler, FALLING);
}

void loop()
{
    digitalWrite(CLK_PIN, HIGH);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(RATE);
    
    digitalWrite(CLK_PIN, LOW);
    digitalWrite(LED_BUILTIN, LOW);
    delay(RATE/2);
    unsigned int data = read_pins();
    char buf[50];
    sprintf(buf, "%04X\n", data);
    Serial.print(buf); 
    delay(RATE/2);
}

unsigned int read_pins()
{
    unsigned int data = 0;
    for (int i = 0; i < 16; i++)
    {
        unsigned int newbit = digitalRead(input_pins[i]) ? 1:0 ;
        data += (newbit << i);
    }
    return data;
}

void interrupt_handler()
{
    delay(1);
    unsigned int data = read_pins();
    char buf[50];
    sprintf(buf, "%04X\n", data);
    
    Serial.print(buf); 
}
