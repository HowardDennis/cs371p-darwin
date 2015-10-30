#pragma once
#include <string>        // String
#include <vector>

using namespace std;

class Instruction {
	private:
		vector<string> names;

		void hop();
		void left();
		void right();
		void infect();
		void if_empty();
		void if_wall();
		void if_random();
		void if_enemy();
		void go();
		
	public:
		Instruction();

};