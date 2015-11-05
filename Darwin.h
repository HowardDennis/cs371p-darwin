// --------------------------
// projects/darwin/Darwin.h
// Copyright (C) 2015
// Glenn P. Downing
// --------------------------

#pragma once

// --------
// includes
// --------

#include <iostream> // istream, ostream
#include <string>   // string
#include <vector>   // vector
#include <utility>  // pair
#include "Creature.h"

#define DEBUG true

using namespace std;

class Darwin {
	private:
		vector < vector<Creature*> > grid;
		vector < pair <int, int> > whitelist;
		vector < pair <int, int> > next_whitelist;
		void step(int n=1); // a single step
		void processCell(int,int); // processes cell at grid[y][x]
		char cellContent(int,int,string name = "blank");
        
        FRIEND_TEST(DarwinFixture, Darwin_construct_default);
        FRIEND_TEST(DarwinFixture, Darwin_construct_args_1);
        FRIEND_TEST(DarwinFixture, Darwin_construct_args_2);
        FRIEND_TEST(DarwinFixture, Darwin_construct_args_3);
        FRIEND_TEST(DarwinFixture, Darwin_add_creature_1);
        FRIEND_TEST(DarwinFixture, Darwin_add_creature_2);
        FRIEND_TEST(DarwinFixture, Darwin_add_creature_3);
        FRIEND_TEST(DarwinFixture, Darwin_cell_content_1);
        FRIEND_TEST(DarwinFixture, Darwin_cell_content_2);
        FRIEND_TEST(DarwinFixture, Darwin_cell_content_3);
        FRIEND_TEST(DarwinFixture, Darwin_process_cell_1);
        FRIEND_TEST(DarwinFixture, Darwin_process_cell_2);
        FRIEND_TEST(DarwinFixture, Darwin_process_cell_3);
        FRIEND_TEST(DarwinFixture, Darwin_step_1);
        
	public:
		Darwin (int w = 1, int h = 1); // default is 1x1
		void addCreature(Creature*, int, int);
        void print(ostream& w, int turn=0);
};

