#ifndef __TREE__NODE__H__
#define __TREE__NODE__H__

#include<cstdlib>

template<class T>
class Node
{
private:
	T data;
	Node<T>* left;
	Node<T>* right;
public:

	Node():data(0),left(NULL),right(NULL){}
	Node(const T& d):data(d),left(NULL),right(NULL){}
	
	//Setter Functions
	void set_data( T& d)			{data = d;	}
	void set_left( Node<T>* l)		{left = l;	}
	void set_right( Node<T>* r)		{right = r;	}

	//Getter Functions
	T			get_data()		{return data;	};
	Node<T>*	get_left()		{return left;	};
	Node<T>*	get_right()		{return right;	};
};

#endif