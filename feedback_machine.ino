#ifdef ESP32
  #include <WiFi.h>
  #include <HTTPClient.h>
#else
  #include <ESP8266WiFi.h>
  #include <ESP8266HTTPClient.h>
  #include <WiFiClient.h>
#endif

#include <Wire.h>
#include <Adafruit_Sensor.h>
const char* ssid     = "Nave19k";
const char* password = "kudelli1234";

const char* serverName = "http://technicalhub.io:5002/iot/feedback/food/post-esp-data.php";
//http://technicalhub.io:5002/iot/feedback/food/
//const char* serverName = "http://192.168.43.112/feedback/food/post-esp-data.php";
String apiKeyValue = "tPmAT5Ab3j7F9";

const int b1Pin = D1;
const int b2Pin = D2;
const int b3Pin = D3;
const int b4Pin = D5;
const int ledPin = D0;

int excellent = 0; 
int good      = 0;
int avarage   = 0;
int bad       = 0 ;
void setup() {
  Serial.begin(115200);
  
  pinMode(ledPin, OUTPUT);
  pinMode(b1Pin, INPUT);
  pinMode(b2Pin, INPUT);
  pinMode(b3Pin, INPUT);
  pinMode(b4Pin, INPUT);
  digitalWrite(ledPin, HIGH);
  delay(500);
  digitalWrite(ledPin, LOW);
  delay(500);
  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  digitalWrite(ledPin, HIGH);
  delay(500);
  digitalWrite(ledPin, LOW);
  delay(500);
  while(WiFi.status() != WL_CONNECTED) { 
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  digitalWrite(ledPin, HIGH);
  delay(200);
  digitalWrite(ledPin, LOW);
  delay(200);
  Serial.println(WiFi.localIP());
  
}
void loop() {
  
   
  if(WiFi.status()== WL_CONNECTED){
    HTTPClient http;
    http.begin(serverName);
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");

 excellent = digitalRead(b1Pin);  good = digitalRead(b2Pin);
 avarage = digitalRead(b3Pin);     bad = digitalRead(b4Pin);
  
  if (excellent == HIGH) {   digitalWrite(ledPin, HIGH);
        Serial.println("excellent"); 
    HTTPClient http;
    http.begin(serverName);
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    String httpRequestData = "api_key=" + apiKeyValue  +
     "&field=" + String("Food") +
     "&value=" + String("1") +
     "&value1=" + String("0")+ 
     "&value2=" + String("0") +
     "&value3=" + String("0") + "";
    Serial.print("httpRequestData: ");
    Serial.println(httpRequestData);
    int httpResponseCode = http.POST(httpRequestData);
    if (httpResponseCode>0) { Serial.print("HTTP Response code: ");
                             Serial.println(httpResponseCode);
    }
    else { Serial.print("Error code: ");  Serial.println(httpResponseCode); }
      http.end();
    }
    else {  digitalWrite(ledPin, LOW);  }
        
   if (good == HIGH) {   digitalWrite(ledPin, HIGH);
       Serial.println("good");
     HTTPClient http;
    http.begin(serverName);
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    String httpRequestData = "api_key=" + apiKeyValue  +
     "&field=" + String("Food") +
     "&value=" + String("0") +
     "&value1=" + String("1")+ 
     "&value2=" + String("0") +
     "&value3=" + String("0") + "";   Serial.print("httpRequestData: ");
    Serial.println(httpRequestData);
    int httpResponseCode = http.POST(httpRequestData);
    if (httpResponseCode>0) { Serial.print("HTTP Response code: ");
                             Serial.println(httpResponseCode);
    }
    else { Serial.print("Error code: ");  Serial.println(httpResponseCode); }
      http.end();
      }
    else {  digitalWrite(ledPin, LOW);  }
    
    
    if (avarage == HIGH) {   digitalWrite(ledPin, HIGH);
        Serial.println("avarage");
            HTTPClient http;
    http.begin(serverName);
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    String httpRequestData = "api_key=" + apiKeyValue  +
     "&field=" + String("Food") +
     "&value=" + String("0") +
     "&value1=" + String("0")+ 
     "&value2=" + String("1") +
     "&value3=" + String("0") + "";
        Serial.print("httpRequestData: ");
    Serial.println(httpRequestData);
    int httpResponseCode = http.POST(httpRequestData);
    if (httpResponseCode>0) { Serial.print("HTTP Response code: ");
                             Serial.println(httpResponseCode);
    }
    else { Serial.print("Error code: ");  Serial.println(httpResponseCode); }
      http.end();
      }
    else {  digitalWrite(ledPin, LOW);  }
    
    if (bad == HIGH) {   digitalWrite(ledPin, HIGH);
       Serial.println("bad"); 
           HTTPClient http;
    http.begin(serverName);
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    String httpRequestData = "api_key=" + apiKeyValue  +
     "&field=" + String("Food") +
     "&value=" + String("0") +
     "&value1=" + String("0")+ 
     "&value2=" + String("0") +
     "&value3=" + String("1") + "";
        Serial.print("httpRequestData: ");
    Serial.println(httpRequestData);
    int httpResponseCode = http.POST(httpRequestData);
    if (httpResponseCode>0) { Serial.print("HTTP Response code: ");
                             Serial.println(httpResponseCode);
    }
    else { Serial.print("Error code: ");  Serial.println(httpResponseCode); }
      http.end();
      }
    else {  digitalWrite(ledPin, LOW);  }
    

  }
  else {   Serial.println("WiFi Disconnected");
  digitalWrite(ledPin, HIGH);
  delay(200);
  digitalWrite(ledPin, LOW);
  delay(200);}
}
