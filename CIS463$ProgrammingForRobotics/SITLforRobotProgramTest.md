<!-- <h2>//** UNDER CONSTRUCTION **// </h2> -->
<h4>Update: Feb-2025, Sangmork Park at VMI</h4>

<h2>CIS 463: Setup SITL for Programming Test (MAVLink - Python - PX4 Autopilot) </h2>

<h3>Components</h3>
<ul>
    <li>Environment: WSL2 (Ubuntu) on Windows 11</li>
    <li>MAVProxy and QGroundControl</li>
    <li>PX4-Gazebo Simulation</li>
    <li>MAVLink-Python packages: pymavlink, mavsdk, and dronekit</li>
</ul>

<h3>1. WSL(Windows Subsystem for Linux) Setup</h3>
<p>WSL is a feature of Winodws that allows to run Linux apllications and utilities on WIndows without separate virtual machine or dual booting.<br/>

Refer to .... <a href="https://learn.microsoft.com/en-us/windows/wsl/">Microsoft WSL Documents</a></p>

<ul>
    <li>Tutorials --> Best practices for set up </li>
    <li>Tutorials --> Get started with VS Code</li>
</ul>

``` sh
# 1. Turn WSL on "windwos Features" and Enable WSL

# 2. Powershell {admin mode}
$ wsl --install         

# restart windows
$ wsl --list --online
$ wsl --install -d Ubuntu

# set default id and password for Ubuntu
$ wsl --shutdown
$ wsl
```

<br/><h3>2. Install PX4 SITL </h3>
<ul>
    <li> Ref-1: <a href="https://docs.px4.io/main/en/dev_setup/building_px4.html">Building PX4 Software </a></li>
    <li> Ref-2: <a href="https://github.com/PX4/PX4-Autopilot">PX4-Autopilot Repository</a></li>
    <li> Ref-3: <a href="https://www.youtube.com/watch?v=iVU8ZNoMn_U">Tutorial from YouTube - 1</a></li>
    <li> Ref-4: <a href="https://www.youtube.com/watch?v=sZbJOSk8Cc4">Tutorial from YouTube - 2</a></li>
</ul>

``` sh
# update & upgrade Linux
$ sudo apt update
$ sudo apt upgrade -y

# set px4-gazebo simulator environment
$ cd ~
$ mkdir DroneSITL
$ cd DroneSITL
$ sudo apt install git
$ git clone https://github.com/PX4/PX4-Autopilot.git --recursive
$ cd PX4-Autopilot
$ bash Tools/setup/ubuntu.sh
$ make px4_sitl
$ make px4_sitl gz_x500

# use the ip-address for Windows QGroundControl connecting setup
$ sudo apt install net-tools
$ ifconfig

# on error messages during installation
$ git stash
$ git pull
$ git submodule init
$ git submodule update --recursive
$ make distclean
$ make clean

```

<br/><h3>3. Install and Setup QGroundControl</h3>
<ul>
  <li> Refer to .... <a href="https://docs.qgroundcontrol.com/master/en/qgc-user-guide/getting_started/download_and_install.html">QGroundControl Download and Install </a> <br/>
  --> QGC on Windows can be connected to SITL on WSL</li>
  <li>Open 'QGC' --> Application Settings --> Comm Links --> Add</li>
  <ul>
    <li>Name: 'you-name-it'</li>
    <li>Type: 'UDP' or 'TCP'</li>
    <li>IP: 'your-wsl-machine-ip</li>
    <li>Port: 18570</li>
  </ul>
</ul>
<h4>QGroundContrl Drone Initaial Location --> VMI</h4>
<p>Set environment variable at "Tools/simulation/gz/worlds/default.sdf"</p>

```
<latitude_deg>37.790124</latitude_deg>
<longitude_deg>-79.437285</longitude_deg>
<elevation>1003</elevation>

```


<br/><h3>4. PX4 Development Environment </h3>
<p>Giudes to setup PX4 development environment on Windows: WSL, PX4, QGroundControl, and Visual Studio Code</p>
<ul>
  <li> Refer to .... <a href="https://docs.px4.io/main/en/">PX4 Autopilot User Guide </a></li>
  <p>--> Development --> Getting Started --> Toolchain Installation -> Windows Setup</p>
</ul>


<br/><h3>5. Simulation with PX4 SLTL and QGroundControl </h3>
<p>Connect PX4 SITL to the QGC Ground Control Station</p>
<ul>
  <li> Ref-1: <a href="https://docs.qgroundcontrol.com/master/en/">QGroundControl Guide </a> </li>
  <li> Ref-2: <a href="https://docs.px4.io/main/en/dev_setup/dev_env_windows_wsl.html">Windows Developement Environment(WSL2) </a> </li>

  <li> Ref-3: <a href="https://docs.px4.io/main/en/simulation/">PX4 Simulation </a> </li>
</ul>


<br/><h3>6. Visudl Studio Code on WSL </h3>
 
 ```sh
 # go to the directory you want to save program
 $ sudo apt install code
 $ mkdir DroneWorkSpace
 $ cd DroneWorkeSpace
 $ .code
 ```

<br/><h3>7.  MAVLink Programming on Python</h3>
<ul>
  <li>Ref-1: <a href="https://mavlink.io/en/mavgen_python/">Pymavlink on MAVLink</a></li>
  <li>Ref-2: <a href="https://pypi.org/project/pymavlink/">pymavlink 2.4.2</a></li>

  ``` sh
  $ pip install pymavelink
  ```
</ul>
  
<br/>
<ul>
  <li>Ref-1: <a href="https://github.com/mavlink/MAVSDK-Python">MAVSDK Python on GitHub</a></li>
  <li>Ref-2: <a href="https://pypi.org/project/mavsdk/">mavsdk 3.0.1</a></li>

  ``` hs
  $ pip install mavsdk
  ```
</ul>
 
<br/>
<ul>
  <li>Ref-1: <a href="https://github.com/dronekit/dronekit-python/">Dronekit-Python on GitHub</a></li>
  <li>Ref-2: <a href="https://github.com/dronekit/dronekit-python/">dronekit 2.9.2</a></li>

  ``` sh
  $ pip install dronekit
  ```
</ul>

<br/>
<ul>
  <li>Ref-1: <a href="https://github.com/mavlink/mavros/blob/ros2/mavros/README.md">MAVROS</a></li>
</ul>

