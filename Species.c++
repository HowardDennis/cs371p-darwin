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
        else
            pc=result.first;
	}
	return result;
}

void Species::addInstruction(Instruction* inst) {
	i.push_back(inst);
}