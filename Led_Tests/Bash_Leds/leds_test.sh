#!/bin/sh

# this is the First LED Test
#
#	 colour 	| 	pin	
# -------------------------------------------
#	Green		| 	4
#	Orange		|	23
#	Yellow 		|	24
#	Red		|	25
#
#
# default code for an Output
# --------------------------
#
#    Set Up GPIO X and set to Output
# $ echo "X"   > /sys/class/gpio/export
# $ echo "out" > /sys/class/gpio/gpioX/direction 
# 
#    Write output 
# $ echo "1"   > /sys/class/gpio/gpioX/value
#
#    Clean up
# $ echo "X"   > /sys/class/gpio/unexport

# Now let's do something!

#   set up GPIOs
#	Leds GOYR (pin 4,23,24,25)
echo "4"  > /sys/class/gpio/export
echo "23" > /sys/class/gpio/export
echo "24" > /sys/class/gpio/export
echo "25" > /sys/class/gpio/export

echo "out" > /sys/class/gpio/gpio4/direction
echo "out" > /sys/class/gpio/gpio23/direction
echo "out" > /sys/class/gpio/gpio24/direction
echo "out" > /sys/class/gpio/gpio25/direction


#infinite loop (for testing pourpuses only 5 times)
a=1	# where the loop starts, 1 for easy of use
b=0.05 	# the time in seconds between steps

while [ $a -le 50 ]
do
	#echo "Start Loop $a"
	echo "1" > /sys/class/gpio/gpio4/value
	sleep $b   
	echo "0" > /sys/class/gpio/gpio4/value
	echo "1" > /sys/class/gpio/gpio23/value
	sleep $b
	echo "1" > /sys/class/gpio/gpio24/value 
	echo "0" > /sys/class/gpio/gpio23/value 
	sleep $b
	echo "1" > /sys/class/gpio/gpio25/value 
	echo "0" > /sys/class/gpio/gpio24/value 
	sleep $b
	echo "0" > /sys/class/gpio/gpio25/value 
	#echo "Mid Lool $a"	
	echo "1" > /sys/class/gpio/gpio24/value
	sleep $b
	echo "0" > /sys/class/gpio/gpio24/value
	echo "1" > /sys/class/gpio/gpio23/value
	sleep $b 
	echo "0" > /sys/class/gpio/gpio23/value
	#echo "End Loop $a"
	#echo " "
	a=`expr $a + 1`
done

#   clean GPIO
echo "4"  > /sys/class/gpio/unexport
echo "23" > /sys/class/gpio/unexport
echo "23" > /sys/class/gpio/unexport
echo "23" > /sys/class/gpio/unexport

