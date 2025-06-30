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
   `git clone https://github.com/neelk-07/KumarN-Capstone-Proj-IoT.git`  

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
     `https://io.adafruit.com/neelkmr/dashboards/nft-hydroponic-monitor`  

## Setup Guide

1. **Open Wokwi Simulation**
   - Go to [Wokwi](https://wokwi.com/projects/new/choose-board/esp32)  
   - Create a new project with an ESP32 board
   - Replace the default `sketch.ino` and `diagram.json` with the versions from this repository

2. **Install Required Libraries**
   - Click the **Library Manager (+)** icon on the left
   - Search for and add:
     - "DHT sensor library"
     - "Adafruit MQTT Library"
     - "Adafruit Unified Sensor"

3. **Set Up Adafruit IO**
   - Sign in at [https://io.adafruit.com](https://io.adafruit.com)
   - Go to **My Key** to get your:
     - Username
     - AIO Key

4. **Edit Code with Your Credentials**
   - In `sketch.ino`, update:
     ```cpp
     #define IO_USERNAME "your_username"
     #define IO_KEY "your_aio_key"
     ```

5. **Run the Simulation**
   - Click the **Play** button in Wokwi
   - Open the **Serial Monitor** to verify connection and publishing
   - After a few seconds, you’ll see sensor data in your Adafruit IO feeds

6. **(Optional) Create a Dashboard**
   - Go to **Dashboards → Create a New Dashboard → Name it NFT Hydroponic Monitor**
   - Add blocks (gauge, chart, text, etc.) and connect them to:
     - temperature
     - humidity
     - co2
     - water
     - alert
     - light
   - Feeds are created automatically when data is first sent
It should look something like this:





## Testing Performed
- Normal sensor readings  
- Simulated low water and high CO₂ trigger alerts  
- Dashboard updates every 15 seconds  
- Visual alerts via LED and Adafruit indicator blocks
  
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
