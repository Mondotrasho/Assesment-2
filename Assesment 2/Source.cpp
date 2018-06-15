#include "Scoreboard.h"
void main() {
	
	Scoreboard scoreboard; //new scoreboard
	scoreboard.populate_scores(); // Fill the scoreboard
	while (1) { //infinite loop	
		//	print
		system("cls"); //at the start of each "frame" clear the console
		scoreboard.print(); // print the current state to console
		//	Input
		scoreboard.setselection(); //let the user change the state
		scoreboard.sort_scores(scoreboard.getselection()); // do work based on changes
	}
}
