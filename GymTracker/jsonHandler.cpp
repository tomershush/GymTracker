#include "jsonHandler.h"

std::string jsonHandler::createExcerciseJson(const Excercise& ex)
{
	
	return std::vformat(EX_JSON_TEMPLATE, std::make_format_args(ex.getName(), ex.getRepetitions()));
}

std::string jsonHandler::createSetJson(const Set& set)
{
	std::string exesJson = "";
	Excercise* tempExes = set.getExcercises();

	for (int i = 0; i < set.getExcerciseNum() - 1; i++)
		exesJson += jsonHandler::createExcerciseJson(tempExes[i]) + ", ";
	exesJson += createExcerciseJson(tempExes[set.getExcerciseNum() - 1]);



	return std::vformat(SET_JSON_TEMPLATE, std::make_format_args(set.getRepetitions(), set.getExcerciseNum(), exesJson));
}

std::string jsonHandler::createSessionJson(const Session& sess)
{

	return std::vformat(SESS_JSON_TEMPLATE, std::make_format_args(sess.getName(), sess.getDate(), createSetJson(sess.getSet())));
}
