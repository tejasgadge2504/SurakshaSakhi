#include <Wire.h>              // I2C for GY-521 (MPU6050)
#include <Adafruit_MPU6050.h>  // Accelerometer library
#include <Adafruit_Sensor.h>
#include <TinyGPS++.h>         // GPS library
#include <WiFi.h>              // WiFi for ESP32
#include <HTTPClient.h>        // HTTP requests

// GPS Setup
TinyGPSPlus gps;
HardwareSerial gpsSerial(2);  // Use UART2 for GPS

// Accelerometer Setup
Adafruit_MPU6050 mpu;

// Button Pin
#define BUTTON_PIN 12

// WiFi credentials
const char* ssid = "HackCoder";
const char* password = "Aimers@2023";



// Server URL
String serverURL = "http://192.168.0.102:5000/update_location";

// Function to setup the GPS
void setupGPS() {
  gpsSerial.begin(9600, SERIAL_8N1, 16, 17); // RX = GPIO16, TX = GPIO17
}

// Function to setup the MPU6050
void setupMPU() {
  if (!mpu.begin()) {
    Serial.println("Could not find a valid MPU6050 sensor, check wiring!");
    while (1) {}
  }
  Serial.println("MPU6050 Found!");
}

// Send GPS and Accelerometer data to the server
void sendLocationToServer(float latitude, float longitude, float accelX, float accelY, float accelZ) {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    
    // JSON format
    String jsonPayload = "{\"latitude\":" + String(latitude, 6) +
                        ",\"longitude\":" + String(longitude, 6) +
                        ",\"accelX\":" + String(accelX) +
                        ",\"accelY\":" + String(accelY) +
                        ",\"accelZ\":" + String(accelZ) + "}";

    // Debugging - Print the data being sent
    Serial.println("Sending POST request to the server:");
    Serial.println(jsonPayload);

    // Send the POST request
    http.begin(serverURL);
    http.addHeader("Content-Type", "application/json");
    int httpResponseCode = http.POST(jsonPayload);

    // Check the response from the server
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);

    if (httpResponseCode > 0) {
      String response = http.getString();
      Serial.println("Server Response: " + response);
    } else {
      Serial.println("Error on sending POST: " + String(httpResponseCode));
    }

    http.end();
  } else {
    Serial.println("WiFi Disconnected");
  }
}

void setup() {
  Serial.begin(115200);

  // WiFi connection
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi!");

  setupGPS();
  setupMPU();

  // Setup Button
  pinMode(BUTTON_PIN, INPUT_PULLUP);  // Button with internal pull-up resistor
}

void loop() {
  // Check if the button is pressed
  if (digitalRead(BUTTON_PIN) == LOW) {
    Serial.println("Button Pressed! Sending alert...");
    
    // Read GPS Data
    while (gpsSerial.available() > 0) {
      gps.encode(gpsSerial.read());
      if (gps.location.isUpdated()) {
        float latitude = gps.location.lat();
        float longitude = gps.location.lng();

        // Read Accelerometer Data
        sensors_event_t a, g, temp;
        mpu.getEvent(&a, &g, &temp);
        
        float accelX = a.acceleration.x;
        float accelY = a.acceleration.y;
        float accelZ = a.acceleration.z;

        // Send GPS and accelerometer data to server
        sendLocationToServer(latitude, longitude, accelX, accelY, accelZ);
      }
    }
    delay(1000);  // Debounce button
  }
}
