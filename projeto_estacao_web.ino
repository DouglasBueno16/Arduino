/*
Projeto de uma estação de monitoramento via web
*/

//Bibliotecas Utilizadas
#include <LiquidCrystal.h>
#include <Keypad.h> 
#include <DHT.h> 
#include <Ethernet.h> 
#include <SPI.h> 

//Definindo as portas dos sensores analógicos e o tipo do DHT
#define usa A0 
#define usc A1 
#define sb A2 
#define DHTPIN 53
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

//Declara as portas digitais para o LCD
LiquidCrystal lcd(22, 24, 26, 28, 30, 32); 

//iniciando servidor declarano o MAC e o IP que sera usado
byte mac[] = {0x48, 0xC2, 0xA1, 0xF3, 0x8D, 0xB7};
byte ip[] = {192,168,0,120};
EthernetServer server (80);

//Variáveis inteiras utilizadas
int i=0;
int j=0, vs=0, slc=0, sla=0;
int p, ll, lh, fo, prs;
int cr=4, ar=0;

//Variáveis inteiras para definir os pinos digitais
int sp=49, rl=47, rh=45, bp=48, bi=46, fg=44, ps=43;

//Varáveis declaradas como float
float h, t;

//Variáveis para receber caracteres
char w, x, y, z, key;

//Bytes constantes para definir valores fixos
const byte li=4, co=3;

//Definindo os pinos digitais de linhas e colunas do teclado 4x3
byte pl[] = {23, 25, 27, 29};
byte pc[] = {31, 33, 35};

//Strings para texto exibido no LCD e na Página Web
String b, f, iv, e, gc, ga, hr, hp;
String a = "Sistema Pronto";
String d; 

//Mapeando teclas do teclado 4x3
char keys[li][co] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'},
};

//Cria o teclado
Keypad tc = Keypad( makeKeymap(keys), pl, pc, li, co);

void setup() {
  //Declarando os pinos de saída e entrada
  pinMode(bp, OUTPUT);
  pinMode(bi, OUTPUT);
  pinMode(fg, INPUT);
  pinMode(ps, INPUT);

  //Inicia o LCD
  lcd.begin(16,2);

  //Inicia o DHT
  dht.begin();

  Ethernet.begin (mac,ip);  //Incia o Etenert com o MAC e o IP declarado inicialmente
  server.begin ();          //Inicia o Servidor

  //Colocando Condição inicial no LCD
  lcd.print(a);
  lcd.setCursor(0,1);
}

