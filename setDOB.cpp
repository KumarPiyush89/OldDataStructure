#include<iostream>
using namespace std;

class date
{
	private:
	int day;
	int mon;
	int year;
	public:
	void setday(int d)
	{
		if(d>0&&d<31)
		{
			day=d;
		}
		else
		{
			day=0;
		}
	}
	
	void setmonth(int m)
	{
		if(m>0&&m<=12)
		{
			mon=m;
		}
		else
		{
			mon=0;
		}
	}
	void setyear(int y)
	{
		if(y>0&&y<2022)
		{
			year=y;
		}
		else
		{
			year=0;
		}
	}
	void printdata()
	{
		cout<<day<<"/"<<mon<<"/"<<year;
	}
};

int main()
{
	date x;
	
	//accept date of birth
	x.setday(03);
	x.setmonth(12);
	x.setyear(2001);
	
	//print date of birth
	cout<<endl<<"Aaryan Date of birth is:";
	x.printdata();
	
	return 0;
}