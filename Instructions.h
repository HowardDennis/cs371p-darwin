#include "Instruction.h"
#include <cassert>
#include <iostream> //cout, endl
#include "gtest/gtest_prod.h"

/* INSTRUCTIONS:
		RESPONSE CHARACTERS - what action should be taken
			l r       //rotation
			n e s w   //movement
			z 	 	  // do nothing
			o k , ;   //infection direction
		SIGNAL CHARACTERS - inform the creature so it can decide on an action
			m // malfactor (enemy)
            f // friend
			a //available
			c //control, d next instruction
			u //unavailable space
//*/

//ACTION
class Hop : private Instruction {
public:
	Hop(){}
private:	
	FRIEND_TEST(DarwinFixture, Darwin_Instruction_Hop_act_n1);
	FRIEND_TEST(DarwinFixture, Darwin_Instruction_Hop_act_n2);
	FRIEND_TEST(DarwinFixture, Darwin_Instruction_Hop_act_s1);
	FRIEND_TEST(DarwinFixture, Darwin_Instruction_Hop_act_s2);
	FRIEND_TEST(DarwinFixture, Darwin_Instruction_Hop_act_w1);
	FRIEND_TEST(DarwinFixture, Darwin_Instruction_Hop_act_w2);
	FRIEND_TEST(DarwinFixture, Darwin_Instruction_Hop_act_e1);
	FRIEND_TEST(DarwinFixture, Darwin_Instruction_Hop_act_e2);
    
    FRIEND_TEST(DarwinFixture, Darwin_Species_addInstruction);
    FRIEND_TEST(DarwinFixture, Darwin_Species_act_1);
    FRIEND_TEST(DarwinFixture, Darwin_Species_act_2);
    FRIEND_TEST(DarwinFixture, Darwin_Creature_act_3);
    
    FRIEND_TEST(DarwinFixture, Darwin_process_cell_3);
        
	pair<int, char> act(char n, char e, char s, char w, int pc, char dir){
		switch(dir) {
			case 'n' : 
					if (n == 'a') {
						return pair<int, char> (++pc, dir);
					}
				break;

			case 'e' : 
					if (e == 'a') {
						return pair<int, char> (++pc, dir);
					}
				break;

			case 's' : 
					if (s == 'a') {
						return pair<int, char> (++pc, dir);
					}				
				break;

			case 'w' : 
					if (w == 'a') {
						return pair<int, char> (++pc, dir);
					}
				break;

		};
		pair<int, char> p = {++pc,'z'};
		return p;
	};

};

class Left : private Instruction {
public:
	Left(){}
private:
	FRIEND_TEST(DarwinFixture, Darwin_Instruction_Left_act);
    
    FRIEND_TEST(DarwinFixture, Darwin_Species_act_3);
    
    FRIEND_TEST(DarwinFixture, Darwin_Creature_act_1);
    FRIEND_TEST(DarwinFixture, Darwin_Creature_act_2);
    
    FRIEND_TEST(DarwinFixture, Darwin_process_cell_1);
    FRIEND_TEST(DarwinFixture, Darwin_process_cell_2);
    
	pair<int, char> act(char n, char e, char s, char w, int pc, char dir){
/*
		switch(dir) {
			case 'n' : 
					return pair<int, char> (++pc, 'w');
				break;

			case 'e' : 
					return pair<int, char> (++pc, 'n');
				break;

			case 's' : 
					return pair<int, char> (++pc, 'e');
					break;

			case 'w' : 
					return pair<int, char> (++pc, 's');
				break;

		}
//*/
		return pair<int,char>(++pc,'l');
	}

};

class Right : private Instruction {
	Right(){}
	FRIEND_TEST(DarwinFixture, Darwin_Instruction_Right_act);
    
    FRIEND_TEST(DarwinFixture, Darwin_process_cell_3);
    
