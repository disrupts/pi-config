pi-config
=========

basic configuration files and samples scripts for Raspberry Pi GPIO

interfaces: 
      * a copy of default /etc/network/interfaces
      * a modified version to connect computer directly to RaspPi (without dhcp server)

Led_tests:
      * a sample sh script to use GPIO
      * another sh script using wiringPi gpio binary
      * a sample C code as included in http://elinux.org/RPi_Low-level_peripherals
      * a simple C code using wiringPi library
      * a rebuild of the previous C code to toggle manually GPIOs, using wiringPi and ncurses
      
Pi_install:
      * install_pi.sh : a sh script for raspbian that installs a few useful apps and libraries (which Led_tests depend on)




Props to @Drogon
https://projects.drogon.net/ 
for wiringPi https://projects.drogon.net/raspberry-pi/wiringpi/
which is licensed with LGPLv3 http://www.gnu.org/copyleft/lesser.html
(see wiringPi.zip for full license)
