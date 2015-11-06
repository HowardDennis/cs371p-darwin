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

/**
 *  Moves the creature forward one space based on where it's facing
 */

class Hop : public Instruction {
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
    FRIEND_TEST(DarwinFixture, Darwin_step_1);
        
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

/**
 *  Turns the creature left
 */

class Left : public Instruction {
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

/**
 *  Turns the creature right
 */

class Right : public Instruction {
public:
	Right(){}
private:
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

/**
 *  Changes the creature ahead to the infector's species
 */

class Infect : public Instruction {
public:
	Infect(){}
private:
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

/**
 *  Checks if the space ahead is empty
 */

class If_Empty : public Instruction {
public:
    If_Empty(int n): num(n){}
private:
    int num;

	FRIEND_TEST(DarwinFixture, Darwin_Instruction_Ifempty_n);
	FRIEND_TEST(DarwinFixture, Darwin_Instruction_Ifempty_s);
	FRIEND_TEST(DarwinFixture, Darwin_Instruction_Ifempty_e);
	FRIEND_TEST(DarwinFixture, Darwin_Instruction_Ifempty_w);
    
    FRIEND_TEST(DarwinFixture, Darwin_process_cell_3);

	
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

/**
 *  Checks if the space ahead is outside of the grid
 */

class If_Wall : public Instruction {
public:
    If_Wall(int _n) : num(_n) {}
private:
	int num;
    
    FRIEND_TEST(DarwinFixture, Darwin_Instruction_Ifwall_n);
    FRIEND_TEST(DarwinFixture, Darwin_Instruction_Ifwall_s);
    FRIEND_TEST(DarwinFixture, Darwin_Instruction_Ifwall_e);
    FRIEND_TEST(DarwinFixture, Darwin_Instruction_Ifwall_w);
    

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

/**
 *  Controls the creature if there is a random number
 */

class If_Random : public Instruction {
public:
    If_Random(int _n) : num(_n) {}
private:
    int num;
    
    FRIEND_TEST(DarwinFixture, Darwin_Instruction_Ifrandom);
    
	
	pair<int, char> act(char n, char e, char s, char w, int pc, char dir){
		int r = rand();
		r %= 2;
		if (r) {
			return pair<int, char> (num, 'c');
		}
		return pair<int, char> (++pc, 'c');
	}
	

};

/**
 *  Sees if there is an enemy ahead
 */

class If_Enemy : public Instruction {
public:
    If_Enemy(int _n) : num(_n) {}
private:
    int num;
    
    FRIEND_TEST(DarwinFixture, Darwin_Instruction_Ifenemy_n);
    FRIEND_TEST(DarwinFixture, Darwin_Instruction_Ifenemy_s);
    FRIEND_TEST(DarwinFixture, Darwin_Instruction_Ifenemy_e);
    FRIEND_TEST(DarwinFixture, Darwin_Instruction_Ifenemy_w);
    
    FRIEND_TEST(DarwinFixture, Darwin_Species_act_3);
    
    FRIEND_TEST(DarwinFixture, Darwin_Creature_act_1);
    FRIEND_TEST(DarwinFixture, Darwin_Creature_act_2);
    
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

/**
 *  Goes to the instruction number indicated
 */

class Go : public Instruction {
public:
    Go(int _n) : num(_n) {}
private:	
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
    FRIEND_TEST(DarwinFixture, Darwin_step_1);
   
	pair<int, char> act(char n, char e, char s, char w, int pc, char dir){
		return pair<int, char> (num, 'c');
	};
};
