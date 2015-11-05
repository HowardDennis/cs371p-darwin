#include "Instruction.h"
#include <cassert>

//ACTION
class Hop : private Instruction {
	Hop(){}
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
		}
		assert(false);
		pair<int, char> p = {-1,'!'};
		return p;
	};

};

class Left : private Instruction {
	Left(){}
	pair<int, char> act(char n, char e, char s, char w, int pc, char dir){
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

	};

};

class Right : private Instruction {
	Right(){}
	pair<int, char> act(char n, char e, char s, char w, int pc, char dir){
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
	};

};

class Infect : private Instruction {
	Infect(){}
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
						return pair<int, char> (++pc, 'l');
					}				break;

			case 'w' : 
					if (w == 'm') {
						return pair<int, char> (++pc, 'k');
					}
				break;

		}
	};

};

//CONTROL

class If_Empty : private Instruction {
	int num;
	If_Empty(){}
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
	};

};

class If_Wall : private Instruction {
	int num;
	If_Wall(int _n) : num(_n) {}
	pair<int, char> act(char n, char e, char s, char w, int pc, char dir){
		switch(dir) {
			case 'n' : 
					if (n != 'a') {
						return pair<int, char> (num, 'c');
					}

					return pair<int, char> (++pc, 'c');

				break;

			case 'e' : 
					if (e != 'a') {
						return pair<int, char> (num, 'c');
					}

					return pair<int, char> (++pc, 'c');

				break;

			case 's' : 
					if (s != 'a') {
						return pair<int, char> (num, 'c');
					}		

					return pair<int, char> (++pc, 'c');

				break;
				
			case 'w' : 
					if (w != 'a') {
						return pair<int, char> (num, 'c');
					}

					return pair<int, char> (++pc, 'c');

				break;

		}
	};

};

class If_Random : private Instruction {
	int num;
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
	If_Enemy(int _n) : num(_n) {}
	pair<int, char> act(char n, char e, char s, char w, int pc, char dir){
		switch(dir) {
			//m stands for malfactor, which mean enemy
			case 'n' : 
					if (n == 'm') { 
						return pair<int, char> (num, 'w');
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
					return pair<int, char> (++pc, 'c');
				break;

		}
	};

};

class Go : private Instruction {
	int num;
	Go(int _n) : num(_n) {}
	pair<int, char> act(char n, char e, char s, char w, int pc, char dir){
		return pair<int, char> (num, 'c');
	};

};