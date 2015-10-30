#pragma once
#include "Instruction.h"
#include "Creature.h"
#include <string>        // String

using namespace std;

class Creature;

class Species {
	private:
		vector<Instruction> i;
		string name;

	public:
		Species(string n = "null");
		char act(char, char, char, char);
		void addInstruction(const Instruction&);
};





