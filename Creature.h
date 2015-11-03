#pragma once

#include "Species.h"
#include <string>       // String
#include <utility>      // pair

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
        void turnLeft();
        void turnRight();

		FRIEND_TEST(DarwinFixture, Darwin_Creature_default);


	public:
		Creature(const Species& s = Species(), char d = 0);
		// send in information regarding area so creature can decide
};