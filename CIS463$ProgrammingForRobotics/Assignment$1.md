

<h2> Programming Assignment-1: Develop Codes to Control LED Light on Distance 
<h3>1. C-programming on Arduino IDE </h3>
<h4>1-1. LED blink </h4>

```c
int OUT_PIN = 16;

  void setup() {
    pinMode(OUT_PIN, OUTPUT);  // Set the output pin
  }

  // loop() function is the same as while(1)
  void loop() {
    digitalWrite(OUT_PIN, LOW);  // Turn the LED off
    delay(2000);                 // Wait for a second
    digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED on
    delay(2000);                      // Wait for two seconds
  }

```

<h4>1-2. Ultrasonic Distance Sensor(HC-SR04)</h4>
<ul>
Measure distance from an object. 
<li> If distance is larger than 10 cm --> Green LED on</li>
<li> If distance is shorter than 10 cm --> Red LED on</li>
</ul>

```c
// Set pin out: PWR on board --> Vin, GND on board --> GND
int GREEN_LT = 16;
int RED_LT = 5;
int ECHO = 12;          // Echo pin
int TRIG = 14;          // Trigger pin

#define SOUND_VELOCITY 0.034    // 340 meter per second

long duration;          // Time from Trigger to Echo
float dist_cm;

void setup() {
  Serial.begin(115200);     // for Serial Monitor output (115200 baud)

  pinMode(TRIG, OUTPUT);    // Trigger pin --> sound output
  pinMode(ECHO, INPUT);     // Echo pin --> receiver sensor

  pinMode(GREEN_LT, OUTPUT);  // Green LED pin
  pinMode(RED_LT, OUTPUT);    // Red LED pin
}

void loop() {

  // Clear Trigger pin
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);

  // Send out sound signal
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  // Receive returning sound signal
  duration = pulseIn(ECHO, HIGH);
  dist_cm = duration * SOUND_VELOCITY / 2;

  // Transfer data through Serial port
  Serial.print("Distance (cm): ");
  Serial.println(dist_cm);

  if (dist_cm < 10) {
    digitalWrite(GREEN_LT, LOW);
    digitalWrite(RED_LT, HIGH);
  } else {
    digitalWrite(GREEN_LT, HIGH);
    digitalWrite(RED_LT, LOW);
  }

  // Wait 100 mili-seconds
  delay(100);
}

```

<h3>2.  MicroPython programming on Thonny IDE </h3>
<h4>2-1. LED blink </h4>

```python
from machine import Pin
from time import sleep

led = Pin(16, Pin.OUT)
while True:
  led.on()
  sleep(1)
  led.off()
  sleep(1)

```

<h4>2-2. Ultrasonic Distance Sensor(HC-SR04)</h4>

```python
# main.py

import machine

from machine import Pin
import time

TRIG_PIN = 14
ECHO_PIN = 12
GREEN_PIN = 16
RED_PIN = 5

SOUND_VELOCITY = 0.034

trigger = Pin(TRIG_PIN, Pin.OUT, pull=None)
echo = Pin(ECHO_PIN, Pin.IN, pull=None)

green_lt = Pin(GREEN_PIN, Pin.OUT)
red_lt = Pin(RED_PIN, Pin.OUT)

def get_pulse_time():
    trigger.value(0)
    time.sleep_us(5)
    trigger.value(1)
    time.sleep_us(10)
    trigger.value(0)
#    return machine.time_pulse_us(echo, 1)
    try:
        pulse_time = machine.time_pulse_us(echo, 1)
        return pulse_time
    except OSSError as ex:
        if ex.args[0] == 110:
            raise OSError('Out of Range')
        raise ex

while True:
    pulse_time = get_pulse_time()
    distance_cm = (pulse_time/2) * SOUND_VELOCITY
    print('Distance ', distance_cm, ' (cm)')
    if (distance_cm > 10):
        green_lt.value(1)
        red_lt.value(0)
    else:
        green_lt.value(0)
        red_lt.value(1)

    time.sleep(1)


```
