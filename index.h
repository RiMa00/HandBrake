const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
  <head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>HandBrake Web Control</title>
    
    <script src="https://code.highcharts.com/highcharts.js"></script>
    <script src="https://code.highcharts.com/highcharts.js"></script>
    <script src="https://code.highcharts.com/highcharts-more.js"></script>
    <script src="https://code.highcharts.com/modules/exporting.js"></script>
    <script src="https://code.highcharts.com/modules/export-data.js"></script>
    <script src="https://code.highcharts.com/modules/accessibility.js"></script>  
    <style>
      /* Copyright 2014 Owen Versteeg; MIT licensed */
      body,textarea,input,select{background:0;border-radius:0;font:16px sans-serif;margin:0}.smooth{transition:all .2s}.btn,.nav a{text-decoration:none}.container{margin:0 20px;width:auto }label>*{display:inline}form>*{display:block;margin-bottom:10px}.btn{background:#999;border-radius:6px;border:0;color:#fff;cursor:pointer;display:inline-block;margin:2px 0;padding:12px 30px 14px}.btn:hover{background:#888}.btn:active,.btn:focus{background:#777}.btn-a{background:#0ae}.btn-a:hover{background:#09d}.btn-a:active,.btn-a:focus{background:#08b}.btn-b{background:#3c5}.btn-b:hover{background:#2b4}.btn-b:active,.btn-b:focus{background:#2a4}.btn-c{background:#d33}.btn-c:hover{background:#c22}.btn-c:active,.btn-c:focus{background:#b22}.btn-sm{border-radius:4px;padding:10px 14px 11px}.row{margin:1% 0;overflow:auto}.col{float:left}.table,.c12{width:100%}.c11{width:91.66%}.c10{width:83.33%}.c9{width:75%}.c8{width:66.66%}.c7{width:58.33%}.c6{width:50%}.c5{width:41.66%}.c4{width:33.33%}.c3{width:25%}.c2{width:16.66%}.c1{width:8.33%}h1{font-size:3em}.btn,h2{font-size:2em}.ico{font:28px Arial Unicode MS,Lucida Sans Unicode}.addon,.btn-sm,.nav,textarea,input,select{outline:0;font-size:14px}textarea,input,select{padding:8px;border:1px solid #ccc}textarea:focus,input:focus,select:focus{border-color:#5ab}textarea,input[type=text]{-webkit-appearance:none;width:13em}.addon{padding:8px 12px;box-shadow:0 0 0 1px #ccc}.nav,.nav .current,.nav a:hover{background:#000;color:#fff}.nav{height:24px;padding:11px 0 15px}.nav a{color:#aaa;padding-right:1em;position:relative;top:-1px}.nav .pagename{font-size:22px;top:1px}.btn.btn-close{background:#000;float:right;font-size:25px;margin:-54px 7px;display:none}@media(min-width:1310px){.container{margin:auto;width:1270px}}@media(max-width:870px){.row .col{width:100%}}@media(max-width:500px){.btn.btn-close{display:block}.nav{overflow:hidden}.pagename{margin-top:-11px}.nav:active,.nav:focus{height:auto}.nav div:before{background:#000;border-bottom:10px double;border-top:3px solid;content:'';float:right;height:4px;position:relative;right:3px;top:14px;width:20px}.nav a{padding:.5em 0;display:block;width:50%}}.table th,.table td{padding:.5em;text-align:left}.table tbody>:nth-child(2n-1){background:#ddd}.msg{padding:1.5em;background:#def;border-left:5px solid #59d}
      .hero {
        background: #eee;
        padding: 20px;
        border-radius: 10px;
        margin-top: 1em;
        margin-bottom: 40px;
      }
      .hero h1 {
        margin-top: 0;
        margin-bottom: 0.3em;
      }
      .c4 {
        padding: 10px;
        box-sizing: border-box;
      }
      .c4 h3 {
        margin-top: 0;
      }
      
      .c4 a {
        margin-top: 10px;
        display: inline-block;
      }
            
      .onoffswitch {
        position: relative; width: 200px;
        -webkit-user-select:none; -moz-user-select:none; -ms-user-select: none;
      }
      
      .onoffswitch-checkbox {
        position: absolute;
        opacity: 0;
        pointer-events: none;
      }

      .onoffswitch-label {
        display: block; overflow: hidden; cursor: pointer;
        border: 2px solid #949494; border-radius: 28px;
      }

      .onoffswitch-inner {
        display: block; width: 200%; margin-left: -100%;
        transition: margin 0.3s ease-in 0s;
      }

      .onoffswitch-inner:before, .onoffswitch-inner:after {
        display: block; float: left; width: 50%; height: 41px; padding: 0; line-height: 41px;
        font-size: 18px; color: white; font-family: Trebuchet, Arial, sans-serif; font-weight: bold;
        box-sizing: border-box;
      }

      .onoffswitch-inner:before {
        content: "DIGITAL";
        padding-left: 50px;
        background-color: #2E62C2; color: #FFFFFF;
      }

      .onoffswitch-inner:after {
        content: "ANALOG";
        padding-right: 50px;
        background-color: #40A639; color: #FFFFFF;
        text-align: right;
      }

      .onoffswitch-switch {
        display: block; width: 25px; margin: 8px;
        background: #FFFFFF;
        position: absolute; top: 0; bottom: 0;
        right: 155px;
        border: 2px solid #949494; border-radius: 28px;
        transition: all 0.3s ease-in 0s; 
      }
      .onoffswitch-checkbox:checked + .onoffswitch-label .onoffswitch-inner {
        margin-left: 0;
      }
      .onoffswitch-checkbox:checked + .onoffswitch-label .onoffswitch-switch {
        right: 0px; 
      }
            
      .grid-container {
        display: grid;
        grid-template-columns: 1fr 1fr;
        grid-gap: 20px;
      }

      .flex-container {
        display: flex;
        margin-top: 40px;
      }

      .flex-child {
        flex: 1;
      }

      .flex-child:first-child {
        margin-right: 20px;
      } 

      .component-label{
        float: right;
        font-weight: bold;
        font-size: 25px;
      }

      canvas{
        -moz-user-select: none;
        -webkit-user-select: none;
        -ms-user-select: none;
      }

      #tableContainer {
        height: 400px;
        display: block;
        overflow-y: scroll;
      }
      #tableContainer2 {
        height: 400px;
        display: block;
        overflow-y: scroll;
      }

      /* Data Table Styling */
      #dataTable {
        font-family: "Trebuchet MS", Arial, Helvetica, sans-serif;
        border-collapse: collapse;
        width: 100%;
      }

      #dataTable td, #dataTable th {
        border: 1px solid #ddd;
        padding: 8px;
      }

      #dataTable tr:nth-child(even){background-color: #f2f2f2;}
      #dataTable tr:hover {background-color: #ddd;}

      #dataTable th {
        padding-top: 12px;
        padding-bottom: 12px;
        text-align: left;
        background-color: #2E62C2;
        color: white;
      }

      .left {
        float: left;
        width: 49%
      }
      .right {
        float: right;
        width: 49%
      }

      .highcharts-credits {
        display:none;
      }

      #chart-distance {
        height: 432px;
      }

       /* Data Table Styling */
      #dataTable2 {
        font-family: "Trebuchet MS", Arial, Helvetica, sans-serif;
        border-collapse: collapse;
        width: 100%;
      }

      #dataTable2 td, #dataTable2 th {
        border: 1px solid #ddd;
        padding: 8px;
      }

      #dataTable2 tr:nth-child(even){background-color: #f2f2f2;}
      #dataTable2 tr:hover {background-color: #ddd;}

      #dataTable2 th {
        padding-top: 12px;
        padding-bottom: 12px;
        text-align: left;
        background-color: #40A639;
        color: white;
      }

      .left {
        float: left;
        width: 48%
      }
      .right {
        float: right;
        width: 48%
      }

      /* GAUGE styles */
      #gaugeContainer {
        height: 400px;
      }

      .highcharts-figure,
      .highcharts-data-table table {
        min-width: 310px;
        max-width: 500px;
        margin: 1em auto;
      }

      .highcharts-data-table table {
        font-family: Verdana, sans-serif;
        border-collapse: collapse;
        border: 1px solid #ebebeb;
        margin: 10px auto;
        text-align: center;
        width: 100%;
        max-width: 500px;
      }

      .highcharts-data-table caption {
        padding: 1em 0;
        font-size: 1.2em;
        color: #555;
      }

      .highcharts-data-table th {
        font-weight: 600;
        padding: 0.5em;
      }

      .highcharts-data-table td,
      .highcharts-data-table th,
      .highcharts-data-table caption {
        padding: 0.5em;
      }

      .highcharts-data-table thead tr,
      .highcharts-data-table tr:nth-child(even) {
        background: #f8f8f8;
      }

      .highcharts-data-table tr:hover {
        background: #f1f7ff;
      }

    </style>
