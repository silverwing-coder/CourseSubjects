
<h4>Update: Jan-2025 by Sangmork Park at VMI</h4>
<h2>CIS 463: Raspberry 4B model Lab Environment Setup</h2>

<ol>
  <br/><li>Raspberry Pi Operating System</li>
    
  <ul>
    <li>Download RPi O.S, imager download from <a href="https://www.raspberrypi.com/software/">Raspberry Pi OS</a></li>
    <li>Connect a Micro-SD card into a USB prot on Laptop</li>
    <li>Choose Device -> Choose OS (Raspberry Pi OS 64 bit, Desktop) -> Choose Storage</li>
    <li>Insert the Micro-SD into Raspberry Pi Storage Connector</li>
  </ul>
    
  <br/><li>Set the Raspberry Pi as a Wi-Fi access point: </li>
  <p>Set the access point to be the default WiFi connection when boot: <br/> WiFi Icon -> Advanced Options -> Edit Connection -> Select Acce Point --> Settings --> General --> Select "Connect automatically wiht priority '0' -> Save ....<p>
  <ul>
    <li>Option-1: Select Wi-Fi icon (upper-right corner) -> Advanced Options -> Create Wi-Fi Hosspot -> Set the SSID and security options</li>      
    <li> Option-2: </li>

  ``` sh
  $ sudo apt update
  $ sudo apt upgrade -y
  $ raspi-config   # System Options -> Wireless LAN
  ```
  </ul>
  
  <br/><li>Set a static ip-address to the Wi-Fi access point </li>
    <ul>
    <li>Select Wi-Fi icon (upper-right corner) -> Advanced Options -> Network Connections -> Settigs button -> IPv4 Settings -> Assign an IP address
    </ul>
  <br/><li>Enable ssh-daemon for remote access</li>
    <ul>
    <li>Option-1: </li>

``` sh
$ raspi-config  # Interface Options -> SSH
```    
   <br/><li>Option-2: </li>

``` sh
$ sudo apt install openssh-server
$ sudo systemctl start ssh
$ sudo systemctl enable ssh
$ sudo systemctl status ssh
```
  </ul>

  <br/><li>Add a user for sharing the device</li>

``` sh
$ sudo useradd -m 'newuser-name' 
$ sudo passwd 'newuser-password'

$ ifconfig
$ ssh user-name@ip-address
```

  <br/><li>Set your Visual Studio Code accessible remote computer via SSH</li>
    <ul>
    <li>Install Remote-SSH extension</li>
    <li>Remote access button (left-lower corner) -> Connect to Host  -> Add SSH Host .....</li>
   </ul>
</ol>