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

    //vector<Creature> v(w*h);
    grid.resize(h, vector<Creature*>(w, nullptr)); // = vector< vector<Creature>(w) >(h);
}



void Darwin::step(int n){
	int w= grid[0].size();
	int h= grid.size();
    Creature* cp;
	for(int i=0; i < n; ++i){  // for every step
		for( int j=0; j < h; ++j){  // for every row (iterate across y)
			for( int k=0; k < w; ++k){ //for every element in the row (iterate across x)
                cp = grid[j][k];
				if(cp!=nullptr && !(cp->acted) ) // if its an active creature
                    processCell(k,j);
                if(cp->acted) // if after processing the creature has acted, can reset
                    cp->acted=false;  // since it will not return in this pass
			}
		}
        cp=nullptr;
	}
}

void Darwin::processCell(int x, int y){
	char n,s,w,e;
    Creature* creature = grid[y][x];
	string name="";
	name = (creature->spec).name;
	// north cell
	if(y==0) { // if its the top row
		n='u';
	} else{
		n=cellContent(x,y-1,name);
	}
	// south cell
	if(y== (int)grid.size()-1) { // if its the bottom row
		s='u';
	} else{
		s=cellContent(x,y+1,name);
	}
	//west cell
	if( x==0 ) {
		w='u';
	} else {
		w=cellContent(x-1,y,name);
	}
	//east cell
	if( x== (int)(grid[0].size())-1 ) {
		e='u';
	} else {
		e=cellContent(x+1,y,name);
	}
	// act on the gathered data
    char response = creature->act(n,s,e,w);
/* RESPONSE CHARACTERS - what action should be taken
	l r   //rotation
	n e s w    //movement
	o k , ;    //infection direction
//*/    
    switch(response){
        //rotate
        case('l'):
            creature->turnLeft();
            break;
        case('r'):
            creature->turnRight();
            break;
        //move
        case('n'):
            grid[y-1][x]=creature; //write pointer to new location
            grid[y][x]=nullptr;     //write nullpointer to old location
            break;
        case('w'):
            grid[y][x-1]=creature; //write pointer to new location
            grid[y][x]=nullptr;     //write nullpointer to old location
            break;
        case('s'):
            creature->acted=true;   //since it is moving forward in the analysis queue
            grid[y+1][x]=creature; //write pointer to new location
            grid[y][x]=nullptr;     //write nullpointer to old location
            break;
        case('e'):
            creature->acted=true;   //since it is moving forward in the analysis queue
            grid[y+1][x+1]=creature; //write pointer to new location
            grid[y][x]=nullptr;     //write nullpointer to old location
            break;
        //infect
        case('o')://creature above is to be infected
            grid[y-1][x]->spec = grid[y][x]->spec;// infect
            grid[y][x]->pc=0;                           //pc reset
            break;
        case('k')://creature west is to be infected
            grid[y][x-1]->spec = grid[y][x]->spec;// infect
            grid[y][x]->pc=0;                           //pc reset
            break;
        case(',')://creature below is to be infected
            grid[y+1][x]->spec = grid[y][x]->spec;// infect
            grid[y][x]->pc=0;                           //pc reset
            break;
        case(';')://creature east is to be infected
            grid[y][x+1]->spec = grid[y][x]->spec;// infect
            grid[y][x]->pc=0;                           //pc reset
            break;
    }
}

char Darwin::cellContent(int x, int y, string name){
	if( grid[y][x] == nullptr )
		return 'a';
	if( name == grid[y][x]->spec.name )
		return 'u';
	return 'e';
}

void Darwin::addCreature ( Creature* c, int w, int h) {
    grid[w][h] = c;
}