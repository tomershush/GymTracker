#pragma once
#include "set.h"
class Session
{
private:
	std::string _date;
	std::string _name;
	Set _set;

public:
	Session();
	Session(const std::string& name, const std::string& date, const Set& set);
	~Session();

	std::string getName() const;
	std::string getDate() const;
	Set getSet() const;

	void setName(const std::string& name);
	void setDate(const std::string& date);
	void setSessionSet(const Set& set);


	Session& operator=(const Session& other);

	std::string toString() const;

};