	pair<int, char> act(char n, char e, char s, char w, int pc, char dir){
		/*
		switch(dir) {
			case 'n' : 
					return pair<int, char> (++pc, 'e');
				break;

			case 'e' : 
					return pair<int, char> (++pc, 's');
				break;

			case 's' : 
					return pair<int, char> (++pc, 'w');
					break;

			case 'w' : 
					return pair<int, char> (++pc, 'n');
				break;

		}
		//*/
		return pair<int,char>(++pc,'r');
	};

};

class Infect : private Instruction {
	Infect(){}
	FRIEND_TEST(DarwinFixture, Darwin_Instruction_Infect_n);
	FRIEND_TEST(DarwinFixture, Darwin_Instruction_Infect_s);
	FRIEND_TEST(DarwinFixture, Darwin_Instruction_Infect_e);
	FRIEND_TEST(DarwinFixture, Darwin_Instruction_Infect_w);
    
    FRIEND_TEST(DarwinFixture, Darwin_Species_addInstruction);
    FRIEND_TEST(DarwinFixture, Darwin_Species_act_2);
    
    FRIEND_TEST(DarwinFixture, Darwin_Creature_act_1);
    FRIEND_TEST(DarwinFixture, Darwin_Creature_act_2);
    FRIEND_TEST(DarwinFixture, Darwin_process_cell_2);
    
	pair<int, char> act(char n, char e, char s, char w, int pc, char dir){
		switch(dir) {
			//m stands for malfactor, which mean enemy
			case 'n' : 
					if (n == 'm') { 
						return pair<int, char> (++pc, 'o');
					}
				break;

			case 'e' : 
					if (e == 'm') {
						return pair<int, char> (++pc, ';');
					}
				break;

			case 's' : 
					if (s == 'm') {
						return pair<int, char> (++pc, ',');
					}
					break;

			case 'w' : 
					if (w == 'm') {
						return pair<int, char> (++pc, 'k');
					}
				break;
		}
		return pair<int,char>(++pc,'z');
	};

};

//CONTROL
class If_Empty : private Instruction {
	int num;

	FRIEND_TEST(DarwinFixture, Darwin_Instruction_Ifempty_n);
	FRIEND_TEST(DarwinFixture, Darwin_Instruction_Ifempty_s);
	FRIEND_TEST(DarwinFixture, Darwin_Instruction_Ifempty_e);
	FRIEND_TEST(DarwinFixture, Darwin_Instruction_Ifempty_w);
    
    FRIEND_TEST(DarwinFixture, Darwin_process_cell_3);

	If_Empty(int n): num(n){}
	pair<int, char> act(char n, char e, char s, char w, int pc, char dir){
		switch(dir) {
			case 'n' : 
					if (n == 'a') {
						return pair<int, char> (num, 'c');
					}

					return pair<int, char> (++pc, 'c');

				break;

			case 'e' : 
					if (e == 'a') {
						return pair<int, char> (num, 'c');
					}

					return pair<int, char> (++pc, 'c');

				break;

			case 's' : 
					if (s == 'a') {
						return pair<int, char> (num, 'c');
					}		

					return pair<int, char> (++pc, 'c');

				break;

			case 'w' : 
					if (w == 'a') {
						return pair<int, char> (num, 'c');
					}

					return pair<int, char> (++pc, 'c');

				break;

		}
		assert(false); // if this is reached, an invalid char made it in somehow
		return pair<int,char>(++pc,'c');
	}

};

class If_Wall : private Instruction {
	int num;
    
    FRIEND_TEST(DarwinFixture, Darwin_Instruction_Ifwall_n);
    FRIEND_TEST(DarwinFixture, Darwin_Instruction_Ifwall_s);
    FRIEND_TEST(DarwinFixture, Darwin_Instruction_Ifwall_e);
    FRIEND_TEST(DarwinFixture, Darwin_Instruction_Ifwall_w);
    
