#include"Token.h"

template<class T>
class Tokenizer{
private:
	istream& input;
public:
	Tokenizer(istream& in):input(in){};
	Token<T> get_token() ;
	void clear(){ input.clear(); };
};

template<class T>
Token<T> Tokenizer<T>::get_token()
{
	char ch;
	T value;
	while(input.get(ch) && (ch==' ' || ch=='\t') );
	if(input.good())
	{
		switch(ch)
		{
		case '+' : return PLUS;
		case '-' : return MINUS;
		case '*' : return MULT;
		case '/' : return DIV;
		case '^' : return EXP;
		case '(' : return LPAREN;
		case ')' : return RPAREN;
		case '\n': return EOL;
		default:
			input.putback(ch);
			if(input>>value)
				return Token<T>(VALUE,value);
			else
			{
				input.clear();
				input.ignore(1000,'\n');
				return UNKNOWN;
			}
		}
	}
	return EOL;
}