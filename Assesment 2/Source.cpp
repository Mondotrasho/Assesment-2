#include <string>
#include <iostream>
#include <windows.h>
#include <algorithm>
#include <random>
#include "Header.h"
#include "Testdata.h"
#include <conio.h>
#include "keyinput.h"

using namespace std;
Score::Score():m_name(randname()),m_points(randpoints()),m_time(randtime()){}
Score::~Score() = default;

const std::string& Score::get_name() const 
{
	return m_name;
};

void Score::set_name(const std::string &new_name)
{
	m_name = new_name;
};

int  Score::get_points() const 
{
	return m_points;
}
void Score::set_points(const int &new_points)
{
	m_points = new_points;
}
int  Score::get_time() const
{
	return m_time;
}
void Score::set_time(const int &new_time)
{
	m_time = new_time;
}
Scoreboard::Scoreboard()
{
	m_title_col_1 = "USER";
	m_title_col_2 = "SCORE";
	m_title_col_3 = "TIME";
	m_sort_col_1 = "^^^^--------------------";
	m_sort_col_2 = "----------^^^^----------";
	m_sort_col_3 = "--------------------^^^^";
	std::vector<Score> m_table;
}
std::string Scoreboard::sortMode()
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
Scoreboard::~Scoreboard() = default;
void Scoreboard::print()
{//print ordered as is

	cout << m_title_col_1 << dash4
		<< m_title_col_2  << dash4
		<< m_title_col_3 << endl;

	for (auto& score : m_table){
		std::cout
			<< score.get_name()   << dash5
			<< score.get_points() << dash5
			<< score.get_time()
			<< std::endl;
		
		
	}
	cout << sortMode() << endl;
}
#include "Sortstuff.h"


void Scoreboard::sort_scores(const int &choice)
{
	//Sorting algorythm goes here
 	switch(choice)
	{
	case 1:
		std::sort(m_table.begin(), m_table.end(),sortAlpha);
		break;
	case 2:
		std::sort(m_table.begin(), m_table.end(), sortPoints);
		break;
	case 3:
		std::sort(m_table.begin(), m_table.end(), sortTime);
		break;
	}
}
void Scoreboard::populate_scores()
{
	for (int i = 0; i <= 15; i++) {
		m_table.push_back(Score()); //cal constructor push into vector
	}
}
int Scoreboard::getselection() const { return m_selection; }
void Scoreboard::setselection()
{

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
				//cout << endl << "Up" << endl;//key up
				m_selection++;
				m_chosen = 1;
				break;
			case KEY_LEFT:
				//cout << endl << "Down" << endl;   // key down
				m_selection--;
				m_chosen = 1;
				break;
			}

			if (m_selection < 1) {
				m_selection = 1;
			}
			if (m_selection > 3) {
				m_selection = 3;
			}
			//MENU slides
			//std::cout << sortMode() << std::endl;

		}
	}
	

int main() {
	names = { "Oscr","Stew","Cath","Ryan","Bobi","Liam","Greg","Darc","Caly","Ding","Gudg","Rich","Zack","Matt","Timm" }; //names to pick from
	Scoreboard scoreboard; //new scoreboard
	//int choice = 1; 
	scoreboard.populate_scores();



	while (1) {
	
	
	
		//	print
		system("cls");
		scoreboard.print();
		//	Input
		scoreboard.setselection();
		scoreboard.sort_scores(scoreboard.getselection());

		
	}

	return 0;
}