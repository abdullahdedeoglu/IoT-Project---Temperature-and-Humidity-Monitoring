# IoT-Project---Temperature-and-Humidity-Monitoring
This project uses an Arduino board, a DHT22 temperature and humidity sensor, and an LCD display to monitor and display temperature and humidity readings.
# Components Used:
Arduino Board
DHT22 Temperature and Humidity Sensor
16x2 LCD Display with I2C Interface
# Libraries Used:
Wire.h: Arduino I2C communication library.
LiquidCrystal_I2C.h: Library for using I2C backpacks on LCDs.
DHT.h: Library for interfacing DHT temperature and humidity sensors.
# Setup:
Connect the DHT22 sensor to the appropriate pin on the Arduino board.
Connect the 16x2 LCD display using an I2C backpack to the Arduino.
Upload the provided code to the Arduino board.
# Code Explanation:
The code initializes the DHT sensor and the LCD display in the setup function.
In the loop function, it reads temperature and humidity values from the DHT sensor.
It prints the temperature and humidity values to the Serial Monitor.
Depending on the temperature and humidity readings, it displays messages on the LCD:
If the temperature is below 0°C, it displays "TEMPERATURE-LOW".
If the temperature is above 0°C, it displays "TEMPERATURE-HIGH".
If the humidity is less than or equal to 50%, it displays "HUMIDITY-LOW".
If the humidity is above 50%, it displays "HUMIDITY-HIGH".
# Usage:
Upload the code to the Arduino board.
Power up the Arduino and the components.
Observe the temperature and humidity readings on the LCD display.
Check the Serial Monitor for detailed temperature and humidity values.
# Notes:
Ensure the components are properly connected before uploading the code.
Adjust the pins used in the code if you have connected the components to different pins on the Arduino board.
