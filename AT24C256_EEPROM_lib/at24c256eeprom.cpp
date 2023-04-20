#include "at24c256eeprom.h"
#include <Wire.h>

#define EEPROM_I2C_ADDRESS 0x19

AT24C::AT24C(){ }

void AT24C::write_byte(unsigned int eeaddress, byte data){
	int rdata = data;
	Wire.beginTransmission(EEPROM_I2C_ADDRESS);
	Wire.write((int)(eeaddress >> 8));    // MSB
	Wire.write((int)(eeaddress & 0xFF));  // LSB
	Wire.write(rdata);
	Wire.endTransmission();
}

void AT24C::write_page(unsigned int eeaddresspage, byte *data, byte length){
	Wire.beginTransmission(EEPROM_I2C_ADDRESS);
	Wire.write((int)(eeaddresspage >> 8));    // MSB
	Wire.write((int)(eeaddresspage & 0xFF));  // LSB
	byte c;
	for (c = 0; c < length; c++){
		Wire.write(data[c]);
	}
	Wire.endTransmission();
}
byte AT24C::read_byte(unsigned int eeaddress){
	byte rdata = 0xFF;
	Wire.beginTransmission(EEPROM_I2C_ADDRESS);
	Wire.write((int)(eeaddress >> 8));    // MSB
	Wire.write((int)(eeaddress & 0xFF));  // LSB
	Wire.endTransmission();
	Wire.requestFrom(EEPROM_I2C_ADDRESS, 1);
	if (Wire.available()){
		rdata = Wire.read();
	} 
	return rdata;
}

void AT24C::read_buffer(unsigned int eeaddress, byte *buffer, int length){
	Wire.beginTransmission(EEPROM_I2C_ADDRESS);
	Wire.write((int)(eeaddress >> 8));    // MSB
	Wire.write((int)(eeaddress & 0xFF));  // LSB
	Wire.endTransmission();
	Wire.requestFrom(EEPROM_I2C_ADDRESS, length);
	if (Wire.available()){
		for (int c = 0; c < length; c++){
			buffer[c] = Wire.read();
		}	
	}	
}  