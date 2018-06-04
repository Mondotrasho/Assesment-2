#ifndef _HEADER_H_
#define _HEADER_H_
#include <vector>

class Score
{
private:
	
public:
	std::string m_name;
	int m_points;
	int m_time;
	Score();
	~Score();
	//get
	int get_time();
	int get_points();
	std::string get_name();
	//set
	void set_time(const int& new_time);
	void set_points(const int& new_points);
	void set_name(const std::string& new_name);
	};

class Scoreboard
{private:
	std::string m_title_col_1, m_title_col_2, m_title_col_3; // NAME    POINTS    TIME    etc
	std::vector<Score> m_table; //stores players scores
public:
	Scoreboard();
	~Scoreboard();
	void populate_scores(); //fill vector
	void print(); //print current state of the m_table Vector
	void sort_scores(const int& choice); //sort scores  by name alpha betically by Points numerically or time numerically
};
#endif
