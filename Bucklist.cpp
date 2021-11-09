#include "BucketList.h"
#include<cmath>
#include<sstream>
#include<cstring>
#include <iostream>
using namespace std;

Node::Node() {
	// IMPLEMENT ME
	
}

Node::~Node() {
	// IMPLEMENT ME
}

BucketList::BucketList() {
	// IMPLEMENT ME		
	buckets_ = new Node*[INITIAL_CAP];
	for (int i = 0; i < INITIAL_CAP; i++)
	{
		buckets_[i]=nullptr;
	}
}

BucketList::~BucketList() {
	// IMPLEMENT ME
	delete []buckets_;
}

BucketList::BucketList(const BucketList& other) {
	// IMPLEMENT ME
	if (buckets_ != nullptr) {
		delete[]buckets_;
		buckets_ = nullptr;
	}
	buckets_ = new Node*[other.INITIAL_CAP];
	for (int i = 0; i < other.INITIAL_CAP; i++)
	{
		buckets_[i] = other.buckets_[i];
	}
}

BucketList& BucketList::operator=(const BucketList& other) {
	// IMPLEMENT ME
	if (buckets_ != nullptr) {
		delete[]buckets_;
		buckets_ = nullptr;
	}
	buckets_ = new Node * [other.INITIAL_CAP];
	for (int i = 0; i < other.INITIAL_CAP; i++)
	{
		buckets_[i] = other.buckets_[i];
	}
	return *this;
}

bool BucketList::contains(const string& s) const {

	 //THIS IS DONE FOR YOU AS AN EXAMPLE
	 //but you need to change something...

	int hc = h(s) % INITIAL_CAP; // ...here.
	Node* temp = buckets_[hc];
	while (temp != nullptr) {
		if (temp->s_ == s) return true;
		temp = temp->next_;
	}
	return false;
}

void BucketList::insert(const string& s) {
	// IMPLEMENT ME
	int hc = h(s) % INITIAL_CAP;
	Node* newNode = new Node;
	newNode->s_ = s;
	if (buckets_[hc] == nullptr)
	{
		newNode->next_ = nullptr;
		buckets_[hc] = newNode;
	}
	else
	{
		if (!contains(s))
		{
			Node* temp = buckets_[hc];
			int num = 0;
			while (temp != nullptr) {
				if (s.compare(temp->s_) > 0) num++;
				temp = temp->next_;
			}
			if (num == 0)
			{
				newNode->next_ = buckets_[hc];
				buckets_[hc] = newNode;
			}
			else if(buckets_[hc] + num==nullptr)
			{
				Node* temp = buckets_[hc];
				for (int i = 0; i < num-1; i++)
				{
					temp = temp->next_;
				}
				temp->next_= newNode;
				newNode->next_ = nullptr;
			}
			else
			{
				Node* temp = buckets_[hc];
				for (int i = 0; i < num - 1; i++)
				{
					temp = temp->next_;
				}
				Node* t = temp->next_;
				temp->next_ = newNode;
				newNode->next_ = t;
			}
		}	
	}	
}

void BucketList::remove(const string& s) {
	// IMPLEMENT ME
	for (int i = 0; i < INITIAL_CAP; i++)
	{
		Node* temp = buckets_[i];
		int count = 0;
		while (temp != nullptr) {
			
			if (temp->s_ == s) 
			{
				if (temp == buckets_[i])
				{
					Node* t = temp->next_;
					buckets_[i] = t;
					delete temp;
					return;
				}
				else
				{
					Node* tp = buckets_[i];
					for (int j = 0; j < count-1; j++)
					{
						tp = tp->next_;
					}
					tp->next_ = temp->next_;
					delete temp;
					return;
				}	
			}
			count++;
			temp = temp->next_;
		}
	}
}

string BucketList::toString() const {
	// IMPLEMENT ME
	string str = "";
	for (int i = 0; i < INITIAL_CAP; i++)
	{
		stringstream ss;
		string num;
		Node* temp = buckets_[i];
		ss << i;
		ss >> num;
		str = str + num;
		while (temp != nullptr) {
			str = str + " " + temp->s_;
			temp = temp->next_;
		}
		if (i < INITIAL_CAP-1)
		{
			str = str + "\n";
		}
	}
	return str; // dummy
}

int BucketList::h(const string& s) const {
	// IMPLEMENT ME
	int len = s.length();
	char* str = new char[len];
	strcpy(str, s.c_str());
	int sum = 0;
	for (int i = 0; i<len; i++)
	{
		sum += (pow(2, i)) * (int(str[i]));
	}
	return sum; // dummy
}

int BucketList::getSize() const {
	// IMPLEMENT ME
	int num = 0;
	for (int i = 0; i < INITIAL_CAP; i++)
	{
		Node* temp = buckets_[i];
		while (temp != nullptr) {
			num++;
			temp = temp->next_;
		}
	}
	return num; // dummy
}

int BucketList::getCap() const {
	// IMPLEMENT ME
	return INITIAL_CAP; // dummy
}
