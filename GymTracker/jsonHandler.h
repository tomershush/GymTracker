#pragma once
#include "pch.h"
#include "Session.h"


#define EX_JSON_TEMPLATE "{\"name\": \"{}\", \"repetitons:\":{}}"

class jsonHandler
{
public:
	static std::string createExcerciseJson(const Excercise& ex);
	static std::string createSetJson(const Set& set);
	static std::string createSessionJson(const Session& ses);

	static Excercise getExcerciseFromJson(const std::string& exJson);
	static Set getSetFromJson(const std::string& setJson);
	static Session getSessionFromJson(const std::string& sesJson);
};

