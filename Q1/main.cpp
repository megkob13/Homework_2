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
	//Use multimap to contain the flight locations (takeoff and departure locations)
	//as well as distance and unit of distance for the flight

	multimap< pair<string, string>, pair<int, string> > flights;
	flights.insert (make_pair (make_pair("SCE", "PHL"), make_pair(160, "mi")));
	flights.insert (make_pair (make_pair("SCE", "ORD"), make_pair(640, "mi")));
	flights.insert (make_pair (make_pair("SCE", "EWR"), make_pair(220, "mi")));

}