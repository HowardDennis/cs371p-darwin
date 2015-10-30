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
#include "Creature.h"

using namespace std;

class Darwin {

	private:
		vector< vector<Creature> > grid;

	public:
		Darwin (int, int);
		void addCreature(const Creature&);
};

#endif // Darwin_h
