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

//Overload << with ostream and Person, so theat a Person can be displayed on screes as: Gender:genderValue, age:ageValue
//this operator cant be overloaded as member function Because for  ostream<<Person, operator<<() should be member of
//class ostream and ostream is a predefined class. We can't make changes in ostream class. So, This operator can be overloaded 
//as non member function as:
ostream& operator<<(ostream& out,Person& person)
{
	/* this function is correct but we cant perform our required operation in this function
	because we have to print the private members value of person object in this function and Person class
	has no any public getter function. And this function is not member of Person so we cant access private member of person object
	*/
	out<<"Gender:"<<person.gender<<", Age:"<<person.age;//Error
	/*
	Above problem can be solved by friend fuction
	friend function is non member function that thas power to access the private member of any specific class object.
	 To do so, we have to create a non member function to frind of any specific class.
	 To make any non member function to friend of any specific class write the declaration of that function in that class
	 preceded by friend keyword.
	 
	 friend keyword represents function is friend of class not member of class.
	 */
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

