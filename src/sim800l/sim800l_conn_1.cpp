// /*
// Checks AT commands for SIM800L
// https://www.youtube.com/channel/UCM9NQ4WcSbzTiCdoyOvzA1g
// */
// #include <SoftwareSerial.h>

// SoftwareSerial Sim800l(10, 11);

// void setup() {
//     Serial.begin(9600);
//     Sim800l.begin(9600);
// }

// void loop() {
//     while(Sim800l.available()) {
//         Serial.write(Sim800l.read());
//     }

//     while(Serial.available()) {
//         Sim800l.write(Serial.read());
//     }
// }