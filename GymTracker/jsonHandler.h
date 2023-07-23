#pragma once
#include "pch.h"
#include "Session.h"


#define EX_JSON_TEMPLATE "{{\"name\":\"{}\", \"repetitons:\":{}}};"
#define SET_JSON_TEMPLATE "{{\"repetitions\":{}, \"numOfExcercises\":{}, \"excercises\":[{}]}};"
#define SESS_JSON_TEMPLATE "{{\"name\":{}, \"date\":\"{}\", \"set\":{}}};"

class jsonHandler
{
public:
	static std::string createExcerciseJson(const Excercise& ex);
	static std::string createSetJson(const Set& set);
	static std::string createSessionJson(const Session& sess);

	static Excercise getExcerciseFromJson(const std::string& exJson);
	static Set getSetFromJson(const std::string& setJson);
	static Session getSessionFromJson(const std::string& sessJson);
};

