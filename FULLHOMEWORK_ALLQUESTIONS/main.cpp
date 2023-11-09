//Homework 2
//AERSP 424
//Megan O'Brien 

//Collaboration with/Assistance from Gabby Hontz, Serin Santhosh, Cece Erndwein, Nicole Collum

//I started this homework by having different solutions and files for each question
//but that was too much so now I am just putting everything into this folder and solution


#include <iostream>
#include <map>
#include <vector>
#include <random>
#include <string>
#include "hw2classes.h"
#include "HW2_Visualizer.h"


using namespace std;

//QUESTION 3 (implementations of Q2 stuff)

//All get functions return the value of their variable
double Plane::getpos() const
{
	return pos;
};

double Plane::getvel() const
{
	return vel;
};

double Plane::getloiter_time() const
{
	return loiter_time;
};

string Plane::getorigin() const
{
	return origin;
};

string Plane::getdestination() const
{
	return destination;
};

bool Plane::getat_SCE() const
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
Plane::Plane(const string& from, const string& to)
{
	origin = from;
	destination = to;

	flights["SCE"]["PHL"] = 160;
	flights["SCE"]["ORD"] = 640;
	flights["SCE"]["EWR"] = 220;
	distance = flights[origin][destination]; 

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
Airliner::Airliner(const string& Airline, const string& from, const string& to) : Plane(from, to), Airline(Airline) {};

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
GeneralAviation::GeneralAviation(const string& from, const string& to) : Plane(from, to) {};

GeneralAviation :: ~GeneralAviation() {}; 

double GeneralAviation::time_on_ground()
{
	return draw_from_normal_dist(600, 60);
};

//QUESTION 6 (implementation of Q6 stuff)

ATC::ATC() {};
ATC::~ATC() {};
void ATC::register_plane(Plane* aircraft)
{
	registered_planes.push_back(aircraft);
};

//Using flowchart given for Q6
void ATC::control_traffic()
{
	int landed_planes = 0;
	int i = 0;
	int registered_planes_num = registered_planes.size();

	if (i < registered_planes_num)
	{
		landed_planes += registered_planes[i]->getat_SCE();
		i++;
	}
	else if (landed_planes >= MAX_LANDED_PLANE_NUM)
	{
		i = 0;
		if (i < registered_planes_num)
		{
			if (registered_planes[i]->getat_SCE() == 0 && registered_planes[i]->distance_to_SCE() <= ATC::AIRSPACE_DISTANCE && registered_planes[i]->getloiter_time() == 0)
			{
				registered_planes[i]->setloiter_time(100);
				i++;
			}
		}
	}

}




int main( int argc, char** argv)
{
	HW2_VIZ viz;

	//QUESTION 1 (create container)
	
	//Use map to contain the flight locations (departure and arrival locations)
	//and distance between locations
	//Using map because the keys should only have one valid value for flight 
	//distance i.e. there should be no duplicate keys

	//map< departure location, map< arrival location, distance > >
	map< string, map<string,int> > flights;
	flights["SCE"]["PHL"] = 160;
	flights["SCE"]["ORD"] = 640;
	flights["SCE"]["EWR"] = 220;


	//QUESTION 5 (instantiating objects that represent aircraft)

	//Instantiate flight info with details from table
	Airliner American_AA5915_5918("AA", "SCE", "PHL");
	Airliner United_UA5236_5331("UA", "SCE", "ORD");
	Airliner United_UA4465_4511("UA", "SCE", "EWR");
	Airliner American_AA6240_6241("AA", "SCE", "ORD");
	GeneralAviation GA_1("SCE", "PHL");
	GeneralAviation GA_2("SCE", "EWR");
	GeneralAviation GA_3("SCE", "ORD");

	//Use set function to set speed (NEED MILES PER SECOND NOT MPH)
	American_AA5915_5918.setvel(470 * .00027778);
	United_UA5236_5331.setvel(515 * .00027778);
	United_UA4465_4511.setvel(480 * .00027778);
	American_AA6240_6241.setvel(500 * .00027778);
	GA_1.setvel(140 * .00027778);
	GA_2.setvel(160 * .00027778);
	GA_3.setvel(180 * .00027778);

	

	//QUESTION 7 (instantiate object atc)
	ATC atc;
	atc.register_plane(&American_AA5915_5918);
	atc.register_plane(&United_UA5236_5331);
	atc.register_plane(&United_UA4465_4511);
	atc.register_plane(&American_AA6240_6241);
	atc.register_plane(&GA_1);  
	atc.register_plane(&GA_2);  
	atc.register_plane(&GA_3);  

	//Create while(true) statement (need to set timestep)
	double dt = 100;
	double time = 0;

	while (time < 28800) //28800 seconds for 8 hour simulation
	{
		//Call operate function for each flight
		for (Plane* aircraft : atc.getregistered_planes())
		{
			aircraft->operate(dt);
			atc.control_traffic();

			//QUESTION 8 (comment out all cout and add visualize)
			
			//cout << "Time: " << time << " seconds" << endl;
			//cout << "Position of " << aircraft->plane_type() << " between " << aircraft->getorigin() << " and " << aircraft->getdestination() << ":" << endl;
			//cout << aircraft->getpos() << " miles" << endl;
			//cout << endl;

			viz.visualize_plane(aircraft->plane_type(), aircraft->getorigin(), aircraft->getdestination(), aircraft->getpos());

			viz.update(dt);
		}

		time += dt;
	};
	return 0;
};