#include <wiringPi.h>
#include <ncurses.h>

// wiringpi number are different from the GPIO numbers i've used so far.
// here a table to show that
//
//	+------------------------------------------+
//	| color	 | GPIO number 	|  wiringpi number |
//	-------------------------------------------+
// 	| green	 |	4	|	7	   |			
// 	| orange |	23	|	4	   |
// 	| yellow |	24	|	5	   |
// 	| red	 |	25	|	6	   |
//	+------------------------------------------+

int main ()
{	
	//delay time in ms
	int dtime = 500;
	//define goyr varibles 
	int g,o,y,r;
	g = 7;
	o = 4;
	y = 5;
	r = 6;

	//ncurses stuff
	initscr();
	//raw();
	cbreak();
	keypad(stdscr, TRUE);
	noecho();
	printw ("Hey, this is going to start, press a button!\n");
	refresh();
	char key = getch();
	//added here to stop execution at first getch() at previous line
	halfdelay(dtime/100);
	printw ("Press q to quit");
	printw ("\n");
	refresh();
	//init GPIO
	wiringPiSetup ();
	
	//set GPIO pins as OUTPUT	
	pinMode (g, OUTPUT);
	pinMode (o, OUTPUT);
	pinMode (y, OUTPUT);
	pinMode (r, OUTPUT);

	//main loop
	for (;;)
	{ 
		key = getch();
		digitalWrite (g, HIGH);
		digitalWrite (o, LOW);
		digitalWrite (y, LOW);
		digitalWrite (r, HIGH);
		printw ("Green & Red ON\n");
		refresh();
		delay (dtime);
		digitalWrite (g, LOW);
		digitalWrite (o, HIGH);
		digitalWrite (y, HIGH);
		digitalWrite (r, LOW);
		printw ("Orange & Yellow ON\n");
		refresh();
		if ( key == 'q' )
			break;
	} 
	
	digitalWrite (g, LOW);	
	digitalWrite (o, LOW);	
	digitalWrite (y, LOW);	
	digitalWrite (r, LOW);	
	endwin();
	return 0;
}
