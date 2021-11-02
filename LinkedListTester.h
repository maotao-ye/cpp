#ifndef LINKEDLISTTESTER_H_
#define LINKEDLISTTESTER_H_

#include <string>
#include "LinkedList.h"

class LinkedListTester {
public:
	LinkedListTester();

	void testa();
	void testb();
	void testc();
	void testd();

private:

	void errorOut_(const std::string& errMsg, unsigned int errBit);
	void passOut_();

	char error_;
	std::string funcname_;
};

#endif /* LINKEDLISTTESTER_H_ */
