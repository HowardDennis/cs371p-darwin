#pragma once
//#include "Instruction.h"   // interface for instructions
#include "Instructions.h"  // instruction implementations
#include <string>        // String
#include <utility>       // pair
#include <iostream>         // cout, endl
using namespace std;

#define DEBUG false

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
        
        FRIEND_TEST(DarwinFixture, Darwin_Creature_construct_default);
        FRIEND_TEST(DarwinFixture, Darwin_Creature_construct_args);
        FRIEND_TEST(DarwinFixture, Darwin_Creature_act_1);
        FRIEND_TEST(DarwinFixture, Darwin_Creature_act_2);
        FRIEND_TEST(DarwinFixture, Darwin_Creature_act_3);
        FRIEND_TEST(DarwinFixture, Darwin_Creature_left_0);
        FRIEND_TEST(DarwinFixture, Darwin_Creature_left_1);
        FRIEND_TEST(DarwinFixture, Darwin_Creature_left_2);
        FRIEND_TEST(DarwinFixture, Darwin_Creature_left_3);
        FRIEND_TEST(DarwinFixture, Darwin_Creature_right_0);
        FRIEND_TEST(DarwinFixture, Darwin_Creature_right_1);
        FRIEND_TEST(DarwinFixture, Darwin_Creature_right_2);
        FRIEND_TEST(DarwinFixture, Darwin_Creature_right_3);
        
        FRIEND_TEST(DarwinFixture, Darwin_add_creature_1);
        FRIEND_TEST(DarwinFixture, Darwin_add_creature_2);
        FRIEND_TEST(DarwinFixture, Darwin_add_creature_3);
        FRIEND_TEST(DarwinFixture, Darwin_cell_content_1);
        FRIEND_TEST(DarwinFixture, Darwin_cell_content_2);
        FRIEND_TEST(DarwinFixture, Darwin_process_cell_1);
        FRIEND_TEST(DarwinFixture, Darwin_process_cell_2);
        FRIEND_TEST(DarwinFixture, Darwin_process_cell_3);
        FRIEND_TEST(DarwinFixture, Darwin_step_1);
        
	public:
		Species(string n = "null");
		void addInstruction(Instruction*);
};