
//Joystick initialization
#include "ibus.h"
#define UPDATE_INTERVAL 10 // Data send update[ms]
#define ANALOG_INPUTS_COUNT 1 // Analog channels (0-1023)
byte analogPins[] = {A0}; //ESP8266 pinout
#define DIGITAL_INPUTS_COUNT 1 // Digital channels (LOW=0, HIGH=1023)
byte digitalPins[] = {5}; //ESP8266 pinout
#define ANALOG_REFERENCE DEFAULT // ESP8266 3.3V = DEFAULT
#define BAUD_RATE 115200
#define NUM_CHANNELS ( (ANALOG_INPUTS_COUNT) + (DIGITAL_INPUTS_COUNT) )
int digital_read;
IBus ibus(NUM_CHANNELS);
//============================================================================


//LEDs initialization
int g1 = 12;
int g2 = 14;
int yel1 = 2;
int y2 = 4;
int r1 = 5;
int r2 = 16;
int potPin = A0;
int ledPins[] = {g1, g2, yel1, y2, r1, r2};
int potValue;
int potMapped;
int ledStatus;
String alreadyRunA;
String alreadyRunD;
//============================================================================


//Web initialization
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include "index.h" //HTML
const char* ssid = "ISKONOVAC-093988"; //WiFi ssid
const char* password = "INNBOX3012504011"; //WiFi pass
ESP8266WebServer server(80); //Start Server on port 80
//==========================================================================







//============================================================
//                      Functions
//============================================================

//Show HTML web page
void handleRoot() {
  String s = MAIN_page; //Read HTML contents
  server.send(200, "text/html", s); //Send web page
}

//Error 404
void handleNotFound() {
  server.send(404, "text/plain", "Not found");
}


//Web switch handler
void handleSwitch() {

  String ledStatusParam = server.arg("ledStatus");


  if (ledStatusParam == "OFF")
  {
    ledStatus = 1;
    alreadyRunD = "true";
  }

  if (ledStatusParam == "ON")
  {
    ledStatus = 2;
    alreadyRunA = "true";
  }

  switch (ledStatus) {
    case 1:
      lediceAnalog();
      joystickAnalog();
      break;

    case 2:
      lediceDigital();
      joystickDigital();
      break;
  }

}

//joyA
void joystickAnalog() {

  int i;
  unsigned long time = millis();

  ibus.begin();

  // read analog pins - one per channel
  for (i = 0; i < ANALOG_INPUTS_COUNT; i++)
    ibus.write(potMapped);


  // read digital pins - one per channel
  for (i = 0; i < DIGITAL_INPUTS_COUNT; i++)
    ibus.write(digitalRead(digitalPins[i]) == HIGH ? 1023 : 0);

  ibus.end();

  time = millis() - time; // time elapsed in reading the inputs
  if (time < UPDATE_INTERVAL)
    // sleep till it is time for the next update
    delay(UPDATE_INTERVAL  - time);
}

//joyD
void joystickDigital() {

  int i;
  unsigned long time = millis();

  ibus.begin();

  // read analog pins - one per channel
  for (i = 0; i < ANALOG_INPUTS_COUNT; i++)


    digital_read = 0;
  if (potValue > 220) {
    digital_read = 1840;
  }
  ibus.write(digital_read);


  // read digital pins - one per channel
  for (i = 0; i < DIGITAL_INPUTS_COUNT; i++)
    ibus.write(digitalRead(digitalPins[i]) == HIGH ? 1023 : 0);

  ibus.end();

  time = millis() - time; // time elapsed in reading the inputs
  if (time < UPDATE_INTERVAL)
    // sleep till it is time for the next update
    delay(UPDATE_INTERVAL  - time);
}

//ledA
void lediceAnalog () {

  if (potValue < 60) {
    analogWrite (g1, 0);
    analogWrite (g2, 0);
    analogWrite (yel1, 0);
    analogWrite (y2, 0);
    analogWrite (r1, 0);
    analogWrite (r2, 0);
  }
  else if (potValue < 110) {
    analogWrite (g1, 255);
    analogWrite (g2, 0);
    analogWrite (yel1, 0);
    analogWrite (y2, 0);
    analogWrite (r1, 0);
    analogWrite (r2, 0);
  }
  else if (potValue < 160) {
    analogWrite (g1, 255);
    analogWrite (g2, 255);
    analogWrite (yel1, 0);
    analogWrite (y2, 0);
    analogWrite (r1, 0);
    analogWrite (r2, 0);
  }
  else if (potValue < 210) {
    analogWrite (g1, 255);
    analogWrite (g2, 255);
    analogWrite (yel1, 100);
    analogWrite (y2, 0);
    analogWrite (r1, 0);
    analogWrite (r2, 0);
  }
  else if (potValue < 260) {
    analogWrite (g1, 255);
    analogWrite (g2, 255);
    analogWrite (yel1, 100);
    analogWrite (y2, 100);
    analogWrite (r1, 0);
    analogWrite (r2, 0);
  }
  else if (potValue < 310) {
    analogWrite (g1, 255);
    analogWrite (g2, 255);
    analogWrite (yel1, 100);
    analogWrite (y2, 100);
    analogWrite (r1, 100);
    analogWrite (r2, 0);
  }
  else if (potValue < 360) {
    analogWrite (g1, 255);
    analogWrite (g2, 255);
    analogWrite (yel1, 100);
    analogWrite (y2, 100);
    analogWrite (r1, 100);
    analogWrite (r2, 100);
  }

}

