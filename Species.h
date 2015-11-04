#pragma once
//#include "Instruction.h"   // interface for instructions
#include "Instructions.h"  // instruction implementations
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

		//FRIEND_TEST(DarwinFixture, Darwin_Species_default);
		//TEST(DarwinFixture, Darwin_Species_named);
	public:
		Species(string n = "null");
		void addInstruction(Instruction*);
};