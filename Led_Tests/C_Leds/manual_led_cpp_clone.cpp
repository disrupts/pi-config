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
	
	bool Gstate,Ostate,Ystate,Rstate;
	Gstate = 0;
	Ostate = 0;
	Ystate = 0;
	Rstate = 0;

	//ncurses stuff
	initscr();
	//raw();
	cbreak();
	keypad(stdscr, TRUE);
	noecho();
	printw ("Press G, O, Y, R to toggle the LEDs\n");
	printw ("Press q to quit\n");
	refresh();
	char key = '0';
	
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
		if (key == 'g' || key == 'G')
		{
			if (Gstate == 0)
			{
				printw ("Green ON\n");
				refresh();
				digitalWrite (g, HIGH);
				Gstate = 1;
			}
			else 
			{
				printw ("Green OFF\n");
				refresh();
				digitalWrite (g, LOW);
				Gstate = 0;
			}
		}
		else if (key == 'o' || key == 'O')

		{
			if (Ostate == 0)
			{
				printw ("Orange ON\n");
				refresh();
				digitalWrite (o, HIGH);
				Ostate = 1;
			}
			else
			{
				printw ("Orange OFF\n");
				refresh();
				digitalWrite (o, LOW);
				Ostate = 0;
			}
		}
		else if (key == 'y' || key == 'Y')	
		{
			if (Ystate == 0)
			{
				printw ("Yellow ON\n");
				refresh();
				digitalWrite (y, HIGH);
				Ystate = 1;
			}
			else
			{
				printw ("Yellow OFF\n");
				refresh();
				digitalWrite (y, LOW);
				Ystate = 0;
			}
		}
		else if (key == 'r' || key == 'R')
		{
			if (Rstate == 0)
			{
				printw ("Red ON\n");
				refresh();
				digitalWrite (r, HIGH);
				Rstate = 1;
			}
			else
			{
				printw ("Red OFF\n");
				refresh();
				digitalWrite (r,LOW);
				Rstate = 0;
			}
		}
		else if ( key == 'q' || key == 'Q' )
		{
			printw("Quiting!");
			refresh();
			break;
		}
		else
		{
			printw ("You pressed a button (");
			printw ("%c",key);
			printw (") that does nothing.\n\n");
			printw ("Press G, O, Y, R to toggle the LEDs\n");
			printw ("Press q to quit\n");
			refresh();
		}
	} 
	
	//end stuff
	digitalWrite (g, LOW);	
	digitalWrite (o, LOW);	
	digitalWrite (y, LOW);	
	digitalWrite (r, LOW);	
	endwin();
	return 0;
}
