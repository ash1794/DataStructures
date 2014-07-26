#ifndef __STACK_INT_H__
#define __STACK_INT_H__
#include<stdexcept>
#include<iostream>
#include<iomanip>
#include<climits>

using namespace std;

class Stack_Int
{
public:
	typedef size_t	size_type;
	typedef int		value_type;
private:
	static const size_type stack_size = 10;
	value_type data[stack_size];
	int top_of_stack;
	
public:
	Stack_Int():top_of_stack(-1){}

	bool empty() const;
	size_type size() const; 
	value_type& top();
	const value_type& top() const;
	void push(const value_type& x);// throw (overflow_exception);
	void pop(); //throw (underflow_error);
	friend ostream& operator<<(ostream& out,const Stack_Int& s);
};
//const Stack_Int::size_type Stack_Int::stack_size;
//#include "Stack_Int.cpp"

#endif