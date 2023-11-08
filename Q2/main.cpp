//Homework 2
//Question 2
//Create class named "Plane" with given class members

//CLASS CREATED IN "Plane.h"
//COPYING AND PASTING FROM FILES FROM PREVIOUS QUESTIONS TO BUILD UP FULL CODE


#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <random>
#include "Plane.h"


using namespace std;

int main()
{
	//Container from Q1
	map< pair<string, string>, pair<int, string> > flights;
	flights.insert (make_pair ( make_pair("SCE", "PHL"), make_pair(160, "miles" )));
	flights.insert (make_pair ( make_pair("SCE", "ORD"), make_pair(640, "miles" )));
	flights.insert (make_pair ( make_pair("SCE", "EWR"), make_pair(220, "miles" )));

}