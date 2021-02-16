#include <DHT.h>
#include <SPI.h>
#include <Ethernet.h>

//Configurando o Ethernet Shield
byte mac[] = {0xDE, 0xAD,0xBE, 0xEF, 0xFE, 0xDE}; // atribuindo endereço MAC
IPAddress manualIP (192,168,0,120); //Definindo o IP manualmente, caso o DHCP estiver OFF

EthernetServer server (80); //Inicia o servidor

boolean dhcpConnected = false;

//Configurando o DHT11
#define DHTPIN 3
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
//Setup Ethernet
if (!Ethernet.begin(mac)) //Conecta usando DHCP
  {
  Ethernet.begin (mac, manualIP); //Em caso de falha do DHCP
  }
  server.begin (); //Inicia o servidor

  dht.begin(); //Inicia o dht
}

void loop() {
  delay (3000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  
  EthernetClient client = server.available(); //Ouve as conexões do cliente
  if (client)
  {
    boolean currentLineIsBlank = true;
    while (client.connected())//Conecta e le dados
    {
      if (client.available())
      {
        char c = client.read(); //Conecta e le os dados do cliente
          if (c == '\n' && currentLineIsBlank) //Envia a resposta ao cliente
          {
            client.println ("HTTP/1.1 200 Ok");
            client.println ("Content - Type: text/html");
            client.println ();
            client.println ("Estacao Meteorologica"); //Envia a resposta ao cliente
            client.println("Temperatura:");
            client.print (t);
            client.println("Umidade");
            client.print (h);
            break;
          }
       if (c == '\n')
       {
        currentLineIsBlank = true;
       }
       else if (c != '\r')
       {
       currentLineIsBlank = false;
       }
       }

    }
    delay (1); //Tempo para o cliente receber os dados
    client.stop(); //Encerra a conexão
  }
  }
