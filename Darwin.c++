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
#include <sstream>  // istringstream, ostringstream
#include <string>   // getline, string
#include <utility>  // make_pair, pair
#include <stdio.h>  // printf

#include "Darwin.h"

using namespace std;

Darwin::Darwin (int w, int h) {
    //vector<Creature> v(w*h);
    grid.resize(h, vector<Creature*>(w, nullptr)); // = vector< vector<Creature>(w) >(h);
}


void Darwin::step(int n){
    if(DEBUG)
        cout <<"Stepping "<<n<<" times over ";
	int w= grid[0].size();
	int h= grid.size();
    if(DEBUG)
        cout <<w<<"x"<<h<<" grid"<<endl;

    Creature* cp;
    if(DEBUG)
        print(cout,0);
	for(int i=0; i < n; ++i){  // for every step
		for( int j=0; j < h; ++j){  // for every row (iterate across y)
			for( int k=0; k < w; ++k){ //for every element in the row (iterate across x)
                if(DEBUG){
                    cout <<"----checking grid["<<j<<"]["<<k<<"]=";
                    //if(cp)
                        //print(cout);
                }
                cp = grid[j][k];
                if(DEBUG)
                    cout << (long int)cp%100;
                if(DEBUG && cp)
                    cout <<" -> "  << cp->acted<<endl;
                else if (DEBUG)
                    cout << endl;
				if(cp!=nullptr && !(cp->acted) ) {// if its an active creature
                    processCell(k,j);
                }
                if(grid[j][k]!=nullptr && cp->acted){ // if after processing the creature has acted, can reset
                    cp->acted=false;  // since it will not return in this pass
                }
			}
		}
        cp=nullptr;
        if(DEBUG)
            print(cout,i+1);
	}
}

void Darwin::processCell(int x, int y){

    if(DEBUG)
        cout << "processing cell("<<x<<", "<<y<<")" << endl;

	char n,s,w,e;
    Creature* creature = grid[y][x];
	string name=(creature->spec).name;
	// north cell
    if(DEBUG)
        cout << " north cell-";
	if(y==0) { // if its the top row
		n='u';
	} else{
		n=cellContent(x,y-1,name);
        if(DEBUG)
            cout << " -returned n="<< n << endl;
	}
	// south cell
    if(DEBUG)
        cout << " south cell-";
	if(y== (int)grid.size()-1) { // if its the bottom row
		s='u';
	} else{
		s=cellContent(x,y+1,name);
        if(DEBUG)
            cout << " -returned s="<< s << endl;
	}
	//west cell
    if(DEBUG)
        cout << " west cell-";
	if( x==0 ) {
		w='u';
	} else {
		w=cellContent(x-1,y,name);
        if(DEBUG)
            cout << " -returned w="<< w << endl;
	}
	//east cell
    if(DEBUG)
        cout << " east cell-";
	if(x== (int)(grid[0].size())-1) {
		e='u';
	} else {
		e=cellContent(x+1,y,name);
        if(DEBUG)
            cout << " -returned e="<< e << endl;
	}
	// act on the gathered data
    if(DEBUG)
        cout << "  gathering response...";
    char response = creature->act(n,e,s,w);
    if(DEBUG)
        cout << "  response gotten: '" << response << "'" << endl;
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
            grid[y][x+1]=creature; //write pointer to new location
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
    if(DEBUG)
        cout << "  checking cell content (" <<x<<", "<<y<<", "<<name<<"): "<<(long int)(grid[y][x])%100<<endl;
	if( grid[y][x] == nullptr )
		return 'a';
	if( name == grid[y][x]->spec.name )
		return 'f';
	return 'm';
}

void Darwin::addCreature ( Creature* c, int w, int h) {
    grid[h][w] = c;
}

void Darwin::print(ostream& w, int turn) {
    //printf("*** Darwin %dx%d ***\n", (int)grid.size(), (int)grid[0].size());
    w << "Turn = " << turn << ".\n";
    unsigned char i = 0;
    unsigned char p = 0;
    w << "  ";
    while (p < grid[0].size()) {
        //The following if statements are to keep the printed indicies numbers and letters
        if (i == 10) {
            i += 7;
        }
        if (i == 43) {
            i += 7;
        }
        if (i == 74) {
            i = 0;
        }
        w << char('0' + i);
        ++i;
        ++p;
    }
    endl(w);
    i = 0;
    p = 0;
    while (p < grid.size()) {
        if (i == 10) {
            i += 7;
        }
        if (i == 43) {
            i += 7;
        }
        if (i == 74) {
            i = 0;
        }
        w << char('0' + i) << " ";
        unsigned int j = 0;
        while (j < grid[0].size()) {
            (grid[p][j] == nullptr) ? w << "." : w << grid[p][j]->spec.name[0];  //change
            ++j;
        }
        endl(w);
        ++i;
        ++p;
    }
}