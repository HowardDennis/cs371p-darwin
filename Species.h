#pragma once
#include "Instruction.h"
#include "Creature.h"
#include <string>        // String

using namespace std;

class Species {
	private:
		vector<Instruction> i;
		string name;

	public:
		Species(const Creature&);

		void addInstruction(const Instruction&);
};





