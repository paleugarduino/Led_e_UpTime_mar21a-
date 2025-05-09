#include "arduino_secrets.h"
/* 
  Sketch generated by the Arduino IoT Cloud Thing "Untitled"
  https://create.arduino.cc/cloud/things/7b523f48-1ad7-4a31-8751-1dd156234636 

  Arduino IoT Cloud Variables description

  The following variables are automatically generated and updated when changes are made to the Thing

  int upTime;
  bool ledStatus;

  Variables which are marked as READ/WRITE in the Cloud Thing will also have functions
  which are called when their values are changed from the Dashboard.
  These functions are generated with the Thing and added at the end of this sketch.
*/

#include "thingProperties.h"

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);  
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
 */
  setDebugMessageLevel(4);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
  // Your code here 
 upTime = millis() / 1000;  
  
}

/*
  Since LedStatus is READ_WRITE variable, onLedStatusChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onLedStatusChange()  {
  // Add your code here to act upon LedStatus change
  Serial.println("OnChange");
  Serial.print("LED Status:");
  Serial.print(ledStatus);
  digitalWrite(LED_BUILTIN,ledStatus);
}

