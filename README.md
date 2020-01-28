# Mirai-Spray
Scans typical mirai loader/hostlists format with Hydra

## INSTALLATION
```bash
apt update -y && apt upgrade -y
apt install tor
https://github.com/Skotizo/Mirai-Spray
cd Mirai-spray
g++ main.cpp -o spray
./spray
```
## USAGE
```bash
./spray host.txt telnet

```
OR
```bash
./spray host.txt ssh

```
## HOST FILE FORMAT
IP PORT USERNAME PASSWORD
### To convert a Mirai loader with commas use 
```bash
sed 's/:/ /g' MiraiLoader.txt > hosts.txt
```

## PROXY
Currently, Hydra only allows a proxy module with the Telnet service.
### Enable Proxy
```bash
export HYDRA_PROXY=socks5://YOURLOGIN:YOURPASSWORD@127.0.0.1:9050

```
### Disable Proxy
```bash
unset HYDRA_PROXY

```

## Ethics
This project is a proof of concept and should not be ran against systems you do not own. Im not responsible for anything you do with this code. Have fun !

## CREDITS
[HYDRA](https://github.com/vanhauser-thc/thc-hydra)
