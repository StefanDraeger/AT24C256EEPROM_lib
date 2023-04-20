#ifndef AT24C_h
#define AT24C_h
#include "Arduino.h"

#define EEPROM_I2C_ADDRESS 0x50

class AT24C {
  public:

  AT24C();

  void write_byte(int deviceaddress, unsigned int eeaddress, byte data);
  void write_page(int deviceaddress, unsigned int eeaddresspage, byte *data, byte length);
  byte read_byte(int deviceaddress, unsigned int eeaddress);
  void read_buffer(int deviceaddress, unsigned int eeaddress, byte *buffer, int length);
  
  private:
  
};

#endif
