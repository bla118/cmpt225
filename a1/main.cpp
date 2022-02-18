using namespace std;
#include <iostream>
#include "StringSet.h"

int main()
{

	StringSet sset1;
	sset1.insert("cat");
	sset1.insert("bat");
	sset1.insert("rat");
	sset1.insert("badger");
	cout << "sset1: " << endl;
	sset1.getSet();
	StringSet sset2;
	sset2.insert("elephant");
	sset2.insert("bat");
	sset2.insert("hamster");
	cout << "sset2: " << endl;
	sset2.getSet();
	// Use the copy constructor to build a StringSet withsset1 –sset2
	StringSet sset3(sset1.difference(sset2));
	cout << "sset3: " << endl;
	sset3.getSet();
	// Use the overloaded assignment operatorto make a StringSet // contain sset2 –sset1
	StringSet sset4;
	sset4 = sset2.difference(sset1);
	cout << "sset4: " << endl;
	sset4.getSet();

}