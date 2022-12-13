/*Overloading VS Default argument*/
#include<iostream>
using namespace std;
//write function to print line
void aLine()
{
	for(int i=1;i<=80;i++)
	cout<<"*";
}
void aLine(char symbol)
{
	for(int i=1;i<=80;i++)
	cout<<symbol;
}
void aLine(int length)
{
	for(int i=1;i<=length;i++)
	cout<<"*";
}
void aLine(char symbol,int length)
{
	for(int i=1;i<=length;i++)
	cout<<symbol;
}
void aLine(int length,char symbol)
{
	aLine(symbol,length);
}

//draw line by rakesh
void rLine(char symbol='*',int length=80)
{
	for(int i=0;i<length;i++)
	cout<<symbol;
}
void rLine(int length,char symbol='*')
{
	rLine(symbol,length);
}

int main()
{
	aLine();
	cout<<endl;
	aLine(40);
	cout<<endl;
	aLine('A');
	cout<<endl;
	aLine('B',40);
	cout<<endl;
	aLine(30,'C');
	cout<<endl<<endl;

	rLine();
	cout<<endl;
	rLine(40);
	cout<<endl;
	rLine('A');
	cout<<endl;
	rLine('b',40);
	cout<<endl;
	rLine(30,'C');
	return 0;
}