//ledD
void lediceDigital() {

  if (potValue > 220) {

    analogWrite (g1, 255);
    analogWrite (g2, 255);
    analogWrite (yel1, 100);
    analogWrite (y2, 100);
    analogWrite (r1, 100);
    analogWrite (r2, 100);
    delay (50);
  }

  else {
    analogWrite (g1, 0);
    analogWrite (g2, 0);
    analogWrite (yel1, 0);
    analogWrite (y2, 0);
    analogWrite (r1, 0);
    analogWrite (r2, 0);
  }
  delay (50);
}

//introA
void introAnalog () {

  for (int i = 0; i < 6; i++) {
    digitalWrite (ledPins[i], HIGH);
    delay (105);
  }

  for (int i = 6; i >= 0; i--) {
    digitalWrite (ledPins[i], LOW);
    delay (105);
  }
}

//introD
void introDigital () {

  for (int i = 0; i < 250; i = i + 2) {

    analogWrite (g1, i);
    analogWrite (g2, i);
    analogWrite (yel1, i);
    analogWrite (y2, i);
    analogWrite (r1, i);
    analogWrite (r2, i);

  }

  for (int i = 250; i >= 0; i = i - 2) {

    analogWrite (g1, i);
    analogWrite (g2, i);
    analogWrite (yel1, i);
    analogWrite (y2, i);
    analogWrite (r1, i);
    analogWrite (r2, i);


  }

}
void introOneTime () {

  if (ledStatus == 1) {
    if (alreadyRunA == "true") {
      introAnalog();
      alreadyRunA = "false";
    }
  }

  if (ledStatus == 2) {
    if (alreadyRunD == "true") {
      introDigital();
      alreadyRunD = "false";
    }
  }
}


void handleAnalogValue() {

  if (ledStatus == 1) {

    String strAnalogValue = String (potMapped);
    server.send(200, "text/plane", strAnalogValue);
  }
}

void handleDigitalValue() {

  if (ledStatus == 2) {

    int digitalValue = 0;
    if (potValue > 220) {
      digitalValue = 1840;
    }
    String strDigitalValue = String (digitalValue);
    server.send(200, "text/plane", strDigitalValue);
  }
}

int handlePot () {
 
   potMapped = map (potValue, 50, 380, 0, 1840);
   
  if (potValue < 50) {
    potMapped = 0;
  }
  else{
    potMapped = map (potValue, 50, 380, 0, 1840);
    }
  if (potValue > 355) {
    potMapped = 1840;
  }
  return potMapped;
}


//==============================================================
//                  SETUP
//==============================================================
void setup(void) {

  Serial.begin(115200);

  analogReference(ANALOG_REFERENCE); // use the defined ADC reference voltage source (DEFAULT)

  //Setting LEDs as output
  for (int i = 0; i < sizeof (ledPins[i]); i++) {
    pinMode (ledPins[i], OUTPUT);
  }

  pinMode (potPin, INPUT);

  //Setting LEDs to LOW
  for (int i = 0; i < 6; i++) {
    analogWrite (ledPins[i], 0);
  }
  //Setting default mode to analog
  ledStatus = 1;
  alreadyRunA = "true";

  WiFi.begin(ssid, password);     //Connect to your WiFi router
  Serial.println("");


  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  //If connection successful show IP address in serial monitor
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  //IP address assigned to your ESP

  server.on("/", handleRoot);      //On root adress show web page
  server.on("/toggleLED", handleSwitch); //Web switch response
  server.on ("/readAnalogValue", handleAnalogValue); // Send analog data
  server.on ("/readDigitalValue", handleDigitalValue); // Send digital data
  server.onNotFound(handleNotFound); //Error 404


  server.begin(); //Start server
  Serial.println("HTTP server started");

}




//==============================================================
//                     LOOP
//==============================================================

void loop(void) {

  potValue = analogRead (potPin);
  handlePot();
  introOneTime ();
  handleSwitch();
  server.handleClient();  //Handle client requests
}
