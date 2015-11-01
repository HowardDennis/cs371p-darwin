#include "Instruction.h"

class Hop : private Instruction {
	Hop () {

	}
	pair<int, char> act(char, char, char, char, int);

};