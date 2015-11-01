#include "Species.h"

Species::Species(string s): 
	name(s) {}

	char Species::act(char n, char e, char s, char w, int pc) {
		bool acted = false;
		while(!acted) {
			(i[pc])->act(n,e,s,w,pc);
		}
		return 'c';//change me
	}

	void Species::addInstruction(Instruction* inst) {
		i.push_back(inst);
	}