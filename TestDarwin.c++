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
#include <cstdlib>   //rand, srand
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
			m // malfactor (enemy)
            f // friend
			a //available
			c //control, d next instruction
			u //unavailable space (wall)
//*/
// * INSTRUCTION - HOP * * * * * * * * * * * * * * * * * 
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

// * INSTRUCTION - IF_EMPTY * * * * * * * * * * * * * * * * *
TEST(DarwinFixture, Darwin_Instruction_Ifempty_n){
	int num=5;
	If_Empty ie(num);
	int pc = 1;
	char dir,n,e,s,w;
	dir='n';
	n='a';
	s=e=w='?';
	pair<int,char> result = ie.act(n,e,s,w,pc,dir);
	ASSERT_EQ(result.first,num);
	ASSERT_EQ(result.second,'c');
	n='m';
	result = ie.act(n,e,s,w,pc,dir);
	ASSERT_EQ(result.first,2);
	ASSERT_EQ(result.second,'c');
}
TEST(DarwinFixture, Darwin_Instruction_Ifempty_s){
	int num=5;
	If_Empty ie(num);
	int pc = 1;
	char dir,n,e,s,w;
	dir='s';
	s='a';
	n=e=w='?';
	pair<int,char> result = ie.act(n,e,s,w,pc,dir);
	ASSERT_EQ(result.first,num);
	ASSERT_EQ(result.second,'c');
	s='m';
	result = ie.act(n,e,s,w,pc,dir);
	ASSERT_EQ(result.first,2);
	ASSERT_EQ(result.second,'c');	
}
TEST(DarwinFixture, Darwin_Instruction_Ifempty_e){
	int num=5;
	If_Empty ie(num);
	int pc = 1;
	char dir,n,e,s,w;
	dir='e';
	e='a';
	s=n=w='?';
	pair<int,char> result = ie.act(n,e,s,w,pc,dir);
	ASSERT_EQ(result.first,num);
	ASSERT_EQ(result.second,'c');
	e='m';
	result = ie.act(n,e,s,w,pc,dir);
	ASSERT_EQ(result.first,2);
	ASSERT_EQ(result.second,'c');
}
TEST(DarwinFixture, Darwin_Instruction_Ifempty_w){
	int num=5;
	If_Empty ie(num);
	int pc = 1;
	char dir,n,e,s,w;
	dir='w';
	w='a';
	s=e=n='?';
	pair<int,char> result = ie.act(n,e,s,w,pc,dir);
	ASSERT_EQ(result.first,num);
	ASSERT_EQ(result.second,'c');
	w='m';
	result = ie.act(n,e,s,w,pc,dir);
	ASSERT_EQ(result.first,2);
	ASSERT_EQ(result.second,'c');
}
// * INSTRUCTION - IF_WALL * * * * * * * * * * * * * * * * *
TEST(DarwinFixture, Darwin_Instruction_Ifwall_n){
    int num=5;
    If_Wall iw(num);
    int pc = 1;
	char dir,n,e,s,w;
	dir='n';
	n='u';
	s=e=w='?';
	pair<int,char> result = iw.act(n,e,s,w,pc,dir);
	ASSERT_EQ(result.first,num);
	ASSERT_EQ(result.second,'c');
	n='a';
	result = iw.act(n,e,s,w,pc,dir);
	ASSERT_EQ(result.first,2);
	ASSERT_EQ(result.second,'c');
}
TEST(DarwinFixture, Darwin_Instruction_Ifwall_s){
    int num=5;
    If_Wall iw(num);
    int pc = 1;
	char dir,n,e,s,w;
	dir='s';
	s='u';
	n=e=w='?';
	pair<int,char> result = iw.act(n,e,s,w,pc,dir);
	ASSERT_EQ(result.first,num);
	ASSERT_EQ(result.second,'c');
	s='f';
	result = iw.act(n,e,s,w,pc,dir);
	ASSERT_EQ(result.first,2);
	ASSERT_EQ(result.second,'c');
}
TEST(DarwinFixture, Darwin_Instruction_Ifwall_e){
    int num=5;
    If_Wall iw(num);
    int pc = 1;
	char dir,n,e,s,w;
	dir='e';
	e='u';
	n=s=w='?';
	pair<int,char> result = iw.act(n,e,s,w,pc,dir);
	ASSERT_EQ(result.first,num);
	ASSERT_EQ(result.second,'c');
	e='f';
	result = iw.act(n,e,s,w,pc,dir);
	ASSERT_EQ(result.first,2);
	ASSERT_EQ(result.second,'c');
}
TEST(DarwinFixture, Darwin_Instruction_Ifwall_w){
    int num=5;
    If_Wall iw(num);
    int pc = 1;
	char dir,n,e,s,w;
	dir='w';
	w='u';
	n=s=e='?';
	pair<int,char> result = iw.act(n,e,s,w,pc,dir);
	ASSERT_EQ(result.first,num);
	ASSERT_EQ(result.second,'c');
	w='f';
	result = iw.act(n,e,s,w,pc,dir);
	ASSERT_EQ(result.first,2);
	ASSERT_EQ(result.second,'c');
}
// * INSTRUCTION - IF_RANDOM * * * * * * * * * * * * * * * * *
TEST(DarwinFixture, Darwin_Instruction_Ifrandom){
    srand(0);
    int num=5;
    If_Random ir(num);
    int pc=1;
    char dir,n,s,w,e;
    dir=n=s=w=e='?';
    pair<int,char> result = ir.act(n,e,s,w,pc,dir);
    ASSERT_EQ(result, (pair<int,char>(num,'c')));
    result = ir.act(n,e,s,w,pc,dir);
    ASSERT_EQ(result, (pair<int,char>(2,'c')));
}
// * INSTRUCTION - IF_ENEMY * * * * * * * * * * * * * * * * *
TEST(DarwinFixture, Darwin_Instruction_Ifenemy_n){
    int num=5;
    If_Enemy ie(num);
    int pc=1;
    char dir,n,s,w,e;
    dir='n';
    n='m';
    s=w=e='a';
    pair<int,char> result = ie.act(n,e,s,w,pc,dir);
    ASSERT_EQ(result, (pair<int,char>(num,'c')));
    n='f';
    result = ie.act(n,e,s,w,pc,dir);
    ASSERT_EQ(result, (pair<int,char>(2,'c')));
}
TEST(DarwinFixture, Darwin_Instruction_Ifenemy_s){
    int num=5;
    If_Enemy ie(num);
    int pc=1;
    char dir,n,s,w,e;
    dir='s';
    s='m';
    n=w=e='a';
    pair<int,char> result = ie.act(n,e,s,w,pc,dir);
    ASSERT_EQ(result, (pair<int,char>(num,'c')));
    s='a';
    result = ie.act(n,e,s,w,pc,dir);
    ASSERT_EQ(result, (pair<int,char>(2,'c')));
}
TEST(DarwinFixture, Darwin_Instruction_Ifenemy_e){
    int num=5;
    If_Enemy ie(num);
    int pc=1;
    char dir,n,s,w,e;
    dir='e';
    e='m';
    s=w=n='a';
    pair<int,char> result = ie.act(n,e,s,w,pc,dir);
    ASSERT_EQ(result, (pair<int,char>(num,'c')));
    e='a';
    result = ie.act(n,e,s,w,pc,dir);
    ASSERT_EQ(result, (pair<int,char>(2,'c')));
}
TEST(DarwinFixture, Darwin_Instruction_Ifenemy_w){
    int num=5;
    If_Enemy ie(num);
    int pc=1;
    char dir,n,s,w,e;
    dir='w';
    w='m';
    s=n=e='a';
    pair<int,char> result = ie.act(n,e,s,w,pc,dir);
    ASSERT_EQ(result, (pair<int,char>(num,'c')));
    w='f';
    result = ie.act(n,e,s,w,pc,dir);
    ASSERT_EQ(result, (pair<int,char>(2,'c')));
}
// * INSTRUCTION - GO * * * * * * * * * * * * * * * * *
TEST(DarwinFixture, Darwin_Instruction_Go){
    int num=5;
    Go g(num);
    int pc=1;
    char dir,n,s,w,e;
    dir='?';
    w=s=n=e='?';
    pair<int,char> result = g.act(n,e,s,w,pc,dir);
    ASSERT_EQ(result, (pair<int,char>(num,'c')));
}

