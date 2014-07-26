#include"Integer.h"
#include<string>
using namespace std;

int main()
{
	cout<<"Hello World\n";
	Integer a(33);

	cout<<a<<"\n";
	Integer c = a;
	cout<<c<<"\n";
	int b = Integer::parse_int("23");
	cout<<b<<"\n";

	//Checking Postfix And Prefix 
	Integer i1(-4), i2(10);
	cout << "i1: " << i1 << endl;
	++i1;
	cout << "After incrementing i1: " << i1 << endl;
	cout << i1-- << endl;
	cout << "After decrementing: " << i1 << endl;
	(--i1).set_data(20); /* What happens here? */
	cout << i1 << endl; /* What is the output here?
	*/
	(i1++).set_data(30); /* Is it error? */
	cout << i1 << endl; /* Will it print ‘30’? */ 
	i1=-4;
	i2=10;
	cout << "i1: " << i1 << endl;
	cout << "OR : It is " << ((i1 || i2) ? "true" : "false") << endl;
	cout << "AND : It is " << ((i1 && i2) ? "true" : "false") << endl;
	cout << "NOT : It is " << ((! i1) ? "true" : "false") << endl; 
	try
	{
		Integer abc("33a");
	}
	catch(invalid_argument error)
	{
		cout<<error.what()<<"\n";
	}

	return 0;
}