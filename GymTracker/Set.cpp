#include "Set.h"

Set::Set()
{
	_exces = nullptr;
	_numOfExces = 0;
	_reps = 0;
}

Set::Set(const int repetitions)
{
	_reps = repetitions;
	_numOfExces = 0;
	_exces = nullptr;
}

Set::~Set()
{
	if (_exces != nullptr && _numOfExces != 0)
		delete[] _exces;

	_exces = nullptr;
}

void Set::operator=(const Set& other)
{


	this->setReps(other.getReps());
	this->setExces(other.getExces(), other.getNumOfExces());

}

Excercise* Set::getExces() const
{
	return _exces;
}

int Set::getReps() const
{
	return _reps;
}

int Set::getNumOfExces() const
{
	return _numOfExces;
}

void Set::setExces(Excercise* exces, const int len)
{
	delete[] _exces;
	_exces = nullptr;

	if (len == 0 || exces == nullptr)
	{
		_exces = nullptr;
		_numOfExces = 0;
	}
	else
	{
		_exces = new Excercise[len];
		_numOfExces = len;

		for (int i = 0; i < len; i++)
			_exces[i] = exces[i];
	}
}

void Set::setReps(const int reps)
{
	_reps = reps;
}


void Set::addExc(const Excercise exc)
{
	_numOfExces++;
	Excercise* temp = new Excercise[_numOfExces];

	for (int i = 0; i < _numOfExces - 1; i++)
		temp[i] = _exces[i];

	temp[_numOfExces - 1] = exc;
	delete[] _exces;

	_exces = temp;
}

std::string Set::toString() const
{
	std::string excerciseList = "";

	for (int i = 0; i < _numOfExces; i++)
		excerciseList += std::to_string(i + 1) + ". " + _exces[i].toString() + "\n";

	return "Number of excercises in Set: " + std::to_string(_numOfExces) + "\n" + "Number of repetitions for set: " + std::to_string(_reps) + "\n" + excerciseList + '\n';
}
