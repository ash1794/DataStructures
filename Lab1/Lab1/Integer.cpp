#include"Integer.h"

ostream& operator << (ostream &out, const Integer& i)
{
	out<<i.num;
	return out;
}
istream& operator>> (istream &in, Integer& i)
{
	in>>i.num;
	return in;
}

Integer operator*(Integer a,Integer b)
{
	return Integer(a.num*b.num);
}

Integer operator/(Integer a,Integer b)
{
	return Integer(a.num/b.num);
}

string Integer::to_string()
{	
	char str[12];
	_itoa_s(num,str,10);
	return string(str);
}
