#include <iostream>
#include "LinkedListTester.h"
#include "LinkedList.h"

using namespace std;

LinkedListTester::LinkedListTester() : error_(false), funcname_("") {}

// find, insert_head
// you can probably pass this even if you did not make it into a
// doubly-linked list (i.e. you ignored prev_ altogether)
void LinkedListTester::testa() {
	funcname_ = "LinkedListTester::testa";

	{
	LinkedList t;
	if (t.find(1) != nullptr)
		errorOut_("found 1 from empty list?", 0);

	t.insert_head(1);
	if (t.find(1) == nullptr)
		errorOut_("cannot find 1 after first insert", 0);

	t.insert_head(2);
	t.insert_head(3);
	if (t.find(1) == nullptr)
		errorOut_("cannot find 1 after three inserts", 0);
	if (t.find(2) == nullptr)
		errorOut_("cannot find 2 after three inserts", 0);
	if (t.find(3) == nullptr)
		errorOut_("cannot find 3 after three inserts", 0);

	}

	passOut_();
}

// insert_head, print
void LinkedListTester::testb() {
	funcname_ = "LinkedListTester::testb";

	{
	LinkedList t;
	t.insert_head(1);
	t.insert_head(2);
	t.insert_head(3);
	cout << "Expected output of print:\n";
	cout << "3 2 1 \n";
	cout << "Your output of print:\n";
	t.print();

	}
}

// insert_after
void LinkedListTester::testc() {
	funcname_ = "LinkedListTester::testc";

	{
	LinkedList t;
	t.insert_head(1);
	t.insert_head(2);
	t.insert_head(3);
	LNode* result = t.find(2);
	t.insert_after(result, 4);

	if (t.find(1) == nullptr)
		errorOut_("cannot find 1 after insert_after", 0);
	if (t.find(2) == nullptr)
		errorOut_("cannot find 2 after insert_after", 0);
	if (t.find(3) == nullptr)
		errorOut_("cannot find 3 after insert_after", 0);
	if (t.find(4) == nullptr)
		errorOut_("cannot find 4 after insert_after", 0);

	cout << "Expected output of print:\n";
	cout << "3 2 4 1 \n";
	cout << "Your output of print:\n";
	t.print();

	}

}

// remove
void LinkedListTester::testd() {
	funcname_ = "LinkedListTester::testd";

	{
	LinkedList t;
	t.insert_head(1);
	LNode* p = t.find(1);
	t.insert_after(p, 2);
	p = t.find(2);
	t.insert_after(p, 3);
	p = t.find(3);
	t.insert_after(p, 4);

	cout << "Expected output of print:\n";
	cout << "1 2 3 4 \n";
	cout << "Your output of print:\n";
	t.print();

	t.remove(t.find(2));

	if (t.find(1) == nullptr)
		errorOut_("cannot find 1 after remove", 0);
	if (t.find(2) != nullptr)
		errorOut_("found 2 after remove", 0);
	if (t.find(3) == nullptr)
		errorOut_("cannot find 3 after remove", 0);
	if (t.find(4) == nullptr)
		errorOut_("cannot find 4 after remove", 0);

	cout << "Expected output of print:\n";
	cout << "1 3 4\n";
	cout << "Your output of print:\n";
	t.print();

	}

}

void LinkedListTester::errorOut_(const string& errMsg, unsigned int errBit) {

	cerr << funcname_ << ":" << " fail";
	cerr << errBit;
	cerr << ": " << errMsg << endl;
	error_ |= (1<<errBit);
	cerr << std::flush;
}

void LinkedListTester::passOut_() {

	if (!error_) {
		cerr << funcname_ << ":" << " pass" << endl;
	}
	cerr << std::flush;
}
