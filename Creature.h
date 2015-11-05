#pragma once

#include "Species.h"
#include <string>       // String
#include <utility>      // pair
#include <iostream>

using namespace std;

#define DEBUG false

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
        FRIEND_TEST(DarwinFixture, Darwin_construct_add_creature_3);
        
        FRIEND_TEST(DarwinFixture, Darwin_cell_content_1);
        FRIEND_TEST(DarwinFixture, Darwin_cell_content_2);
        FRIEND_TEST(DarwinFixture, Darwin_process_cell_1);
        FRIEND_TEST(DarwinFixture, Darwin_process_cell_2);
        FRIEND_TEST(DarwinFixture, Darwin_process_cell_3);
        FRIEND_TEST(DarwinFixture, Darwin_step_1);
        
	public:
		Creature(const Species& s = Species(), char d = '?');
		void print(int turn = 0);
};