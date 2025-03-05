<h2>/** UNDER CONSTRUCTION **/</h2>

<h4>Update: Feb-2025, Sangmork Park at VMI </h4>

<h3> $ WSL Environment Setup</h3>
<li>Follow <a href="https://learn.microsoft.com/en-us/windows/wsl/setup/environment">Microsoft Windows Instruction</a></li>



``` sh
# update & upgrade
$ sudo apt update
$ sudo apt upgrade -y

# setup px4-gazebo simulation environment
$ sudo apt install git
$ cd ~
$ mkdir DroneSITL
$ cd DroneSITL
$ git clone https://github.com/PX4/PX4-Autopilot.git --recursive
$ bash ./PX4-Autopilot/Tools/setup/ubuntu.sh
$ make px4_sitl

# use the ip-address for Windows QGroundControl connecting setup
$ sudo apt install net-tools
$ ifconfig

```
<h3>$ PX4 Development Environment Setup</h3>
<li>Refer to .... <a href="https://docs.px4.io/main/en/">PX4 Guide</a> --> Toolchain installation -> Windows Setup</li>