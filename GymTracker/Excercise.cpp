#include "Excercise.h"

Excercise::Excercise()
{
	_name = "";
	_repetitions = 0;
}

Excercise::Excercise(const std::string& name, int repetitions)
{
	_name = name;
	_repetitions = repetitions;
}

Excercise::~Excercise()
{
}

std::string Excercise::getName() const
{
	return _name;
}

int Excercise::getRepetitions() const
{
	return _repetitions;
}

void Excercise::setName(const std::string name)
{
  _name = name;
}

void Excercise::setRepetitions(const int repetitions)
{
	_repetitions = repetitions;
}



Excercise& Excercise::operator=(const Excercise& other)
{
	this->setName(other.getName());
	this->setRepetitions(other.getRepetitions());

	return *this;
}

std::string Excercise::toString() const
{
	return "Excercise name: " + _name + "\n" + "Excercise repetitions: " + std::to_string(_repetitions) + '\n';
}
