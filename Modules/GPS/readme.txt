##
##	SETUP
##

	UNLESS USING AUTOBOOT FOR GPSD FOLLOW STEPS

	KILL ALL AUTO SYSTEMS (THESE WILL INTERFERE WITH READINGS)

	pi@:~$ sudo systemctl stop gpsd.socket
	pi@:~$ sudo systemctl disable gpsd.socket

	THEN GET USB SOCKET NAME (can be found via [dmesg | grep tty])

	START GPSD WITH SELECTED SOCKET

	pi@:~$ sudo gpsd /dev/ttyUSB0 -F /var/run/gpsd.sock