#include "Creature.h"

Creature::Creature(const Species& s, char d): 
	spec(s) {}
	
char Creature::act(char n, char e, char s, char w) { //get instruction and execute
	spec.act(n, e, s, w, pc, dir);
	return 'c';//change me
}

	