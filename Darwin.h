// --------------------------
// projects/darwin/Darwin.h
// Copyright (C) 2015
// Glenn P. Downing
// --------------------------

#ifndef Darwin_h
#define Darwin_h

// --------
// includes
// --------

#include <iostream> // istream, ostream
#include <string>   // string
#include <utility>  // pair

using namespace std;

// ------------
// darwin_read
// ------------

/**
 * read two ints
 * @param s a string
 * @return a pair of ints, representing the beginning and end of a range, [i, j]
 */
pair<int, int> darwin_read (const string& s);

// ------------
// darwin_eval
// ------------

/**
 * @param i the beginning of the range, inclusive
 * @param j the end       of the range, inclusive
 * @return the max cycle length of the range [i, j]
 */
int darwin_eval (int i, int j);

// -------------
// darwin_print
// -------------

/**
 * print three ints
 * @param w an ostream
 * @param i the beginning of the range, inclusive
 * @param j the end       of the range, inclusive
 * @param v the max cycle length
 */
void darwin_print (ostream& w, int i, int j, int v);

// -------------
// darwin_solve
// -------------

/**
 * @param r an istream
 * @param w an ostream
 */
void darwin_solve (istream& r, ostream& w);

#endif // Darwin_h
