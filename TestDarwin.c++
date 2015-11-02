// --------------------------------
// projects/darwin/TestDarwin.c++
// Copyright (C) 2015
// Glenn P. Downing
// --------------------------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // string
#include <utility>  // pair

#include "gtest/gtest.h"

#include "Darwin.h"

using namespace std;

// -----------
// TestDarwin
// -----------


TEST(DarwinFixture, Darwin_addCreature_1) {
	Species s("test species");
	Creature c(s,'n');
	Darwin d(2,2);
}

TEST(DarwinFixture, Darwin_addCreature_2) {
}

TEST(DarwinFixture, Darwin_addCreature_3) {
}