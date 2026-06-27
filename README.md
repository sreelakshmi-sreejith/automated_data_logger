# 📊 Automated Data Logger with Web Visualization (ESP32)

## 📌 Overview
This project implements a real-time automated data logging system using ESP32 and multiple sensors. 
It collects environmental data, visualizes it graphically through a web server, and provides a feature to download logged data for further analysis.
The system combines embedded sensing with IoT-based visualization, making it suitable for real-time monitoring applications.

## 🎯 Objectives
- Collect real-time sensor data (Temperature, Humidity, Gas levels)
- Visualize data graphically on a web dashboard
- Enable data storage and downloading for analysis
- Build a scalable IoT-based monitoring system

## 🚀 Key Features
- 📡 Real-time data acquisition from multiple sensors  
- 🌐 Web-based dashboard hosted on ESP32  
- 📈 Graphical visualization of sensor data  
- 💾 Data download feature (CSV / log format)  
- 🔄 Continuous and automated data logging  

## 🛠️ Hardware Components

| Component | Function |
|----------|--------|
| ESP32 | Main controller and web server |
| DHT11 | Temperature & humidity sensor |
| LM35 | Analog temperature sensor |
| Gas Sensor (MQ series) | Gas detection |
| Power Supply | 5V regulated |


## 💻 Software & Tools
- Arduino IDE  
- Embedded C  
- ESP32 Web Server  
- HTML, CSS, JavaScript (for dashboard)  

## ⚙️ Working Principle

1. ESP32 reads data from:
   - DHT11 (Temperature & Humidity)
   - LM35 (Analog temperature)
   - Gas sensor (gas concentration)

2. Data is processed and updated periodically  

3. ESP32 hosts a web server:
   - Displays real-time data  
   - Plots data graphically  

4. Data is stored temporarily or in log format  

5. User can:
   - View graphs  
   - Download logged data  

## 📊 Data Visualization

The web dashboard displays:
- Real-time graphs of temperature, humidity, and gas levels  
- Dynamic updates without page refresh  
- Multiple sensor comparison  

## 💾 Data Logging & Download

- Data is stored in structured format (e.g., CSV)  
- Users can download logged data directly from the web interface  
- Enables offline analysis and record keeping  


## ▶️ How to Run

1. Connect sensors to ESP32  
2. Upload code via Arduino IDE  
3. Connect ESP32 to WiFi  
4. Open IP address in browser  
5. View real-time dashboard  
6. Download data if required  

---

## 🔧 Applications

- Environmental monitoring systems  
- Smart home automation  
- Industrial safety monitoring  
- Air quality monitoring systems  

## 🚀 Future Scope

- Cloud integration (Firebase / AWS)  
- Mobile app dashboard  
- Advanced analytics and alerts  
- Multi-node distributed monitoring  


## 👩‍💻 Author

**Sreelakshmi S S**  
ECE | Embedded Systems | IoT  


## 📌 Conclusion

This system demonstrates an effective integration of embedded systems and IoT technologies by enabling real-time monitoring, 
graphical visualization, and data logging, making it a scalable solution for modern monitoring applications.---


