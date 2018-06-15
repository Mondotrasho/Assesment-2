#ifndef _TESTDATA_H_
#define _TESTDATA_H_
//###############TEST DATA
//this purely exists to test against
//Includes a vector full of random 4 character names -> names
//

static std::vector<std::string> names = { "Oscr","Stew","Cath","Ryan","Bobi","Liam","Greg","Darc","Caly","Ding","Gudg","Rich","Zack","Matt","Timm" }; //names to pick from
int vecRange = names.size(); // returns the number of names in the names vector

std::string randname() //selects a random name 
{
	return names[rand() % vecRange]; //rand within the range of the size of the names vector using vecRange var
}
int randpoints() //selects a random amount of points
{
	int val = rand() % 999; //rand within 1-999
	return val;
}
int randtime()//selects a random time
{
	int  val = rand() % 300; //rand within 1 -300
	return val;
}


//######TEST DATA
#endif

