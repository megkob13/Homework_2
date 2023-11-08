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
	//and distance between locations

	//Using map because the keys should only have one valid value for flight 
	//distance i.e. there should be no duplicate keys

	//map< pair< departure location, arrival location >, distance  >
	map< pair<string, string>, int > flights;
	flights[make_pair("SCE", "PHL")] = 160;
	flights[make_pair("SCE", "ORD")] = 640;
	flights[make_pair("SCE", "EWR")] = 220;


}