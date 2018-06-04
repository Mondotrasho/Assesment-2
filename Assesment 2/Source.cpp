#include <string>
#include <iostream>
#include <windows.h>
#include <algorithm>
#include <random>
#include "Header.h"



//###############TEST DATA
static std::vector<std::string> names;



std::string randname()
{
	return names[rand() % 14];
}
int randpoints()
{
	int val = rand() % 999;
	return val;
}
int randtime()
{
	int  val = rand() % 300;
	return val;
}


//######TEST DATA
using namespace std;
Score::Score()
{
	m_name = randname();//boop1;//"Bob";
	m_points = randpoints();// 500;
	m_time = randtime();//1000;
}
Score::~Score() = default;

std::string Score::get_name()
{
	return m_name;
};

void Score::set_name(const std::string &new_name)
{
	m_name = new_name;
};

int  Score::get_points()
{
	return m_points;
}
void Score::set_points(const int &new_points)
{
	m_points = new_points;
}
int  Score::get_time()
{
	return m_time;
}
void Score::set_time(const int &new_time)
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
 /*	for (int i = 0; i <= 15; i++) {
		std::cout
			<< m_table[i].get_name()
			<< m_table[i].get_points()
			<< m_table[i].get_time()
			<< std::endl;
}	*/
}
auto sortAlpha = [](Score& first, Score& last) //predicate for sort take 2 monster bits sort names
{
	return  first.m_name < last.m_name; //compare first name to second smallest (a) to largest (z)   hence <
};

auto sortPoints = [](Score& first, Score& last) //predicate for points
{
	return  first.m_points > last.m_points; //compare first Points to second largest (99999999) to smallest (-999999) hence >
};

auto sortTime = [](Score& first, Score& last) //predicate for time
{
	return  first.m_time < last.m_time; //compare first time to second smallest (-99999999) to largest  (999999) hence >
};

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

//sortVV


int main() {
	names = { "oscar","stew","cath","ryan","bob","liam","greg","darcy","cal","dingle","roger","richard","zack","matt","timw" };
	Scoreboard scoreboard;
	int choice = 0;

	

	while (1) {
		scoreboard.populate_scores();
	//	if (GetAsyncKeyState(1)) { choice = 1; }
	//	if (GetAsyncKeyState(2)) { choice = 2; }
	//	if (GetAsyncKeyState(3)) { choice = 3; }
	//	cout << "press 1 to sort alphabetically 2 to sort by score and 3 to sort by time" << endl;
	//	scoreboard.sort_scores(choice);
		system("cls");
	//	scoreboard.print();
		scoreboard.print();
		scoreboard.sort_scores(2);
		system("cls");
		scoreboard.print();
		system("pause");
	}

	return 0;
}