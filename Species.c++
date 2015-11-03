#include "Species.h"

Species::Species(string s): 
	name(s) {}

pair <int, char> Species::act(char n, char e, char s, char w, int pc, char dir) {
	bool acted = false;
    pair<int, char> result;
	while(!acted) {
		result = (i[pc])->act(n,e,s,w,pc,dir);
        if(result.second!='c')
            acted=true;
	}
	return result;//change me
}

void Species::addInstruction(Instruction* inst) {
	i.push_back(inst);
}

/*
RESPONSE CHARACTERS - what action should be taken
	l r       //rotation
	n e s w   //movement
	o k , ;   //infection direction
SIGNAL CHARACTERS - inform the creature so it can decide on an action
	m // malfactor (which mean enemy)
	a //available
	c //control, d next instruction
	u //unavailable space
//*/