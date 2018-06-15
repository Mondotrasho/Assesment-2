#include "Score.h"
#include "Testdata.h"

using namespace std;
Score::Score() :m_name(randname()), m_points(randpoints()), m_time(randtime()) {} //constructor currently uses values from testdata
Score::~Score() = default;

//GETTERS AND SETTERS VVVV

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

