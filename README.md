# 🔐 SurakshaSaKey: Smart Emergency Keychain

SurakshaSaKey is an intelligent IoT-based emergency detection keychain designed to enhance the safety of drivers, passengers, and elderly individuals. Powered by machine learning, real-time sensor analysis, and seamless Bluetooth integration, this device ensures that help is never out of reach during critical situations.

---

## 🚀 Features

- 🎤 **Audio & Motion Monitoring**: Constantly listens for distress sounds and detects abnormal movements like falls or jerks.
- 🧠 **ML-Based Emergency Detection**: Uses a trained model to classify events as normal or dangerous based on sensor data.
- 📡 **Instant Alerts**: Sends live location and emergency message to the user’s trusted contact.
- 📱 **Companion Flutter App**: Allows users to set emergency contacts, customize sensitivity, and monitor keychain status.
- 🔗 **Bluetooth Communication**: Efficient data transfer between the keychain and the mobile app.

---

## 🛠️ Tech Stack

### 🔧 Hardware
- Arduino Nano / ESP32
- Microphone Sensor (Sound Detection)
- Accelerometer / Gyroscope Sensor
- Bluetooth Module (HC-05 / BLE)
- Rechargeable Battery Pack

### 💻 Software
- **Embedded C/C++** for Microcontroller Code
- **Flutter** for Mobile App (Android/iOS)
- **Firebase** for Realtime Database and Notifications
- **TensorFlow Lite** for ML Model Deployment
- **Python** for Model Training and Data Preprocessing

---

## 📱 Flutter App Screens

- 🔒 **Login/Register**
- 👤 **Profile & Emergency Contact Setup**
- 📡 **Live Device Status**
- 📍 **Alert Preview with Location Sharing**

---

## 🧠 Machine Learning Model

- **Input**: Audio intensity + motion sensor data
- **Labels**: `Normal`, `Scream`, `Fall`, `Crash`
- **Model**: Random Forest / Lightweight Neural Net
- **Training Tool**: Python (scikit-learn / TensorFlow)

---

## 🧪 How It Works

1. 📟 Keychain constantly monitors audio and motion signals.
2. 🧠 ML model running on-device or via app classifies the situation.
3. 📲 If an emergency is detected:
   - Location is fetched.
   - Emergency message is sent to a trusted contact via Firebase.
   - App alerts the user visually and via sound.

---

## 📦 Project Structure

surakshasakey/  
│  
├── hardware/ # Arduino code and circuit diagram  
├── flutter\_app/ # Flutter mobile app source  
├── ml\_model/ # Training notebooks and model files  
├── firebase/ # Firestore rules and functions  
└── README.md can paste directly from Word or other rich text sources.
---

## 🧪 Use Cases

- 🚗 Car accident or crash detection
- 👴 Fall detection for elderly individuals
- 🗣️ Detection of screams or distress sounds
- 👨‍👩‍👧 Child safety during commutes

---

## 🙌 Contributors

- **Tejas Gadge** – IoT & App Development
- ... (Add teammates if applicable)

---

## 📍 Future Improvements

- Integration with SOS services and police hotline
- Fall severity estimation
- Battery health monitor
- Wearable form factor (wristband or pendant)

---

## 📄 License

MIT License – Feel free to use, modify, and share this project with proper attribution.

---

Developed with ❤️ by Tejas Gadge
