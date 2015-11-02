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

    //vector<const Creature> v(w*h);
    grid.resize(h, vector< const Creature*>(w, nullptr)); // = vector< vector<Creature>(w) >(h);
}



void Darwin::step(int n){
	int w= grid[0].size();
	int h= grid.size();
	for(int i=0; i < n; ++i){  // for every step
		for( int j=0; j < h; ++j){  // for every row (iterate across y)
			for( int k=0; k < w; ++k){ //for every element in the row (iterate across x)
				if(grid[j][k]!=nullptr) // if its a creature
					processCell(k,j);
			}
		}
	}
}

void Darwin::processCell(int x, int y){
	char n,s,w,e;
	string name="";
	name = (grid[y][x]->spec).name;
	// north cell
	if(x==0) { // if its the top row
		n='u';
	} else{
		n=cellContent(x-1,y,name);
	}
	// south cell
	if(x== (int)grid.size()-1) { // if its the top row
		s='u';
	} else{
		s=cellContent(x+1,y,name);
	}
	//west cell
	if( y==0 ) {
		w='u';
	} else {
		w=cellContent(x,y-1,name);
	}
	//east cell
	if( y== (int)(grid[0].size())-1 ) {
		e='u';
	} else {
		e=cellContent(x,y+1,name);
	}
	// act on the gathered data

}

char Darwin::cellContent(int x, int y, string name){
	if( grid[y][x] == nullptr )
		return 'a';
	if( name == grid[y][x]->spec.name )
		return 'u';
	return 'e';
}

void Darwin::addCreature ( const Creature* c, int w, int h) {
    grid[w][h] = c;
}