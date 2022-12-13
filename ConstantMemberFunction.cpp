/*Constant nmember function

In C++ class a member function can be constant.
A constant memeber function can access all private and public member of class but can't make changes in
any member. In this type of cuntion all members are read only.

Declaration:
returnType functionName(argList) const
{
//function defination
}
*/
#include<iostream>
using namespace std;
class Demo
{
	int i;
	int j;
	public:
		Demo(int i=0,int j=0)
		{
			this->i=i;
			this->j=j;
		}
		public:
		 void set(int i,int j)
		{
			this->i=i;
			this->j=j;
		}
		void show() const
		{
			cout<<i<<", "<<j;
			//it is a const function it can read the class member but can't change the value of class member
			//if it try so the compiler will generate error
			//i+=2; //Error!
		}
		
};
int main()
{
	Demo ob1,ob2(10,20);
	cout<<"ob1=";
	ob1.show();
	cout<<endl<<"ob2=";
	ob2.show();
	//We Can create constant reference of object as:
	Demo &ob3=ob2;
	const Demo &ob4=ob2;
	//Normal reference can access all public member of object
	//Constant reference can access onlyconstant public member of class
	ob3.set(30,40);
	cout<<"ob3=";
	ob3.show();
	cout<<endl<<"ob2=";
	ob2.show();
	
	//ob4.set(50,50);//Error: only constant member can be called
	cout<<"\nob4=";
	ob4.show();//bca show() ia a constant function
	
	return 0;
}