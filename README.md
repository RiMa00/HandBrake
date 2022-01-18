# SimRacing Web controlled Handbrake

### About project:
Sim racing handbrake based on NodeMcu ESP8266. Using the ibus protocol and vJoy serial feeder, it can be used for all games that support axes mapping. Web control and monitoring supported via local WiFi, for both analog and digital mode.

## Details about included files
### `HandBrake_Final.ino`
The main Arduino sketch for flashing on ESP8266.
### `index.h`
C header source file. It contains html code stored in a char MAIN_page so Arduino can read it as a character value. Using PROGMEM variable modifier, the file is stored into flash memory, instead of into SRAM where it would normally go. 
### `ibus.cpp`
The file containing IBus protocol that structures data coming through the serial port. Data is structured in a specific way so the feeder can recognize it. 
### `Web Final.html`
Web page for handbrake monitoring and control. Thanks https://www.highcharts.com/ for data visualization scripts.

## vJoySerialFeeder
A program for feeding data from a serial port to a virtual joystick. GitHub repo https://github.com/Cleric-K/vJoySerialFeeder.
Driver download https://sourceforge.net/projects/vjoystick/.


