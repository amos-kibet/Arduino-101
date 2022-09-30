#include <SoftwareSerial.h>

// Create software serial object to communicate with SIM800L
SoftwareSerial mySerial(3, 2); // SIM800L Tx & Rx is connected to Arduino #3 & #2

void setup() {
    // Begin serial communication with Arduino and Arduino IDE
    Serial.begin(9600);

    // Begin serial communication with Arduino and SIM800L
    mySerial.begin(9600);

    Serial.println("Initializing...");
    delay(1000);

    mySerial.println("AT"); // Once the handshake test is successful, it will back to OK
    updateSerial();
    mySerial.println("AT+CSQ"); // Signal quality test, value range is 0-31 , 31 is the best
    updateSerial();
    mySerial.println("AT+CCID"); // Read SIM information to confirm whether the SIM is plugged
    updateSerial();
    mySerial.println("AT+CREG?"); // Check whether it has registered in the network
    updateSerial();
    mySerial.println("ATI"); // Returns the module name & revision
    updateSerial();
    mySerial.println("AT+COPS?"); // Checks which network you are connected to
    updateSerial();
    mySerial.println("AT+CMGF=1"); // Configure TEXT mode
    updateSerial();
    mySerial.println("AT+CMGS=\"+254700323350\"");
    updateSerial();
    mySerial.print("Testing sms");
    updateSerial();
    mySerial.write(26);

}

void loop() {

}

void updateSerial() {
    delay(500);
    while (Serial.available()) {
        mySerial.write(Serial.read()); // Forward what Serial received to Software serial port
    }
    while(mySerial.available()) {
        Serial.write(mySerial.read()); // Forward what Software serial received to Serial port 
    }
}