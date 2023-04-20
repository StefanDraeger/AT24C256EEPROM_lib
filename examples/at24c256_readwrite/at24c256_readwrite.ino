#include <at24c256eeprom.h>
#include <Wire.h>

//create object of type AT24C 
//with I2C Address 0x51
AT24C at24c256 = AT24C(0x51);

void setup() {
  //content to write
  char data[] = "Test123456";
  //begin OneWire communication
  Wire.begin();
  //begin serial communication
  Serial.begin(9600);
  //write content from field data to eeprom
  at24c256.write_page(0, (byte *)data, sizeof(data));
  //tiny break for 100 ms.
  delay(100);
  //write message to serial interface
  Serial.println("Write data successfull.");
}

void loop() {
  //start with address 0
  int addr = 0;
  //read the first byte
  byte b = at24c256.read_byte(0);
  //as long as the value in the variable b
  //is not equal to 0 makes..
  while (b != 0) {
    //print character to serial interface
    Serial.print((char)b);
    //increment address
    addr++;
    //read content from new address
    b = at24c256.read_byte(addr);
  }
  //send linebreak to serial interface
  Serial.println(" ");
  //tiny break for 2 seconds
  delay(2000);
}