// SPECIES
// * Species Constructors * * * * * * * * * * * * * * * * * * * *
TEST(DarwinFixture, Darwin_Species_default) {
	Species c;
	ASSERT_EQ(c.name, "null");
}
TEST(DarwinFixture, Darwin_Species_named) {
	Species c("pass");
	ASSERT_EQ(c.name, "pass");
}
// * Species addInstruction() * * * * * * * * * * * * * * * * * * * *
TEST(DarwinFixture, Darwin_Species_addInstruction) {
	Species c;
    Hop i1 = Hop();
    Go i2 = Go(5);
    Infect i3 = Infect();
    c.addInstruction(&i1);
    c.addInstruction(&i2);
	ASSERT_EQ((c.i).size(),2);
    ASSERT_EQ(((Go*)(c.i[1]))->num,5);
}
// * Species act() * * * * * * * * * * * * * * * * * * * *
TEST(DarwinFixture, Darwin_Species_act_1) {
    Species sp;
    Hop i1;
    Go i2(0);
    sp.addInstruction(&i1);
    sp.addInstruction(&i2);
    
    char dir,n,s,e,w;
    int pc=0;
    dir='n';
    n=s=e=w='a';
    pair<int, char> result = sp.act(n, e, s, w, pc, dir);
    ASSERT_EQ(result,( pair<int,char>( 1, 'n' ) ));
    result = sp.act(n, e, s, w, pc, dir);
    ASSERT_EQ(result,( pair<int,char>( 1, 'n' ) ));
}
TEST(DarwinFixture, Darwin_Species_act_2) {
    Species sp;
    Go i0(2);
    Hop i1;
    Infect i2;
    sp.addInstruction(&i0);
    sp.addInstruction(&i1);
    sp.addInstruction(&i2);
    
    char dir,n,s,e,w;
    int pc=0;
    dir='n';
    n=s=e=w='m';
    pair<int, char> result = sp.act(n, e, s, w, pc, dir);
    ASSERT_EQ(result,( pair<int,char>( 3, 'o' ) ));
    n='a';
    result = sp.act(n, e, s, w, pc, dir);
    ASSERT_EQ(result,( pair<int,char>( 3, 'z' ) ));
}
TEST(DarwinFixture, Darwin_Species_act_3) {
    Species sp;
    Go i0(2);
    If_Enemy i1(3);
    Go i2(1);
    Left i3;
    sp.addInstruction(&i0);
    sp.addInstruction(&i1);
    sp.addInstruction(&i2);
    sp.addInstruction(&i3);
    
    char dir,n,s,e,w;
    int pc=0;
    dir='s';
    n=s=e=w='m';
    pair<int, char> result = sp.act(n, e, s, w, pc, dir);
    ASSERT_EQ(result,( pair<int,char>( 4, 'l' ) ));
}

