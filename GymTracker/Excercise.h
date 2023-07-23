#pragma once
#include "pch.h"
class Excercise
{
private:
	std::string _name;
	int _repetitions;

public:
	Excercise();
	Excercise(const std::string& name, int repetitions);
	~Excercise();

	std::string getName() const;
	int getRepetitions() const;

	void setName(const std::string name);
	void setRepetitions(const int repetitions);
	
	void operator=(const Excercise& other);

	std::string toString() const;


};

