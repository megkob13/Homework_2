#pragma once

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <random>

using namespace std;


//QUESTION 2 (creating class)
class Plane
{
public:

	//Constructor that takes in two strings "from" and "to" as input arguments
	Plane(const string& from, const string& to);

	//Virtual deconstructor
	virtual ~Plane();

	//Function named operate with double variables "dt" as input, return nothing
	void operate(double dt);

	//Get functions
	double getpos() const;
	double getvel() const;
	double getloiter_time() const;
	string getorigin() const;
	string getdestination() const;
	bool getat_SCE() const;

	//Set functions
	void setvel(double x);
	void setloiter_time(double y);

	//Function named "distance_to_SCE" that returns double
	double distance_to_SCE();

	//Virtual functions
	virtual double time_on_ground();
	virtual string plane_type();

	//Static function named "draw_from_normal_dist" that takes in two
	//double variables (mean and standard deviation), and returns back
	//a random number from a normal distribution
	static double draw_from_normal_dist(double mean, double standard_deviation);

private:

	//Double variables named "pos", "vel", "distance", and "loiter_time"
	double pos;
	double vel;
	double distance;
	double loiter_time;

	//Boolean variable named "at_SCE"
	bool at_SCE;

	//String variables named "origin" and "destination"
	string origin;
	string destination;

	//Container from Question 1
	map< string, map<string,int> > flights;

protected:

	//Double variable named "wait_time"
	double wait_time;
};


//QUESTION 4 (creating classes)
class Airliner : public Plane
{
public:

	//Constructor that takes in three strings as input arguments
	Airliner(const string& Airline, const string& from, const string& to);

	//Empty deconstructor
	virtual ~Airliner();

	//Overridden function "plane_type" that returns "Airline"
	virtual string plane_type() override;

	//Overridden function "time_on_ground" that returns "wait_time"
	virtual double time_on_ground() override;


private:

	string Airline;

};

class GeneralAviation :public Plane
{
public:

	//Constructor that takes in two strings as input arguments
	GeneralAviation( const string& from, const string& to);

	//Empty deconstructor
	~GeneralAviation();

	//Overridden function "time_on_ground" that returns "wait_time"
	virtual double time_on_ground() override;

};


//QUESTION 6 (create class ATC)
class ATC
{
public:

	//Empty constructor
	ATC();

	//Empty deconstructor
	~ATC();

	//Function "register_plane" that takes in airplane object to store in container
	void register_plane(Plane* aircraft);

	//Function "control_traffic" that contains flowchart
	void control_traffic();

	//Get function for registered planes to use in while(true) loop
	vector<Plane*> getregistered_planes()
	{
		return registered_planes;
	};

private:

	//Container to store plane objects
	vector <Plane*> registered_planes;

	//Positive integers
	const int MAX_LANDED_PLANE_NUM = 2;
	const int AIRSPACE_DISTANCE = 50;

};