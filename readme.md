## Arduino AT24C Library
This tiny library is for read and write data to I2C EEPROMs at Arduino microcontrollers.

<p align="center" width="100%">
    <img width="33%" src="https://github.com/StefanDraeger/AT24C256EEPROM_lib/blob/main/documentation/AT24C256_EEPROM.png">
</p>


The code is copied from https://playground.arduino.cc/Code/I2CEEPROM/ so Iam not the original autor.
My service is only the transformation into a library so that the functions can be reused more easily.
###  Structure of I2C EEPROM module
The AT24C I2C EEPROM modul has the following structure.

<p align="center" width="100%">
    <img width="33%" src="https://github.com/StefanDraeger/AT24C256EEPROM_lib/blob/main/documentation/I2C_EEPROM_Pinout.webp">
</p>

### I2C Adresses
With the jumpers you can set the I2C Address of this module. If you remove all jumpers (without WP) you have set the I2C Address 0x18, 0x50x 0x58 otherwise you can set it by move a jumper to the first socket. 

<p align="center" width="100%">
    <img width="33%" src="https://github.com/StefanDraeger/AT24C256EEPROM_lib/blob/main/documentation/EEPROM_256K_A0_active.webp">
</p>

|Jumper|I2C Addresses  |
|--|--|
|A0  |0x19, 0x51x, 0x59  |
|A1  |0x1A, 0x52, 0x5A   |
|A2  |0x18, 0x50, 0x58  |

###  Connection to Arduino UNO
The connection is via I2C pins very easy. You only connect the module like the following image.

<p align="center" width="100%">
    <img width="33%" src="https://github.com/StefanDraeger/AT24C256EEPROM_lib/blob/main/documentation/ArduinoUNO_I2C_256K_EEPROM.webp">
</p>