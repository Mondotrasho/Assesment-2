#include <string>
#include <iostream>
#include <windows.h>
#include <algorithm>

#include "Header.h"

using namespace std;
Score::Score()
{
		m_name = "Bob";
		m_points = 500;
		m_time = 1000;
}
Score::~Score() = default;

std::string Score::get_name()
{
	return m_name;
};

void Score::set_name(std::string new_name)
{
	m_name = new_name;
};

int  Score::get_points()
{
	return m_points;
}
void Score::set_points(int new_points)
{
	m_points = new_points;
}
int  Score::get_time()
{
	return m_time;
}
void Score::set_time(int new_time)
{
	m_time = new_time;
}
Scoreboard::Scoreboard()
{
	m_title_col_1 = "hey";
	m_title_col_2 = "hey";
	m_title_col_3 = "hey";
	std::vector<Score> m_table;
}
Scoreboard::~Scoreboard() = default;
void Scoreboard::print()
{//print ordered as is
	for (int i = 0; i <= 15; i++) {
		std::cout
			<< m_table[i].get_name()
			<< m_table[i].get_points()
			<< m_table[i].get_time()
			<< std::endl;
}	
}
void Scoreboard::sort_scores(int choice)
{
	//Sorting algorythm goes here
	switch(choice)
	{
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	}
}
void Scoreboard::populate_scores()
{
	for (int i = 0; i <= 15; i++) {
		m_table.push_back(Score());
	}
}

int main() {
	Scoreboard scoreboard;
	int choice = 0;
	
	
	while (1) {
		scoreboard.populate_scores();
		if (GetAsyncKeyState(1)) { choice = 1; }
  		if (GetAsyncKeyState(2)) { choice = 2; }
 		if (GetAsyncKeyState(3)) { choice = 3; }
		cout << "press 1 to sort alphabetically 2 to sort by score and 3 to sort by time" << endl;
 			scoreboard.sort_scores(choice);
			system("cls");
			scoreboard.print();

	}
	return 0;
}