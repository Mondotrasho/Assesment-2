#ifndef _SCORE_H_
#define _SCORE_H_
#include <vector>

class Score
{
private:
	//variables we care about
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

#endif
