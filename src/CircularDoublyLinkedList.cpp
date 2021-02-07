
#include <iostream>

#include "CircularDoublyLinkedList.h"
#include "Node.h"

using namespace std;

CircularDoublyLinkedList::CircularDoublyLinkedList(){

	middleOfList = new Node();
	sizeOfList = 0;	 
}

CircularDoublyLinkedList::~CircularDoublyLinkedList(){

	Node *current = middleOfList;

	while( current != NULL ) {
       Node *next = current->next;
       delete current;
       current = next;
   }

   middleOfList = NULL;		
}

int CircularDoublyLinkedList::getSizeOfList(){
	return sizeOfList;
}

Node* CircularDoublyLinkedList::getMiddleOfList(){
    return middleOfList;
}

void CircularDoublyLinkedList::setSizeOfList(int size){
    sizeOfList = size;
}

bool CircularDoublyLinkedList::IsEmpty() const {

	return (middleOfList->next == NULL && middleOfList->prev == NULL);
}

const int CircularDoublyLinkedList::MiddleData() const {
    return this->middleOfList->data;
}

void CircularDoublyLinkedList::Add(int *arrayNumbers){


    Node* temp = new Node();
    temp->data = arrayNumbers[0];
    this->middleOfList = temp;

    Node* temp1 = middleOfList;
    Node* temp2 = middleOfList;
    Node* prevOrNext = middleOfList;

    int i;

    for(i=1; i<(sizeOfList+1)/2; i++)
    {
        Node* t = new Node();
        t->data = arrayNumbers[i];
        t->next = prevOrNext;
        temp1->prev = t;

        
        temp1 = temp1->prev;  
        prevOrNext = temp1;

    }

    prevOrNext = this->middleOfList;
    for(; i < sizeOfList; i++){
        Node* t = new Node();
        t->data = arrayNumbers[i];
        t->prev = prevOrNext;
        temp2->next = t;

        temp2 = temp2->next;
        prevOrNext = temp2;
    }

    temp1->prev = temp2;
    temp2->next = temp1;

}

void CircularDoublyLinkedList::printList(){

    
    Node* temp1 = this->middleOfList;

    for(int i=0; i<(sizeOfList-1)/2; i++){
       temp1 = temp1->prev;     
    }

    for(int i=0; i < sizeOfList; i++){
        cout << temp1->data << " ";
        temp1 = temp1->next;
    }
}