#include <iostream>
#include <windows.h>
#include <string.h>

#include "Header.h"
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

void Scoreboard::print()
{
	std::cout << "SCORES GO HERE" << std::endl;
}
void Scoreboard::sort_scores(int choice)
{
	//Sorting algorythm goes here
}


int main() {
	Scoreboard scoreboard;
	int choice = 0;

	while (1) {
		
		if (GetAsyncKeyState(1)) { choice = 1; }
		if (GetAsyncKeyState(2)) { choice = 2; }
		if (GetAsyncKeyState(3)) { choice = 3; }

			scoreboard.sort_scores(choice);
			scoreboard.print();
	}
	return 0;
}