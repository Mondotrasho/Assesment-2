#include "Keyinput.h"
#include <conio.h>
#include "Scoreboard.h"
#include <iostream>
#include <algorithm>

using namespace std;

Scoreboard::Scoreboard()
{
	//column names and visual selection characters
	m_title_col_1 = "USER";
	m_title_col_2 = "SCORE";
	m_title_col_3 = "TIME";
	m_sort_col_1 = "^^^^--------------------";
	m_sort_col_2 = "----------^^^^----------";
	m_sort_col_3 = "--------------------^^^^";
	//table that stores all of the contained scores
	std::vector<Score> m_table;
}
Scoreboard::~Scoreboard() = default;


std::string Scoreboard::sortMode() const // Function outputs the correct arrow to indicate what is being sorted by THIS IS FOR COUT not sorting 
{
	switch (m_selection)
	{
	case 1: return m_sort_col_1;
		break;
	case 2: return m_sort_col_2;
		break;
	case 3: return m_sort_col_3;
		break;
	default:
		return m_sort_col_1;
	}
}

void Scoreboard::print() //prints the table of scores and the titles for each column
{//print ordered as is
	//catagories

	cout << m_title_col_1 << dash4
		<< m_title_col_2 << dash4
		<< m_title_col_3 << endl;

	//for loop to print the table of Scores
	for (auto& score : m_table) {
		std::cout
			<< score.get_name() << dash5
			<< score.get_points() << dash5
			<< score.get_time()
			<< std::endl;


	}
	cout << sortMode() << endl; //CALL ME TO DISPLAY WHAT IT IS BEING SORTED BY UNDER THE TABLE
}
#include "Sortstuff.h"


void Scoreboard::sort_scores(const int &choice) //function takes an int and chooses the coresponding method to sort the m_table vector
{
	switch (choice)
	{
	case 1:
		std::sort(m_table.begin(), m_table.end(), sortAlpha); //sort using predicate for names
		break;
	case 2:
		std::sort(m_table.begin(), m_table.end(), sortPoints); //sort using predicate for points
		break;
	case 3:
		std::sort(m_table.begin(), m_table.end(), sortTime); //sort using predicate for time
		break;
	}
}
void Scoreboard::populate_scores() //fill score board
{
	for (int i = 0; i <= 15; i++) {
		m_table.push_back(Score()); //call constructor push into vector
	}
}
int Scoreboard::getselection() const { return m_selection; } //getter
void Scoreboard::setselection()
{

	//use arrow keys as input calls other function to do work such as sorting of change what it will print you as sorting
	//relies heavily on Keyinput.h

	// best reference http://www.lagmonster.org/docs/DOS7/v-ansi-keys.html
	// more http://www.cplusplus.com/forum/beginner/5136/
	// unicode/ascii characters https://stackoverflow.com/a/16510089
	//list of characters https://msdn.microsoft.com/en-us/library/6aw8xdf2.aspx

	m_chosen = 0;
	while (m_chosen == 0)
	{
		m_key = getch(); //IMPORTANT BELOW VVVV
						 //getch() for characters needs to be called twice as the key codes for arrows are two part 224 to show it an arrow 75 for specif key etc
						 //keyboard input switch to cycle through sort
		switch ((m_key = getch())) { //get char using conio header
		case KEY_RIGHT:
			m_selection++;
			m_chosen = true;
			break;
		case KEY_LEFT:
			m_selection--;
			m_chosen = true;
			break;
		}

		//Clamps selection
		if (m_selection < 1) {
			m_selection = 1;
		}
		if (m_selection > 3) {
			m_selection = 3;
		}
	}
}