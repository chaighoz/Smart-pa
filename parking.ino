#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "eBipkGWmD66baWvGwpAj1dc6hHN6C4qG";   //token dari akun blynk

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "school";     //ssid wifi yang terhubung
char pass[] = "hakim123";            // password wifi yang terhubung

WidgetLED led1(V1);            // Virtual LED untuk menampilkan status di aplikasi
//WidgetLED led2(V2);

int sensor1 = D4;                   //IR sensor
//int sensor2 = D2;


void setup()
{

  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
 // pinMode(sensor2,INPUT);
  pinMode(sensor1,INPUT);
  while (Blynk.connect() == false) {
  }
  
}

void loop()
{
  int sensorval1 = digitalRead(sensor1);
  //int sensorval2 = digitalRead(sensor2);
  delay(1000);

// LED Nyala, parkir tersedia
  if (sensorval1 == 1)
  {
led1.on();
  }
  


//LED Mati, parkir tidak tersedia
if (sensorval1 == 0)
  {
led1.off();
  }
  

  
  Blynk.run();
}
