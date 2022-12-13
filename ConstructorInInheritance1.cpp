/*
If a base class has multiple constructors and there is no info provided in derived class' constructor then
all derived class constructor calls default constructor of its base class*/
#include<iostream>
using namespace std;
class A
{
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
};
int main()
{
	B b1;
	
	cout<<endl<<endl;
	B b2(12);
	
	
	return 0;
	
}
