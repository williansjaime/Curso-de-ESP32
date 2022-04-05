/*
  Aula de conexão com wifi
*/

#include <WiFi.h>
#include <FirebaseESP32.h>

const char* usuario = "COLEGUINHA";

const char* senha = "tecoleguinha09";

#define Host "https://esp32-71964-default-rtdb.firebaseio.com/"
#define Senha_Fire "FTSO5R5GfiLanyzJuz9v0SlA3HDhvWX6DyXoRfAe"

float temperatura;


void setup(){
  Serial.begin(115200);//
  WiFi.begin(usuario, senha);
  
  while(WiFi.status()!= WL_CONNECTED)
  {
    delay(500);
    Serial.println("Conectando ao WIFI....");
  }
  
  Serial.println("Conectado ao Wifi");
  Firebase.begin(Host, Senha_Fire);
}

void loop()
{
  float min = 10;
  float max = 60;
  temperatura = random(100*min, 100*max);
  temperatura = temperatura/100;
  
  Firebase.setFloat("sala25/temperatura", temperatura); //enviar dados para o firebase
  Serial.println(temperatura);
  delay(2000);
    
}
