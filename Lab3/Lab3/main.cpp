#include "Stack.h"
#include "Tokenizer.h"
using namespace std;
int main()
{
	typedef	int data_type;

	Tokenizer<data_type> input(cin);
	Stack<data_type> stk;
	data_type op1,op2,result;
	bool err_flag;
	while(true)
	{
		err_flag = false;
		stk.clear();
		Token<int> cur_token = input.get_token();
		while(cur_token.get_type() != EOL)
		{
			if(cur_token.get_type()==UNKNOWN)
				break;
			switch(cur_token.get_type())
			{
			case VALUE:
				stk.push(cur_token.get_value());
				break;
			case MULT:
			case DIV:
			case PLUS:
			case MINUS:
				if(stk.size()>=2)
				{
					op2 = stk.top() ;stk.pop();
					op1 = stk.top() ;stk.pop();
					switch(cur_token.get_type())
					{
						case MULT:
							result = op1 * op2;
						break;
						case DIV:
							result = op1 / op2;
						break;
						case PLUS:
							result = op1 + op2;
						break;
						case MINUS:
							result = op1 - op2;
						break;
					}
					stk.push(result);
				}
				else
				{
					err_flag = true;
				}
				break;
			}
			cur_token = input.get_token();
		}

		if(!err_flag)
		{
			if(stk.size() == 1)
			{
				cout<<stk.top()<<endl;
			}
			else
			{
				cerr<<"Invalid Expression"<<endl;
					
			}
		}
		else
		{
			cerr<<"Error"<<endl;
			input.clear();
			cin.putback('\n');
			cin.ignore(1000,'\n');
		}
		//cout<<stk<<endl;
		
	}
	return 0;
}