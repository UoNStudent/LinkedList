
//Check for safety net
#ifndef NODE_H
//Put down the net
#define NODE_H

#include <iostream>
#include <cstdlib>

#include "Card.h"

class Node 
{ 
	public:
//Card is now a data type		
		typedef Card data_type;
		
		Node();
//Construct it
		Node(const data_type& intData = data_type(), Node* intNext = NULL, Node* intPrev = NULL);

//Destroy it
		~Node();

//Get it	
		Node* getNext();
		Node* getPrev();
		data_type& getData();	

//Set it		
		void setNext(Node* nextPtr);
		void setPrev(Node* prevPtr);
		void setData(const data_type& new_data);
		
//Don't look at my privates this is my safe space	
	private:
		Node* next;
		Node* prev;
		data_type data;
};
//Throw out old net
#endif