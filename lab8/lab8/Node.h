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
	Node<T>* parent;
	size_t height;
public:

	Node():
	  data(0),height(0),left(NULL),right(NULL),parent(NULL){}
	Node(const T& d):
	  data(d),height(0),left(NULL),right(NULL),parent(NULL){}
	
	//Setter Functions
	void set_data( T& d)			{data	= d;	}
	void set_height(size_t h)		{height = h;	}
	void set_left( Node<T>* l)		{left	= l;	}
	void set_right( Node<T>* r)		{right	= r;	}
	void set_parent(Node<T>* p)		{parent = p;	}
	

	//Getter Functions
	T			get_data()		const	{return data;	};
	size_t		get_height()	const	{return height;	};
	Node<T>*	get_left()		const	{return left;	};
	Node<T>*	get_right()		const	{return right;	};
	Node<T>*	get_parent()	const	{return parent;	};

};

#endif