</head>
  <body>
    <div class="container">
      <div class="hero">
        <h1>Handbrake Web Control</h1>
        <div class="flex-container">
          <div class="flex-child magenta">
          <span class="component-label">Choose Mode</span>
          </div>
          <div class="flex-child green">
          <div class="grid-child green">
            <div style="display: inline">
              <div class="onoffswitch">
                <input type="checkbox" name="onoffswitch" class="onoffswitch-checkbox" id="ledSwitch" tabindex="0">
                <label class="onoffswitch-label" for="ledSwitch">
                  <span class="onoffswitch-inner"></span>
                  <span class="onoffswitch-switch"></span>
                </label>
              </div>
            </div>
          </div>
          </div>
        </div>
      </div>
      <div class="container left">
        <div style="text-align:center;"><b>Analog Plot</b></div>
        <figure class="highcharts-figure">
          <div id="gaugeContainer"></div>
      </figure>
<div id="tableContainer2">
          <table id="dataTable2">
            <tr><th>Time</th><th>Brake Force [kN]</th></tr>
          </table>
        </div>

      </div>
      <div class="container right">
        <div style="text-align:center;"><b>Digital Plot</b></div>
        <div id="chart-distance"> </div>
        <div id="tableContainer">
          <table id="dataTable">
            <tr><th>Time</th><th>Brake Force [kN]</th></tr>
          </table>
        </div>
        <br>
        <br>
      </div>
    </div>
    <!-- > end of main container  -->
    <script>
      
      document.getElementById('ledSwitch').onclick = function() {
        // access properties using this keyword
        var ledStatus;
        if ( this.checked ) {
          ledStatus = "ON";
          
        } else {
          ledStatus = "OFF";
      
        }
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
          if (this.readyState == 4 && this.status == 200) {
            console.log("Successfully received ");
          }
        };
        xhttp.open("GET", "toggleLED?ledStatus="+ledStatus, true);
        xhttp.send();
      };



      // skripta za graf:
         var chartT = new Highcharts.Chart({
                  chart:{ 
                  renderTo : 'chart-distance',
                  zoomType: 'x',
                  panning: true,
                  panKey: 'shift'
                  },

                  title: { text: '' },
                  series: [{
                    showInLegend: false,
                    data: []
                  }],
                  plotOptions: {
                    line: { animation: false,
                    dataLabels: { enabled: true }
                    },

                    series:{
                    lineWidth: 3,
                    name: 'Brake Force [kN]',
                    color: '#2E62C2'
                  }

                  },

                   xAxis: {
                type: 'datetime',
                labels: {
                  formatter: function() {
                    var x=new Date().toLocaleTimeString();
                    return x;

                    
        }
      }
    },
                  yAxis: {
                    title: { text: 'Brake force [kN]' }
                  },
                  credits: { enabled: false }
                });


      


      setInterval(function() {
        getData();
      }, 500); //Update rate [ms]
        
      function getData() {

        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
          if (this.readyState == 4 && this.status == 200) {
          
            
           
           var x=new Date().toLocaleTimeString();
          
           var y = parseFloat(this.responseText);
                      
           if(chartT.series[0].data.length > 5000) {
           chartT.series[0].addPoint([x, y], true, true, true);
           }else {
            chartT.series[0].addPoint([x, y], true, false, true);
            }

        //Update Data Table
          var table = document.getElementById("dataTable");
          var row = table.insertRow(1); //Add after headings
          var cell1 = row.insertCell(0);
          var cell2 = row.insertCell(1);
          cell1.innerHTML = x;
          cell2.innerHTML = y;
          }
        };
        xhttp.open("GET", "readDigitalValue", true); //Handle digital value
        xhttp.send();
      }






      // GAUGE SCRIPT
      Highcharts.chart('gaugeContainer', {
        chart: {
        type: 'gauge',
        plotBackgroundColor: null,
        plotBackgroundImage: null,
        plotBorderWidth: 0,
        plotShadow: false
    },

    title: {
        text: ''
    },

    pane: {
        startAngle: -150,
        endAngle: 150,
        background: [{
            backgroundColor: {
                linearGradient: { x1: 0, y1: 0, x2: 0, y2: 1 },
                stops: [
                    [0, '#FFF'],
                    [1, '#333']
                ]
            },
            borderWidth: 0,
            outerRadius: '109%'
        }, {
            backgroundColor: {
                linearGradient: { x1: 0, y1: 0, x2: 0, y2: 1 },
                stops: [
                    [0, '#333'],
                    [1, '#FFF']
                ]
            },
            borderWidth: 1,
            outerRadius: '107%'
        }, {
            // default background
        }, {
            backgroundColor: '#DDD',
            borderWidth: 0,
            outerRadius: '105%',
            innerRadius: '103%'
        }]
    },

    // the value axis
    yAxis: {
        min: 0,
        max: 1840,

        minorTickInterval: 'auto',
        minorTickWidth: 1,
        minorTickLength: 10,
        minorTickPosition: 'inside',
        minorTickColor: '#666',

        tickPixelInterval: 30,
        tickWidth: 2,
        tickPosition: 'inside',
        tickLength: 10,
        tickColor: '#666',
        labels: {
            step: 2,
            rotation: 'auto'
        },
        title: {
            text: 'kN'
        },
        plotBands: [{
            from: 0,
            to:700,
            color: '#55BF3B' // green
        }, {
            from: 700,
            to: 1300,
            color: '#DDDF0D' // yellow
        }, {
            from: 1300,
            to: 1840,
            color: '#DF5353' // red
        }]
    },

    series: [{
        name: 'Brake Force',
        data: [0],
        tooltip: {
            valueSuffix: ' kN'
        }
    }]

},




      // Add some life
      function (chart) {
      if (!chart.renderer.forExport) {
          setInterval(function () {
            updateGauge(chart); 
          }, 500); // svako 100ms sekund update
      }
      });
      
    
      function updateGauge(chart) {
        var xhttp = new XMLHttpRequest();

        xhttp.onreadystatechange = function() {
          if (this.readyState == 4 && this.status == 200) {
        var point = chart.series[0].points[0];
        var time = new Date().toLocaleTimeString();
        var analogValue=this.responseText;
        point.update(parseInt(analogValue));
         


         //Update Data Table
          var table = document.getElementById("dataTable2");
          var row = table.insertRow(1); //Add after headings
          var cell1 = row.insertCell(0);
          var cell2 = row.insertCell(1);
          cell1.innerHTML = time;
          cell2.innerHTML = analogValue;
      
     
      }


    };
        xhttp.open("GET", "readAnalogValue", true); 
        xhttp.send();
      }



    </script>
  </body>
</html>
)=====";
