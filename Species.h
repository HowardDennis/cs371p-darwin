#pragma once
#include "Instruction.h"
#include <string>        // String
#include <utility>       // pair
using namespace std;

class Species {

	friend class Creature;
	friend class Darwin;
	private:
		//DATA
		vector<Instruction*> i;
		string name;

		//METHODS
		pair <int, char> act(char, char, char, char, int, char);


	public:
		Species(string n = "null");
		void addInstruction(Instruction*);
};