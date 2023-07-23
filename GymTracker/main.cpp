#include "session.h"
#include "userInput.h"
#include "jsonHandler.h"

int main()
{
	Session test = userInput::getUserSession();

	std::cout << jsonHandler::createSessionJson(test);

	return 0;
}