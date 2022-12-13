/*
Constructor can take arguments.
So, constructors can be overloaded.
So, a class may have many constructors.

types of constructor
------------------------
Constructor without argument (Default Constructor)
Constructor with arguments (Parametrized Constructor)

Copy Constructor
------------------------------------
-----------------------------------------
Parametrized Constructor
-------------------------------------
Constructors That take arguments
*/
#include<iostream>
using namespace std;
class Point
{
	private:
		int x;
		int y;
	public:
		Point()//default constructor
		{
			x=0;
			y=0;
		}
	Point(int x,int y)
	{
		this->x=x;
		this->y=y;	
	}	
	//overloading constructor
	Point(int x)
	{
		this->x=x;
		this->y=x;
	}
	void show(char * n)
	{
		cout<<n<<"="<<x<<", "<<y;
	}
		
};
/* Creating object using parametrized constructor
//using default constructor
ClassName objectName;

//using parametrized constructor
ClassName objectName(parameters);
*/
int main()
{
Point p1; //default constructor will be called
Point p2(10,2); //Constructor having two integer argument will be called
Point p3(30);//Constructor having one integer argument will be called
p1.show("p1");
cout<<endl;
p2.show("p2");
cout<<endl;
p3.show("p3");
return 0;
}/*
In C++ if we create a class and don't create any constructor in it then compiler automatically creates
default constructor(Constructor without argument) that initializes the members by garbage value.

If we create any constructor in class then compiler will not create any constructor, so create default constructor 
to create objects without argument.

next topic -->copy constructor
*/