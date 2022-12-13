/*
Copy Constructor:It is called when and object is initialized with object

Copy constructor takes argument of same type as reference
*/
#include<iostream>
using namespace std;
class Point
{
	private :
		int x;
		int y;
	public:
		Point()
		{
			x=0;
			y=0;
			cout<<"\nObject Created with default constructor";
		}
		Point(int x)
		{
			this->x=y=x;
			cout<<"\nObject created with one integer argument constructor";
		}
		Point(int x,int y)
		{
			this->x=x;
			this->y=y;
			cout<<"\nObject created with two integer argument constructor";
		}
		//user defined copy construcor
		Point(Point &p)
		{
			this->x=p.x;
			this->y=p.y;
			cout<<"\nCopy constructor is called to create object";
		}
		void show()
		{
			cout<<x<<", "<<y;
		}
		void show(char * str,bool changeLine=false)
		{
			cout<<str<<"="<<x<<", "<<y;
			if(changeLine)
			cout<<endl;
		}
		
};
int main()
{
	Point p1; //default contructor wil be called
	Point p2(5); //constructor having one integer argument will be called
	Point p3(10,3);// constructor having two integer argument will be called
	
	p1.show("p1",true);
	p2.show("p2",true);
	p3.show("p3",true);
	
	//create an objct same as p3
	Point p4(p3); //Copy constructor will be called(default copy constryctor-Constructor created by compiler)
	p4.show("p4",true);
	/*
	Is default copy constructor performs member by member copy?
	Ans: No, default copy constructor performs bitwise copy.
	 Many problems are solved by bitwise copy but some problems are not solved by bitwise copy. to solve these
	 type problems, we have to define own copy constructor*/
	 
	 /* Constructoe having one argument can be called as in c++*/
	//Point p5=7; //constructor having one integer argument  will be called
	 Point p6=p3; //copy constructor wil be called
	 
	// p5.show("p5",true);
	 p6.show("p6",true);
	
	return 0;
}