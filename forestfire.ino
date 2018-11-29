#include <SoftwareSerial.h>

#define RX 0
#define TX 1

String AP = "OnePlus 6 v"; 
String PASS = "12345678"; 

String API = "722Z0KZJON5VIBX2";
String HOST = "api.thingspeak.com";
String PORT = "80";
String field1 = "field1";
String field2 = "field2";
String field3 = "field3";

int countTrueCommand;
int countTimeCommand; 
boolean found = false; 
int flameSensor = 0;
int temperature = 0;
int gasSensor = 0;

SoftwareSerial esp8266(RX,TX); 
 
  
void setup() {
  Serial.begin(9600);
  esp8266.begin(115200);
  sendCommand("AT",5,"OK");
  sendCommand("AT+CWMODE=1",5,"OK");
  sendCommand("AT+CWJAP=\""+ AP +"\",\""+ PASS +"\"",20,"OK");
}

void loop() {
 flameSensor = getSensorData();
 temperature = getTemperature();
 gasSensor = getGas();
 String getData = "GET /update?api_key="+ API +"&"+ field1 +"="+String(flameSensor);
 String getData1 = "GET /update?api_key="+ API +"&"+ field2 +"="+String(temperature);
 String getData2 = "GET /update?api_key="+ API +"&"+ field3 +"="+String(gasSensor);
sendCommand("AT+CIPMUX=1",5,"OK");
 sendCommand("AT+CIPSTART=0,\"TCP\",\""+ HOST +"\","+ PORT,15,"OK");
 sendCommand("AT+CIPSEND=0," +String(getData.length()+4),4,">");
 esp8266.println(getData);delay(1500);countTrueCommand++;
 sendCommand("AT+CIPCLOSE=0",5,"OK");

sendCommand("AT+CIPMUX=1",5,"OK");
 sendCommand("AT+CIPSTART=0,\"TCP\",\""+ HOST +"\","+ PORT,15,"OK");
 sendCommand("AT+CIPSEND=0," +String(getData1.length()+4),4,">");
 esp8266.println(getData);delay(1500);countTrueCommand++;
 sendCommand("AT+CIPCLOSE=0",5,"OK");

sendCommand("AT+CIPMUX=1",5,"OK");
 sendCommand("AT+CIPSTART=0,\"TCP\",\""+ HOST +"\","+ PORT,15,"OK");
 sendCommand("AT+CIPSEND=0," +String(getData2.length()+4),4,">");
 esp8266.println(getData);delay(1500);countTrueCommand++;
 sendCommand("AT+CIPCLOSE=0",5,"OK");
 
}

int getSensorData(){
  return digitalRead(4);
}

float getTemperature(){
  int temp = analogRead(A0);
  return temp/1023.0*5;
}

int getGas(){
  int gas = analogRead(A1);
  if(gas<290)return 0;
  return 1;
}

void sendCommand(String command, int maxTime, char readReplay[]) {
  Serial.print(countTrueCommand);
  Serial.print(". at command => ");
  Serial.print(command);
  Serial.print(" ");
  while(countTimeCommand < (maxTime*1))
  {
    Serial.write(command);
    esp8266.write(command);//at+cipsend
    if(esp8266.find(readReplay))//ok
    {
      found = true;
      break;
    }

    countTimeCommand++;
  }
  
  if(found == true)
  {
    Serial.println("YES");
    countTrueCommand++;
    countTimeCommand = 0;
  }
  
  if(found == false)
  {
    Serial.println("Fail");
    countTrueCommand = 0;
    countTimeCommand = 0;
  }
  
  found = false;
 }
