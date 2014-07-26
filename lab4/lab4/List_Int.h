#include "Node.h"
#include "Iterator_Node.h"
#include <iostream>
#include <algorithm>
class List_Int
{
public:
	typedef int data_type;
	typedef size_t size_type;
	typedef Iterator_Node iterator;
	typedef const Iterator_Node const_iterator;

private:
	Node *head,*tail;
	size_type list_size;
public:
	//Constructor 
	explicit List_Int()
		:head(NULL),tail(NULL),list_size(0){};
	explicit List_Int(size_type n, const int& val = 0)
		:head(NULL),tail(NULL),list_size(0)
	{
		for(int i=0;i<int(n);i++)push_front(val);
	}
	explicit List_Int(const_iterator first,const_iterator last)
		:head(NULL),tail(NULL),list_size(0)
	{
		for(List_Int::iterator it=first;it!=last;it++)
			push_back(*it);
	}

	List_Int(const List_Int& x)
		:head(NULL),tail(NULL),list_size(0)
	{
		for(List_Int::iterator it=x.begin();it!=x.end();it++)
			push_back(*it);
	}/* Constructor */
	/*~List_Int()
	{
		while(!empty())
			pop_front();
		
	}*/

	void push_back(const int& val);
	void push_front(const int& val);
	void pop_back();
	void pop_front();
	bool empty(){return (list_size == 0); }
	friend ostream & operator<<(ostream &out,const List_Int &l);
	size_type size() const {return list_size;};
	
	iterator begin()			 {return iterator(head);		}
	const_iterator begin() const {return const_iterator(head);	}

	iterator end()				 {return iterator(NULL);		}
	const_iterator end()  const  {return const_iterator(NULL);	}

	void clear()				 {while(! empty() )pop_front();	}

	iterator insert(iterator pos,const int&x);
	void swap(List_Int &x);
	iterator erase	(iterator position);
	iterator erase	(iterator first, iterator last );
	void remove		(const int& value);
	void unique		();


};