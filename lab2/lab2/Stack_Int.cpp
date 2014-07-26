#include"Stack_Int.h"

using namespace std;

bool Stack_Int::empty() const
{
	return (top_of_stack==-1);
}
Stack_Int::size_type Stack_Int::size() const
{
	return top_of_stack+1;
}

Stack_Int::value_type& Stack_Int::top()
{
	return data[top_of_stack];
}
const Stack_Int::value_type& Stack_Int::top() const
{
	return data[top_of_stack];
}

void Stack_Int::push(const Stack_Int::value_type& x)// throw (overflow_exception)
{
	if(top_of_stack+1 == Stack_Int::stack_size)
		throw std::overflow_error("Stack Overflow");
	data[++top_of_stack] = x;
}
void Stack_Int::pop()// throw (underflow_error)
{
	if(top_of_stack==-1)
		throw underflow_error("Stack Underflow");
	--top_of_stack;
}
ostream& operator<<(ostream& out,const Stack_Int& s)
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