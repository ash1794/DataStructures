#include<string>
#include<iostream>

using namespace std;

class time24{
private:
	int hour;
	int minute; 
	string separator; 
	
	void normalize_time( );
public:

	time24( ):hour(0),minute(0){}
	time24(int h, int m ):hour(h),minute(m){}
	time24(const time24& t):hour(t.hour),minute(t.minute){}

	int get_hour( )const		{return hour;	}
	int get_minute( ) const 	{return minute;	}
	
	void read_time( );

	void write_time( );

	time24 duration(const time24& t);
	
	void add_time(int minutes);
};
