/*Function Overloading and Ambiguity*/
#include<iostream>
#include<cstdlib>
using namespace std;
void fun(int i)
{
	cout<<endl<<"I am fun with integer argument";
}
void fun(float i)
{
	cout<<endl<<"I am fun with float argument";
}
int main()
{
	int x=10.0;
	float y=10.0;
	fun(x) ;
	fun(y)
;
	fun(10);
	//fun(10.0);//Ambiguous code. Compiler is unable to decide that convert the double value in int of float
	fun((float)10.0);//not ambiguous- float version vill be called
	fun((int)10.0);//not ambiguous- int version will be called
	cout<<endl;
	system("pause");
	return 0;
}