/* Write a CPP program that accepts a hexadecimal number and print the entered number and its equivalent
decimal and octal*/
#include<iostream>
using namespace std;
int main()
{
	int a;
	cout<<endl<<"Enter any number in hexadecimal form:";
	cin>>hex>>a;
	cout<<endl<<"You have entered:"<<hex<<a;
	cout<<endl<<"its decimal form:"<<dec<<a;
	cout<<endl<<"its octal form:"<<oct<<a;
	return 0;
}