#pragma once

#include "Species.h"
#include <string>        // String

using namespace std;

class Creature {

	private:
	//DATA	
		Species spec;
		int pc;
		char dir;
		bool acted; // if the creature has acted this turn

	//METHODS

	public:
		Creature(const Species& s = Species(), char d = 0);
		// send in information regarding area so creature can decide
		char act(char n, char e, char s, char w);  //get instruction and execute
};