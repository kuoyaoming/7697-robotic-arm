/*
 * Generated using BlocklyDuino:
 *
 * https://github.com/MediaTek-Labs/BlocklyDuino-for-LinkIt
 *
 * Date: Fri, 25 Aug 2017 09:17:04 GMT
 */

#include <LWiFi.h>
#include "MCS.h"

#include <Servo.h>

char _lwifi_ssid[] = "CAVEDU_02";
char _lwifi_pass[] = "12345678";
MCSDevice mcs("DcrUWbou", "ZhhM0ZubgvAotXxw");

MCSControllerInteger a1("a1");
MCSControllerInteger a2("a2");
MCSControllerInteger a3("a3");
MCSControllerInteger a4("a4");
Servo __myservo7;
Servo __myservo8;
Servo __myservo9;
Servo __myservo10;

void setup()
{
  mcs.addChannel(a1);
  mcs.addChannel(a2);
  mcs.addChannel(a3);
  mcs.addChannel(a4);
  __myservo7.attach(7,500,2400);
  __myservo8.attach(8,500,2400);
  __myservo9.attach(9,500,2400);
  __myservo10.attach(10,500,2400);
  while (WiFi.begin(_lwifi_ssid, _lwifi_pass) != WL_CONNECTED) { delay(1000); }
  while(!mcs.connected()) { mcs.connect(); }
  Serial.begin(9600);
}


void loop()
{
  while (!mcs.connected()) {
    mcs.connect();
    if (mcs.connected()) { Serial.println("MCS Reconnected."); }
  }
  mcs.process(100);
  __myservo7.write(a1.value());
  __myservo8.write(a2.value());
  __myservo9.write(a3.value());
  __myservo10.write(a4.value());
  delay(500);
}
