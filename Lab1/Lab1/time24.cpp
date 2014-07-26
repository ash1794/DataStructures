#include"time24.h"

void time24::normalize_time()
{
	if(minute>59)
	{
		hour+= minute/60;
		minute%=60;
	}
	hour%=24;
	return;
}

void time24::read_time()
{
	cin>>hour>>separator>>minute;
	normalize_time();
}

void time24::write_time()
{
	cout<<hour<<separator<<minute;
}

time24 time24::duration(const time24& t)
{
	int cur_mins = hour*60 + minute;
	int rec_mins = t.hour*60 + t.minute;
	if(rec_mins < cur_mins)
		throw range_error("Input Time Earlier");
	int diff = rec_mins - cur_mins;
	return time24(diff/60,diff%60);
}

void time24::add_time(int min)
{
	minute+=min;
	normalize_time();
}