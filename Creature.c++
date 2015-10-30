#include "Creature.h"

Creature::Creature(const Species& s, char d): 
	spec(s), 
	dir(d), 
	pc(0), 
	acted(false) {}

	