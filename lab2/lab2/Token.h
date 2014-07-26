enum	Token_type	{
	EOL,
	VALUE,
	LPAREN,
	RPAREN,
	PLUS,
	MINUS,
	DIV,
	MULT,
	EXP,
	UNKNOWN
};

template<class T>
class Token{
private:
	Token_type	token_type	;
	T			token_value	;
public:
	Token(Token_type tt = EOL,const T& va = 0)
		:token_type(tt),token_value(va){}

	Token_type get_type()	{return token_type;		};
	T			get_value()	{return token_value;	};
	
};