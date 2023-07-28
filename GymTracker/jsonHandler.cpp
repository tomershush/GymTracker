#include "jsonHandler.h"

std::string jsonHandler::createExcJson(const Excercise& exc)
{
	
	return std::vformat(EX_JSON_TEMPLATE, std::make_format_args(exc.getName(), exc.getReps()));
}

std::string jsonHandler::createSetJson(const Set& set)
{
	std::string exesJson = "";
	Excercise* tempExes = set.getExces();

	for (int i = 0; i < set.getNumOfExces() - 1; i++)
		exesJson += jsonHandler::createExcJson(tempExes[i]) + ",";
	exesJson += createExcJson(tempExes[set.getNumOfExces() - 1]);



	return std::vformat(SET_JSON_TEMPLATE, std::make_format_args(set.getReps(), set.getNumOfExces(), exesJson));
}

std::string jsonHandler::createSessJson(const Session& sess)
{

	return std::vformat(SESS_JSON_TEMPLATE, std::make_format_args(sess.getName(), sess.getDate(), createSetJson(sess.getSet())));
}

std::string jsonHandler::getFieldFromJson(const std::string json, const std::string fieldName)
{
	/*
	* NOTES:
	* 1) Should remove special chars ('{', '[', ',', etc) from string input by user for correct function.
	* 2) Only works if the JSON input contains one field of the name (Won't work for nested JSONs, and it shouldn't).
	* 3) Add exceptions. Not only for JSON, but in general.
	*/
	int fieldColon = 0;	// Index of seperating colon
	int fieldComma = 0;	// Index of ending comma or semicolon.
	int fieldIndex = 0;
	int numOfBrackets = 0;
	std::string fieldVal = "";

	fieldIndex = json.find("{" + fieldName);	// Adding the curly bracket to make sure it's a field name and not simply data.


	if(fieldIndex == std::string::npos)	// In case it is not the first field.
		fieldIndex = json.find("," + fieldName);

	fieldIndex += fieldName.length() + 2; 	// Adding 2, one for bracket and one for the colon.


	if (json[fieldIndex] == '[')	// In case the value is an array.
	{
		fieldVal = json.substr(fieldIndex, bracketCounter(json.substr(fieldIndex), '[') + 1);	// Slice the array itself from the value field.
	}
	else if (json[fieldIndex] == '{')	// In case the value is an object.
	{
		fieldVal = json.substr(fieldIndex, bracketCounter(json.substr(fieldIndex), '{') + 1);	// Slice the array itself from the value field.
	}
	else
	{
		fieldVal = json.substr(fieldIndex);
		fieldComma = fieldVal.find(",");

		if (fieldComma == std::string::npos)	// Switch to bracket counting.
			fieldComma = fieldVal.find("};");

		fieldVal = fieldVal.substr(0, fieldComma);

		if (fieldVal[0] == '\"')	// In case the value is a string.
			fieldVal = fieldVal.substr(1, fieldVal.length() - 2);
	}
	return fieldVal;
}

int jsonHandler::bracketCounter(const std::string bracketedStr, const char bracketType)
{
	int closingBracketIndex = 0;
	int numOfBrackets = 0;

	for (int i = 1; i < bracketedStr.length(); i++)
	{
		if (bracketedStr[i] == bracketType)	// Count brackets.
			numOfBrackets++;
		if (bracketedStr[i] == bracketType + 2)	// Ascii conversion to ending bracket.
			numOfBrackets--;
		if (numOfBrackets == -1)	// Meaning we have found the final bracket.
		{
			closingBracketIndex = i;
			i = bracketedStr.length();	// Breaking the loop.
		}
	}

	return closingBracketIndex;
}

Excercise jsonHandler::getExcFromJson(const std::string& excJson)
{
	Excercise jsonExcercise;
	int repetitions = std::stoi(getFieldFromJson(excJson, "repetitions"));

	jsonExcercise.setName(getFieldFromJson(excJson, "name"));
	jsonExcercise.setReps(repetitions);

	return jsonExcercise;
}

/*
* TODO:
* 1) Count occurences of ';' in order to create array of exes.
* 2) Iterate over each of the exes json, creating an object.
* 3) Create the Set object.
*/
Set jsonHandler::getSetFromJson(const std::string& setJson)
{
	int repetitions = std::stoi(getFieldFromJson(setJson, "repetitions"));
	int numOfExes = std::stoi(getFieldFromJson(setJson, "numOfExcercises"));
	std::string exesJson = getFieldFromJson(setJson, "excercises");
	std::string tempExJson = "";
	Excercise tempEx;
	Set set;

	set.setReps(repetitions);

	exesJson = exesJson.substr(1, exesJson.length() - 2);	// Removing square brackets of the array.

	for (int i = 0; i < numOfExes; i++)	// Looping over all the exes.
	{
		tempExJson = exesJson.substr(0, exesJson.find("},"));	// Finding the end of the current object.
		tempEx = getExcFromJson(tempExJson);	// Creating and adding the ex.
		set.addExc(tempEx);

		exesJson = exesJson.substr(exesJson.find("},") + 2);	// Removing the object's representation from the JSON string.

		tempEx.~Excercise();
	}

	return set;
}

Session jsonHandler::getSessFromJson(const std::string& sessJson)
{
	Session sess;
	Set tempSet;
	sess.setName(getFieldFromJson(sessJson, "name"));
	sess.setDate(getFieldFromJson(sessJson, "date"));
	tempSet = getSetFromJson(getFieldFromJson(sessJson, "set"));

	sess.setSessionSet(tempSet);


	return sess;
}
