#include"Stack.h"
#include"Tokenizer.h"

int main()
{
	Stack< Token<int> > stk;
	Tokenizer<int> input(cin);
	bool err_flag = false;
	while(true)
	{
		cout<<"Enter Expression: ";
		cout.flush();
		Token<int> cur_token = input.get_token();
		while(!err_flag && cur_token.get_type()!=EOL)
		{
			cout<<cur_token.get_type()<<"\n";
			if(cur_token.get_type()==LPAREN)
			{
				stk.push(cur_token);
			}
			else if(cur_token.get_type()==RPAREN)
			{
				if(stk.empty())
				{
					cerr<<"Unbalanced Right Parenthesis"<<endl;
					err_flag = true;
				}
				else
				{
					stk.pop();
				}
			}else if(cur_token.get_type()==UNKNOWN)
			{
				cerr<<"Error in Parse "<<endl;
				err_flag = true;
				break;
				
			}
			cur_token = input.get_token();

		}
		if(!err_flag)
		{
			if(stk.empty())
				cout<<"Equal Left and Right Parenthesis";
			else
				cout<<"Unbalenced Left Parenthesis";
			cout<<endl;
		}
		err_flag = false;
		stk.clear();
		input.clear();
		cout<<"Press any key to continue.. "<<endl;
		cin.ignore(1000,'\n');

	}
	return 0;
}