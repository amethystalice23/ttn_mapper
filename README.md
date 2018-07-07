# ttn_mapper
LoRaWAN Test and TTN Mapper node

Arduino code for ESP32 based LoRa enabled devices, the two examples
used are the TTGO LoRa ESP32 and the Heltec Wifi LoRa 32 boards.

The code uses a GPS module connected as a serial port to get time
and location, then sends them via The Things Network to theTTNMapper
service.

Follow the instructions in config.h to customise the device.
