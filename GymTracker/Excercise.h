#pragma once
#include "pch.h"
class Excercise
{
private:
	std::string _name;
	int _reps;

public:
	Excercise();
	Excercise(const std::string& name, int reps);
	~Excercise();

	std::string getName() const;
	int getReps() const;

	void setName(const std::string name);
	void setReps(const int reps);
	
	void operator=(const Excercise& other);

	std::string toString() const;


};

