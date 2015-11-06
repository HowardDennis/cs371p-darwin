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
#include <iterator> // input_iterator_tag
#include "Creature.h"

#define DEBUG false

using namespace std;

class Darwin_Iterator;

class Darwin {
	friend class Darwin_Iterator;
    private:
		vector < vector<Creature*> > grid;
		void step(int n=1); // a single step
		void processCell(int,int); // processes cell at grid[y][x]
		char cellContent(int,int,string name = "blank");
        
        FRIEND_TEST(DarwinFixture, Darwin_construct_default);
        FRIEND_TEST(DarwinFixture, Darwin_construct_args_1);
        FRIEND_TEST(DarwinFixture, Darwin_construct_args_2);
        FRIEND_TEST(DarwinFixture, Darwin_construct_args_3);
        FRIEND_TEST(DarwinFixture, Darwin_add_creature_1);
        FRIEND_TEST(DarwinFixture, Darwin_add_creature_2);
        FRIEND_TEST(DarwinFixture, Darwin_add_creature_3);
        FRIEND_TEST(DarwinFixture, Darwin_cell_content_1);
        FRIEND_TEST(DarwinFixture, Darwin_cell_content_2);
        FRIEND_TEST(DarwinFixture, Darwin_cell_content_3);
        FRIEND_TEST(DarwinFixture, Darwin_process_cell_1);
        FRIEND_TEST(DarwinFixture, Darwin_process_cell_2);
        FRIEND_TEST(DarwinFixture, Darwin_process_cell_3);
        FRIEND_TEST(DarwinFixture, Darwin_step_1);
        FRIEND_TEST(DarwinFixture, Darwin_step_2);
        FRIEND_TEST(DarwinFixture, Darwin_step_3);
        FRIEND_TEST(DarwinFixture, Darwin_iteration_1);
        FRIEND_TEST(DarwinFixture, Darwin_iteration_2);
        
	public:
        Darwin_Iterator begin();
        Darwin_Iterator end();
        const Creature& at(int n);
		Darwin (int w = 1, int h = 1); // default is 1x1
		void addCreature(Creature*, int, int);
        void print(ostream& w, int turn=0);
};

class Darwin_Iterator : public iterator<input_iterator_tag, int> {
    
    FRIEND_TEST(DarwinFixture, Darwin_iteration_1);
    FRIEND_TEST(DarwinFixture, Darwin_iteration_2);
    
    int _p; // position
    Darwin* d;
public:
    Darwin_Iterator(int v, Darwin* dar) :
                _p (v), d(dar)
            {}
    bool operator == (const Darwin_Iterator& rhs) const {
            return (_p == rhs._p);}

    bool operator != (const Darwin_Iterator& rhs) const {
        return !(*this == rhs);}

    const Creature& operator * () const {
        int width = d->grid[0].size();
        cout << width << endl;
        return *(d->grid[_p/width][_p%width]);}

    Darwin_Iterator& operator ++ () {
        ++_p;
        return *this;}

    Darwin_Iterator operator ++ (int) {
        Darwin_Iterator x = *this;
        ++*this;
        return x;}
};
