#include <iostream>
#include "LinkedListTester.h"

using std::cout;
using std::endl;

int main(int argc, char* argv[]) {

	for(int i=1; i<argc; i++) {
		switch (argv[i][0]) {
		case 'a': { LinkedListTester t; t.testa(); } break;
		case 'b': { LinkedListTester t; t.testb(); } break;
		case 'c': { LinkedListTester t; t.testc(); } break;
		case 'd': { LinkedListTester t; t.testd(); } break;
		default: { cout << "Options are a -- d." << endl; } break;
	       	}
	}
	return 0;
}

