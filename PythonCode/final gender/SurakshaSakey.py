from flask import Flask, request, jsonify
from flask_cors import CORS

app = Flask(__name__)
CORS(app)  # This will enable CORS for all routes

# To store the latest location and accelerometer data
latest_data = {
    "latitude": None,
    "longitude": None,
    "accelX": None,
    "accelY": None,
    "accelZ": None
}

# Endpoint to receive data from ESP32
@app.route('/update_location', methods=['POST'])
def update_location():
    global latest_data
    data = request.json
    print(f"Received data: {data}")
    
    # Store the received data
    latest_data['latitude'] = data.get('latitude')
    latest_data['longitude'] = data.get('longitude')
    latest_data['accelX'] = data.get('accelX')
    latest_data['accelY'] = data.get('accelY')
    latest_data['accelZ'] = data.get('accelZ')
    
    return jsonify({"status": "success", "data": latest_data}), 200

# Endpoint to send the latest data to Flutter app
@app.route('/latest_location', methods=['GET'])
def latest_location():
    return jsonify(latest_data)

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000)
