/*
Calling Specific base class constructor using derived class constructor
class A
{
...
};
class B:public A
{
	public:
	B()	//it will call default constructor of base class
	{
	}
	B(args)//it will call default constructor of base class
	{
	}
	B(args):A(args) //it will call parametrized constructor(that maches arguments) of Base Calss
	{
	}
};

*/
#include<iostream>
using namespace std;
class A
{
	private:
	int a;
	public:
		A()
		{
			a=0;
			cout<<"\nA's default constructor is called.";
		}
		A(int a)
		{
			this->a=a;
			cout<<"\nA's parametrized constructor is called";
		}
};
class B:public A
{
	private:
		int b;
	public:
		B()
		{
			b=0;
			cout<<"\nB's default constructor is called";
		}
		B(int b)
		{
			this->b=b;
			cout<<"\nB's parametrized constructor is called";
		}
		B(int a,int b):A(a)  //It will call constructor of Class A having one int argument
		{		
			this->b=b;
			cout<<"\nB's parametrized constructor having two argument is called";
		}
};
int main()
{
	B b1;
	
	cout<<endl<<endl;
	B b2(12);
	
	cout<<endl<<endl;
	B b3(10,20);
	
	
	return 0;
	
}