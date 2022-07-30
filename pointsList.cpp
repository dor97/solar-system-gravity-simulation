
#include"pointsList.h"

//----------------------------------------------------------------------------------------------------------------------------------------
//push a node to the end of the list
void pointsList::push(float x, float y)
{
	node* newNode = new node(x, y);
	tail->setNext(newNode);
	tail = tail->getNext();
	++counNode;
	if (counNode == 30)
		pop();
}
//----------------------------------------------------------------------------------------------------------------------------------------
//remove the first node on the list
void pointsList::pop()
{
	node* temp = head->getNext();
	delete head;
	head = temp;
	--counNode;
}
//----------------------------------------------------------------------------------------------------------------------------------------
pointsList::~pointsList()
{
	node* temp = head->getNext();
	delete head;
	while (temp != nullptr)
	{ 
		head = temp;
		temp = temp->getNext();
		delete head;
	}
}
//----------------------------------------------------------------------------------------------------------------------------------------