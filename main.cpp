#include "LinkedList.h"

int main() {
	LinkedList mylist;
	mylist.print();
	mylist.insert_head(1);
	mylist.insert_head(2);
	mylist.insert_head(3);
	mylist.print();
	LNode* result = mylist.find(3);
	if (result != nullptr) mylist.insert_after(result, 4);
	mylist.print();
	mylist.remove(mylist.find(3));
	mylist.print();
	mylist.remove(mylist.find(2));
	mylist.print();
	mylist.remove(mylist.find(4));
	mylist.print();
	mylist.remove(mylist.find(1));
	mylist.print();

}
