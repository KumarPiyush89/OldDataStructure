#include<iostream>
using namespace std;
//declare a class for fraction value
class FractionNumber
{
	private://Only accessible by member of class
	int num;
	int dnum;
	public://accessible by any function
	void setValue(int a,int b)
	{
		num=a;
		if(b==0)
		dnum=1;
		else 
		dnum=b;
		
	}
	void show()
	{
		cout<<num<<"/"<<dnum;
	}
		
};

int main()
{
	//create an object of Fraction Number
	FractionNumber x,y;
	//put values in members of object x
	//x.num=34;
	//x.dnum=80;
	x.setValue(34,80);
	
	//put values in members of object y
	//y.num=23;
	//y.dnum=0;
	y.setValue(23,0);
	
	//print the value of x
	//cout<<x.num<<"/"<<x.dnum;
	//print the value of y
	//cout<<endl<<y.num<<"/"<<y.dnum;
	x.show();
	cout<<endl;
	y.show();
	return 0;

}