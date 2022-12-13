/* 
Reference To constant variable
=============================================
*/
#include<iostream>
using namespace std;
int main()
{
	const int x=10;
	//create a reference of x
	//int &y=x;//error:
	const int &y=x;
	int z=10;
	volatile int &a=z;
	const int &b=z;
	return 0;
}