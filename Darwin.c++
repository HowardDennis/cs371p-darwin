// ----------------------------
// projects/darwin/Darwin.c++
// Copyright (C) 2015
// Glenn P. Downing
// ----------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <sstream>  // istringstream
#include <string>   // getline, string
#include <utility>  // make_pair, pair

#include "Darwin.h"

using namespace std;

Darwin::Darwin (int w, int h) {

    vector<Creature> v(w);

    //grid.resize(w, vector<Creature>(w, nullptr)); // = vector< vector<Creature>(w) >(h);

}

    void Darwin::addCreature(const Creature& c, int w, int h) {

        grid[w][h] = c;

    }
