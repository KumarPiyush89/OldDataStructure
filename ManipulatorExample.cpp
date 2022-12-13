/* C++ program to print the table of any entered number*/
/*
	Manipulator
Manipulators are helping function that can modify the input/output stream.

There are two types of manipulato
1. Manipulator that doesn't take argument
2. Manipulator that takes argument
If we use 2nd type manipulator we must include<iomanip>
ex:
endl -> used with output stream-> changes the line and flushes the stream
*/
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int n;
    cout<<"Enter any number:";
    cin>>n;
    cout<<"Table of "<<n<<"is as:";
    for(int i=1;i<=10;i++)
    cout<<endl<<setfill((char)4)<<setw(5)<<n<<"*"<<setw(2)<<i<<"="<<setw(6)<<n*i;
return 0;
}


