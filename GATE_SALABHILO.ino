const int button2 = 4; 
const int button3 = 5; 
const int button4 = 2; 
const int button5 = 3;
const int button6 = 6;

const int OUT7 = 7;

const int relay9 = 8;
const int relay10 = 9; 
const int relay11 = 10; 
const int relay12 = 11; 

int OUT7STATE = HIGH;
int relay9State = HIGH; 
int relay10State = HIGH;
int relay11State = HIGH;
int relay12State = HIGH;

int button2State;
int button3State;  
int button4State;  
int button5State;
int button6State;


int lastButton2State = LOW; 
int lastButton3State = LOW;  
int lastButton4State = HIGH;  
int lastButton5State = HIGH; 
int lastButton6State = HIGH;  

int reading2;
int reading3;
int reading4;
int reading5;
int reading6;


unsigned long lastDebounceTime2 = 0;  
unsigned long debounceDelay2 = 50;
unsigned long lastDebounceTime3 = 0;  
unsigned long debounceDelay3 = 50;    
unsigned long lastDebounceTime4 = 0;  
unsigned long debounceDelay4 = 50;    
unsigned long lastDebounceTime5 = 0;  
unsigned long debounceDelay5 = 50;
unsigned long lastDebounceTime6 = 0;  
unsigned long debounceDelay6 = 50;    


long time;

void setup() {
  Serial.begin(9600);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);
  pinMode(button5, INPUT);
  pinMode(button6, INPUT);
  
  pinMode(OUT7, OUTPUT);
  digitalWrite(OUT7, HIGH);  
pinMode(relay9, OUTPUT);
    digitalWrite(relay9, relay9State);   
pinMode(relay10, OUTPUT);
    digitalWrite(relay10, relay10State);
pinMode(relay11, OUTPUT);
    digitalWrite(relay11, relay11State);
pinMode(relay12, OUTPUT);
    digitalWrite(relay12, relay12State);   

}    
void loop() {
  reading2 = digitalRead(button2);
  reading3 = digitalRead(button3);
  reading4 = digitalRead(button4);
  reading5 = digitalRead(button5);
  reading6 = digitalRead(button6);
  
if ((reading4) ==HIGH)
{       
 relay10State = HIGH;
}
if ((reading5) ==HIGH)
{       
relay9State = HIGH;
}

  
  if (reading2 != lastButton2State)
  {    
    lastDebounceTime2 = millis();
  }
  if ((millis() - lastDebounceTime2) > debounceDelay2) 
  {
      if (reading2 != button2State) 
      {
      button2State = reading2;
     if (button2State == LOW) 
      {
       
        relay10State = HIGH;
       relay11State = HIGH;
        relay12State = HIGH;
        delay(100);
        relay9State = !relay9State;
      }
      }
  }
if (reading3 != lastButton3State)
  {    
    lastDebounceTime3 = millis();
  }
  if ((millis() - lastDebounceTime3) > debounceDelay3) 
  {
      if (reading3 != button3State) 
      {      
      button3State = reading3;
      if (button3State == LOW) 
      {
        relay9State = HIGH;
        
       relay11State = HIGH;
        relay12State = HIGH;
        delay(100);
        relay10State = !relay10State;
      }
      }
  }
  if (reading4 != lastButton4State)
  {    
   lastDebounceTime4 = millis();
 }
 if ((millis() - lastDebounceTime4) > debounceDelay4) 
  {
      if (reading4 != button4State) 
      {      
      button4State = reading4;
      if (button4State == HIGH) 
      {
        relay11State =LOW;
        relay9State = HIGH;
        relay10State = HIGH;
        relay12State = HIGH; 
             
        }
      }
  }
  if (reading5 != lastButton5State)
  {    
    lastDebounceTime5 = millis();
  }
  if ((millis() - lastDebounceTime5) > debounceDelay5) 
  {
      if (reading5 != button5State) 
      {      
      button5State = reading5;
      if (button5State == HIGH) 
      {
        relay9State = HIGH;
        relay10State = HIGH;
       relay11State = LOW;
        relay12State = HIGH;       
      }
    }
  }
   if (reading6 == HIGH)
   {
    OUT7STATE == LOW;
    }
  
  
   
  
        
lastButton2State = reading2;
lastButton3State = reading3;
lastButton4State = reading4;
lastButton5State = reading5;
lastButton6State = reading6;

  
  digitalWrite(relay9, relay9State);
  digitalWrite(relay10, relay10State);
  digitalWrite(relay11, relay11State);
  digitalWrite(relay12, relay12State);
  digitalWrite(OUT7, OUT7STATE);  
}
  
  
  
