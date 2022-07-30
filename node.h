#pragma once

//----------------------------------------------------------------------------------------------------------------------------------------
class node {

	float x, y;
	node* next = nullptr;

public:
	node(){}
	node(float x, float y) : x(x), y(y) {}
	float getX() { return x; }
	float getY() { return y; }
	void setX(float _x) { x = _x; }
	void setY(float _y) { y = _y; }
	void setNext(node* newNode) { next = newNode; }
	node* getNext() { return next; }

};
//----------------------------------------------------------------------------------------------------------------------------------------