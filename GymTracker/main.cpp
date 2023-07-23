#include "session.h"
#include "userInput.h"
#include "jsonHandler.h"

int main()
{

	Session testSes = userInput::getUserSession();

	std::cout << testSes.toString();

	return 0;
}