#ifndef ____NODE__H__
#define ____NODE__H__

#include<cstdlib>
#include<cassert>

using namespace std;
class Node
{
public:
	typedef int data_type;
	typedef size_t size_type;
private:
	data_type data;
	Node* next;
public:
	Node():data(0),next(NULL){}
	Node(int d):data(d),next(NULL){}
	int get_data() const {			return data;	};
	Node* get_next_ptr() const {	return next;	};
	void set_data(int d) {			data=d;			};
	void set_next_ptr(Node *ptr){	next = ptr;		};
	
	friend class Iterator_Node;
};

#endif