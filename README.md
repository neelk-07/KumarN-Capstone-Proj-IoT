# NFT Hydroponics Monitoring System

This project is a simulated IoT system designed to monitor environmental parameters in an NFT hydroponics setup. The system reads from virtual sensors using an ESP32 microcontroller on Wokwi, sends data to the cloud via Adafruit IO, and visualizes it on a live dashboard.

## Features of Project
- Temperature and humidity monitoring using DHT22 sensor  
- CO₂ concentration simulation using analog sensor  
- Water level detection with float switch  
- Visual LED alert for threshold breaches  
- Cloud integration using MQTT and Adafruit IO  
- Real-time dashboard with charts, gauges, and status indicators  

## Setup Guide
1. Clone the repository  
   `git clone https://github.com/YOUR_USERNAME/YOUR_REPOSITORY.git`  

2. Open Wokwi Simulation  
   - Go to [Wokwi](https://wokwi.com/projects/new/choose-board/esp32)  
   - Select Arduino
   - Replace the default Wokwi `diagram.json` and `sketch.ino` files with the ones from this repository
   - Go into the **Library Manager**, click the **plus (+)** icon, then search for and add the following libraries:  
     - DHT sensor library  
     - Adafruit MQTT Library  
     - Adafruit Unified Sensor  
     
3. Set Up Adafruit IO  
   - Create an account at https://io.adafruit.com  
   - Create the following feeds:  
     - `capstone-feeds.temperature`  
     - `capstone-feeds.humidity`  
     - `capstone-feeds.co2`  
     - `capstone-feeds.water`  
     - `capstone-feeds.alert`  
     - `capstone-feeds.light`  
   - Navigate to **My Key** in your Adafruit IO dashboard and copy your **AIO Key** and **Username**

4. Adjust Code  
   - In `sketch.ino`, replace the existing credentials with your own:  
     ```cpp
     #define IO_USERNAME "your_username"
     #define IO_KEY "your_aio_key"
     ```

5. Run Simulation  
   - Press the play button in Wokwi  
   - Open Serial Monitor to confirm data is being sent  
   - View your Adafruit IO dashboard live at  
     `https://io.adafruit.com/YOUR_USERNAME/dashboards/YOUR_DASHBOARD_NAME`  

## Testing Performed
- Normal sensor readings  
- Simulated low water and high CO₂ trigger alerts  
- Dashboard updates every 15 seconds  
- Visual alerts via LED and Adafruit indicator blocks
- 
## File Structure
├── sketch.ino # Main ESP32 program
├── diagram.json # Wokwi simulation configuration
├── libraries.txt # List of Arduino libraries used
├── README.md # Project documentation

yaml
Copy code

## License
This project is provided for educational use under the MIT License.

---

*For questions or contributions, please contact Neel Kumar.*
