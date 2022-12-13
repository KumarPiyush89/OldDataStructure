/* Function with default argument*/
#include<iostream>
using namespace std;
long power(int n,int p=2)//here 2nd argument has default value 2, if power()function is called with only one argument the function will be called and the 2nd argument will be 2
{
	long power=1;
	for(int i=1;i<=p;i++)
	power*=n;
	return power;
}
int main()
{
	cout<<"Result="<<power(2,1);
	cout<<endl<<"Result="<<power(5,0);
	cout<<"\nResult="<<power(3,4);
	cout<<"\nResult="<<power(2);
	cout<<"\nResult="<<power(10);
	return 0;
}
/* rules for making default argument

1. Any number of argument can be default value in default argument function
ex:
returnType function1(int x,int y,int z=10);
returntype function2(int x,int y=5,int z=10);
returnType function3(int x=2,int y=5,int z=12);

2. A non default argument can't be after default argument
ex:
returntype function1(int x,int y,int z=13);//correct
returnType function2(int x,int y=10,int z);//error

3. If we are declaring and defining functions, the default argument must be 
specified in function declaration.
Note : Default argument value can't be set in bot declaration and defination
ex:
Correct:
void sum(int=0,int=0);
void sum(int x,int y)
{
//function body
}

Error:
void sum(int=0,int=0);
void sum(int x=0,int y=0)
{
//function body
}

Error:
void sum(int,int);
void sum(int x=0,int y=0)
{
//function body
}

Correct:

void sum(int x=0,int y=0)
{
//function body
}
*/