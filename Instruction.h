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

/*  	void hop();
		void left();
		void right();
		void infect();
		void if_empty();
		void if_wall();
		void if_random();
		void if_enemy();
		void go(); //*/