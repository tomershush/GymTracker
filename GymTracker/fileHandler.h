#pragma once
#include "Session.h"
#include "pch.h"

/*
* Program files:
* 1) Excercises file: Contains all previously added excercises.
* 2) Sessions file: Contains all previosly added sessions. (As templates).
* 3) User logs: Files containing data about the user's sessions.
*/


#define LOG_FILE_NAME_TEMPLATE "{}_log.json"
#define LOG_TEMPLATE "{{sessions=[{}]}}"

class fileHandler
{
public:
	static void writeSessToLog(const std::string& username, const std::string& sessJson);
};

