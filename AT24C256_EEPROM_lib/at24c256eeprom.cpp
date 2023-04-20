#include "at24c256eeprom.h"
#include <Wire.h>

int i2cAddress = 0x51;

AT24C::AT24C(int i2cAddress){
	this.i2Address = i2cAddress;	
}

void AT24C::write_byte(unsigned int eeaddress, byte data){
	int rdata = data;
	Wire.beginTransmission(i2cAddress);
	Wire.write((int)(eeaddress >> 8));    // MSB
	Wire.write((int)(eeaddress & 0xFF));  // LSB
	Wire.write(rdata);
	Wire.endTransmission();
}

void AT24C::write_page(unsigned int eeaddresspage, byte *data, byte length){
	Wire.beginTransmission(i2cAddress);
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
	Wire.beginTransmission(i2cAddress);
	Wire.write((int)(eeaddress >> 8));    // MSB
	Wire.write((int)(eeaddress & 0xFF));  // LSB
	Wire.endTransmission();
	Wire.requestFrom(i2cAddress, 1);
	if (Wire.available()){
		rdata = Wire.read();
	} 
	return rdata;
}

void AT24C::read_buffer(unsigned int eeaddress, byte *buffer, int length){
	Wire.beginTransmission(i2cAddress);
	Wire.write((int)(eeaddress >> 8));    // MSB
	Wire.write((int)(eeaddress & 0xFF));  // LSB
	Wire.endTransmission();
	Wire.requestFrom(i2cAddress, length);
	int c = 0;
	for (int c = 0; c < length; c++){
		if (Wire.available()){
			buffer[c] = Wire.read();
		}	
	}	
}  