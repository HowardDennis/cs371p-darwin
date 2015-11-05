#include <sstream>  // istringtstream, ostringstream
#include "Darwin.h"

int main () {
	Darwin d(4, 4);
	Species s1("test species 1");
	Species s2("d");
	Creature c1(s1,'n');
	Creature c2(s2,'s');
	d.addCreature(&c1, 1, 1);
	d.addCreature(&c2, 3, 3);
	//*/
	ostringstream w;
	d.print(w);
	cout << w.str();
}