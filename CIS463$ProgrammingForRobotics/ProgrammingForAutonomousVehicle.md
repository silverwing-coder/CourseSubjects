<h2>//** UNDER CONSTRUCTION **//</h2>

<h4>Update: Mar-2025 by Sangmork Park at VMI</h4>
<p>//***** <br/>
This page is created to provide instructions to setup aerial drone programming on <a href="https://docs.px4.io/main/en/">PX4" Autopilot</a>. <p>
<ul>
    <li><u>Python interpreter version was downgraded to 3.8 in order to make the python packages (pymavlink, mavsdk, and dronekit) compatitable with PX4 programming</u></li>
    <li>Tested compatibility with MAVProxy, Mission Planner, and QGroundControl</li>
    <li>SITL tested with QGroundControl, PX4-Autopilot, Gazebo Simulator on WSL (Ubuntu) environment</li>
</ul>
<p>*****//</p>

<h4> /* Install multiple version of Python on Linux */</h4>
Refer to ...
<ul>
    <li><a href="https://github.com/pyenv/pyenv">Pyenv Documnetation</a></li>
    <li><a href="https://www.youtube.com/watch?v=QdlopCUuXxw">YouTube Tutorial</a></li>
</ul>

<h2>CIS 463: Python Programming for an Autonomous Aerial Vechicle</h2>
<h3>Devices / Components</h3>
<ul>
    <li>S500 Drone Kit</li>
    <li>PX4 Autopilot</li>
    <li>Companion Computer: Raspberry Pi 4 </li>
        <ul>
            <li>O.S: Rasberry Pi 4, 64 bits</li>
            <li>Enable: SSH, Hotspot, Serial (UART) connection to PX4</li>
            <li>Disable: Bluetooth</li>
            <li>IDE: Visual Studio Code</li>
        </ul>
    <li>MAVLink-Python programming packages: pymavlink, mavsdk, dronekit</li>
    <li>SITL: MAVproxy, QGroundControl, PX4 Gazebo on WSL environment</li>
    <li>IDE: Visual Studio Code on WSL and SSH</li>
</ul>

<br/><h3>1. S500 Drone Kit Assembly</h3>
<ul>
    <li>This is required to finish on student's group work. There are numerous tutorals and guidances on the Web. Most useful references will be the YouTube tutorials that provide step by step demonstration. <br/>--> Refer to the PPT silde on Canvas for CIS 463 course</br></li>
    <li>After assembliing the drone kit finished, perform calibration with a Ground Control Station; Mission Planner or QGroundContro, and perform flight test with a RC Transmitter Controller located in the Lab Cabinet. </li>
</ul>

<br/><h3>2. Connect RPi to PX4 Auto Pilot</h3>
<p>Refer to ....</p>
<ul>
    <li>Korean Language: https://www.youtube.com/@KoreaFalcon</li>
</ul>


``` sh
# setup raspberry configuration
$ sudo raspi-config
```

<ol>
    <li>Enable ssh: raspi-config -> Interface Options -> SSH</li>
    <li>Enalble Serial: raspi-config -> Interface Options --> Serial Port --> "... log in shell ....": No --> "... serial port... ": Yes --> reboot</li>

``` sh
# check if serial-communication enabled: there is "/dev/ttyAMA0"
$ ls /dev/tty*

# if there is no "/dev/ttyAMA0" --> disable Bluetooth
$ nano /boot/firmware/config.txt

# add a line to disable Bluetooth
dtoverlay=disable_bt

``` 

<li>Open and connect Mission Pllanner to PX4 via USB on Windows</li>
    <ul>
        <li>Connect via COMM-# (USB)  and monitor vehicle status</li>
        <li>For skipping system test: CONFIG --> Standard Params --> Arm Check to Perform .... --> unchek all items</li>
    </ul>
</ol>

<br/><h3>3. Test RPi - PX4 Connection</h3>

``` sh
# on system shell environment - optional
$ sudo apt update
$ sudo apt upgrade -y 
$ sudo apt install python3-pip
$ sudo apt install python3-dev
$ sudo apt install future
# some package may not work
$ sudo apt install screen, wxgtk, libxml libxlts    

# on .venv shell
$ pip install pyserial 
$ pip install dronekit
$ pip install mavproxy
$ pip install mavsdk

$ ls /dev/tty*  # confirm /dev/ttyAMA0 exists
$ sudo apt reboot
$ MAVProxy.py --masger=/dev/ttyAMA0

# on mavproxy shell
>> mode GUIDED
>> mode STABILIZE

# disable pre-flight check via Mission Planner settings: 
# Mission Planner --> Config --> Standard Params --> Arm Checks to Perform ..... --> uncheck all items

# MAVProxy shell
>> arm throttle 

## open an IDE --> create a programming code --> test .....
$ code .
```
