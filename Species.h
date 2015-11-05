#pragma once
//#include "Instruction.h"   // interface for instructions
#include "Instructions.h"  // instruction implementations
#include <string>        // String
#include <utility>       // pair
#include <iostream>         // cout, endl
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

        FRIEND_TEST(DarwinFixture, Darwin_Species_addInstruction);
		FRIEND_TEST(DarwinFixture, Darwin_Species_default);
		FRIEND_TEST(DarwinFixture, Darwin_Species_named);
        FRIEND_TEST(DarwinFixture, Darwin_Species_act_1);
        FRIEND_TEST(DarwinFixture, Darwin_Species_act_2);
        FRIEND_TEST(DarwinFixture, Darwin_Species_act_3);
        
	public:
		Species(string n = "null");
		void addInstruction(Instruction*);
};