/*
Projeto para automatizar um dispenser de alcool em gel

jun/2020
*/

#include <Servo.h>

int pot = A0;
float distancia = 0;
int led = 3; //led no pino digital 3
int trig = 7;
int echo = 6;
float tempo; // variável tempo do ultrassom
Servo servo;

void setup()
{
  pinMode(pot,INPUT);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(led,OUTPUT);
  servo.attach(9);
    
} // setup

void loop()
{

  // Ligando o ultrassom
  tempo = pulseIn(echo,HIGH);
  distancia = (tempo/58.8);


  if(distancia <= 30){
    digitalWrite(led,HIGH);
    servo.write(60);
    delay(2000);
    digitalWrite(led,LOW); 
    servo.write(0);
       
    }// if
  
} // loop
