#pragma once

#include "Species.h"
#include "Direction.h"
#include <string>        // String

using namespace std;

class Creature {

	private:
	//DATA	
		int program_ctr;
		Species spec;
		Direction dir;
		bool acted; // if the creature has acted this turn

	//METHODS

	public:
		Creature(const Species&, Direction d);
		// send in information regarding area so creature can decide
		char act(char n, char e, char s, char w);  //get instruction and execute
		void refresh();
};