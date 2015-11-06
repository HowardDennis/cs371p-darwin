#include "Species.h"

Species::Species(string s): 
	name(s) {}

/**
 *  Has the species act based on it's instruction list
 */

pair <int, char> Species::act(char n, char e, char s, char w, int pc, char dir) {
	if(DEBUG)
        cout<<"   S:act(n="<<n <<", e="<<e<<", s="<<s<<", w="<<w<<", pc="<<pc<<", dir="<<dir<<")"<<endl;
    bool acted = false;
    pair<int, char> result;
    if(DEBUG)
            cout<< "   instruction count: "<< i.size()<< endl;
	while(!acted) {
		result = (i[pc])->act(n,e,s,w,pc,dir);
        if(DEBUG)
            cout<< "   S loop result:"<< result.first <<", " << result.second<< endl;
        if(result.second!='c')
            acted=true;
        else
            pc=result.first;
	}
	return result;
}

/**
 *  Adds an instruction to the vector of instructions
 */

void Species::addInstruction(Instruction* inst) {
	i.push_back(inst);
}