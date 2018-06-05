#ifndef _HEADER_H_
#define _HEADER_H_
#include <vector>

class Score
{
private:
	std::string m_name;
	int m_points;
	int m_time;
public:
	
	Score();
	~Score();
	//get
	int get_time()const;
	int get_points()const;
	const std::string& get_name()const;
	//set
	void set_time(const int& new_time);
	void set_points(const int& new_points);
	void set_name(const std::string& new_name);
	};

class Scoreboard
{private:
	std::string m_title_col_1, m_title_col_2, m_title_col_3, m_sort_col_1, m_sort_col_2, m_sort_col_3; // NAME    POINTS    TIME   and sort are arrows pointing to what you are sorting by etc
	std::vector<Score> m_table; //stores players scores
	bool m_chosen = 0; //used as a loop condition
	int m_key = 0; //stores the keyboard input as int
	int m_selection = 1; //indicates which menu atribute you have selected
public:
	Scoreboard();
	~Scoreboard();
	void populate_scores(); //fill vector
	void print(); //print current state of the m_table Vector
	void sort_scores(const int& choice); //sort scores  by name alpha betically by Points numerically or time numerically
	std::string sortMode();
	int getselection()const;
	void setselection();
};
#endif
