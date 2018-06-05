#ifndef _TESTDATA_H_
#define _TESTDATA_H_
//###############TEST DATA
static std::vector<std::string> names;

std::string randname() //selects a random name 
{
	return names[rand() % 14];
}
int randpoints() //selects a random amount of points
{
	int val = rand() % 999;
	return val;
}
int randtime()//selects a random time
{
	int  val = rand() % 300;
	return val;
}


//######TEST DATA
#endif

