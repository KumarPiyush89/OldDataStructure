/*
Reference
===============
Passing argument by Reference
---------------------------------
We can pass arguments to function as reference.
As we Know reference is synonym for any variable, if we perform
any changes on reference the it directly affects th variable.
So if we pass any variable as reference to function then the formal argument
will be the synonym of actual  argument. Any changes made in formal argument 
will affect the actual argument.
*/
#include<iostream>
using namespace std;
void swapIntByRef(int&,int&);
void swapIntByRef(int &a,int &b)
{
	int c;
	c=a;
	a=b;
	b=c;	
}

void swapIntByAdd(int*,int*);
void swapIntByAdd(int *a,int *b)
{
	int c;
	c=*a;
	*a=*b;
	*b=c;
}
int main()
{
	int a=10,b=20,c=18,d=30;
	cout<<"Before swap a="<<a<<", b="<<b<<", c="<<c<<" and d="<<d;
	//call swapByReference to swap value of a and b
	swapIntByRef(a,b);
	//call swapByAdd to swap value of c and d
	swapIntByAdd(&c,&d);
	cout<<"\nAfter swap a="<<a<<", b="<<b<<", c="<<c<<" and d="<<d;
	return 0;
	
	
}