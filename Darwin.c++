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

// ------------
// darwin_read
// ------------

pair<int, int> darwin_read (const string& s) {
    istringstream sin(s);
    int i;
    int j;
    sin >> i >> j;
    return make_pair(i, j);}

// ------------
// darwin_eval
// ------------

int darwin_eval (int i, int j) {
    // <your code>
    return 1;}

// -------------
// darwin_print
// -------------

void darwin_print (ostream& w, int i, int j, int v) {
    w << i << " " << j << " " << v << endl;}

// -------------
// darwin_solve
// -------------

void darwin_solve (istream& r, ostream& w) {
    string s;
    while (getline(r, s)) {
        const pair<int, int> p = darwin_read(s);
        const int            i = p.first;
        const int            j = p.second;
        const int            v = darwin_eval(i, j);
        darwin_print(w, i, j, v);}}
