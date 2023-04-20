#ifndef AT24C_h
#define AT24C_h
#include "Arduino.h"

class AT24C {
  public:

  AT24C();

  void write_byte(unsigned int eeaddress, byte data);
  void write_page(unsigned int eeaddresspage, byte *data, byte length);
  byte read_byte(unsigned int eeaddress);
  void read_buffer(unsigned int eeaddress, byte *buffer, int length);
  
  private:
  
};

#endif
