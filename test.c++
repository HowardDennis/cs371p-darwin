#include "Darwin.h"

int main () {
	Darwin d(80, 80);
	Species s1("test species 1");
	Species s2("d");
	Creature c1(s1,'n');
	Creature c2(s2,'s');
	d.addCreature(&c1, 1, 1);
	d.addCreature(&c2, 50, 49);
	d.print();

}