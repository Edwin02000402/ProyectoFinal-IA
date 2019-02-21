#include <SoftwareSerial.h>
#include "musical_notes.h"
SoftwareSerial BTserial(4,5); // tx | rX

//Pines del Sensor Ultrasonico
long tiempo,distancia;
int trigger = 13;
int echo = 12;

//Pin de los motores amarillos 
const int control=10;

//pines del motor a paso
int motorPin1 = 52;  //pin8----1N4
int motorPin2 = 50;  //pin8----1N3
int motorPin3 = 48; //pin8----1N2
int motorPin4 = 46; //pin8----1N1


void setup(){
  //Conexion serial
  BTserial.begin(9600);
  Serial.begin(9600);
  //Pines del sensor
  pinMode(echo, INPUT);
  pinMode(trigger, OUTPUT);
  digitalWrite(trigger,LOW);
  //Pines de los motores amarilos
  pinMode(control,OUTPUT);
  //Pines del motor a pasos
 pinMode(motorPin1, OUTPUT);
 pinMode(motorPin2, OUTPUT);
 pinMode(motorPin3, OUTPUT);
 }
 
 void loop(){
  for(int n = 0 ; n < 255 ; n++){
    analogWrite (control,  n) ;
  }
  delay(100);
  digitalWrite(trigger, HIGH);
  digitalWrite (trigger, LOW);  
  tiempo = pulseIn(echo,HIGH); 
  distancia=0.017*tiempo; 
  luces(distancia);
  Serial.print(distancia);
  BTserial.print(distancia);
  BTserial.print("#");
  delay(1000);
  
   else if(distancia >=15  && distancia <=30){
   for (int i=0; i <= 60; i++){
                gira_horario(2); 
             } 
          delay(2000);//espera 2 segundos
      }
    for(int n = 0 ; n < 30 ; n++){
    analogWrite (control,  n) ;
  }
  }
  
  void gira_antihorario(int delayTime){

digitalWrite(motorPin1, HIGH); // Los pines se activan en secuencia
digitalWrite(motorPin2, HIGH);
digitalWrite(motorPin3, LOW);
digitalWrite(motorPin4, LOW);
delay(delayTime);

digitalWrite(motorPin1, LOW);
digitalWrite(motorPin2, HIGH);
digitalWrite(motorPin3, HIGH);
digitalWrite(motorPin4, LOW);
delay(delayTime);

digitalWrite(motorPin1, LOW);
digitalWrite(motorPin2, LOW);
digitalWrite(motorPin3, HIGH);
digitalWrite(motorPin4, HIGH);
delay(delayTime);

digitalWrite(motorPin1, HIGH);
digitalWrite(motorPin2, LOW);
digitalWrite(motorPin3, LOW);
digitalWrite(motorPin4, HIGH);
delay(delayTime);  
}

void gira_horario(int delayTime){
digitalWrite(motorPin1, HIGH);
digitalWrite(motorPin2, LOW);
digitalWrite(motorPin3, LOW);
digitalWrite(motorPin4, HIGH);
delay(delayTime); 
digitalWrite(motorPin1, LOW);
digitalWrite(motorPin2, LOW);
digitalWrite(motorPin3, HIGH);
digitalWrite(motorPin4, HIGH);
delay(delayTime);
digitalWrite(motorPin1, LOW);
digitalWrite(motorPin2, HIGH);
digitalWrite(motorPin3, HIGH);
digitalWrite(motorPin4, LOW);
delay(delayTime);
digitalWrite(motorPin1, HIGH); // Los pines se activan en secuencia
digitalWrite(motorPin2, HIGH);
digitalWrite(motorPin3, LOW);
digitalWrite(motorPin4, LOW);
delay(delayTime);
}
  
  