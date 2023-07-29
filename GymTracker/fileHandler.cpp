#include "fileHandler.h"

void fileHandler::writeSessToLog(const std::string& username, const std::string& sessJson)
{
	std::fstream logFile;
	std::string existingLog = "";
	std::string newLog = std::format(LOG_TEMPLATE, sessJson);
	std::string fileName = std::format(LOG_FILE_NAME_TEMPLATE, username);

	logFile.open(fileName, std::ios_base::in);
	// Checking if the file exists.
	if (logFile.is_open())
	{
		logFile >> existingLog;
		newLog = existingLog.substr(0, existingLog.length() - 2) + ',' + sessJson + "]}";	// Copying the previous data.
		logFile.close();
	}
	logFile.open(fileName, std::ios_base::out);	// Writing the new data to the log.
	logFile << newLog;

	logFile.close();
}
