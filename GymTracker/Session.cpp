#include "Session.h"

Session::Session()
{
	_name = "";
	_date = "1/1/2000";
	_set = Set();
}

Session::Session(const std::string& name, const std::string& date, const Set& set)
{
	_name = name;
	_date = date;
	_set = set;
}

Session::~Session()
{
	_set.~Set();
}

std::string Session::getName() const
{
	return _name;
}

std::string Session::getDate() const
{
	return _date;
}

Set Session::getSet() const
{
	Set tempSet;
	tempSet = _set;
	return tempSet;
}

void Session::setName(const std::string& name)
{
	_name = name;
}

void Session::setDate(const std::string& date)
{
	_date = date;
}

void Session::setSessionSet(const Set& set)
{
	_set = set;
}

void Session::operator=(const Session& other)
{
	this->setName(other.getName());
	this->setDate(other.getDate());
	this->setSessionSet(other.getSet());
}

std::string Session::toString() const
{
	return "Session name: " + _name + '\n' + "Session date: " + _date + '\n' + _set.toString();
}
