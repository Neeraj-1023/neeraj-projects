
int motorPin1 = 3; // pin 2 on L293D IC
int motorPin2 = 4; // pin 7 on L293D IC
int enablePin = 5; // pin 1 on L293D IC
int state;
int value; 
int flag=0;  
const int l1 = 10, l2 = 11, l3 = 12;
//makes sure that the serial only prints once the state
 
void setup() {
    // sets the pins as outputs:
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    pinMode(enablePin, OUTPUT);
    pinMode(l1,OUTPUT);
    pinMode(l2,OUTPUT);
    pinMode(l3,OUTPUT);
    // sets enablePin high so that motor can turn on:
    digitalWrite(enablePin, HIGH);
    // initialize serial communication at 9600 bits per second:
    Serial.begin(9600);
}
 
void loop() {
   
    //if some date is sent, reads it and saves in state
    if(Serial.available() > 0){     
      state = Serial.read();   
      flag=0;
    }
    //if state is '0', the motor will turn ON.
    else if (state == '0') {
        digitalWrite(motorPin1, LOW); // set pin 2 on L293D low
        digitalWrite(motorPin2, HIGH); // set pin 7 on L293D high
        if(flag == 0){
          Serial.println("Fan is ON");
          flag=1;
        }
    }   
    // if the state is '1' the DC motor will turn OFF
    if (state == '1') {
        digitalWrite(motorPin1, LOW); // set pin 2 on L293D low
        digitalWrite(motorPin2, LOW); // set pin 7 on L293D low
        if(flag == 0){
          Serial.println("Fan is OFF");
          flag=1;
        }
    }
    // if the state is '2' the led will turn ON
    
    else if(state == '2'){
          digitalWrite(l1,HIGH);
          if(flag == 0){
            Serial.println("Light 1 is ON");
            flag = 1;
            }
          }
     //If the state is '3', the led will turn OFF
     else if(state == '3'){
          digitalWrite(l1,LOW);
          if(flag == 0){
            Serial.println("Light 1 is OFF");
            flag = 1;
            }
          }
     //if the state id '4', the led will turn ON
     else if(state == '4'){
          digitalWrite(l2,HIGH);
          if(flag == 0){
            Serial.println("Light 2 is ON");
            flag = 1;
            }
          }
     //if the state is '5', the led will turn OFF
     else if(state == '5'){
          digitalWrite(l2,LOW);
          if(flag == 0){
            Serial.println("Light 2 is OFF");
            flag = 1;
            }
          }
     //if the state is '6', the led will turn ON
     else if(state == '6'){
          digitalWrite(l3,HIGH);
          if(flag == 0){
            Serial.println("Light 3 is ON");
            flag = 1;
            }
          }
     //if the state is '7', the led will turn OFF
     else if(state == '7'){
          digitalWrite(l3,LOW);
          if(flag == 0){
            Serial.println("Light 3 is OFF");
            flag = 1;
            }
          }
}
