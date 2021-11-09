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
	buckets_ = new Node*[getCap()];
	for (int i = 0; i < getCap(); i++)
	{
		buckets_[i]=nullptr;
	}
}

BucketList::~BucketList() {
	// IMPLEMENT ME
	for (int i = 0; i < getCap(); i++)
	{
		Node* &temp = buckets_[i];
		if (temp == nullptr)
		{
			delete temp;
		}
		while (temp != nullptr) {
			Node* &t = temp;
			temp = temp->next_;
			delete t;
		}
	}
	delete[]buckets_;
	buckets_ = nullptr;
}

BucketList::BucketList(const BucketList& other) {
	// IMPLEMENT ME
	size = other.size;
	buckets_ = new Node*[getCap()];          //create a new buckets with the same size, copy the string into the new one
	for (int i = 0; i <getCap(); i++)
	{
		buckets_[i] = nullptr;
	}
	for (int i = 0; i < getCap(); i++) 
	{
		Node* temp = other.buckets_[i];
		if (other.buckets_[i] != nullptr)
		{
			temp = temp->next_;
			while (temp!= nullptr) 
			{
				insert(temp->s_);
				temp = temp->next_;
			}
		}
		
	}
}

BucketList& BucketList::operator=(const BucketList& other) {
	// IMPLEMENT ME
	if (&other == this) return *this;
	else
	{
		for (int i = 0; i < getCap(); i++)           //delete the old buckets_
		{
			Node* temp = buckets_[i];
			while (temp != nullptr) 
			{
				Node* t = temp;
				temp = temp->next_;
				delete t;
			}
		}
		delete []buckets_;
		buckets_ = nullptr;

		size = other.size;
		buckets_ = new Node * [other.getCap()];          //create a new buckets with the same size, copy the string into the new one
		for (int i = 0; i < other.getCap(); i++)
		{
			buckets_[i] =nullptr;
		}
		for (int i = 0; i < other.getCap(); i++)
		{
			Node* temp = other.buckets_[i];
			if (other.buckets_[i] != nullptr)
			{
				temp = temp->next_;
				while (temp != nullptr) 
				{
					insert(temp->s_);
					temp = temp->next_;
				}
			}
		}
	}
	return *this;
}

bool BucketList::contains(const string& s) const {

	 //THIS IS DONE FOR YOU AS AN EXAMPLE
	 //but you need to change something...

	int hc = h(s) % getCap(); // ...here.
	Node* temp = buckets_[hc];
	while (temp != nullptr) {
		if (temp->s_ == s) return true;
		temp = temp->next_;
	}
	return false;
}

void BucketList::insert(const string& s) {
	// IMPLEMENT ME
	if (contains(s)) return;

	float load = float(getSize() + 1) / float(getCap());        //current inserts, if load exceed the maximum, call doublesize and double the number of buckets
	if (load > MAX_LOAD_FACTOR)
	{
		doublesize();
	}

	int hc = h(s) % getCap();
	Node* newNode = new Node;
	newNode->s_ = s;
	if (buckets_[hc] == nullptr)
	{
		buckets_[hc] = new Node();
		Node* temp = buckets_[hc];
		temp->next_ = newNode;
		newNode->next_ = nullptr;
	}
	else
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
		else if(buckets_[hc] + num==nullptr)        //the insertion position is at the end
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
			for (int i = 0; i < num - 1; i++)   //find the front node and insert
			{
				temp = temp->next_;
			}
			Node* t = temp->next_;
			temp->next_ = newNode;
			newNode->next_ = t;
		}	
	}	
}

void BucketList::remove(const string& s) {
	// IMPLEMENT ME
	for (int i = 0; i < getCap(); i++)
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
					for (int j = 0; j < count-1; j++)      //find the front node and delete specified node
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
	for (int i = 0; i < getCap(); i++)
	{
		stringstream ss;
		string num;                     //the buckets numbers
		Node* temp = buckets_[i];
		ss << i;                       
		ss >> num;
		str = str + num;
		while (temp != nullptr) {
			if(temp==buckets_[i])
			{
				str = str + temp->s_;
			}
			else
			{
				str = str + " " + temp->s_;
			}		
			temp = temp->next_;
		}
		if (i < getCap() -1)
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
	for (int i = 0; i < getCap(); i++)
	{
		Node* temp = buckets_[i];
		if (temp != nullptr)
		{
			temp = temp->next_;
			while (temp != nullptr) {
				num++;
				temp = temp->next_;
			}
		}
	}
	return num; // dummy
}

int BucketList::getCap() const {
	// IMPLEMENT ME
	int cap = (this->size) * INITIAL_CAP;
	return cap; // dummy
}

void BucketList::doublesize()  {
	// IMPLEMENT ME
	BucketList copy(*this);
	for (int i = 0; i < getCap(); i++)    //delete old buckets_
	{
		Node* temp = buckets_[i];
		while (temp != nullptr) {
			Node* t = temp;
			temp = temp->next_;
			delete t;
		}
	}
	delete []buckets_;
	buckets_ = nullptr;
	size = copy.size * 2;               //doublesize and create the new buckets_
	int cap = getCap();
	buckets_ = new Node * [cap];
	for (int i = 0; i < cap; i++) 
	{
		buckets_[i] = nullptr;
	}

	for (int i = 0; i < copy.getCap(); i++)
	{
		if (copy.buckets_[i] != nullptr)
		{
			Node* temp =copy.buckets_[i];
			temp = temp->next_;
			while (temp != nullptr) 
			{
				string str = temp->s_;
				insert(str);
				temp = temp->next_;
			}
		}
	}
}
