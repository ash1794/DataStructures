#ifndef ____ITERATOR__NODE__H__
#define ____ITERATOR__NODE__H__

#include "Node.h"
class Iterator_Node{
private:
	Node* node_ptr;
public:
	Iterator_Node(Node *p):node_ptr(p){}

	Node* get_node_ptr(){return node_ptr;};
	int& operator* () {return node_ptr->data;}
	const int& operator*() const{return node_ptr->data;}

	Node* operator ->()
	{
		assert(node_ptr!=NULL);
		return node_ptr;
	}
	const Node* operator ->() const
	{
		assert(node_ptr!=NULL);
		return node_ptr;
	}

	bool operator==( const Iterator_Node& x)
	{
		return (node_ptr == x.node_ptr);
	}

	bool operator!= (const Iterator_Node& x)
	{
		return !(*this == x);
	}

	Node& operator++()
	{
		node_ptr = node_ptr->get_next_ptr();
		return *node_ptr;
	}
	
	Node operator++(int)
	{
		Node* temp = node_ptr;
		node_ptr = node_ptr->get_next_ptr();
		return *temp;
	}
};

#endif