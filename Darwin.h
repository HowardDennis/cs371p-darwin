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

using namespace std;

class Darwin {
	private:
		vector < vector<Creature*> > grid;
		vector < pair <int, int> > whitelist;
		vector < pair <int, int> > next_whitelist;
		void step(int n=1); // a single step
		void processCell(int,int); // processes cell at grid[y][x]
		char cellContent(int,int,string name = "blank");

	public:
		Darwin (int w = 0, int h = 0);
		void addCreature(Creature*, int, int);
		void print();
};

