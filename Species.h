#pragma once
#include "Instruction.h"
#include <string>        // String

using namespace std;

class Species {

	friend class Creature;
	private:
		//DATA
		vector<Instruction> i;
		string name;

		//METHODS
		char act(char, char, char, char, int);


	public:
		Species(string n = "null");
		void addInstruction(const Instruction&);
};





