#include "session.h"
#include "userInput.h"
#include "jsonHandler.h"
#include "fileHandler.h"
/*
* TODO:
* 1) Add safer user input (getline).
* 2) Filter user input for special chars ({, [, ',', etc).
* 3) Add exceptions.
* 4) Change names to easier ones (repetitions => reps, excercise = exc, etc).
* 5) Add file handling.
*/

/*
* Naming:
* exc - Excercies
* exces - Excercises
* sess - Session
*/
int main()
{
	std::string testJSON = "{name:\"testSession\",date:\"1/1/2000\",set:{repetitions:5,numOfExcercises:2,excercises:[{name:\"ex1\",repetitions:5},{name:\"ex2\",repetitions:10}]}}";


	fileHandler::writeSessToLog("Tomer", testJSON);

	return 0;
}