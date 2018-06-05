#ifndef _SORTSTUFF_H_
#define _SORTSTUFF_H_

//Predicates for sorting Scoreboard Scores

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


#endif