/* Write a CPP program that will accept number and prints its square*/
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
	double a;
	cout<<"Enter any Number:";
	cin>>a;
	cout<<endl<<setprecision(10)<<"You have entered :"<<a<<" and its square root is:"<<setprecision(10)<<sqrt(a);
	return 0;
}


