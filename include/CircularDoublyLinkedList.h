#ifndef CIRCULARDOUBLYLINKEDLIST_H
#define CIRCULARDOUBLYLINKEDLIST_H

#include "Node.h"

class CircularDoublyLinkedList
{
public:
	CircularDoublyLinkedList();
	~CircularDoublyLinkedList();

	//getters
	int getSizeOfList();
	Node* getMiddleOfList();
	
	//setters
	void setSizeOfList(int size);

	bool IsEmpty() const;
	const int MiddleData() const;
	void Add(int *arrayNumbers);
	void printList();
	
private:

	Node *middleOfList;
	int sizeOfList;   // count of nodes for every line
	
};

#endif

