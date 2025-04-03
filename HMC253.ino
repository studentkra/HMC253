//esptool -p /dev/ttyUSB0 write_flash 0x00000  PE4302_eeprom2.bin


// D7 -> A
// D6 -> B
// D5 -> C


#include <EEPROM.h>

#define pinC D5
#define pinB D6
#define pinA D7

String val = "";
String ant_s = "" ;
byte ant; 
byte eeprom_ant;
void setup() {
 pinMode(pinA, OUTPUT);
 pinMode(pinB, OUTPUT);
 pinMode(pinC, OUTPUT);
 EEPROM.begin(1);
eeprom_ant = EEPROM.read(0);
set_pins(eeprom_ant);
Serial.begin(115200); 
             }
void loop() 
    {
  if (Serial.available() > 0) 
    {
val = Serial.readString();
if (val.indexOf("ant:") != -1)
{
ant_s = val.substring(5,10);
ant = ant_s.toInt();
eeprom_ant = EEPROM.read(0);
Serial.print("Read atn from eeprom: ");
Serial.print(eeprom_ant);
Serial.print(" Set ant to: ");
Serial.println(ant);
set_pins(ant);
EEPROM.write(0, ant);
EEPROM.commit();
}
if (val.indexOf("get") != -1)
{
eeprom_ant = EEPROM.read(0);
Serial.print("Current antenna is: ");
Serial.println(eeprom_ant);
  }
    }
      }
void set_pins( byte argument)
//GPOC LOW
//GPOS HIGH
{
if (argument == 1) 
{ 
GPOC = (1 << pinA);
GPOC = (1 << pinB);
GPOC = (1 << pinC);
}
if (argument == 2) 
{ 
GPOS = (1 << pinA);
GPOC = (1 << pinB);
GPOC = (1 << pinC);
}
if (argument == 3) 
{ 
GPOC = (1 << pinA);
GPOS = (1 << pinB);
GPOC = (1 << pinC);
}
if (argument == 4) 
{ 
GPOS = (1 << pinA);
GPOS = (1 << pinB);
GPOC = (1 << pinC);
}
if (argument == 5) 
{ 
GPOC = (1 << pinA);
GPOC = (1 << pinB);
GPOS = (1 << pinC);
}
if (argument == 6) 
{ 
GPOS = (1 << pinA);
GPOC = (1 << pinB);
GPOS = (1 << pinC);
}
if (argument == 7) 
{ 
GPOC = (1 << pinA);
GPOS = (1 << pinB);
GPOS = (1 << pinC);
}
if (argument == 8) 
{ 
GPOS = (1 << pinA);
GPOS = (1 << pinB);
GPOS = (1 << pinC);
}
}
