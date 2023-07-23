#pragma once
#include "pch.h"
#include "Session.h"

class userInput
{
public:
	// Basic input
	static int getInt();
	static std::string getDate();
	//TODO: Add safe string input.

	
	// Input for data structures:

	static Excercise getUserExcercise();
	static void addToSet(Set* set);
	static Set getUserSet();
	static Session getUserSession();
};

