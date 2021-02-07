
#include <iostream>

#include "Node.h"

using namespace std;

Node::Node(int data, Node *next=NULL, Node *prev=NULL){

	this->data = data;
	this->next = next;
	this->prev = prev;
}

Node::~Node(){


}