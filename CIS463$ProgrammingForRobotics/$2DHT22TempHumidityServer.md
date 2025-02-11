
<h2> Programming Exercise-1: Temperature/Humidity Server on HTTP 
<h3>MicroPython</h3>

``` python
## CIS 463 Demo, Feburary-2025
## Edited by Sangmork Park at VMI
## Referrence from "RandomNerdTutorial"

# Read data from DHT-22 Temperature and Humidity
def read_sensor_data()->str:
    global temperature, humidity
    temperature = humidity = 0
    try:
        sensor.measure()
        temperature = sensor.temperature()
        humidity = sensor.humidity()
        # if both temperature and humidity are read by the dht sensor
        if (isinstance(temperature, float) and isinstance(humidity, float)) or (isinstance(temperature, int) and isinstance(humidity, int)):
            # set data into the byte code for data transmission
            message = (b'{0:3.1f},{1:3.1f}'.format(temperature, humidity))
            return(message)
        else:
            return('Invalid sensor readings.')
    except OSError as e:
        return('Sensor failed!')

def get_web_page()->str:
    html = """<!DOCTYPE HTML><html>
        <head>
            <meta name="viewport" content="width=device-width, initial-scale=1">
            <style>
                html {
                 font-family: Arial;
                 display: inline-block;
                 margin: 0px auto;
                 text-align: center;
                }
                h2 { font-size: 3.0rem; }
                h3 { font-size: 2.0rem; }
                p { font-size: 3.0rem; }
                .units { font-size: 1.2rem; }
                .dht-labels{
                  font-size: 1.5rem;
                  color: green;
                  vertical-align:middle;
                  padding-bottom: 15px;
                }
            </style>
        </head>
        <body>
            <h2>CIS 463 Class Demo, VMI</h2>
            <h3>Temperature and Humidity From DHT22</h3>
                <p>
                    <i style="color:#059e8a;"></i> 
                    <span class="dht-labels">Temperature</span> 
                    <span>"""+str(temperature)+"""</span>
                    <sup class="units">&deg;C</sup>
                </p>
                <p>
                    <i style="color:#00add6;"></i> 
                    <span class="dht-labels">Humidity</span>
                    <span>"""+str(humidity)+"""</span>
                    <sup class="units">%</sup>
                </p>
        </body>
    </html>"""
    return html

# TCP socket connection on Port number 80 (http-service) 
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.bind(('', 80))
sock.listen(5)

while True:
    conn, addr = sock.accept()
    print('Connection from %s' % str(addr))
    
    # get message from client
    request = conn.recv(1024)
#    print('Request message = %s' % str(request))

    # sensor_reading_message to transmit (string)
    sensor_readings = read_sensor_data()
    print(sensor_readings)
    
    # response message (html)
    response = get_web_page()
    conn.send('HTTP/1.1 200 OK\n')
    conn.send('Content-Type: text/html\n')
    conn.send('Connection: close\n\n')
    conn.sendall(response)
    conn.close()

```