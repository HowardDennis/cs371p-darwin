// -----------------------------
// projects/darwin/RunDarwin.c++
// Copyright (C) 2015
// Glenn P. Downing
// -----------------------------

// --------
// includes
// --------

#include <cassert>   // assert
#include <cstdlib>   // rand, srand
#include <iostream>  // cout, endl
#include <stdexcept> // invalid_argument, out_of_range

#include "Darwin.h"

// ----
// main
// ----

int main () {
    using namespace std;

    // ----
    // food
    // ----
    Species food("food");
    Left fi0;
    Go fi1(0);
    food.addInstruction(&fi0);
    food.addInstruction(&fi1);
    /*
     0: left
     1: go 0
    */

    // ------
    // hopper
    // ------
    Species hopper("hopper");
    
    Hop hi0;
    Go hi1(0);

    hopper.addInstruction(&hi0);
    hopper.addInstruction(&hi1);
    /*
     0: hop
     1: go 0
    */

    // -----
    // rover
    // -----
    Species rover("rover");
    If_Enemy ri0(9);
    If_Empty ri1(7);
    If_Random ri2(5);
    Left ri3;
    Go ri4(0);
    Right ri5;
    Go ri6(0);
    Hop ri7;
    Go ri8(0);
    Infect ri9;
    Go ri10(0);
    rover.addInstruction(&ri0);
    rover.addInstruction(&ri1);
    rover.addInstruction(&ri2);
    rover.addInstruction(&ri3);
    rover.addInstruction(&ri4);
    rover.addInstruction(&ri5);
    rover.addInstruction(&ri6);
    rover.addInstruction(&ri7);
    rover.addInstruction(&ri8);
    rover.addInstruction(&ri9);
    rover.addInstruction(&ri10);
    /*
     0: if_enemy 9
     1: if_empty 7
     2: if_random 5
     3: left
     4: go 0
     5: right
     6: go 0
     7: hop
     8: go 0
     9: infect
    10: go 0
    */

    // ----
    // trap
    // ----
    Species trap("trap");
    
    If_Enemy ti0(3);
    Left ti1;
    Go ti2(0);
    Infect ti3;
    Go ti4(0);
    
    trap.addInstruction(&ti0);
    trap.addInstruction(&ti1);
    trap.addInstruction(&ti2);
    trap.addInstruction(&ti3);
    trap.addInstruction(&ti4);
    /*
     0: if_enemy 3
     1: left
     2: go 0
     3: infect
     4: go 0
    */

    // ----
    // best
    // ----
    
    Species best("best");
    
    If_Enemy bi0(4);
    If_Empty bi1(6);
    Right bi2;
    Go bi3(0);
    Infect bi4;
    Go bi5(0);
    Hop bi6;
    Go bi7(0);
    
    
    best.addInstruction(&bi0);
    best.addInstruction(&bi1);
    best.addInstruction(&bi2);
    best.addInstruction(&bi3);
    best.addInstruction(&bi4);
    best.addInstruction(&bi5);
    best.addInstruction(&bi6);
    best.addInstruction(&bi7);
    // ----------
    // darwin 8x8
    // ----------

    cout << "*** Darwin 8x8 ***" << endl;
    /*
    8x8 Darwin
    Food,   facing east,  at (0, 0)
    Hopper, facing north, at (3, 3)
    Hopper, facing east,  at (3, 4)
    Hopper, facing south, at (4, 4)
    Hopper, facing west,  at (4, 3)
    Food,   facing north, at (7, 7)
    Simulate 5 moves.
    Print every grid.
    */
    {
        Darwin d(8,8);
        Creature f1(food, 'e');
        d.addCreature(&f1,0,0);
        Creature h1(hopper,'n');
        d.addCreature(&h1,3,3);
        Creature h2(hopper,'e');
        d.addCreature(&h2,3,4);
        Creature h3(hopper,'s');
        d.addCreature(&h3,4,4);
        Creature h4(hopper,'w');
        d.addCreature(&h4,4,3);
        Creature f2(food, 'n');
        d.addCreature(&f1,7,7);
        
        d.print(cout);
        for(int i=1; i<=5;++i){
            d.step();
            d.print(cout,i);
            cout <<endl;
        }
    }
    // ----------
    // darwin 7x9
    // ----------

    cout << "*** Darwin 7x9 ***" << endl;
    srand(0);
    /*
    7x9 Darwin
    Trap,   facing south, at (0, 0)
    Hopper, facing east,  at (3, 2)
    Rover,  facing north, at (5, 4)
    Trap,   facing west,  at (6, 8)
    Simulate 5 moves.
    Print every grid.
    */
    {
        Darwin d(9,7);
        Creature t2_1(trap,'s');
        d.addCreature(&t2_1,0,0);
        Creature h2_1(hopper,'e');
        d.addCreature(&h2_1,2,3);
        Creature r2_1(rover,'n');
        d.addCreature(&r2_1,4,5);
        Creature t2_2(trap,'w');
        d.addCreature(&t2_2,8,6);
        
        d.print(cout);
        for(int i=1; i<=5;++i){
            d.step();
            d.print(cout,i);
            cout <<endl;
        }
    }    
    // ------------
    // darwin 72x72
    // without best
    // ------------

    cout << "*** Darwin 72x72 without Best ***" << endl;
    srand(0);
    /*
    Randomly place the following creatures facing randomly.
    Call rand(), mod it with 5184 (72x72), and use that for the position
    in a row-major order grid.
    Call rand() again, mod it with 4 and use that for it's direction with
    the ordering: west, north, east, south.
    Do that for each kind of creature.
    10 Food
    10 Hopper
    10 Rover
    10 Trap
    Simulate 1000 moves.
    Print the first 10 grids          (i.e. 0, 1, 2...9).
    Print every 100th grid after that (i.e. 100, 200, 300...1000).
    */
    {
        Darwin d(72,72);
        Creature t2_1(trap,'s');
        d.addCreature(&t2_1,0,0);

        char ca[]={'w','n','e','s'};
        
        int pos=0;
        //food
        Creature foods[10];
        for(int i=0;i < 10;++i){
            pos=rand()%5184;
            foods[i]= Creature(food,ca[rand()%4]);
            d.addCreature(&(foods[i]),pos%72,pos/72);
        }
        //hopper
        Creature hoppers[10];
        for(int i=0;i < 10;++i){
            pos=rand()%5184;
            hoppers[i]= Creature(hopper,ca[rand()%4]);
            d.addCreature(&(hoppers[i]),pos%72,pos/72);
        }
        //rover
        Creature rovers[10];
        for(int i=0;i < 10;++i){
            pos=rand()%5184;
            rovers[i]= Creature(rover,ca[rand()%4]);
            d.addCreature(&(rovers[i]),pos%72,pos/72);
        }
        //trap
        Creature traps[10];
        for(int i=0;i < 10;++i){
            pos=rand()%5184;
            traps[i]= Creature(trap,ca[rand()%4]);
            d.addCreature(&(traps[i]),pos%72,pos/72);
        }
        //first 10
        for(int i=0; i <= 10;++i){
            d.step();
            d.print(cout,i);
            cout <<endl;
        }
        d.step(91);
        for(int i=100; i<=1000;i+=100){
            d.print(cout,i);
            d.step(100);
            cout <<endl;
        }
    }    
    // ------------
    // darwin 72x72
    // with best
    // ------------

    cout << "*** Darwin 72x72 with Best ***" << endl;
    srand(0);
    /*
    Randomly place the following creatures facing randomly.
    Call rand(), mod it with 5184 (72x72), and use that for the position
    in a row-major order grid.
    Call rand() again, mod it with 4 and use that for it's direction with
    the ordering: 0:west, 1:north, 2:east, 3:south.
    Do that for each kind of creature.
    10 Food
    10 Hopper
    10 Rover
    10 Trap
    10 Best
    Simulate 1000 moves.
    Best MUST outnumber ALL other species for the bonus pts.
    Print the first 10 grids          (i.e. 0, 1, 2...9).
    Print every 100th grid after that (i.e. 100, 200, 300...1000).
    */
{
        Darwin d(72,72);
        Creature t2_1(trap,'s');
        d.addCreature(&t2_1,0,0);

        char ca[]={'w','n','e','s'};
        
        int pos=0;
        //food
        Creature foods[10];
        for(int i=0;i < 10;++i){
            pos=rand()%5184;
            foods[i]= Creature(food,ca[rand()%4]);
            d.addCreature(&(foods[i]),pos%72,pos/72);
        }
        //hopper
        Creature hoppers[10];
        for(int i=0;i < 10;++i){
            pos=rand()%5184;
            hoppers[i]= Creature(hopper,ca[rand()%4]);
            d.addCreature(&(hoppers[i]),pos%72,pos/72);
        }
        //rover
        Creature rovers[10];
        for(int i=0;i < 10;++i){
            pos=rand()%5184;
            rovers[i]= Creature(rover,ca[rand()%4]);
            d.addCreature(&(rovers[i]),pos%72,pos/72);
        }
        //trap
        Creature traps[10];
        for(int i=0;i < 10;++i){
            pos=rand()%5184;
            traps[i]= Creature(trap,ca[rand()%4]);
            d.addCreature(&(traps[i]),pos%72,pos/72);
        }
        //best
        Creature bests[10];
        for(int i=0;i < 10;++i){
            pos=rand()%5184;
            bests[i]= Creature(best,ca[rand()%4]);
            d.addCreature(&(bests[i]),pos%72,pos/72);
        }
        //first 10
        for(int i=0; i <= 10;++i){
            d.step();
            d.print(cout,i);
            cout <<endl;
        }
        d.step(91);
        for(int i=100; i<=1000;i+=100){
            d.print(cout,i);
            d.step(100);
            cout <<endl;
        }
    }
    return 0;}
