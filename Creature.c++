#include "Creature.h"

Creature::Creature(const Species& s, char d): 
	spec(s), dir(d) {}
	
char Creature::act(char n, char e, char s, char w) { //get instruction and execute
    if(DEBUG)
        cout<<"    C:act(n="<<n <<", e="<<e<<", s="<<s<<", w="<<w<<")"<<endl;
	pair<int, char> result = spec.act(n, e, s, w, pc, dir);
    if(DEBUG)
        cout<<"    C: result: ( "<< result.first <<", " << result.second <<")"<<endl;
    pc=result.first;
    return result.second;
}

void Creature::turnLeft(){
    switch(dir){
        case('n'):
            dir='w';
            break;
        case('s'):
            dir='e';
            break;
        case('e'):
            dir='n';
            break;
        case('w'):
            dir='s';
            break;    
    }
}

void Creature::turnRight(){
    switch(dir){
        case('n'):
            dir='e';
            break;
        case('s'):
            dir='w';
            break;
        case('e'):
            dir='s';
            break;
        case('w'):
            dir='n';
            break;    
    }
}