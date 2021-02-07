#ifndef NODE_H_
#define NODE_H_

class Node
{
public:
	int data;
	Node *next;
	Node *prev;	

	Node(){
		this->next = NULL;
		this->prev = NULL;
		this->data = 0;
	}
	Node(int data, Node *next, Node *prev);
	~Node();

private:
	
};

#endif
