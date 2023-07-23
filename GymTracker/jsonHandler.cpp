#include "jsonHandler.h"

std::string jsonHandler::createExcerciseJson(const Excercise& ex)
{
    std::format(EX_JSON_TEMPLATE, ex.getName(), ex.getRepetitions());
}
