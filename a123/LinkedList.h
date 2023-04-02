/*Program Description: Includes all the method headers for the LinkedList.cpp file
*/

#ifndef LINK_H
#define LINK_H

#include "Node.h"
#include <cstdlib>

using namespace std;

class LinkedList
{
	public:
// Use same data_type as Node
		typedef Node::data_type data_type;
	
// Construct it
		LinkedList();
		
// Destroy it
		~LinkedList();
	
// Get it
		getCurrent();
		getHead();
		getTail();
	
// Set it
		void addToHead(data_type& data);
		void addToTail(data_type& data);
	
		void removeHead();
		void removeTail();
		void removeCurrent();
	
		void next();
		void prev();
	
	
		void countSuit();
		void highestRank();
		void averageRank();
	
		void remove();
//		int LinkedList::length();
//		boolean search();
		
// Incase I wanted a stab at the bonus question
//		void order();
	
// Private member variables
	private:
		Node* head;
		Node* tail;
		Node* current;
};

// Overloaded ostream operator
ostream& operator << (ostream& out, LinkedList& list);
// Overloaded += operator
LinkedList& operator += (LinkedList& a, LinkedList& b);

#endif