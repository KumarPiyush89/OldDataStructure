/* this - Pointer*/
#include<iostream>
using namespace std;
class Point
{
	private:
		int x;
		int y;
	public:
		void set(int x=0,int y=0)
		{
			this->x=x;
			this->y=y;
		}
		void setX(int a=0)
		{
			x=a;
		}
		void setY(int a=0)
		{
			y=a;
		}
		int getX()
		{
			return x;
		}
		int getY()
		{
			return y;
		}
		void show()
		{
			//cout<<x<<", "<<y;
			cout<<this->x<<", "<<this->y; 
		}
};
int main()
{
	Point p1,p2,p3;
	cout<<"p1=";
	p1.show();
	cout<<endl<<"p2=";
	p2.show();
	cout<<endl<<"p3=";
	p3.show();
	
	p1.set(5,4);
	p2.set(6,10);
	p3.set(10,10);
	
	cout<<"\n\np1=";
	p1.show();
	cout<<endl<<"p2=";
	p2.show();
	cout<<endl<<"p3=";
	p3.show();
	
	return 0;
}
/*
When ever a non static member function is called with the help of object then 
at the time of function call the address of calling object
is passed to that function automatically.
That address is available in invoking method in the form of 'this'.

In all non static member function a pointer is available named 'this' that contains the address of invoking object*/