// CREATURE
// * Creature Constructors * * * * * * * * * * * * * * * * * * * *
TEST(DarwinFixture, Darwin_Creature_construct_default){
    Species sp;
    Creature cr(sp,'n'); //a north-facing null
    ASSERT_EQ(cr.spec.name,"null");
}
TEST(DarwinFixture, Darwin_Creature_construct_args){
    Species sp("Elephant");
    Creature cr(sp,'n'); //a north-facing Elephant
    ASSERT_EQ(cr.spec.name,"Elephant");
}
TEST(DarwinFixture, Darwin_Creature_act_1){
    Species sp("Elephant");
    If_Enemy i0(2);
    Left i1;
    Infect i2;
    Go i3(1);
    
    sp.addInstruction(&i0);
    sp.addInstruction(&i1);
    sp.addInstruction(&i2);
    sp.addInstruction(&i3);
    
    Creature cr(sp,'n'); //a north-facing Elephant
    
    char n,s,e,w;
    n=s=e=w='m';
    char result = cr.act(n,e,s,w);
    ASSERT_EQ(result,'o');
    ASSERT_EQ(cr.pc,3);
}
TEST(DarwinFixture, Darwin_Creature_act_2){
    Species sp("Candiru");
    If_Enemy i0(2);
    Left i1;
    Infect i2;
    Go i3(0);
    
    sp.addInstruction(&i0);
    sp.addInstruction(&i1);
    sp.addInstruction(&i2);
    sp.addInstruction(&i3);
    Creature cr(sp,'s'); //a south-facing Candiru
    char n,s,e,w;
    n=s=e=w='m';
    cr.act(n,e,s,w);
    char result = cr.act(n,e,'a',w);// next step, space is available
    ASSERT_EQ(result,'l');
    ASSERT_EQ(cr.pc,2);
}
TEST(DarwinFixture, Darwin_Creature_act_3){
    Species dodo("dodo");
    Hop i0;
    Go i1(0); 
    
    dodo.addInstruction(&i0);
    dodo.addInstruction(&i1);
    
    Creature cr(dodo,'e');//an eastern dodo
    
    char n,s,e,w;
    n=s=e=w='m';
    cr.act(n,e,s,w);
    char result = cr.act(n,e,'a',w);// next step, space is available
    ASSERT_EQ(result,'z');
    ASSERT_EQ(cr.pc,1);
}
TEST(DarwinFixture, Darwin_Creature_left_0){
    Species sp("Walrus");
    Creature cr(sp,'w');
    cr.turnLeft();
    ASSERT_EQ(cr.dir,'s');
}
TEST(DarwinFixture, Darwin_Creature_left_1){
    Species sp("Eagle");
    Creature cr(sp,'e');
    cr.turnLeft();
    ASSERT_EQ(cr.dir,'n');
}
TEST(DarwinFixture, Darwin_Creature_left_2){
    Species sp("Narwhal");
    Creature cr(sp,'n');
    cr.turnLeft();
    ASSERT_EQ(cr.dir,'w');
}
TEST(DarwinFixture, Darwin_Creature_left_3){
    Species sp("Spider");
    Creature cr(sp,'s');
    cr.turnLeft();
    ASSERT_EQ(cr.dir,'e');
}
TEST(DarwinFixture, Darwin_Creature_right_0){
    Species sp("Walrus");
    Creature cr(sp,'w');
    cr.turnRight();
    ASSERT_EQ(cr.dir,'n');
}
TEST(DarwinFixture, Darwin_Creature_right_1){
    Species sp("Eagle");
    Creature cr(sp,'e');
    cr.turnRight();
    ASSERT_EQ(cr.dir,'s');
}
TEST(DarwinFixture, Darwin_Creature_right_2){
    Species sp("Narwhal");
    Creature cr(sp,'n');
    cr.turnRight();
    ASSERT_EQ(cr.dir,'e');
}
TEST(DarwinFixture, Darwin_Creature_right_3){
    Species sp("Spider");
    Creature cr(sp,'s');
    cr.turnRight();
    ASSERT_EQ(cr.dir,'w');
}
// DARWIN
// * Darwin Constructors * * * * * * * * * * * * * * * * * * * *
TEST(DarwinFixture, Darwin_construct_default){
    Darwin d;
    ASSERT_EQ(1, d.grid.size());
}
TEST(DarwinFixture, Darwin_construct_args_1){
    Darwin d(10);
    ASSERT_EQ(1, d.grid.size());
    ASSERT_EQ(10, (d.grid[0]).size());
}
<<<<<<< HEAD