	If_Wall(int _n) : num(_n) {}
	pair<int, char> act(char n, char e, char s, char w, int pc, char dir){
		switch(dir) {
			case 'n' : 
					if (n == 'u') {
						return pair<int, char> (num, 'c');
					}

					return pair<int, char> (++pc, 'c');

				break;

			case 'e' : 
					if (e == 'u') {
						return pair<int, char> (num, 'c');
					}

					return pair<int, char> (++pc, 'c');

				break;

			case 's' : 
					if (s == 'u') {
						return pair<int, char> (num, 'c');
					}		

					return pair<int, char> (++pc, 'c');

				break;
				
			case 'w' : 
					if (w == 'u') {
						return pair<int, char> (num, 'c');
					}

					return pair<int, char> (++pc, 'c');
				break;
		}
        assert(false);//this should not happen
        return pair<int,char> (666,'!');
        
	}

};

class If_Random : private Instruction {
	int num;
    
    FRIEND_TEST(DarwinFixture, Darwin_Instruction_Ifrandom);
    
	If_Random(int _n) : num(_n) {}
	pair<int, char> act(char n, char e, char s, char w, int pc, char dir){
		int r = rand();
		r %= 2;
		if (r) {
			return pair<int, char> (num, 'c');
		}
		return pair<int, char> (++pc, 'c');
	}
	

};

class If_Enemy : private Instruction {
	int num;
    
    FRIEND_TEST(DarwinFixture, Darwin_Instruction_Ifenemy_n);
    FRIEND_TEST(DarwinFixture, Darwin_Instruction_Ifenemy_s);
    FRIEND_TEST(DarwinFixture, Darwin_Instruction_Ifenemy_e);
    FRIEND_TEST(DarwinFixture, Darwin_Instruction_Ifenemy_w);
    
    FRIEND_TEST(DarwinFixture, Darwin_Species_act_3);
    
    FRIEND_TEST(DarwinFixture, Darwin_Creature_act_1);
    FRIEND_TEST(DarwinFixture, Darwin_Creature_act_2);
    
	If_Enemy(int _n) : num(_n) {}
	pair<int, char> act(char n, char e, char s, char w, int pc, char dir){
		switch(dir) {
			//m stands for malfactor, which mean enemy
			case 'n' : 
					if (n == 'm') { 
						return pair<int, char> (num, 'c');
					}
					return pair<int, char> (++pc, 'c');
				break;

			case 'e' : 
					if (e == 'm') {
						return pair<int, char> (num, 'c');
					}
					return pair<int, char> (++pc, 'c');
				break;

			case 's' : 
					if (s == 'm') {
						return pair<int, char> (num, 'c');
					}				
					return pair<int, char> (++pc, 'c');
				break;

			case 'w' : 
					if (w == 'm') {
						return pair<int, char> (num, 'c');
					}
					return pair <int, char> (++pc, 'c');
				break;

		}
        assert(false); // should not occur
        return pair<int,char> (666,'!');
	}

};

class Go : private Instruction {
	int num;
    
    FRIEND_TEST(DarwinFixture, Darwin_Instruction_Go);
    
    FRIEND_TEST(DarwinFixture, Darwin_Species_addInstruction);
    FRIEND_TEST(DarwinFixture, Darwin_Species_act_1);
    FRIEND_TEST(DarwinFixture, Darwin_Species_act_2);
    FRIEND_TEST(DarwinFixture, Darwin_Species_act_3);
    
    FRIEND_TEST(DarwinFixture, Darwin_Creature_act_1);
    FRIEND_TEST(DarwinFixture, Darwin_Creature_act_2);
    FRIEND_TEST(DarwinFixture, Darwin_Creature_act_3);
    
    FRIEND_TEST(DarwinFixture, Darwin_process_cell_1);
    FRIEND_TEST(DarwinFixture, Darwin_process_cell_2);
    
    FRIEND_TEST(DarwinFixture, Darwin_process_cell_3);
    
	Go(int _n) : num(_n) {}
	pair<int, char> act(char n, char e, char s, char w, int pc, char dir){
		return pair<int, char> (num, 'c');
	};
};
