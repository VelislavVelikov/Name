#include <SoftwareSerial.h>

#include <SoftwareSerial.h>
#define SIM800_TX_PIN 8
#define SIM800_RX_PIN 7
 
//Create software serial object to communicate with SIM800
SoftwareSerial serialSIM800(SIM800_TX_PIN,SIM800_RX_PIN);
 
void setup() {
  //Begin serial comunication with Arduino and Arduino IDE (Serial Monitor)
  Serial.begin(9600);
  while(!Serial){}
  //Begin serial communication with Arduino and SIM800
  serialSIM800.begin(9600);
  delay(1000);
  Serial.println("Setup Complete!");
  Serial.println("Hello!");
}
 
void loop() {
  if(Serial.available()){
    serialSIM800.write(Serial.read());
    Serial.write(Serial.read());
  }
  if(serialSIM800.available()) 
    Serial.write(serialSIM800.read());
}
