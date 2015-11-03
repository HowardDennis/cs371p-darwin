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
#include <cassert>   // assert
#include "gtest/gtest.h"

#include "Darwin.h"

using namespace std;

/* bottom up test methodology useful for procedural development
 * INSTRUCTIONS:

		RESPONSE CHARACTERS - what action should be taken
			l r       //rotation
			n e s w   //movement
			z 	 	  // do nothing
			o k , ;   //infection direction
		SIGNAL CHARACTERS - inform the creature so it can decide on an action
			m // malfactor (which mean enemy)
			a //available
			c //control, d next instruction
			u //unavailable space
//*/


// -----------
// TestDarwin
// -----------

/*
TEST(DarwinFixture, Darwin_addCreature_1) {
	Species s("test species");
	Creature c(s,'n');
	Darwin d(2,2);
}

TEST(DarwinFixture, Darwin_addCreature_2) {
	Species s1("test species 1");
	Species s2("test species 2");
	Creature c1(s1,'n');
	Creature c2(s2,'s');
}

TEST(DarwinFixture, Darwin_addCreature_3) {
}
//*/