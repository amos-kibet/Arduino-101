// #include <Arduino.h>
// #include <DHT.h>
// #include <Adafruit_Sensor.h>
// // #include <DHT_U.h>


// // Define pin & DHT Type
// #define pin 8
// #define type DHT11



// DHT dht{pin, type};

// void setup() {
//   // Serial.begin(9600);

//   // Initialize the Sensor
//   // dht.begin();
//   // Serial.println();
//   // Serial.println();
//   // Serial.println();
//   // Serial.println();
//   // Serial.println(F("-------------------Testing DHT11 Sensor!--------------------"));

//   // // Miscellaneous info about the sensor
//   // sensor_t sensor;
//   // Serial.print(F("Sensor Type: "));
//   // Serial.println(sensor.name);
//   // Serial.print(F("Driver Version: "));
//   // Serial.println(sensor.version);
//   // Serial.print(F("Unique ID: "));
//   // Serial.println(sensor.sensor_id);
//   // Serial.print(F("Max Value: "));
//   // Serial.print(sensor.max_value);
//   // Serial.println(F("%"));
//   // Serial.print(F("Min Value: "));
//   // Serial.print(sensor.min_delay);
//   // Serial.println(F("%"));
//   // Serial.print(F("Resolution: "));
//   // Serial.print(sensor.resolution);
//   // Serial.println(F("%"));
// }

// void loop() {
//   // delay(2000);
//   // float h = dht.readHumidity();
//   // float t = dht.readTemperature();
//   // // Read temp in degrees Fahrenheit
//   // float f = dht.readTemperature(true);

//   // // Check if any readings failed & exit
//   // if (isnan(h) || isnan(t) || isnan(f)) {
//   //   Serial.println("Failed to read from DHT Sensor!");
//   //   return;
//   // }

//   // Print results on serial monitor
//   // Serial.println(F("------------------------------------"));
//   // Serial.print(F("Humidity: "));
//   // Serial.println(h);
//   // Serial.println(F("------------------------------------"));
//   // Serial.print(F("Temp in Celcius: "));
//   // Serial.println(t);
//   // Serial.print(F("Temp in Fahrenheit: "));
//   // Serial.println(f);

// }



// #include "DHT.h"
// #include <WiFiEspClient.h>
// #include <WiFiEsp.h>
// #include <WiFiEspUdp.h>
// #include "SoftwareSerial.h"
// #include <ThingsBoard.h>
// /*
// Libraries to download
//     PubSubClient => http://pubsubclient.knolleary.net/
//     WiFiWsp => https://github.com/bportaluri/WiFiEsp
//     Adafruit Unified Sensor => https://github.com/adafruit/Adafruit_Sensor
//     DHT Sensor => https://github.com/adafruit/DHT-sensor-library
//     Arduino ThingsBoard SDK => https://github.com/thingsboard/ThingsBoard-Arduino-MQTT-SDK
//     ArduinoJSON => https://github.com/bblanchon/ArduinoJson
//     Arduino Http Client => https://github.com/arduino-libraries/ArduinoHttpClient
// */

// #define WIFI_AP "ADANIAN"
// #define WIFI_PASSWORD "!ARL2021@"

// #define TOKEN "YOUR_ACCESS_TOKEN"

// // DHT
// #define DHTPIN 8
// #define DHTTYPE DHT11

// // char thingsboardServer[] = "YOUR_THINGSBOARD_HOST_OR_IP";
// char thingsboardServer[] = "localhost:8080";


// // Initialize the Ethernet client object
// WiFiEspClient espClient;

// // Initialize DHT sensor.
// DHT dht(DHTPIN, DHTTYPE);

// ThingsBoard tb(espClient);

// SoftwareSerial soft(2, 3); // RX, TX

// int status = WL_IDLE_STATUS;
// unsigned long lastSend;

// void setup() {
//   // initialize serial for debugging
//   Serial.begin(9600);
//   dht.begin();
//   InitWiFi();
//   lastSend = 0;
// }

// void loop() {
//   status = WiFi.status();
//   if ( status != WL_CONNECTED) {
//     while ( status != WL_CONNECTED) {
//       Serial.print("Attempting to connect to WPA SSID: ");
//       Serial.println(WIFI_AP);
//       // Connect to WPA/WPA2 network
//       status = WiFi.begin(WIFI_AP, WIFI_PASSWORD);
//       delay(500);
//     }
//     Serial.println("Connected to AP");
//   }

//   if ( !tb.connected() ) {
//     reconnect();
//   }

//   if ( millis() - lastSend > 1000 ) { // Update and send only after 1 seconds
//     getAndSendTemperatureAndHumidityData();
//     lastSend = millis();
//   }

//   tb.loop();
// }

// void getAndSendTemperatureAndHumidityData() {
//   Serial.println("Collecting temperature data.");

//   // Check if any reads failed and exit early (to try again).
//   if (isnan(humidity) || isnan(temperature)) {
//     Serial.println("Failed to read from DHT sensor!");
//     return;
//   }

//   // Reading temperature or humidity takes about 250 milliseconds!
//   float humidity = dht.readHumidity();
//   // Read temperature as Celsius (the default)
//   float temperature = dht.readTemperature();

//   Serial.println("Sending data to ThingsBoard:");
//   Serial.print("Humidity: ");
//   Serial.print(humidity);
//   Serial.print(" %\t");
//   Serial.print("Temperature: ");
//   Serial.print(temperature);
//   Serial.println(" *C ");

//   tb.sendTelemetryFloat("temperature", temperature);
//   tb.sendTelemetryFloat("humidity", humidity);
// }

// void InitWiFi() {
//   // initialize serial for ESP module
//   soft.begin(9600);
//   // initialize ESP module
//   WiFi.init(&soft);
//   // check for the presence of the shield
//   if (WiFi.status() == WL_NO_SHIELD) {
//     Serial.println("WiFi shield not present");
//     // don't continue
//     while (true);
//   }

//   Serial.println("Connecting to AP ...");
//   // attempt to connect to WiFi network
//   while ( status != WL_CONNECTED) {
//     Serial.print("Attempting to connect to WPA SSID: ");
//     Serial.println(WIFI_AP);
//     // Connect to WPA/WPA2 network
//     status = WiFi.begin(WIFI_AP, WIFI_PASSWORD);
//     delay(500);
//   }
//   Serial.println("Connected to AP");
// }

// void reconnect() {
//   // Loop until we're reconnected
//   while (!tb.connected()) {
//     Serial.print("Connecting to ThingsBoard node ...");
//     // Attempt to connect (clientId, username, password)
//     if ( tb.connect(thingsboardServer, TOKEN) ) {
//       Serial.println( "[DONE]" );
//     } else {
//       Serial.print( "[FAILED]" );
//       Serial.println( " : retrying in 5 seconds" );
//       // Wait 5 seconds before retrying
//       delay( 5000 );
//     }
//   }
// }
