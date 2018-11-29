# forestfire-detection-arduino
Forest Fire Detection using arduino and esp8266 wifi module



# FOREST FIRE DETECTION USING ARDUINO

## SUMMARY

- Forest fire detector is used to detect flames, CO and CO2 gases, temperature, as these are the important parameters to detect wild fire.

- We used four types of sensors to detect forest fire for multiple uses.

- These data will be sent to forest fire department through either internet or mobile application.

- This idealogy makes the forest fire department to  quickly respond to the wild fire

- You can create a thingspeak(for IOT based networks) account and plot the graph wih respect to time

- Hence,they can save many trees with our idealogy

## Components Required

|Component|Quantity|Price (INR as of 2018)|
|---|---|---|
|Arduino|1|200|
|MQ-9 gas sensor|1|200|
|Flame sensor module|1|200|
|ESP8266|1|350|
|Jumper wires|50|200|
|Breadboard|1|100|
|LM-35 temperature sensor|1|200|

## METHODOLOGY

- To receive the signal from the forest Arduino UNO board is used. The signal received from the board can be treated as an alarm / warning of fire. The Arduino board is connected to the gas sensor. The gas sensor is capable of sensing the gases like CO and CO2 . As these are the gases are emitted during the burning of trees. The gas sensors are placed at different locations for identification of smoke / fire in the regions where forest fire is of major concern. The Arduino board is controlled using a smart device that runs on and android platform. The data shared by the Arduino board are received by the smart device. Depends on the threshold that has been set for detection of fire, the smart device will communicate to the concerned authorities and thereby taking the appropriate action. The data from the sensor and the android based smart device are integrated by using the IP (Internet Protocol) address of the chip and Ethernet server functionality. Smart device receives the HTTP request in JSON (JavaScript Object Notation) format and the signal will be sent from chip within the server. Alerting of messages can be shared with the concerned authorities.
- Wireless sensor network is a group of dedicated sensors for monitoring and recording the physical condition of the environment and organizing the collected data at a central location. Mainly it is used for serial data transmission and is the platform to monitor and control the automation systems in a timely basis. Reception center observe and monitor the specific area regarding to the allocation the task.


## CONCLUSION

 Identification of forest fire is a critical and a difficult task. The proposed methodology for detection of forest fire decreases the time to take the appropriate action and the intimation time to the concerned. **The cost involved in setting up the proposed methodology is negligible when compared with the loss of trees.**


