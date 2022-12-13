/*
Constant refernce (Read Only Reference)
++++++++++++++++++++++++++
we can create constant reference as:
----------------------------------------
const dataType &referenceName=VarName;
ex:
int x=10;
const int &y=x;

using y we can read the value of x,but we cant change the value of x.
*/
#include<iostream>
using namespace std;
int main()
{
	int x=10;
	const int &y=x;
	int &z=x;
	z=20;
	y=30;//error
}
/* Passing constant reference as argument
int pow(const int &x,const int &y)
{
//we can read the value of x and y but we can't change the value of x
}
*/