// --------------------------
// projects/darwin/Darwin.h
// Copyright (C) 2015
// Glenn P. Downing
// --------------------------

#ifndef Darwin_h
#define Darwin_h

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
		vector < vector<Creature> > grid;
		vector < pair <int, int> > whitelist;
		vector < pair <int, int> > next_whitelist;
		void step(); // at beginning, refresh all creatures

	public:
		Darwin (int, int);
		void addCreature(const Creature&, int, int);
};

#endif // Darwin_h
