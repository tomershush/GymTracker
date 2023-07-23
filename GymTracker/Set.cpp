#include "Set.h"

Set::Set()
{
	_excercises = nullptr;
	_excerciseNum = 0;
	_repetitions = 0;
}

Set::Set(const int repetitions)
{
	_repetitions = repetitions;
	_excerciseNum = 0;
	_excercises = nullptr;
}

Set::~Set()
{
	if (_excercises != nullptr && _excerciseNum != 0)
		delete[] _excercises;

	_excercises = nullptr;
}

void Set::operator=(const Set& other)
{


	this->setRepetitions(other.getRepetitions());
	this->setExcercises(other.getExcercises(), other.getExcerciseNum());

}

Excercise* Set::getExcercises() const
{
	return _excercises;
}

int Set::getRepetitions() const
{
	return _repetitions;
}

int Set::getExcerciseNum() const
{
	return _excerciseNum;
}

void Set::setExcercises(Excercise* excercises, const int len)
{
	delete[] _excercises;
	_excercises = nullptr;

	if (len == 0 || excercises == nullptr)
	{
		_excercises = nullptr;
		_excerciseNum = 0;
	}
	else
	{
		_excercises = new Excercise[len];
		_excerciseNum = len;

		for (int i = 0; i < len; i++)
			_excercises[i] = excercises[i];
	}
}

void Set::setRepetitions(const int repetitions)
{
	_repetitions = repetitions;
}


void Set::addExcercise(const Excercise excercise)
{
	_excerciseNum++;
	Excercise* temp = new Excercise[_excerciseNum];

	for (int i = 0; i < _excerciseNum - 1; i++)
		temp[i] = _excercises[i];

	temp[_excerciseNum - 1] = excercise;
	delete[] _excercises;

	_excercises = temp;
}

std::string Set::toString() const
{
	std::string excerciseList = "";

	for (int i = 0; i < _excerciseNum; i++)
		excerciseList += std::to_string(i + 1) + ". " + _excercises[i].toString() + "\n";

	return "Number of excercises in Set: " + std::to_string(_excerciseNum) + "\n" + "Number of repetitions for set: " + std::to_string(_repetitions) + "\n" + excerciseList + '\n';
}
