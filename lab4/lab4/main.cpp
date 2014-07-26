#include "List_Int.h"
int main()
{
	List_Int l;
	for(int i=0;i<=5;i++)
		l.push_back(i);
	cout<<l;
	for(int i=0;i<=5;i++)
	{
		l.pop_back();
		cout<<l;
	}
	return 0;
}