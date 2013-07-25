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


# set colour variables
g=4
o=23
y=24
r=25

# set time varible
time=0.5
# set loop init
init=1

# set up GPIOs
# Leds GOYR (pin 4,23,24,25)
gpio -g mode $g out
gpio -g mode $o out
gpio -g mode $y out
gpio -g mode $r out

gpio -g write $g 0
gpio -g write $o 0
gpio -g write $y 0
gpio -g write $r 0

while [ $init -le 5 ]
do 
	gpio -g write $g 1
	gpio -g write $o 0
	gpio -g write $y 0
	gpio -g write $r 0
	sleep $time 	
	gpio -g write $g 0
	gpio -g write $o 0
	gpio -g write $y 0
	gpio -g write $r 0
	sleep $( echo "$time/2" | bc -l )

	gpio -g write $g 0
	gpio -g write $o 1
	gpio -g write $y 0
	gpio -g write $r 0
	sleep $time 	
	gpio -g write $g 0
	gpio -g write $o 0
	gpio -g write $y 0
	gpio -g write $r 0
	sleep $( echo "$time/2" | bc -l )

	gpio -g write $g 0
	gpio -g write $o 0
	gpio -g write $y 1
	gpio -g write $r 0
	sleep $time 	
	gpio -g write $g 0
	gpio -g write $o 0
	gpio -g write $y 0
	gpio -g write $r 0
	sleep $( echo "$time/2" | bc -l )

	gpio -g write $g 0
	gpio -g write $o 0
	gpio -g write $y 0
	gpio -g write $r 1
	sleep $time 	
	gpio -g write $g 0
	gpio -g write $o 0
	gpio -g write $y 0
	gpio -g write $r 0
	sleep $( echo "$time/2" | bc -l )

	#Mid-cycle reached

	gpio -g write $g 0
	gpio -g write $o 0
	gpio -g write $y 1
	gpio -g write $r 0
	sleep $time 	
	gpio -g write $g 0
	gpio -g write $o 0
	gpio -g write $y 0
	gpio -g write $r 0
	sleep $( echo "$time/2" | bc -l )

	gpio -g write $g 0
	gpio -g write $o 1
	gpio -g write $y 0
	gpio -g write $r 0
	sleep $time 	
	gpio -g write $g 0
	gpio -g write $o 0
	gpio -g write $y 0
	gpio -g write $r 0
	sleep $( echo "$time/2" | bc -l )

	init=`expr $init + 1` 
done

#  pseudo_clean GPIO -> put down
gpio -g write $g 0
gpio -g write $o 0
gpio -g write $y 0
gpio -g write $r 0
