#include "Instruction.h"

class Hop : private Instruction {
	Hop(){}
	~Hop(){}
	pair<int, char> act(char, char, char, char, int){
		pair<int, char> p = {2,'c'};
		return p;
	};

};