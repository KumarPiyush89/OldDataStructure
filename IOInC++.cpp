/*
C++ is an Object oriented programming language
In C++ I/O operation is performed with object.

For output on screen a pre defined object is available of class 'outputstream' named 'cout'.
Syntax:
cout<<valueOrVariableOrExpression;

here 
cout ->Object of output stream class
<< ->Insertion Operator
 ex:
 int i=10;
 cout<<10; //output:10
 cout<<i; //output:10
 cout<<i*3; //output:30
 cout<<'A'; //output: A
 cout<<12.45; //output:12.45
 cout<<"Abhishek Kumar" //output: Abhishek Kumar

 we can cascade <<
 --------------------------
 cout<<2<<"+"<<2<<"="<<2+2; //2+2=4

 to use cout must include<iostream>

to read any type of data from keyboard a pre defined object is available of class 'inputstream' name 'cin'

Syntax:
cin>>varName;

cin - Object of input stream class
>>  -- Extraction operator
ex:
int c;
cin>>c;
 */
/* CPP program that will read a number from user and print the table of that number on screen*/
#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter any number:";
    cin>>n;
    cout<<"Table of "<<n<<" is as:";
    for(int i=1;i<=10;i++)
    cout<<"\n"
	<<n<<"*"<<i<<"="<<n*i;
    cout<<"\n";
    return 0;
}