#include "Species.h"

Species::Species(string s): 
	name(s) {}

	char Species::act(char n, char e, char s, char w, int pc) {
		bool acted = false;
		while(!acted) {
			i[pc].act();
		}
	}

	void Species::addInstruction(const Instruction& inst) {
		i.push_back(inst);
	}