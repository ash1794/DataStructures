#ifndef __STACK_H__
#define __STACK_H__
#include<stdexcept>
#include<iostream>
#include<iomanip>
#include<climits>

using namespace std;

template<class T>
class Stack
{
public:
	typedef size_t	size_type;
	typedef T		value_type;
private:
	static const size_type stack_size = 100;
	value_type data[stack_size];
	int top_of_stack;
	
public:
	Stack():top_of_stack(-1){}

	bool empty() const {return (top_of_stack==-1);				}
	size_type size() const {return size_type(top_of_stack+1);	}
	value_type& top() {return data[top_of_stack]				}
	const value_type& top() const {return data[top_of_stack]	}
	void push(const value_type& x)								;// throw (overflow_exception);
	void pop()													; //throw (underflow_error);
	void clear() {	top_of_stack=-1;							}
	friend ostream& operator<< <T>(ostream& out,const Stack<T>& s);
};
#include "Stack.cpp"

#endif