#include "LinkedList.h"
#include "Card.h"

#include <iostream>
#include <cstdlib>

//Construct it--------------------------------------------------------//
//No precondition, making a new linked list with null values so I'm certain I won't get a dumb error
LinkedList::LinkedList()
{
	head = NULL;
	current = NULL;
	tail = NULL;
}

//No precondition, making new linked list with correct data type
LinkedList::LinkedList(data_type& data)
{
	head = new Node(data);
	current = head;
	tail = current;
}
//--------------------------------------------------------------------//


//Destroy it----------------------------------------------------------//
//Lecture 4, slide 33
//No precondition, just burns the list
LinkedList::~LinkedList()
{
	while(head!=NULL)
	{
		removeHead();
	}
}
//--------------------------------------------------------------------//


//Getters and setters-------------------------------------------------//
//Pointer is initialised, returns current node data
LinkedList::data_type LinkedList::getCurrent()
{
	return current->getData();
}

LinkedList::getHead()
{
	current = head;
	return current;
}

LinkedList::getTail()
{
	current = tail;
	return current;
}

//Data has been added, make new node with data type and add to the head(front)
void LinkedList::addToHead(const Node::data_type& data)
{
//Constructor with 3 parameters
	head = new Node(data, head, NULL);
//This is used incase empty list
	if(tail == NULL)
	{
		tail = head;
	}
}	

//All the same things but with the tail(back)
void LinkedList::addToTail(const Node::data_type& data)
{
	Node* newNode = new Node(data, tail, NULL);
	if(head == NULL)
	{
		head = newNode;
		tail = newNode;
	} else {
		tail->setNext(newNode);
		tail = newNode;
		}
}

//Lecture 4, slide 30
//No precondition, beheading the list
void LinkedList::removeHead()
{
	Node* temp;
	temp = head;
	head = head->getNext();
	if(head != NULL)
	{
		head->setPrev(NULL);
	} else {
		tail = NULL;
		}
	delete temp;

}

//Copy of lecture 4, slide 30 but switched to tail
//No precondition, "betailing" the list?
void LinkedList::removeTail()
{
	Node* temp;
	temp = tail;
	tail = tail->getPrev();
	if(tail != NULL)
	{
		tail->setNext(NULL);
	} else {
		head = NULL;
		}
	delete temp;
}

//Slide 32
//No precondition, removing the current node pointer(middle)
void LinkedList::removeCurrent()
{
//I'll put a step by step in here so you guys know I understood it

//Point to the node before the removed node
	Node* temp;
//Go around the moved node like in the diagram in lecture 4 timestamp 1:07:55, well visually similar
	temp = current->getPrev();
//Point to the node after the removed one
	temp = setNext(current->getNext());
//Pointing around the removed node again but the other direction I believe
	temp->setPrev(current->getPrev());
//Free up the memory
	delete current;
//Set current node to one that was after the removed
	current = temp;
}

void LinkedList::next()
{
	current = current->getNext();
}

void LinkedList::prev()
{
	current = current->getPrev();
}

void LinkedList::remove(const Node::data_type& target)
{
	for(current = head; current != NULL; current = current->getNext())
	{
		if(target == current->getData())
		{
//Found the item and can remove it
			removeCurrent();
		}
	}
}
//--------------------------------------------------------------------//

//Access and mutation-------------------------------------------------//






//--------------------------------------------------------------------//

//If wondering why these functions that may not get used are here, holding from lectures to use a guidelines for other functions
/*
//No precondition, current looking for first node with target to return true, if NULL then returns false
boolean Linkedlist::search(const Node::data_type& target)
{
	for(current = head; current != NULL; current = current->getNext())
	{
		if(target == current->getData())
		{
//Found the item and can move on
			return true;
		}
	}
//Couldn't find it
	return false;
}

//No precondition, just counts nodes in list
int LinkedList::length()
{
	int answer = 0;
	for(current = head; current != NULL; current = current->getNext())
	{
		listLength++;
	}
	return listLength;
}
*/