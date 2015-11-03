#pragma once
#include <string>        // String
#include <vector>
#include <utility>       //Pair
#include <cstdlib>       //random

using namespace std;

class Instruction {
	
	public:
		Instruction();
		virtual ~Instruction();

		virtual pair<int, char> act(char, char, char, char, int, char) = 0;

};