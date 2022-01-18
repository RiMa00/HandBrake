# SimRacing Web controlled Handbrake

<p align="center">
  <img src="https://github.com/RiMa00/HandBrake/blob/main/Project%20Images/0.jpg" width="450" title="Cover">
</p>


## About project:
Sim racing handbrake based on NodeMcu ESP8266. Using the ibus protocol and vJoy serial feeder, it can be used for all games that support axes mapping. Web control and monitoring supported via local WiFi, for both analog and digital mode.


## Details about included files
### `HandBrake_Final.ino`
The main Arduino sketch for flashing on ESP8266.

Make sure to edit ssid and password credentials:
```cpp
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include "index.h" //HTML
const char* ssid = "your_ssid; //WiFi ssid
const char* password = "your_password"; //WiFi pass
ESP8266WebServer server(80); //Start Server on port 80
```
### `index.h`
C header source file. It contains html code stored in a char MAIN_page so Arduino can read it as a character value. Using PROGMEM variable modifier, the file is stored into flash memory, instead of into SRAM where it would normally go. 
### `ibus.cpp`
The file containing IBus protocol that structures data coming through the serial port. Data is structured in a specific way so the feeder can recognize it. 

Protocol description: http://blog.dsp.id.au/posts/2017/10/22/flysky-ibus-protocol/

GitHub repo: https://github.com/bmellink/IBusBM
### `Web Final.html`
Web page for handbrake monitoring and control. Thanks https://www.highcharts.com/ for data visualization scripts.

Data update rate can be edited for graph:

```js
380   setInterval(function() {
381   getData();
382   }, 250); //Update rate [ms]
```
as well as for gauge:
```js
 519    function (chart) {
 520     if (!chart.renderer.forExport) {
 521        setInterval(function () {
 522          updateGauge(chart); 
 523      }, 250); //Update rate [ms]
 524   }
 525   });
```


## vJoySerialFeeder
A program for feeding data from a serial port to a virtual joystick. GitHub repo: https://github.com/Cleric-K/vJoySerialFeeder.

Driver download: https://sourceforge.net/projects/vjoystick/.

After installing driver make sure it's visible in device manager:

<p align="left">
  <img src="https://github.com/RiMa00/HandBrake/blob/main/Project%20Images/Device%20manager.png" width="500" title="vJoy driver">
</p>

Adding axis and configuring it:

<p align="left">
  <img src="https://github.com/RiMa00/HandBrake/blob/main/Project%20Images/vJoyFeeder%20Setting2.png" width="500" title="vJoy axis">
</p>

## Wiring
Breadboard & Schematics                             
<p align="Center">
  <img src="https://github.com/RiMa00/HandBrake/blob/main/Project%20Images/Scheme.png" width="400" title="Breadboard">
  <img src="https://github.com/RiMa00/HandBrake/blob/main/Project%20Images/Wire.png" width="400" title="Schematics">
  </p>


## Some project photos :sunglasses:
<p align="center">

  <img src="https://github.com/RiMa00/HandBrake/blob/main/Project%20Images/14.jpg" width="400" >
  <img src="https://github.com/RiMa00/HandBrake/blob/main/Project%20Images/13.jpg" width="400" >
  <img src="https://github.com/RiMa00/HandBrake/blob/main/Project%20Images/12.jpg" width="400" >
  <img src="https://github.com/RiMa00/HandBrake/blob/main/Project%20Images/10.jpg" width="400" >
  <img src="https://github.com/RiMa00/HandBrake/blob/main/Project%20Images/9.jpg" width="400" >
  <img src="https://github.com/RiMa00/HandBrake/blob/main/Project%20Images/5.jpg" width="400" >
   <img src="https://github.com/RiMa00/HandBrake/blob/main/Project%20Images/8.jpg" width="400" >
  <img src="https://github.com/RiMa00/HandBrake/blob/main/Project%20Images/7.jpg" width="400" >
  <img src="https://github.com/RiMa00/HandBrake/blob/main/Project%20Images/4.jpg" width="400" >
  <img src="https://github.com/RiMa00/HandBrake/blob/main/Project%20Images/3.jpg" width="400" >
  <img src="https://github.com/RiMa00/HandBrake/blob/main/Project%20Images/2.jpg" width="400" >
  <img src="https://github.com/RiMa00/HandBrake/blob/main/Project%20Images/1.jpg" width="400" >
</p>






