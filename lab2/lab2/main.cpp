//#include<iostream>
//#include<string>
//#include<stdexcept>
//#include"Stack.h"
//
//using namespace std;
//
//int main()
//{
//	Stack<string> s;
//	string str;
//	string num;
//	cin>>str;
//	while(str!="exit")
//	{
//		try
//		{
//			if(str=="push")
//			{
//				//cin>>num;
//				
//				while(! (cin>>num)) cin.clear(), cin.ignore(1000,'\n');
//				s.push(num);
//			}
//			else if(str=="pop")s.pop();
//			else if(str=="print")cout<<s<<endl;
//			else
//				cerr<<"Invalid Command"<<endl;
//				
//		}
//		catch(overflow_error e)
//		{
//			cerr<<e.what()<<endl;
//		}
//		catch(underflow_error e)
//		{
//			cerr<<e.what()<<endl;
//		}
//		
//		cin>>str;
//	}
//	return 0;
//}