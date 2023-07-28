#include "Excercise.h"

Excercise::Excercise()
{
	_name = "";
	_reps = 0;
}

Excercise::Excercise(const std::string& name, int reps)
{
	_name = name;
	_reps = reps;
}

Excercise::~Excercise()
{
}

std::string Excercise::getName() const
{
	return _name;
}

int Excercise::getReps() const
{
	return _reps;
}

void Excercise::setName(const std::string name)
{
  _name = name;
}

void Excercise::setReps(const int reps)
{
	_reps = reps;
}



void Excercise::operator=(const Excercise& other)
{
	this->setName(other.getName());
	this->setReps(other.getReps());
}

std::string Excercise::toString() const
{
	return "Excercise name: " + _name + "\n" + "Excercise repetitions: " + std::to_string(_reps) + '\n';
}
