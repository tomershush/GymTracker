#pragma once
#include "Excercise.h"
class Set
{
private:
	Excercise* _excercises;
	int _repetitions;
	int _excerciseNum;

public:

	Set();
	Set(const int repetitions);
	~Set();

	void operator=(const Set& other);

	Excercise* getExcercises() const;
	int getRepetitions() const;
	int getExcerciseNum() const;

	void setExcercises(Excercise* excercises, int len);
	void setRepetitions(const int repetitions);


	void addExcercise(const Excercise excercise);

	std::string toString() const;
};

