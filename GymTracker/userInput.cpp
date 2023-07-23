#include "userInput.h"


//TODO: Switch simple cin to safe string input.

int userInput::getInt()
{
    int integerVal = 0;
    bool flag = false;

    do
    {
        flag = false;
        std::cin >> integerVal;
        

        if (std::cin.fail())
        {
            std::cout << "Enter a valid number.\n";
            std::cin.clear();   // Clearing the failed state.
            flag = true;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Flushing the buffer.
        }

    } while (flag);

    return integerVal;
}

std::string userInput::getDate()
{
    tm testTime;
    time_t timeTemplate;
    int flag = 0;

    time(&timeTemplate);
    localtime_s(&testTime, &timeTemplate);

    do 
    {
        std::cout << "Enter day: ";
        testTime.tm_mday = getInt();
        
        std::cout << "Enter month: ";
        testTime.tm_mon = getInt() - 1;

        std::cout << "Enter year: ";
        testTime.tm_year = getInt() - 1900;

        flag = mktime(&testTime);

        if (flag == -1)
            std::cout << "Enter a valid date!\n";
           
    } while (flag == -1);

    return std::to_string(testTime.tm_mday) + '/' + std::to_string(testTime.tm_mon + 1) + '/' + std::to_string(testTime.tm_year + 1900);
}

Excercise userInput::getUserExcercise()
{
    Excercise userExcercise;
    std::string tempName = "";

    std::cout << "Enter excercise name: ";
    std::cin >> tempName;
    userExcercise.setName(tempName);

    std::cout << "Enter number of repetitions for excercise: ";
    userExcercise.setRepetitions(getInt());

    return userExcercise;
}

void userInput::addToSet(Set* set)
{
    set->addExcercise(getUserExcercise());
}



Set userInput::getUserSet()
{
    Set userSet;
    std::string choice = "";

    std::cout << "Enter number of repetitions for set: ";
    userSet.setRepetitions(getInt());

    std::cout << "Would you like to add excercises? ['y' - Yes, anything else - No]: ";
    std::cin >> choice;

    if (choice == "y")
    {
        do
        {
            addToSet(&userSet);

            std::cout << "Would you like to add another excercise? ['y' - Yes, anything else - No]: ";
            std::cin >> choice;
        } while (choice == "y");
    }

    return userSet;
}

Session userInput::getUserSession()
{
    Session userSession;
    std::string userName = "";

    std::cout << "Enter session name: ";
    std::cin >> userName;
    userSession.setName(userName);

    std::cout << "Enter session date: ";
    userSession.setDate(getDate());

    std::cout << "*** Moving to Set creation ***\n\n";
    userSession.setSessionSet(getUserSet());

    return userSession;
}
