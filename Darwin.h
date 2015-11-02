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
		vector < vector<const Creature*> > grid;
		vector < pair <int, int> > whitelist;
		vector < pair <int, int> > next_whitelist;
		void step(); // at beginning, refresh all creatures

	public:
		Darwin (int w = 0, int h = 0);
		void addCreature(const Creature*, int, int);
};

