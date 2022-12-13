//C++ program to demostrate dynamic array
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int *a,n;
	cout<<"How many numbers do you want to enter: ";
	cin>>n;
	n=abs(n);
	a=new int[n];
	int i;
	for( i=0;i<n;i++)
	{
		cout<<"Enter number "<<i+1<<" : ";
		cin>>a[i];
	}
	cout<<endl<<"All entered numbers are "<<endl;
	for(i=0;i<n;i++)
	cout<<a[i]<<", ";
	//deleteing dynamic allocated array.
	delete []a;
	
	return 0;
	
}