#pragma once
#include "Excercise.h"
class Set
{
private:
	Excercise* _exces;
	int _reps;
	int _numOfExces;

public:

	Set();
	Set(const int repetitions);
	~Set();

	void operator=(const Set& other);

	Excercise* getExces() const;
	int getReps() const;
	int getNumOfExces() const;

	void setExces(Excercise* exces, int len);
	void setReps(const int reps);


	void addExc(const Excercise exc);

	std::string toString() const;
};

