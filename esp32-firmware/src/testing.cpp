// // To interface a **ZD10-100 Thin Film Pressure Sensor** with an ESP32, you don't need a specific library since it provides an analog output based on the pressure applied. The ESP32's built-in ADC (Analog-to-Digital Converter) is sufficient to read the sensor's values.

// // ### **Wiring**
// // 1. Connect the **VCC** pin of the ZD10-100 to the **3.3V** pin of the ESP32.
// // 2. Connect the **GND** pin of the ZD10-100 to the **GND** pin of the ESP32.
// // 3. Connect the **Signal** pin of the ZD10-100 to one of the ESP32's **ADC** pins (e.g., GPIO34).

// // ### **Code Example**

// // ```cpp
// // Define the ADC pin
// const int sensorPin = 34; // GPIO34 (ADC1)

// // Calibration variables
// const float voltageReference = 3.3; // ESP32's reference voltage in volts
// const int adcResolution = 4095;     // 12-bit ADC resolution (0-4095)
// const float sensorMaxPressure = 100.0; // Maximum pressure in units (adjust based on datasheet)
// const float sensorMinVoltage = 0.5;    // Minimum voltage at no pressure (datasheet value)
// const float sensorMaxVoltage = 4.5;    // Maximum voltage at full pressure (datasheet value)

// void setup() {
//   Serial.begin(115200);
//   delay(1000); // Give time for serial monitor to initialize
// }

// void loop() {
//   // Read the raw ADC value
//   int rawValue = analogRead(sensorPin);

//   // Convert raw ADC value to voltage
//   float voltage = (rawValue * voltageReference) / adcResolution;

//   // Map voltage to pressure
//   float pressure = mapPressure(voltage);

//   // Print values to Serial Monitor
//   Serial.print("Raw ADC Value: ");
//   Serial.print(rawValue);
//   Serial.print("\tVoltage: ");
//   Serial.print(voltage, 2);
//   Serial.print("V\tPressure: ");
//   Serial.print(pressure, 2);
//   Serial.println(" units");

//   delay(500); // Adjust delay as needed
// }

// // Function to map voltage to pressure
// float mapPressure(float voltage) {
//   if (voltage <= sensorMinVoltage) return 0.0;
//   if (voltage >= sensorMaxVoltage) return sensorMaxPressure;
//   return (voltage - sensorMinVoltage) * (sensorMaxPressure / (sensorMaxVoltage - sensorMinVoltage));
// }


// // ---

// // ### **Explanation**
// // 1. **`analogRead(sensorPin)`**:
// //    - Reads the sensor's analog signal as a raw ADC value (0-4095 for 12-bit resolution).
// // 2. **Voltage Conversion**:
// //    - Converts the raw ADC value to the actual voltage based on the ESP32's reference voltage.
// // 3. **Pressure Calculation**:
// //    - Maps the voltage to the pressure range based on the sensor's datasheet.

// // ---

// // ### **No Additional Libraries Needed**
// // This code uses the ESP32's built-in `analogRead()` function, which does not require any external libraries. However, ensure you have the **ESP32 board support** installed in your Arduino IDE.

// // ---

// // ### **Notes**
// // - Adjust the `sensorMinVoltage` and `sensorMaxVoltage` values according to the sensor's datasheet to ensure accurate pressure readings.
// // - If you're using other ADC pins, confirm they support ADC functionality, as some GPIO pins on the ESP32 do not.











// const int flexPin = A0; 
// const int ledPin = 23; 

// void setup() { 
//   Serial.begin(9600);
//   pinMode(ledPin,OUTPUT);
// } 

// void loop(){ 
//   int flexValue;
//   flexValue = analogRead(flexPin);
//   Serial.print("sensor: ");
//   Serial.println(flexValue);
 
//   if(flexValue>3600)
//      digitalWrite(ledPin,HIGH);
//   else
//     digitalWrite(ledPin,LOW);
 
//   delay(20);
// } 





// #include <Arduino.h>

// // Pin assignments
// const int flexSensorPin = 32; // GPIO32 (ADC4)(TOUCH9)
// const int ledPin = 15;

// // Threshold to determine when the sensor is bent
// const int flexThreshold = 800; // Adjust based on your sensor and setup

// void setup() {
//   Serial.begin(9600);          // Initialize Serial Monitor for debugging
//   pinMode(ledPin, OUTPUT);     // Set LED pin as output
// }

// void loop() {
//   // Read the flex sensor value
//   int sensorValue = analogRead(flexSensorPin);

//   // Print the sensor value to the Serial Monitor
//   Serial.print("Flex Sensor Value: ");
//   Serial.println(sensorValue);

//   // Check if the flex sensor is bent beyond the threshold
//   if (sensorValue > flexThreshold) {
//     digitalWrite(ledPin, HIGH); // Turn on LED
//   } else {
//     digitalWrite(ledPin, LOW);  // Turn off LED
//   }

//   delay(100); // Add a small delay for stability
// }