void loop() {
  //Configurar variáveis para receber a leitura dos periféricos
  h = dht.readHumidity();
  t = dht.readTemperature();
  p = digitalRead(sp);
  ll = digitalRead(rl);
  lh = digitalRead(rh);
  fo = digitalRead(fg);
  prs = digitalRead(ps);
  vs = analogRead (sb);
  slc = analogRead(usc);
  sla = analogRead(usa);
  key = tc.getKey();

  //Condição inicial para o sistema
  if (cr==4){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(a);
    lcd.setCursor(0,1);
    lcd.print(b);
    delay(1000);
    if (key != NO_KEY){ //Recebe a tecla para Armar o sistema de Alarme
      if (key == '#'){
        cr = cr+1;
      }
    }
  }

  //Prepara a tela do LCD para receber a senha
  if (cr==5){
    lcd.clear();
    a = "Digite sua Senha";
    lcd.print(a);
    delay(100);
    key = '+';
    cr = cr +1;
  }

  //Código para receber a entrada do teclado para digitar a senha
  //Primeiro caracter da senha
  if(cr==6){
    if(key != NO_KEY){
      if (key == '1'){ //Se precionar 1
        w = '1';
        lcd.setCursor(cr,1); //Posiciona no 1° Caracter da senha
        lcd.print(w);
        delay(100); //Espera 100ms
        key = '+';  //Armqzena um char inexistente no teclado para receber outra tecla precionada
        cr = cr+1;  //Soma 1 ao cr para colocar o próximo caracter
      }
      if (key == '2'){ //Se precionar 2
        w = '2';
        lcd.setCursor(cr,1); //Posiciona no 1° Caracter da senha
        lcd.print(w);
        delay(100);
        key = '+';
        cr = cr+1;  //Soma 1 ao cr para colocar o próximo caracter
      }
      if (key == '3'){ //Se precionar 3
        w = '3';
        lcd.setCursor(cr,1); //Posiciona no 1° Caracter da senha
        lcd.print(w);
        delay(100);
        key = '+';
        cr = cr+1;  //Soma 1 ao cr para colocar o próximo caracter
      }
      if (key == '4'){ //Se precionar 4
        w = '4';
        lcd.setCursor(cr,1); //Posiciona no 1° Caracter da senha
        lcd.print(w);
        delay(100);
        key = '+';
        cr = cr+1;  //Soma 1 ao cr para colocar o próximo caracter
      }
      if (key == '5'){ //Se precionar 5
        w = '5';
        lcd.setCursor(cr,1); //Posiciona no 1° Caracter da senha
        lcd.print(w);
        delay(100);
        key = '+';
        cr = cr+1;  //Soma 1 ao cr para colocar o próximo caracter
      }
      if (key == '6'){ //Se precionar 6
        w = '6';
        lcd.setCursor(cr,1); //Posiciona no 1° Caracter da senha
        lcd.print(w);
        delay(100);
        key = '+';
        cr = cr+1;  //Soma 1 ao cr para colocar o próximo caracter
      }
      if (key == '7'){ //Se precionar 7
        w = '7';
        lcd.setCursor(cr,1); //Posiciona no 1° Caracter da senha
        lcd.print(w);
        delay(100);
        key = '+';
        cr = cr+1;  //Soma 1 ao cr para colocar o próximo caracter
      }
      if (key == '8'){ //Se precionar 8
        w = '8';
        lcd.setCursor(cr,1); //Posiciona no 1° Caracter da senha
        lcd.print(w);
        delay(100);
        key = '+';
        cr = cr+1;  //Soma 1 ao cr para colocar o próximo caracter
      }
      if (key == '9'){ //Se precionar 9
        w = '9';
        lcd.setCursor(cr,1); //Posiciona no 1° Caracter da senha
        lcd.print(w);
        delay(100);
        key = '+';
        cr = cr+1;  //Soma 1 ao cr para colocar o próximo caracter
      }
      if (key == '0'){ //Se precionar 0
        w = '0';
        lcd.setCursor(cr,1); //Posiciona no 1° Caracter da senha
        lcd.print(w);
        delay(100);
        key = '+';
        cr = cr+1;  //Soma 1 ao cr para colocar o próximo caracter
      }
    }
  }

  //Segundo caracter da senha
  if(cr==7){
    if(key != NO_KEY){
      if (key == '1'){ //Se precionar 1
        x = '1';
        lcd.setCursor(cr,1); //Posiciona no 1° Caracter da senha
        lcd.print(x);
        delay(100);
        key = '+';
        cr = cr+1;  //Soma 1 ao cr para colocar o próximo caracter
      }
      if (key == '2'){ //Se precionar 2
        x = '2';
        lcd.setCursor(cr,1); //Posiciona no 1° Caracter da senha
        lcd.print(x);
        delay(100);
        key = '+';
        cr = cr+1;  //Soma 1 ao cr para colocar o próximo caracter
      }
      if (key == '3'){ //Se precionar 3
        x = '3';
        lcd.setCursor(cr,1); //Posiciona no 1° Caracter da senha
        lcd.print(x);
        delay(100);
        key = '+';
        cr = cr+1;  //Soma 1 ao cr para colocar o próximo caracter
      }
      if (key == '4'){ //Se precionar 4
        x = '4';
        lcd.setCursor(cr,1); //Posiciona no 1° Caracter da senha
        lcd.print(x);
        cr = cr+1;  //Soma 1 ao cr para colocar o próximo caracter
      }
      if (key == '5'){ //Se precionar 5
        x = '5';
        lcd.setCursor(cr,1); //Posiciona no 1° Caracter da senha
        lcd.print(x);
        delay(100);
        key = '+';
        cr = cr+1;  //Soma 1 ao cr para colocar o próximo caracter
      }
      if (key == '6'){ //Se precionar 6
        x = '6';
        lcd.setCursor(cr,1); //Posiciona no 1° Caracter da senha
        lcd.print(x);
        delay(100);
        key = '+';
        cr = cr+1;  //Soma 1 ao cr para colocar o próximo caracter
      }
      if (key == '7'){ //Se precionar 7
        x = '7';
        lcd.setCursor(cr,1); //Posiciona no 1° Caracter da senha
        lcd.print(x);
        delay(100);
        key = '+';
        cr = cr+1;  //Soma 1 ao cr para colocar o próximo caracter
      }
      if (key == '8'){ //Se precionar 8
        x = '8';
        lcd.setCursor(cr,1); //Posiciona no 1° Caracter da senha
        lcd.print(x);
        delay(100);
        key = '+';
        cr = cr+1;  //Soma 1 ao cr para colocar o próximo caracter
      }
      if (key == '9'){ //Se precionar 9
        x = '9';
        lcd.setCursor(cr,1); //Posiciona no 1° Caracter da senha
        lcd.print(x);
        delay(100);
        key = '+';
        cr = cr+1;  //Soma 1 ao cr para colocar o próximo caracter
      }
      if (key == '0'){ //Se precionar 0
        x = '0';
        lcd.setCursor(cr,1); //Posiciona no 1° Caracter da senha
        lcd.print(x);
        delay(100);
        key = '+';
        cr = cr+1;  //Soma 1 ao cr para colocar o próximo caracter
      }
    }
  }

   //Terceiro caracter da senha
   if(cr==8){
    if(key != NO_KEY){
      if (key == '1'){ //Se precionar 1
        y = '1';
        lcd.setCursor(cr,1); //Posiciona no 1° Caracter da senha
        lcd.print(y);
        delay(100);
        key = '+';
        cr = cr+1;  //Soma 1 ao cr para colocar o próximo caracter
      }
      if (key == '2'){ //Se precionar 2
        y = '2';
        lcd.setCursor(cr,1); //Posiciona no 1° Caracter da senha
        lcd.print(y);
        delay(100);
        key = '+';
        cr = cr+1;  //Soma 1 ao cr para colocar o próximo caracter
      }
      if (key == '3'){ //Se precionar 3
        y = '3';
        lcd.setCursor(cr,1); //Posiciona no 1° Caracter da senha
        lcd.print(y);
        delay(100);
        key = '+';
        cr = cr+1;  //Soma 1 ao cr para colocar o próximo caracter
      }
      if (key == '4'){ //Se precionar 4
        y = '4';
        lcd.setCursor(cr,1); //Posiciona no 1° Caracter da senha
        lcd.print(y);
        cr = cr+1;  //Soma 1 ao cr para colocar o próximo caracter
      }
      if (key == '5'){ //Se precionar 5
        y = '5';
        lcd.setCursor(cr,1); //Posiciona no 1° Caracter da senha
        lcd.print(y);
        delay(100);
        key = '+';
        cr = cr+1;  //Soma 1 ao cr para colocar o próximo caracter
      }
      if (key == '6'){ //Se precionar 6
        y = '6';
        lcd.setCursor(cr,1); //Posiciona no 1° Caracter da senha
        lcd.print(y);
        delay(100);
        key = '+';
        cr = cr+1;  //Soma 1 ao cr para colocar o próximo caracter
      }
      if (key == '7'){ //Se precionar 7
        y = '7';
        lcd.setCursor(cr,1); //Posiciona no 1° Caracter da senha
        lcd.print(y);
        delay(100);
        key = '+';
        cr = cr+1;  //Soma 1 ao cr para colocar o próximo caracter
      }
      if (key == '8'){ //Se precionar 8
        y = '8';
        lcd.setCursor(cr,1); //Posiciona no 1° Caracter da senha
        lcd.print(y);
        delay(100);
        key = '+';
        cr = cr+1;  //Soma 1 ao cr para colocar o próximo caracter
      }
      if (key == '9'){ //Se precionar 9
        y = '9';
        lcd.setCursor(cr,1); //Posiciona no 1° Caracter da senha
        lcd.print(y);
        delay(100);
        key = '+';
        cr = cr+1;  //Soma 1 ao cr para colocar o próximo caracter
      }
      if (key == '0'){ //Se precionar 0
        y = '0';
        lcd.setCursor(cr,1); //Posiciona no 1° Caracter da senha
        lcd.print(y);
        delay(100);
        key = '+';
        cr = cr+1;  //Soma 1 ao cr para colocar o próximo caracter
      }
    }
  }

   //Quarto caracter da senha
   if(cr==9){
    if(key != NO_KEY){
      if (key == '1'){ //Se precionar 1
        z = '1';
        lcd.setCursor(cr,1); //Posiciona no 1° Caracter da senha
        lcd.print(z);
        delay(100);
        key = '+';
        cr = cr+1;  //Soma 1 ao cr para colocar o próximo caracter
      }
      if (key == '2'){ //Se precionar 2
        z = '2';
        lcd.setCursor(cr,1); //Posiciona no 1° Caracter da senha
        lcd.print(z);
        delay(100);
        key = '+';
        cr = cr+1;  //Soma 1 ao cr para colocar o próximo caracter
      }
      if (key == '3'){ //Se precionar 3
        z = '3';
        lcd.setCursor(cr,1); //Posiciona no 1° Caracter da senha
        lcd.print(z);
        delay(100);
        key = '+';
        cr = cr+1;  //Soma 1 ao cr para colocar o próximo caracter
      }
      if (key == '4'){ //Se precionar 4
        z = '4';
        lcd.setCursor(cr,1); //Posiciona no 1° Caracter da senha
        lcd.print(z);
        cr = cr+1;  //Soma 1 ao cr para colocar o próximo caracter
      }
      if (key == '5'){ //Se precionar 5
        z = '5';
        lcd.setCursor(cr,1); //Posiciona no 1° Caracter da senha
        lcd.print(z);
        delay(100);
        key = '+';
        cr = cr+1;  //Soma 1 ao cr para colocar o próximo caracter
      }
      if (key == '6'){ //Se precionar 6
        z = '6';
        lcd.setCursor(cr,1); //Posiciona no 1° Caracter da senha
        lcd.print(z);
        delay(100);
        key = '+';
        cr = cr+1;  //Soma 1 ao cr para colocar o próximo caracter
      }
      if (key == '7'){ //Se precionar 7
        z = '7';
        lcd.setCursor(cr,1); //Posiciona no 1° Caracter da senha
        lcd.print(z);
        delay(100);
        key = '+';
        cr = cr+1;  //Soma 1 ao cr para colocar o próximo caracter
      }
      if (key == '8'){ //Se precionar 8
        z = '8';
        lcd.setCursor(cr,1); //Posiciona no 1° Caracter da senha
        lcd.print(z);
        delay(100);
        key = '+';
        cr = cr+1;  //Soma 1 ao cr para colocar o próximo caracter
      }
      if (key == '9'){ //Se precionar 9
        z = '9';
        lcd.setCursor(cr,1); //Posiciona no 1° Caracter da senha
        lcd.print(z);
        delay(100);
        key = '+';
        cr = cr+1;  //Soma 1 ao cr para colocar o próximo caracter
      }
      if (key == '0'){ //Se precionar 0
        z = '0';
        lcd.setCursor(cr,1); //Posiciona no 1° Caracter da senha
        lcd.print(z);
        delay(100);
        key = '+';
        cr = cr+1;  //Soma 1 ao cr para colocar o próximo caracter
      }
    }
  }

  //Verificando a senha digitada
  if (cr==10){
    //Caso para desarmar o Alarme disparado
    if (ar==1){
      if (key != NO_KEY){
      if (key == '*'){
        if (w != '1' || x != '2' || y != '3' || z != '4'){ //Caso esteja errada
          lcd.clear();
          a = "Senha Incorreta!";
          lcd.print(a);
          delay (2000);
          key = '+';
          cr = 6;
          lcd.clear();
          a = "Digite sua Senha";
          lcd.print(a);
        }
        if (w == '1'){
          if (x == '2'){
            if (y == '3'){
              if (z == '4'){ //Caso esteja certa
                lcd.clear();
                a = "Senha Correta!";
                key = '+';
                lcd.print(a);
                delay (1000);
                lcd.clear();
                a = "Sistema Pronto";
                lcd.print(a);
                delay(1000);
                cr=4;
                ar=0;
                iv = "Desativado";
              }
            }
          }
        }
      }
    }
  }
    //Caso para Armar o Alarme
    if (ar == 0){
    if (key != NO_KEY){
      if (key == '*'){
        if (w != '1' || x != '2' || y != '3' || z != '4'){ //Caso esteja errada
          lcd.clear();
          a = "Senha Incorreta!";
          lcd.print(a);
          delay (2000);
          cr = 6;
          lcd.clear();
          a = "Digite sua Senha";
          lcd.print(a);
        }
        if (w == '1'){
          if (x == '2'){
            if (y == '3'){
              if (z == '4'){ //Caso esteja certa
                lcd.clear();
                a = "Senha Correta!";
                lcd.print(a);
                key = '+';
                delay (1000);
                for (i=0; i<11; i++){ //Tempo de 10s para se retirar do local
                  lcd.setCursor(0,1);
                  lcd.print(i);
                  delay(1000);
                }
                lcd.clear();
                a = "Sistema Armado";
                iv = "Ativado";
                lcd.print(a);
                delay(1000);
                cr=4;
                ar=1;
                key = '+';
              }
            }
          }
        }
      }
    }
  }
}
  if (ar==1){
    if (prs == 1 || vs >= 1000){
      lcd.clear();
      a = "Digite sua Senha";
      lcd.print(a);
      delay(100);
      cr=6;
      iv = "Aleta de Invasao!";
    }
  }

  //Detectando incêndio
  if (fo==1){
    f = "Alerta de Incendio";
  }
  if (fo==0){
    f = "Lavoura Segura";
  }
  
  //Sistema de irrigação automática
  label: //Retorna para o início das verificações
  //Se não há água no poço
  if (p==0){
    b = "Poco Vazio";
    digitalWrite(bp, HIGH);
    digitalWrite(bi, HIGH);
    hr = "Desativado";
    hp = "Desativado";
  }
  //Se tiver água no poço
  if (p==1){
    b = "Poco Cheio";

    //Se houver possibilidade de chuva
    if (h >= 50){
      d = "Possibilidade de Chuva";
      digitalWrite(bi, HIGH);
      digitalWrite(bp, HIGH);
      hr = "Desativado";
      hp = "Desativado";
    }
    else{
      d = "Clima limpo";
      //Caso há água no poço e no reservatório e esteja possibilitada a irrigação
      if (p==1 && ll==1 && j==1){
        
        //Se o solo estiver úmido
       if (slc >= 0 && slc < 600 && sla >=0 && sla < 600){
         digitalWrite(bi, HIGH);
         digitalWrite(bp, HIGH);
         gc = "Umido";
         ga = "Umido";
         hr = "Desativado";
         hp = "Desativado";
       }

       //Se a área do solo estiver seca seja no centro ou no perímetro
       if(slc >= 600 && slc <= 1023 && sla >= 600 && sla <=1023){
         digitalWrite(bi, LOW); 
         digitalWrite(bp, HIGH);
         gc = "Seco";
         ga = "Seco";
         hr = "Ativado";
         hp = "Desativado";
       }
       if(slc >= 0 && slc < 600 && sla >= 600 && sla <= 1023){
         digitalWrite(bi, LOW); 
         digitalWrite(bp, HIGH);
         gc = "Umido";
         ga = "Seco";
         hr = "Ativado";
         hp = "Desativado";
       }
       if(slc >= 600 && slc <= 1023 && sla >= 0 && sla < 600){
         digitalWrite(bi, LOW); 
         digitalWrite(bp, HIGH);
         gc = "Umido";
         ga = "Seco";
         hr = "Ativado";
         hp = "Desativado";
       }
    }
    else
    {
      //Se há água no poço e não na reserva se inicia o processo de encher a reserva
      if(p==1 && ll==0 && lh==0){
        j=0; //Impede a irrigação até que a reserva estja cheia
        digitalWrite(bi, HIGH);
        digitalWrite(bp, LOW);
        hr = "Desativado";
        hp = "Ativado";
        e = "Vazio";
      }
      else
      {
        //Verifica se está enchendo a reserva
        if(p==1 && ll==1 && lh==0)
        {
          digitalWrite(bi, HIGH);
          digitalWrite(bp, LOW);
          hr = "Desativado";
          hp = "Ativado";
          e = "Enchendo";
        }
        else
        {
          //Caso haja defeito no sensor de nível baixo da reserva
          if(p==1 && ll==0 && lh==1)
          {
            digitalWrite(bi, HIGH); //DESLIGA irrigação
            digitalWrite(bp, HIGH);
            hr = "Desativado";
            hp = "Desativado";
            e = "Sensor de Nivel Baixo da Reserva com defeito";
          }
          else{
            //Com a reserva cheia e o poço com água possibilita a irrigação
            if(p==1 && ll==1 && lh==1){
              j=1;  //possibilita a irrigação com a reserva completa
              goto label; //Retorna para a verificação
              digitalWrite(bi, HIGH);
              digitalWrite(bp, HIGH);
              hr = "Desativado";
              hp = "Desativado";
              e = "Cheio";
            }
            //Caso não tenha nenhuma das situações a cima, defito de leitura.
            else
            {
              digitalWrite(bi, HIGH);
              digitalWrite(bp, HIGH);
              hr = "Desativado";
              hp = "Desativado";
            }
          }
        }
      }
    }
  }
}

  //Codigo para gerar o Web Server       
  EthernetClient client = server.available();
  if (client)
    {
    boolean BlankLine = true;
     while (client.connected())//Conecta e le dados
    {
      if (client.available())
      {
        char c = client.read(); //Conecta e le os dados do cliente
          if (c == '\n' && BlankLine) //Envia a resposta ao cliente
          {
            client.println ("HTTP/1.1 200 Ok"); // Resposta HTTP padrão
            client.println ("Content - Type: text/html");
            client.println ();
            client.println ("<body>");
            client.println ("<h1>Central de Monitoramento<h1>");
            
            client.println ("<h2>Dados da Lavoura<h2>");
            client.println ("<h3> <h3>");
            client.println ("Umidade do Ar: ");
            client.println (h);
            client.print   ("%");
            client.println ("<br/>");
            
            client.println ("Temperatura do Ambiente: ");
            client.println (t);
            client.print   ("C");
            client.println ("<br/>");
            
            client.println ("");
            client.println ("<br/>");
            client.println (f);
            
            client.println ("<br/>");

            client.println ("<h2>Umidade do solo<h2>");

            client.println ("<h3> <h3>");
            client.println ("Solo Centro:");
            client.print (gc);
            client.println ("<br/>");
            client.println ("Solo Area:");
            client.print (ga);
            client.println ("<br/>");
            
            client.println ("<h2>Dados dos Recursos Hidricos<h2>");

            client.println ("<h3> <h3>");
            client.println ("Situacao do Poco:");
            client.print (b);
            client.println ("<br/>");
            client.println ("Bomba do Poco        :");
            client.print (hp);
            client.println ("<br/>");
            client.println ("Bomba do Reservatorio:");
            client.print (hr);
            client.println ("<br/>");
            client.println ("Reservatorio:");
            client.print (e);
            client.println ("<br/>");

            client.println ("<h2>Local da Central<h2>");

            client.println ("<h3> <h3>");
            client.println ("Alarme:");
            client.print (iv);
            
            break;
          }
       if (c == '\n')
       {
        BlankLine = true;
       }
       else if (c != '\r')
       {
       BlankLine = false;
       }
       }
    }
    delay (10); //Tempo para o cliente receber os dados
    client.stop(); //Encerra a conexão
  }
}
