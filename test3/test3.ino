#include <Servo.h>
#include <LTask.h>
#include <LWiFi.h>
#include <LWiFiClient.h>

#define WIFI_AP "CAVEDU_02"
#define WIFI_PASSWORD "12345678"
#define WIFI_AUTH LWIFI_WPA  // choose from LWIFI_OPEN, LWIFI_WPA, or LWIFI_WEP.
#define SITE_URL "api.mediatek.com"

LWiFiClient content;

Servo myservo7;
Servo myservo8;
Servo myservo9;
Servo myservo10;

int a=0;
void setup()
{
  LTask.begin();
  LWiFi.begin();
  Serial.begin(9600);
  Serial.println("Connecting to AP");
  while (0 == LWiFi.connect(WIFI_AP, LWiFiLoginInfo(WIFI_AUTH, WIFI_PASSWORD)))
  {
    Serial.println("Connecting to AP...");
    delay(1000);
  }

  // keep retrying until connected to website
  Serial.println("Connecting to WebSite");
  while (0 == content.connect(SITE_URL, 80))
  {
    Serial.println("Re-Connecting to WebSite");
    delay(1000);
  }

  // send HTTP request, ends with 2 CR/LF
  Serial.println("send HTTP GET request");

  // ---- copied form MCS Arduino code hint ----
  content.println("POST /mcs/v2/devices/DcrUWbou/datapoints.csv HTTP/1.1");
  String data = "servo_degree,,123,456";
  int dataLength = data.length();
  content.println("Host: api.mediatek.com");
  content.println("deviceKey: ZhhM0ZubgvAotXxw");
  content.print("Content-Length: ");
  content.println(dataLength);
  content.println("Content-Type: text/csv");
  content.println("Connection: close");
  content.println();
  content.println(data);
// ---- ----

  // waiting for server response
  Serial.println("waiting HTTP response:");
  while (!content.available())
  {
    delay(100);
  }
  
  myservo7.attach(7);
  myservo8.attach(8);
  myservo9.attach(9);
  myservo10.attach(10);
     
  myservo7.writeMicroseconds(90);
  myservo8.writeMicroseconds(90);
  myservo9.writeMicroseconds(90);
  myservo10.writeMicroseconds(90);
}

void loop()
{
  while (Serial.available()>0)
  {
    a=Serial.read();
    
    Serial.println(a);
    myservo7.writeMicroseconds(a);
    myservo8.writeMicroseconds(a);
    myservo9.writeMicroseconds(a);
    myservo10.writeMicroseconds(a);
    delay(50);   
  }
  

}
