#include <Servo.h>
int LED = 13;
int LEDR = 12;
int capteur = 4;
int detect = 0;
char d; // variable contenant le caractère lu
int etat = HIGH;
//int i=0;

Servo myservo;


void setup(){
  pinMode(LED,OUTPUT);
  pinMode(LEDR,OUTPUT);
  pinMode(capteur,INPUT);
  digitalWrite(LED,LOW);
  digitalWrite(LEDR,LOW);
  myservo.attach(9);
  Serial.begin(9600);
}

void loop(){
  detect = digitalRead(capteur);
  if(detect == HIGH){
    Serial.write('1');
    digitalWrite(LED,HIGH);
    digitalWrite(LEDR,LOW);    

    //Serial.println("Mouveent detecte   ***\n");
    if(Serial.available()){
      d=Serial.read();
      if(d){
        myservo.write(0);
        delay(3000);
        myservo.write(90);
      }
    }    
    }    
  else if(detect == LOW){ 
    Serial.write('0');  
    digitalWrite(LEDR,HIGH); 
    digitalWrite(LED,LOW);
    //Serial.println("pas client");
  }
delay(1000);
}
