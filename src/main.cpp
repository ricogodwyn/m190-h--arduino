#include <SoftwareSerial.h>
#include <Arduino.h>
#include <Wire.h>

SoftwareSerial mySerial(10, 9); // RX, TX

void setup()
{
  Serial.begin(9600);   // Initialize serial communication for debugging
  mySerial.begin(9600); // Initialize software serial for AT commands
  mySerial.println("AT+");
  // mySerial.println("AT+JOIN=01");
}

void loop()
{
  // readButton();
  // Send AT command to the module
  if (mySerial.available())

  {
    // Read incoming AT command response
    String response = mySerial.readStringUntil('\n');
    Serial.println(response); // Print response to serial monitor

    // Process the response as needed (e.g., extract data, send further commands)
  }

  // Check if there is any input from the serial monitor
  if (Serial.available())
  {
    // Read the input from the serial monitor
    String command = Serial.readStringUntil('\n');
    command.trim(); // Remove leading and trailing whitespaces

    // Send the command to the module
    mySerial.println(command);
    Serial.println("Sent command: " + command);
  }

  delay(1000); // Wait for response (adjust delay as required)
}
// AT+SEND=1,5,010203
// aGVsbG8=
// at+join=01