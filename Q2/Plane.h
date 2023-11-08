#pragma once

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <random>

class Plane
{
public:

//Constructor that takes in two strings "from" and "to" as input arguments
	Plane(const string from, const string to);

//Virtual deconstructor
	virtual ~Plane();

//Function named operate with double variables "dt" as input, return nothing
	void operate(double dt);

//Get functions
	double getpos();
	double getvel();
	double getloiter_time();
	string getorigin();
	string getdestination();
	bool getat_SCE();

//Set functions
	void setvel(double);
	void setloiter_time(double);

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
	map< pair<string, string>, int> flights;

protected:

//Double variable named "wait_time"
	double wait_time;
};
