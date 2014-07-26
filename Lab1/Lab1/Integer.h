#include<iostream>
#include<stdexcept>
using namespace std;
class Integer
{
private:
	int num;
public:
	Integer():num(0){}

	Integer(const Integer& b):num(b.num){}

	Integer(int b):num(b){}

	Integer(const char* s)
	{
		num=atoi(s);
		int sz =strlen(s);
		for(int i=0;s[i]!='\0';i++)
			if(!isdigit(s[i]))
				throw invalid_argument("Invaild String");
	}
	int get_data()
	{
		return num;
	}
	void set_data(int n)
	{
		num=n;
	}
	friend ostream& operator << (ostream &out, const Integer& i);
	friend istream& operator>> (istream &in, Integer& i);

	Integer operator+ (Integer b)
	{
		return Integer(num+b.num);
	}
	Integer operator- (Integer b)
	{
		return Integer(num-b.num);
	}
	friend Integer operator*(Integer a,Integer b);
	friend Integer operator/(Integer a,Integer b);

	string to_string();
	static int parse_int(string str)
	{
		return atoi(str.c_str());
	}
	bool operator > (Integer b)
	{
		return num>b.num;
	}
	bool operator < (Integer b)
	{
		return num<b.num;
	}
	bool operator >= (Integer b)
	{
		return num>=b.num;
	}
	bool operator <= (Integer b)
	{
		return num<=b.num;
	}
	bool operator == (Integer b)
	{
		return num==b.num;
	}
	
	Integer& operator++()
	{
		++num;
		return *this;
	}
	Integer operator++(int)
	{
		return Integer(num++);
	}

	Integer& operator--()
	{
		--num;
		return *this;
	}
	Integer operator--(int)
	{
		return Integer(num--);
	}

	bool operator||(const Integer& b)
	{
		return num||b.num;
	}

	bool operator&&(const Integer& b)
	{
		return num&&b.num;
	}
	bool operator!()
	{
		return !num;
	}
};