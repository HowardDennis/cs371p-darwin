#include "Species.h"

Species::Species(string s): 
	name(s) {}

	char Species::act(char n, char e, char s, char w, int pc, char dir) {
		bool acted = false;
		while(!acted) {
			(i[pc])->act(n,e,s,w,pc,dir);
		}
		return 'c';//change me
	}

	void Species::addInstruction(Instruction* inst) {
		i.push_back(inst);
	}

/*
	char l,r; //rotation
	n,e,s,w; //movement
	w,q,x,d  //infection direction
	m // malfactor (which mean enemy)
	a //available
	c //control, d next instruction
//*/