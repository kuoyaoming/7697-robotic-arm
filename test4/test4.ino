#include <LWiFi.h>
#include <WiFiClient.h>
#include "MCS.h"


// Assign AP ssid / password here
#define _SSID "CAVEDU_02"
#define _KEY  "12345678"

// Assign device id / key of your test device
MCSDevice mcs("DcrUWbou", "ZhhM0ZubgvAotXxw");

// Assign channel id 
// The test device should have 2 channel
// the first channel should be "Controller" - "On/Off"
// the secord channel should be "Display" - "On/Off"
MCSControllerPWM servo_degree("sd");
//MCSDisplayOnOff    remote("your_channel2_id");

//#define LED_PIN 7

//Servo setting
#include <Servo.h>
Servo myservo7;
int i;
void setup() {
  // setup Serial output at 9600
  Serial.begin(9600);

  // setup LED/Button pin
  myservo7.attach(7);

  // setup Wifi connection
  while(WL_CONNECTED != WiFi.status())
  {
    Serial.print("WiFi.begin(");
    Serial.print(_SSID);
    Serial.print(",");
    Serial.print(_KEY);
    Serial.println(")...");
    WiFi.begin(_SSID, _KEY);
  }
  Serial.println("WiFi connected !!");

  // setup MCS connection
  mcs.addChannel(servo_degree);
  while(!mcs.connected())
  {
    Serial.println("MCS.connect()...");
    mcs.connect();
  }
  Serial.println("MCS connected !!");

  
}

void loop() {
  // call process() to allow background processing, add timeout to avoid high cpu usage
  Serial.print("process(");
  Serial.print(millis());
  Serial.println(")");
  mcs.process(100);
  
  // updated flag will be cleared in process(), user must check it after process() call.
  if(servo_degree.updated())
  {
    Serial.print("servo_degree updated, new value = ");
    Serial.println(servo_degree.value().mDutyCycle);
    i=servo_degree.value().mDutyCycle;
    myservo7.write(i);
  }
  
  // check if need to re-connect
  while(!mcs.connected())
  {
    Serial.println("re-connect to MCS...");
    mcs.connect();
    if(mcs.connected())
      Serial.println("MCS connected !!");
  }
}
