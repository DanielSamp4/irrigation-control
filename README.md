# Control plants irrigation using ESP32

A challenge made by Neurobots

# Overview

This project consist in creat a system that can irrigate plants based on day period and degree of humidity. This system have to be pownred by a battery of 3.7v 

### System

<div align="center"><img alt="Block Diagram" width="580" src="docs/Image/Block-Diagram.png" />

 In summary, the system is made to charge the battery with solar pannels or power grid (giving priority to the power grid), and power a ESP32 that will be the brain operation, that will check if LDR and Soil Hmidity Sensor get in determinate condition, and will trigger the circuit switch to activate the solenoid, therefore irrigating a plant.

 The Soil Hmidity Sensor, Solenoid and LDR have conectors attached to the PCB (See Hardware Section) to connect them, and the user feel free to use them.
 
### Power Circuit
lithium batteries can be dangerous if not charged properly and that's why the TP4056 is useful as it stops over voltage and current charging by detecting specific voltage conditions. You should never use the TP4056 as a charger and as a load driver at the same time. For this we will use a PMOSFET that will function like a controlled switch that disconnects the battery when external power is applied. The TP4056 still charges the battery but without a load. Power to the load is supplied from the power source directly.

To know more about the right way to use TP4056 see https://www.best-microcontroller-projects.com/tp4056.html

### Logical Circuit

Both LDR and Sensor Humidity are analog devices, therefore can be atached to any ADC GPIO of ESP32, i choose GPIO 34 and 35 (See Firmware Section).

For Activate the solenoid, must be a output GPIO (anyone except 34, 35, 36, 39 because they are input only) and the circuit switch will be a NMOSFET with gate connect to GPIO, drain connect to GND from the solenoid and source connect to GND from the circuit, with this configuration when GPIO is high the NMOSFET will connect the GND from NMOSFET with the GND from de circuit and de valvula solenoid will open. I will connect to GPIO 25 and will use PWM signal to see if will genarate some kind of water flow control from solenoid.

