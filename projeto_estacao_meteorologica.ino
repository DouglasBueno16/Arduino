#include <LiquidCrystal.h>
#include <DHT.h>

//Configurando o DHT11
#define DHTPIN 8
#define DHTTYPE DHT11
DHT dht (DHTPIN, DHTTYPE);
LiquidCrystal lcd (11,12,4,5,6,7); // Cria um objeto lcd

/*
Ligar os pinos do LCD:
Pino 4 - Porta Digital 11
Pino 6 - Porta Digital 12
Pino 11 - Porta Digital 4
Pino 12 - Porta Digital 5
Pino 13 - Porta Digital 6
Pino 14 - Porta Digital 7
*/

void setup() {
  // DHT
dht.begin (); //dht iniciado
  //Serial
Serial.begin (9600);
Serial.println("Teste DHT");
  //LCD
lcd.clear(); //Limpa o LCD antes de comecar
lcd.begin (16,2); //Inicia um display de 16x2
lcd.home(); //Posiciona no canto superior esquerdo
lcd.print("Central do Tempo");
lcd.clear();

}

void loop() {
  //DHT
float h = dht.readHumidity();
float t = dht.readTemperature();
  //Serial
Serial.print (h);
Serial.println("%");
Serial.print (t);
Serial.println("C");
  //LCD
lcd.home();
lcd.print("Umidade ");
lcd.print (h);
lcd.print ("%");
lcd.setCursor (0,1); // Cursor na coluna 0 e linha 1
lcd.print("Temp. ");
lcd.print (t);
lcd.print ("C");
delay (2000);
}
