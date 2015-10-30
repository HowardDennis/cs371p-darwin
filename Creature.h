#pragma once

#include "Species.h"
#include "Direction.h"
#include <string>        // String

using namespace std;

class Creature {
	private:
		int program_ctr;
		Species spec;
		Direction dir;

	public:
		Creature(const Species&);
		void step(int, int);  //get instruction and execute
};