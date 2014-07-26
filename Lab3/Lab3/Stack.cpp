#include"Stack.h"

using namespace std;

template<class T>
void Stack<T>::push(const value_type& x)// throw (overflow_exception)
{
	if(top_of_stack+1 == stack_size)
		throw std::overflow_error("Stack Overflow");
	data[++top_of_stack] = x;
}

template<class T>
void Stack<T>::pop()// throw (underflow_error)
{
	if(top_of_stack==-1)
		throw underflow_error("Stack Underflow");
	--top_of_stack;
}

template<class T>
ostream& operator<<(ostream& out,const Stack<T>& s)
{
	for(int i=s.size()-1;i>=0;i--)
	{
		out<<"+-----+"<<endl;
		out<<"|"<<setw(5)<<s.data[i]<<"|";//<<endl;
		if(s.size()-1 == i)
			out<<"<-- Top";
		out<<endl;
	}
	if(s.size() !=0)
		out<<"+-----+"<<endl;
	else
		out<<"Stack Empty"<<endl;
	return out;
}