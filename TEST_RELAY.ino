

const int button2 = 2; 
const int button5 = 5; 

int reading2;


const int relay3 = 3;
const int relay4 = 4; 
 
unsigned long lastDebounceTime2 = 0;  
unsigned long debounceDelay2 = 50;

int relay3State = HIGH; 
int relay4State = HIGH;

int button2State;
int button5State;

int lastButton2State = LOW;
int lastButton5State = LOW;
void setup() {
 Serial.begin(9600);
  pinMode(button2, INPUT);
   pinMode(button5, INPUT);   
pinMode(relay3, OUTPUT);
    digitalWrite(relay3, relay3State);   
pinMode(relay4, OUTPUT);
    digitalWrite(relay4, relay4State);

}

void loop() {
  if ((digitalRead(button2)==HIGH)&&(digitalRead(button5)==HIGH))
  {
 
digitalWrite(relay3, HIGH);   
digitalWrite(relay4, HIGH);
Serial.println("LED OFF");
delay(10000);
digitalWrite(relay3, HIGH);   
digitalWrite(relay4, LOW);
Serial.println("LED ON");
delay(500);
digitalWrite(relay3, HIGH);   
digitalWrite(relay4, HIGH);
Serial.println("LED OFF");
delay(100); 

}
else if ((digitalRead(button2)==LOW)&&(digitalRead(button5)==LOW))
{
  digitalWrite(relay4, HIGH);   
digitalWrite(relay3, LOW);
Serial.println("RELAY3 ON");

}

else 
{
  Serial.println("LED OFF");
  digitalWrite(relay3, HIGH);   
digitalWrite(relay4, HIGH);
}
}
