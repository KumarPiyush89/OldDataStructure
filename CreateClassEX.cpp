/*Write a CPP program in which we create a class storing a date value,create object of that class, store data of object 
and print value of all object*/
#include<iostream>
using namespace std;
class Date
{
	private:
	int day;
	int month;
	int year;
	public:
	void setDay(int d)
	{	
		if(d>=1&&d<=31)
		day=d;
		else
		day=0;
	}
	void setMonth(int m)
	{
		if(m>=1&&m<=12)
		month=m;
		else
		month=0;
	}	
	void setYear(int y)
	{
		if(y>0)
		year=y;
		else
		year=0;
	}
	void setDate(int d,int m,int y)
	{
		if(d>0&&d<=31)
		day=d;
		else
		day=0;
		
		if(m>0&&m<=12)
		month=m;
		else
		month=0;
		
		if(y>=0)
		year=y;
		else
		y=0;
		
	}
	int getMonth()
	{
		return month;
	}
	int getDay()
	{
		return day;
	}
	int getYear()
	{
		return year;
	}
	void show()
	{
		cout<<day<<"-"<<month<<"-"<<year;
	}	
};
int main()
{
	Date rakeshDob,ankitDob,alokDob,sDate;
	rakeshDob.setDay(19);
	rakeshDob.setMonth(9);
	rakeshDob.setYear(2004);
	ankitDob.setDay(12);
	ankitDob.setMonth(4);
	ankitDob.setYear(2002);
	alokDob.setDay(02);
	alokDob.setMonth(01);
	alokDob.setYear(2002);
	cout<<"Rakesh DOB = ";
	rakeshDob.show();
	cout<<endl<<"Ankit DOB = ";
	ankitDob.show();
	cout<<endl<<"Alok DOB = ";
	alokDob.show();
	sDate.setDate(31,5,2022);
	cout<<endl<<"S DOB = ";
	sDate.show();
	sDate.setMonth(sDate.getMonth()+1);
	cout<<endl<<"S DOB = ";
	sDate.show();
	
	return 0;
}