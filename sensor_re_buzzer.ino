/*
Pinagem LCD

PINO  - Porta Arduino
1     -   GND
2     -   5V
3     -   Potenciometro
4     -   Digital 12
5     -   GND
6     -   Digital 11
11    -   Digital 5
12    -   Digital 4
13    -   Digital 3
14    -   Digital 2
15    -   5V (Utilizar um resistor de 1k ohm)
16    -   GND
*/

#include <LiquidCrystal.h> // Inclui a biblioteca LiquidCrystal
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // define os pinos do LCD
int trig = 7; // Define o pino trig do sensor na porta digital 7
int echo = 8; // Define o pino echo do sensor na porta digital 8
float tempo; // variável de tempo
float dist_cm; // variável para a distância em cm
int led_g = 9;
int led_b = 10;
int led_r = 13;
float seno;
float frequencia;
int buzz = 6;
int x;

void setup() {
  
  lcd.begin(16, 2);
  lcd.print("testing...");
  lcd.clear();
  pinMode(trig, OUTPUT); // define o pino trig como saída
  pinMode(echo, INPUT); // define o pino echo como entrada
  pinMode(led_g, OUTPUT); // led verde como saída
  pinMode(led_b, OUTPUT);
  pinMode(led_r, OUTPUT); // led vermelho como saída
  pinMode(buzz, OUTPUT);

} // Setup

void loop()
{
 
// Disparando o ultrassom
  digitalWrite(trig, HIGH); // Coloca o pino trig em nível alto
  delayMicroseconds(10); // define um delay de 10 us
  digitalWrite(trig, LOW); // Retorna o pino trig para nível baixo

// Medindo o tempo do pulso
  tempo = pulseIn(echo, HIGH); // Conta o tempo entre o pino echo sair do estado alto e voltar para baixo

  dist_cm = (tempo/29.4)/2; // Calcula a velocidade

  lcd.setCursor(1,0);
  lcd.print("Distancia: ");
  lcd.setCursor(2,6);
  lcd.print(dist_cm);
  lcd.print(" cm");
 
//IF
  
  if (dist_cm > 50){
    
    x = 0;
    seno = sin(x*3.14/180); // converte o seno em rad
  frequencia = 2000 + seno*1000;
    digitalWrite(led_g, HIGH);
    digitalWrite(led_b,LOW);
    digitalWrite(led_r,LOW);
    tone (buzz, frequencia);
  }

  if(dist_cm <= 50 && dist_cm > 20){
  
    x = 45;
  seno = sin(x*3.14/180); // converte o seno em rad
    frequencia = 2000 + seno*1000;
    digitalWrite(led_g, LOW);
    digitalWrite(led_b,HIGH);
    digitalWrite(led_r,LOW);
    tone (buzz, frequencia);
  
  }
  
  if(dist_cm < 20) {
    
    x = 90;
    seno = sin(x*3.14/180); // converte o seno em rad
    frequencia = 2000 + seno*1000;
    digitalWrite(led_g, LOW);
    digitalWrite(led_b,LOW);
    digitalWrite(led_r,HIGH);
    tone(buzz, frequencia);
    
  } 
  
  delay(1000); //aguarda 1s para recomeçar o loop
  
} // Loop
