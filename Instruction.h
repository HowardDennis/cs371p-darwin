#pragma once
#include <string>        // String
#include <vector>
#include <utility>       //Pair
#include <cstdlib>       //random

using namespace std;

/**
 *  Interface for the individual instructions
 */

class Instruction {
	
	public:
		Instruction(){}
		~Instruction(){}

		virtual pair<int, char> act(char, char, char, char, int, char) = 0;

};