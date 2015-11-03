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

// * INSTRUCTION - HOP * * * * * * * * * * * * * * * * * 
//	 north ==============================================
TEST(DarwinFixture, Darwin_Instruction_Hop_act_n1){ // hop
	Hop h;
	int pc = 1;
	char dir,n,e,s,w;
	dir='n';
	n='a';
	s=w=e='u';
	pair<int,char> result = h.act(n, e, s, w, pc, dir);
	ASSERT_EQ( 'n', result.second);
	ASSERT_EQ( 2, result.first);}
TEST(DarwinFixture, Darwin_Instruction_Hop_act_n2){ // if hop is blocked
	Hop h;
	int pc = 1;
	char dir,n,e,s,w;
	dir='n';
	n='u';
	s=w=e='a';
	pair<int,char> result = h.act(n, e, s, w, pc, dir);
	ASSERT_EQ( 'z', result.second);}
//	 south ==============================================
TEST(DarwinFixture, Darwin_Instruction_Hop_act_s1){ // hop
	Hop h;
	int pc = 1;
	char dir,n,e,s,w;
	dir='s';
	s='a';
	n=w=e='u';
	pair<int,char> result = h.act(n, e, s, w, pc, dir);
	ASSERT_EQ( 's', result.second);
	ASSERT_EQ( 2, result.first);}
TEST(DarwinFixture, Darwin_Instruction_Hop_act_s2){ // if hop is blocked
	Hop h;
	int pc = 1;
	char dir,n,e,s,w;
	dir='s';
	s='u';
	n=w=e='a';
	pair<int,char> result = h.act(n, e, s, w, pc, dir);
	ASSERT_EQ( 'z', result.second);}
//	 east ==============================================
TEST(DarwinFixture, Darwin_Instruction_Hop_act_e1){ // hop
	Hop h;
	int pc = 1;
	char dir,n,e,s,w;
	dir='e';
	e='a';
	n=s=w='u';
	pair<int,char> result = h.act(n, e, s, w, pc, dir);
	ASSERT_EQ( 'e', result.second);
	ASSERT_EQ( 2, result.first);}
TEST(DarwinFixture, Darwin_Instruction_Hop_act_e2){ // if hop is blocked
	Hop h;
	int pc = 1;
	char dir,n,e,s,w;
	dir='e';
	e='u';
	n=s=w='a';
	pair<int,char> result = h.act(n, e, s, w, pc, dir);
	ASSERT_EQ( 'z', result.second);}
//	 west ==============================================
TEST(DarwinFixture, Darwin_Instruction_Hop_act_w1){ // hop
	Hop h;
	int pc = 1;
	char dir,n,e,s,w;
	dir='w';
	w='a';
	n=s=e='u';
	pair<int,char> result = h.act(n, e, s, w, pc, dir);
	ASSERT_EQ( 'w', result.second);
	ASSERT_EQ( 2, result.first);}
TEST(DarwinFixture, Darwin_Instruction_Hop_act_w2){ // if hop is blocked
	Hop h;
	int pc = 1;
	char dir,n,e,s,w;
	dir='w';
	w='u';
	n=s=e='a';
	pair<int,char> result = h.act(n, e, s, w, pc, dir);
	ASSERT_EQ( 'z', result.second);}

// * INSTRUCTION - LEFT * * * * * * * * * * * * * * * * *
TEST(DarwinFixture, Darwin_Instruction_Left_act){
	Left l;
	int pc = 1;
	char dir,n,e,s,w;
	dir='n';
	n=e=s=w='?';
	pair<int,char> result = l.act(n, e, s, w, pc, dir);
	ASSERT_EQ( 'l', result.second);
	ASSERT_EQ( 2, result.first);}

// * INSTRUCTION - RIGHT * * * * * * * * * * * * * * * * *
TEST(DarwinFixture, Darwin_Instruction_Right_act){
	Right r;
	int pc = 1;
	char dir,n,e,s,w;
	dir='w';
	n=e=s=w='?';
	pair<int,char> result = r.act(n, e, s, w, pc, dir);
	ASSERT_EQ( 'r', result.second);
	ASSERT_EQ( 2, result.first);}

// * INSTRUCTION - INFECT * * * * * * * * * * * * * * * * *
//	north -------------------------------------------------
TEST(DarwinFixture, Darwin_Instruction_Infect_n){
	Infect i;
	int pc = 1;
	char dir,n,e,s,w;
	dir='n';
	n='m';
	s=e=w='?';
	pair<int,char> result = i.act(n,e,s,w,pc,dir);
	ASSERT_EQ('o',result.second);
	ASSERT_EQ(2,result.first);
	n='a';
	result = i.act(n,e,s,w,pc,dir);
	ASSERT_EQ('z',result.second);
}
//	south -------------------------------------------------
TEST(DarwinFixture, Darwin_Instruction_Infect_s){
	Infect i;
	int pc = 1;
	char dir,n,e,s,w;
	dir='s';
	s='m';
	n=e=w='?';
	pair<int,char> result = i.act(n,e,s,w,pc,dir);
	ASSERT_EQ(',',result.second);
	ASSERT_EQ(2,result.first);
	s='a';
	result = i.act(n,e,s,w,pc,dir);
	ASSERT_EQ('z',result.second);
}
//	east -------------------------------------------------
TEST(DarwinFixture, Darwin_Instruction_Infect_e){
	Infect i;
	int pc = 1;
	char dir,n,e,s,w;
	dir='e';
	e='m';
	s=n=w='?';
	pair<int,char> result = i.act(n,e,s,w,pc,dir);
	ASSERT_EQ(';',result.second);
	ASSERT_EQ(2,result.first);
	e='a';
	result = i.act(n,e,s,w,pc,dir);
	ASSERT_EQ('z',result.second);
}
//	west -------------------------------------------------
TEST(DarwinFixture, Darwin_Instruction_Infect_w){
	Infect i;
	int pc = 1;
	char dir,n,e,s,w;
	dir='w';
	w='m';
	s=e=n='?';
	pair<int,char> result = i.act(n,e,s,w,pc,dir);
	ASSERT_EQ('k',result.second);
	ASSERT_EQ(2,result.first);
	w='a';
	result = i.act(n,e,s,w,pc,dir);
	ASSERT_EQ('z',result.second);
}

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