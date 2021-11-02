#include <iostream>
#include "LinkedList.h"
using std::cout;
using std::endl;

LinkedList::LinkedList() {
	head_ = nullptr;
}

LinkedList::~LinkedList() {
	// IMPLEMENT ME
	LNode* tmp = head_;
	while (head_ != nullptr)
	{
		tmp = head_;
		head_ = head_->next_;
		delete tmp;
	}
}

void LinkedList::print() const {
	// IMPLEMENT ME
	LNode* tmp = head_;
	while (tmp != nullptr) {
		cout << tmp->data_ << " ";
		tmp = tmp->next_;
	}
	cout << endl;
}

LNode* LinkedList::find(int t) const {
	// IMPLEMENT ME
	LNode* tmp = head_;
	while (tmp!=nullptr)
	{
		if (tmp->data_ == t) return tmp;
		tmp = tmp->next_;
	}
	return tmp; // stub
}

void LinkedList::insert_head(int t) {
	// IMPLEMENT ME
	if (head_ == nullptr) {
		LNode* tmp = new LNode;
		tmp->prev_ = nullptr;
		tmp->next_ = nullptr;
		tmp->data_ = t;
		head_ = tmp;
	}
	else {
		LNode* tmp = new LNode;
		tmp->next_ = head_;
		tmp->data_ = t;
		tmp->prev_ = head_->prev_;
		head_->prev_ = tmp;
		head_ = tmp;
	}
}

void LinkedList::insert_after(LNode* location, int t) {
	// IMPLEMENT ME
	LNode* tmp = new LNode;
	tmp->prev_ = location;
	tmp->data_ = t;
	tmp->next_ = location->next_;
	if (location->next_ != nullptr)
	{
		location->next_->prev_ = tmp;
	}
	location->next_ = tmp;
}

void LinkedList::remove(LNode* location) {
	// IMPLEMENT ME
	if (location == nullptr) return;
	LNode* prv = location->prev_;
	LNode* nxt = location->next_;
	if (prv!= nullptr)
	{
		prv->next_ = nxt;
	}
	else
	{
		head_ = location->next_;
	}
	if (nxt!=nullptr)
	{
		nxt->prev_ = prv;
	}
	delete location;
}

