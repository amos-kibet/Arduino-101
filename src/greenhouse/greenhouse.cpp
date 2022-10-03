// //Libraries included
// #include <LiquidCrystal.h>
// #include <Adafruit_Sensor.h>
// #include <DHT.h>
// #include <DHT_U.h>

// /*
// Devices Used
//     Arduino Uno
//     Alphanumeric LCD (16 X 2)
//     DHT11 Temp & Humidity Sensor
//     SparkFun Soil Moisture Sensor
//     LDR (5Mohms)
//     4 channel SPDT Relay
//     Trimmer Potentiometer (10kohms)
//     Resistor (10kohms, 220ohms)

// */

// //LCD digital pins connection
// LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
// //DHT11 digital pins connection and dht sensor type
// #define DHTPIN 13
// #define DHTTYPE DHT11
// DHT dht(DHTPIN, DHTTYPE);
// //4Relay module digital pins connection
// #define PIN_RELAY_1 7   // the Arduino digital pin 7 - IN1 pin of relay module
// #define PIN_RELAY_2 8   // the Arduino digitall pin 8- IN2 pin of relay module
// #define PIN_RELAY_3 9   // the Arduino digital pin 9 - IN3 pin of relay module
// #define PIN_RELAY_4 10  // the Arduino digital pin 10 - IN4 pin of relay module
// //define soil moisture sensor analog pin A0
// const int Soil_Pin = A0;
// const int Ldr_pin = A1;

// void setup() {
//   Serial.begin(9600);
//   lcd.begin(16, 2);  // initialize the LCD
//   dht.begin();       // initialize the dht sensor
//   // initialize digital pins as an output.
//   pinMode(PIN_RELAY_1, OUTPUT);
//   pinMode(PIN_RELAY_2, OUTPUT);
//   pinMode(PIN_RELAY_3, OUTPUT);
//   pinMode(PIN_RELAY_4, OUTPUT);
//   //ldr read as input
//   pinMode(Ldr_pin, INPUT);
// }

// void loop() {
//   // wait between measurements.(500ms = 0.5 Second)
//   delay(500);
//   float temperature = dht.readTemperature();  // read temperature in Celsius  // temperature in Celsius
//   float humidity = dht.readHumidity(); //read humidity //humidity declaration

//   //ldr read as analog
//   int ldr_Value = analogRead(Ldr_pin); 

//   //soil sensor data in percentage
//   float moisture_percentage;
//   int sensor_analog;
//   sensor_analog = analogRead(Soil_Pin);
//   moisture_percentage = (100 - ((sensor_analog / 1023.00) * 100));
  
// // Plot live data in the Arduino ide serial plotter 
//   Serial.print(moisture_percentage);
//   Serial.print(" "); // a space ' ' or  tab '\t' character is printed between the two values.
//   Serial.print(temperature);
//   Serial.print(" "); // a space ' ' or  tab '\t' character is printed between the two values.
//   Serial.println(humidity); 
//   Serial.print(" "); // a space ' ' or  tab '\t' character is printed between the two values.  
// //  lcd screen display order
//   lcd.setCursor(0, 0);
//   lcd.print("M %");
//   lcd.setCursor(0, 1);  
//   lcd.print(moisture_percentage);
//   lcd.setCursor(6, 0); 
//   lcd.print("Tc");
//   lcd.print((char)223);//shows degrees character  
//   lcd.setCursor(6, 1);
//   lcd.print(temperature);
//   lcd.setCursor(12, 0);
//   lcd.print("H %");
//   lcd.setCursor(12, 1);
//   lcd.print(humidity);
// // Conditional statment to control the relays (Greenhouse systems)

//   if (moisture_percentage < 60.00){
//     digitalWrite(PIN_RELAY_1, LOW);    // turn in1 ON 
//   } else {
//      digitalWrite(PIN_RELAY_1, HIGH);  // turn in1 OFF 
//   } 
//   if (temperature < 20) {
//     digitalWrite(PIN_RELAY_2, LOW);    // turn in2 ON
//   } else {
//      digitalWrite(PIN_RELAY_2, HIGH);  // turn in2 OFF
//   }
//   if (temperature > 30) {
//     digitalWrite(PIN_RELAY_3, LOW);    // turn in3 ON
//   } else { 
//       digitalWrite(PIN_RELAY_3, HIGH); // turn in3 OFF
//   }
//   if (ldr_Value < 300) {
//     digitalWrite(PIN_RELAY_4, LOW);    // turn in4 ON
//   } else {
//     digitalWrite(PIN_RELAY_4, HIGH);   // turn in4 OFF
//   }
 
//   delay(2000);  // wait after loop for 2 Seconds  

// }