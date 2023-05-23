#include <WiFi.h>
#include <WebServer.h>
#define RX2 16
#define TX2 17


const char* ssid = "ESP32";
const char* password = "1234";


IPAddress local_ip(192,168,1,1);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);

WebServer server(80);

uint8_t LED1pin = 26;
bool LED1status = LOW;
unsigned long ledOnTime = 0;

void setup() {
  Serial.begin(115200);
  pinMode(LED1pin, OUTPUT);

  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(local_ip, gateway, subnet);
  delay(100);
  
  server.on("/", handle_OnConnect);
  server.on("/led1on", handle_led1on);
  server.on("/led1off", handle_led1off);
  server.onNotFound(handle_NotFound);
  
  server.begin();
  Serial.println("HTTP server started");
  Serial2.begin(9600, SERIAL_8N1, RX2, TX2);

}
void loop() {
  server.handleClient();
  if(LED1status)
  {digitalWrite(LED1pin, HIGH);}
  else
  {digitalWrite(LED1pin, LOW);}

}

void handle_OnConnect() {
  LED1status = LOW;

  Serial.println("GPIO26 Status: OFF");
  server.send(200, "text/html", SendHTML(LED1status)); 
}

void handle_led1on() {
  LED1status = HIGH;
  ledOnTime = millis();
  Serial.println("1");
  Serial2.println("1");
  //digitalWrite(LED1pin, HIGH);
  //delay(3000);
  //digitalWrite(LED1pin, LOW);
  LED1status = LOW;
  Serial.println("GPIO26 Status: ON");
  server.send(200, "text/html", SendHTML(false)); 
}

void handle_led1off() {
  LED1status = LOW;
  Serial.println("GPIO26 Status: OFF");
  server.send(200, "text/html", SendHTML(false)); 
}

void handle_NotFound(){
  server.send(404, "text/plain", "Not found");
}


String SendHTML(uint8_t led1stat){
  String ptr = "<!DOCTYPE html> <html>\n";
  ptr +="<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  ptr +="<title>LINKA</title>\n";
  ptr +="<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\n";
  ptr +="body{margin-top: 50px;} h1 {color: #444444;margin: 50px auto 30px;} h3 {color: #444444;margin-bottom: 50px;}\n";
  ptr +=".button {display: block;width: 80px;background-color: #36454F;border: none;color: white;padding: 13px 30px;text-decoration: none;font-size: 25px;margin: 0px auto 35px;cursor: pointer;border-radius: 4px;}\n";
  ptr +=".button-on {background-color: #36454F;}\n";
  ptr +=".button-on:active {background-color: #B2BEB5;}\n";
  ptr +=".button-off {background-color: #34495e;}\n";
  ptr +=".button-off:active {background-color: #2c3e50;}\n";
  ptr +="p {font-size: 14px;color: #888;margin-bottom: 10px;}\n";
  ptr +="</style>\n";
  ptr +="</head>\n";
  ptr +="<body>\n";
  ptr +="<h1>Ahoj</h1>\n";
  ptr +="<h3>Write me something</h3>\n";
  ptr +="<form>\n";
  ptr +="	<input type=\"text\" name=\"input1\">\n";
  ptr +="</form>\n";
  ptr +="<br>\n";

   if(led1stat)
  {ptr +="<a class=\"button button-off\" href=\"/led1off\">OFF</a>\n";}
  else
  {ptr +="<a class=\"button button-on\" href=\"/led1on\">Submit</a>\n";}

  ptr +="</body>\n";
  ptr +="</html>\n";
  return ptr;
}