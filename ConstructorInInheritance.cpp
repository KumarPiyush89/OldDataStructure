/*
Inheritance and Constructor
--------------------------------------
Constructors are called in order of derivation
-----------------------------------------------
ex:
class A
{
...
};

class B:public A
{
...
};

class C:public B
{
...
};

class D:public C
{
....
};

A oba; Class A constructor will be called to create this object
B obb; Class A then class B constructor will be called to create this object
C obc; class A then class B then class C constructor will be called to create this object
D obd; class A then class B then class C then class D constructor will be called to create this object

*/
#include<iostream>
using namespace std;
class A
{
	public:
		A()
		{
			cout<<"\nA's constructor is called";
		}
};

class B:public A
{
	public:
		B()
		{
			cout<<"\nB's constructor is called";
		}
};

class C:public B
{
	public:
		C()
		{
			cout<<"\nC's constructor is called";
		}
};

class D:public C
{
	public:
		D()
		{
			cout<<"\nD's constructor is called";
		}
};

int main()
{
	A a;
	cout<<endl<<endl;
	B b;
	
	cout<<endl<<endl;
	C c;
	
	cout<<endl<<endl;
	D d;
	
	return 0;
}