
<h2>Raspberry 4B model lab environment setup</h2>


<ol>
  <li>Raspberry Pi Operating System</li>
    
  <ul>
    <li>Download RPi O.S, imager download from <a href="https://www.raspberrypi.com/software/">Raspberry Pi OS</a></li>
    <li>Connect a Micro-SD card into a USB prot on Laptop</li>
    <li>Choose Device -> Choose OS (Raspberry Pi OS 64 bit, Desktop) -> Choose Storage</li>
    <li>Insert the Micro-SD into Raspberry Pi Storage Connector</li>
  </ul>
    
  <li>Set the Raspberry Pi as a Wi-Fi access point: </li>
      
  <ul>
    <li>Option-1: Select Wi-Fi icon (upper-right corner) -> Advanced Options -> Create Wi-Fi Hosspot -> Set the SSID and security options</li>      
    <li> Option-2: </li>

``` sh
$ sudo apt update
$ sudo apt upgrade -y
$ raspi-config   # System Options -> Wireless LAN

```
  </ul>
  
  <li>Set a static ip-address to the Wi-Fi access point </li>
    <ul>
    <li>Select Wi-Fi icon (upper-right corner) -> Advanced Options -> Network Connections -> Settigs button -> IPv4 Settings -> Assign an IP address
    </ul>
  <li>Enable ssh-daemon for remote access</li>
    <ul>
    <li>Option-1: </li>

``` sh
$ raspi-config  # Interface Options -> SSH

```    
   <li>Option-2: </li>

``` sh
$ sudo apt install openssh-server
$ sudo systemctl start ssh
$ sudo systemctl enable ssh
$ sudo systemctl status ssh

```
  </ul>
  <li>Add a user for sharing the device</li>

``` sh
$ sudo useradd -m 'newuser-name' 
$ sudo passwd 'newuser-password'

$ ifconfig
$ ssh user-name@ip-address

```

  <li>Set your Visual Studio Code accessible remote computer via SSH</li>
    <ul>
    <li>Install Remote-SSH extension</li>
    <li>Remote access button (left-lower corner) -> Connect to Host  -> Add SSH Host .....</li>
   </ul>
</ol>