//Homework 2
//AERSP 424
//Megan O'Brien - Collaboration with/Assistance from Gabby Hontz and Serin Santhosh

//I started this homework by having different solutions and files for each question
//but that was too much so now I am just putting everything into this folder and solution


#include <iostream>
#include <map>
#include <vector>
#include <random>
#include <string>
#include "hw2classes.h"


using namespace std;

//QUESTION 3 (implementations of Q2 stuff)

//All get functions return the value of their variable
double Plane::getpos()
{
	return pos;
};

double Plane::getvel()
{
	return vel;
};

double Plane::getloiter_time()
{
	return loiter_time;
};

string Plane::getorigin()
{
	return origin;
};

string Plane::getdestination()
{
	return destination;
};

bool Plane::getat_SCE()
{
	return at_SCE;
};


//All set functions set the value of their variable based on input
void Plane::setvel(double x)
{
	vel = x;
};

void Plane::setloiter_time(double y)
{
	loiter_time = y;
};

//Constructor that stores "from" as "origin", "to" as "destination",
//sets value of distance to distance between origin and destination,
//and initializes values
Plane::Plane(string from, string to)
{
	origin = from;
	destination = to;

	flights[make_pair("SCE", "PHL")] = 160;
	flights[make_pair("SCE", "ORD")] = 640;
	flights[make_pair("SCE", "EWR")] = 220;
	distance = flights[make_pair(origin, destination)];

	pos = 0;
	vel = 0;
	wait_time = 0;
	loiter_time = 0;
	at_SCE = 0;
};

//Deconstructor with implementation empty
Plane::~Plane() {};

//Operate function that contains given flowchart
void Plane::operate(double dt)
{
	if (loiter_time != 0)
	{
		loiter_time -= dt;
	}
	else if (wait_time != 0)
	{
		wait_time -= dt;
	}
	else if (pos < distance)
	{
		pos += vel * dt;
		at_SCE = 0;
	}
	else if (destination == "SCE")
	{
		at_SCE = 1;
		time_on_ground();
		swap(origin, destination);
		pos = 0.0;
	}
	else
	{
		time_on_ground();
		swap(origin, destination);
		pos = 0.0;
	};

};

double Plane::distance_to_SCE()
{
	if (destination == "SCE")
	{
		return (distance - pos);
	}
	else
	{
		return 0;
	}
};

string Plane::plane_type()
{
	return "GA";
};

double Plane::time_on_ground()
{
	return 0;
};

double Plane::draw_from_normal_dist(double mean, double standard_deviation)
{
	random_device rd{};
	mt19937 gen{ rd() };
	normal_distribution<> d{ mean,standard_deviation };
	return d(gen);
};


//QUESTION 4 (implementation)

//Implementations from Airliner class
Airliner::Airliner(string Airline, string from, string to) : Plane(from, to), Airline(Airline) {};

Airliner :: ~Airliner() {};

string Airliner::plane_type()
{
	return Airline;
};

double Airliner::time_on_ground()
{
	return draw_from_normal_dist(1800, 600);
};


//Implementations from GeneralAviation class
GeneralAviation::GeneralAviation(string from, string to) : Plane(from, to) {};

GeneralAviation :: ~GeneralAviation() {};

double GeneralAviation::time_on_ground()
{
	return draw_from_normal_dist(600, 60);
};




int main()
{

	//QUESTION 1 (create container)
	
	//Use map to contain the flight locations (departure and arrival locations)
	//and distance between locations
	//Using map because the keys should only have one valid value for flight 
	//distance i.e. there should be no duplicate keys

	//map< pair< departure location, arrival location >, distance  >
	map< pair<string, string>, int > flights;
	flights[make_pair("SCE", "PHL")] = 160;
	flights[make_pair("SCE", "ORD")] = 640;
	flights[make_pair("SCE", "EWR")] = 220;

};