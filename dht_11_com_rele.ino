  // Inclusão de bibliotecas
#include <DHT.h>

  //Definindo as variáveis
#define DHTPIN 2 //Dht no pino digital 
#define DHTTYPE DHT11 //esta sendo usado o DHT 11
int releh = 8;// rele que controla a umidade no digital 8
int relet = 9;// rele que controla a temperatura
int led = 7; //led no digital 7
DHT dht (DHTPIN, DHTTYPE);

void setup() 
  {
 pinMode (releh, OUTPUT);
 digitalWrite (releh, LOW); 
 pinMode (relet, OUTPUT);
 digitalWrite (relet, LOW);
 pinMode (led, OUTPUT);
 digitalWrite (led, LOW);
 Serial.begin(9600);
 Serial.println("DHT11 Test! ");
  }
  
void loop() {
  //Iniciando as medicoes

  delay (2000);

  float h = dht.readHumidity(); //variavel h, para armazenar a leitura da umidade
  float t = dht.readTemperature(); //t -> temperatura em Celsius (padrao) 
  //Para leitura em Fahrenheit colocar -> dht.Temperature(true)
 
  //Print das medicoes
  Serial.print("Umidade: ");
  Serial.print (h);
  Serial.println("%");
  Serial.print("Temperatura: ");
  Serial.print(t);
  //int valor=248;
  Serial.print("*");
  Serial.println("C");
    
 if (h > 85) 
   {
    digitalWrite (releh, LOW);
   }
 if (h < 65)
    {
  digitalWrite (releh, HIGH);
    }
if (h < 85 && h > 65)
  {
  digitalWrite (led, HIGH);
  }


}
