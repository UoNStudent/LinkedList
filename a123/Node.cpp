#include "Node.h"
#include <cstdlib>

Node::Node()
{
	next = NULL;
	data = NULL;
	prev = NULL;
}
//Construct it
Node::Node(const data_type& intData, Node* intNext, Node* intPrev) 
{
	data = intData;
	next = intNext;
	prev = intPrev;
}

//Destroy it
Node::~Node(){}

//Get it
Node* Node::getNext()
{
	return next;
}

Node* Node::getPrev()
{
	return prev;
}

Node::data_type& Node::getData()
{
	return data;
}

//Set it
void Node::setNext(Node* nextPtr)
{
		next = nextPtr;
}

void Node::setPrev(Node* prevPtr)
{
		prev = prevPtr;
}

void Node::setData(const data_type& newData)
{
		data = newData;
}
