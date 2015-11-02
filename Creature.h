#pragma once

#include "Species.h"
#include <string>        // String

using namespace std;

class Creature {
	friend class Darwin;
	private:
	//DATA	
		Species spec;
		int pc = 0;
		char dir = 0;
		bool acted = false; // if the creature has acted this turn

	//METHODS
		char act(char n, char e, char s, char w);  //get instruction and execute


	public:
		Creature(const Species& s = Species(), char d = 0);
		// send in information regarding area so creature can decide
};