/*
Friend Function
--------------------------
Note: Member function can access all type(private, public, protected) member of its object

A Non member function can access only public member of any object.
*/
#include<iostream>
using namespace std;
class Person
{
	private:
		int age;
		char gender;
		
	//friend function declaration
	friend ostream& operator<<(ostream&,Person&);//
	public:
		Person(int age=0,char gender='m')
		{
			this->age=age;
			this->gender=gender;
		}
		void show()
		{
			cout<<"Person:Gender:"<<gender<<", age:"<<age;
		}
		//Note there is no getter functtion for any private member
};

ostream& operator<<(ostream& out,Person& person)
{
	out<<"Gender:"<<person.gender<<", Age:"<<person.age;//Error
	return out;
} 

int main()
{
	Person p1,p2(32,'m');
	//show the content of both object
	p1.show();
	cout<<endl;
	p2.show();
	
	cout<<endl;
	cout<<p2;
	return 0;
}