TEST(DarwinFixture, Darwin_construct_args_2){
    Darwin d(1300,1700);
    ASSERT_EQ(1700, d.grid.size());
    ASSERT_EQ(1300, (d.grid[0]).size());
}
TEST(DarwinFixture, Darwin_construct_args_3){
    Darwin d(0,0);
    ASSERT_EQ(0, d.grid.size());
}
// * Darwin add creature * * * * * * * * * * * * * * * * * * * *
TEST(DarwinFixture, Darwin_add_creature_1){
    Species konoha("Kohoha shinobi");
    Species akatsuki("Akatsuki shinobi");
    
    Creature madara(akatsuki, 's');
    Creature gaisensei(konoha, 'n');
    
    Darwin d(4,4);
    d.addCreature ( &madara, 0, 0);
    d.addCreature ( &gaisensei, 0, 1);
    ASSERT_EQ(d.grid[0][0],&madara);
    ASSERT_EQ(d.grid[1][0],&gaisensei);
}
TEST(DarwinFixture, Darwin_add_creature_2){
    Species konoha("Kohoha shinobi");
    Species akatsuki("Akatsuki shinobi");
    
    Creature kisame(akatsuki, 's');
    Creature kakashi(konoha, 'n');
    
    Darwin d(4,4);
    d.addCreature ( &kisame, 1, 2);
    d.addCreature ( &kakashi, 1, 2);
    ASSERT_EQ(d.grid[2][1],&kakashi);
}
TEST(DarwinFixture, Darwin_add_creature_3){
    Species konoha("Kohoha shinobi");
    Species akatsuki("Akatsuki shinobi");
    
    Creature tobi(akatsuki, 's');
    Creature rocklee(konoha, 'n');
    
    Darwin d(4000,4000);
    d.addCreature ( &tobi, 1000, 2000);
    d.addCreature ( &rocklee, 1000, 2001);
    ASSERT_EQ(d.grid[2000][1000],&tobi);
    ASSERT_EQ(d.grid[2001][1000],&rocklee);
}
// * Darwin check cell content * * * * * * * * * * * * * * * * * * * *
TEST(DarwinFixture, Darwin_cell_content_1){
    
    string name = "Marsupial";
    Species sp(name);
    
    Creature kangaroo(sp,'s');
    
    Darwin d;
    d.addCreature(&kangaroo,0,0);
    char result = d.cellContent(0, 0, name);
    ASSERT_EQ('f',result);
=======
TEST(DarwinFixture, Darwin_print_default){
    Darwin d(1, 1);
    ostringstream w;
    d.print(w);
    ASSERT_EQ("Turn = 0.\n  0\n0 .\n", w.str());
}
TEST(DarwinFixture, Darwin_print_bigger){
    Darwin d(5, 5);
    ostringstream w;
    d.print(w);
    ASSERT_EQ("Turn = 0.\n  01234\n0 .....\n1 .....\n2 .....\n3 .....\n4 .....\n", w.str());
}
TEST(DarwinFixture, Darwin_print_creatures){
    Darwin d(4, 4);
    Species s1("test species 1");
	Species s2("d");
	Creature c1(s1,'n');
	Creature c2(s2,'s');
	d.addCreature(&c1, 1, 1);
	d.addCreature(&c2, 3, 3);
    ostringstream w;
    d.print(w);
    ASSERT_EQ("Turn = 0.\n  0123\n0 ....\n1 .t..\n2 ....\n3 ...d\n", w.str());
}
TEST(DarwinFixture, Darwin_full_of_creatures){
    Darwin d(4, 4);
    Creature c;
	int i = 0;
	while (i < 4) {
		int j = 0;
		while (j < 4) {
			d.addCreature(&c, i, j);
			++j;
		}
		++i;
	}
    ostringstream w;
    d.print(w);
    ASSERT_EQ("Turn = 0.\n  0123\n0 nnnn\n1 nnnn\n2 nnnn\n3 nnnn\n", w.str());
}
/*
TEST(DarwinFixture, Darwin_construct_args_1){
    Darwin d(10);
    ASSERT_EQ(1, d.grid.size());
    ASSERT_EQ(10, (d.grid[0]).size());
>>>>>>> 31dbea202e667c3ab0fab6772a9d4071b5dda941
}
TEST(DarwinFixture, Darwin_cell_content_2){
    string name = "Marsupial";
    Species sp(name);
    
    Creature wallaby(sp,'s');
    
    Darwin d;
    d.addCreature(&wallaby,0,0);
    char result = d.cellContent(0, 0, "Hey this isn't the bathroom");
    ASSERT_EQ('m',result);
}
TEST(DarwinFixture, Darwin_cell_content_3){
    Darwin d;
    ASSERT_EQ(d.cellContent(0,0,"blerf"),'a');
}
// * Darwin process a cell in the grid * * * * * * * * * * * * * * * * * * * *
TEST(DarwinFixture, Darwin_process_cell_1){
    Species lefty("Lefty");
    Left i0;
    Go i1(0);
    lefty.addInstruction(&i0);
    lefty.addInstruction(&i1);
    
    Creature sonoflefty(lefty,'n');
    
    Darwin d(2,1);
    d.addCreature(&sonoflefty,1,0);
    d.processCell(1,0);
    
    ASSERT_EQ(d.grid[0][1]->dir,'w');
    ASSERT_FALSE(d.grid[0][1]->acted);
}
TEST(DarwinFixture, Darwin_process_cell_2){
    Species a("A");
    Species b("B");
    Left ai0;
    Go ai1(0);
    a.addInstruction(&ai0);
    a.addInstruction(&ai1);
    
    Infect bi0;
    Go bi1(0);
    
    b.addInstruction(&bi0);
    b.addInstruction(&bi1);
    
    Creature alpha(a,'n');
    Creature omega(b,'w');
        
    Darwin d(2,1);
    d.addCreature(&alpha,0,0);
    d.addCreature(&omega,1,0);
    
    ASSERT_EQ(d.cellContent(0,0,"B"),'m');
    
    d.processCell(1,0);
    
    ASSERT_EQ(d.cellContent(0,0,"B"),'f');
    ASSERT_FALSE(d.grid[0][1]->acted);
}
TEST(DarwinFixture, Darwin_process_cell_3){
    Species a("A");
    
    If_Empty i0(2);
    Right i1;
    Hop i2;
    Go i3(0);
    
    a.addInstruction(&i0);
    a.addInstruction(&i1);
    a.addInstruction(&i2);
    a.addInstruction(&i3);
                        //grid: 0  1  2
    Creature a1(a,'n'); //  0   -- -- a1
    Creature a2(a,'n'); //  1   -- a2 --
    Creature a3(a,'n'); //  2   a3 -- --
    
    Darwin d(3,3);
    d.addCreature(&a1,2,0);
    d.addCreature(&a2,1,1);
    d.addCreature(&a3,0,2);
    
    ASSERT_EQ(d.cellContent(2,0,"A"),'f');
    ASSERT_EQ(d.cellContent(2,0,"B"),'m');
                        //grid: 0  1  2
    d.processCell(2,0); //  0   -- a2 a1   a1 turns right
    d.processCell(1,1); //  1   a3 ^^ --   a2 moves up
    d.processCell(0,2); //  2   ^^ -- --   a3 moves up
    
    ASSERT_EQ(d.grid[0][2],&a1);
    ASSERT_EQ((d.grid[0][2])->dir,'e');
    ASSERT_EQ(d.grid[0][1],&a2);
    ASSERT_EQ(d.grid[1][0],&a3);
    ASSERT_EQ(d.grid[2][0],nullptr);
    ASSERT_EQ(d.grid[1][1],nullptr);
}

//*/