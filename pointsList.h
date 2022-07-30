#pragma once
#include"node.h"

//----------------------------------------------------------------------------------------------------------------------------------------
class pointsList {

	node* head = new node();	//dummy head
	node* tail = head;
	int counNode = 0;

public:
	pointsList() {}
	void push(float x, float y);
	void pop();
	node* getHead() { return head->getNext(); }
	int getCount() { return counNode; }
	~pointsList();
	
};
//----------------------------------------------------------------------------------------------------------------------------------------