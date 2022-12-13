/* C++ program to add two numbers using dynamic memory allocation*/
#include<iostream>
using namespace std; 
int main()
{
	int *p1,*p2,*p3;
	p1=new int;
	p2=new int;
	p3=new int;
	cout<<"Enter 1st number:";
	cin>>*p1;
	cout<<"Enter 2nd number:";
	cin>>*p2;
	*p3=*p1+*p2;
	cout<<*p1<<"+"<<*p2<<"="<<*p3;
	delete p1;
	delete p2;
	delete p3;
	return 0;
	
}