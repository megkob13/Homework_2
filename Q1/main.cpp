//Homework 2
//Question 1
//Design a container that stores information shown in the picture


#include <iostream>
#include <map>
#include <string>
#include <vector>



using namespace std;

int main()
{
	//Use map to contain the flight locations (departure and arrival locations)
	//as well as distance and unit of distance for the flight

	//Using map because the keys should only have one valid value for flight 
	//distance i.e. there should be no duplicate keys

	//map< pair< departure location, arrival location >, pair < distance magnitude, distance unit> >
	map< pair<string, string>, pair<int, string> > flights;
	flights.insert (make_pair ( make_pair("SCE", "PHL"), make_pair(160, "miles" )));
	flights.insert (make_pair ( make_pair("SCE", "ORD"), make_pair(640, "miles" )));
	flights.insert (make_pair ( make_pair("SCE", "EWR"), make_pair(220, "miles" )));

}