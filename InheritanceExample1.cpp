/*
Inheritance
---------------------------
Syntax:
class ClassName[:[accessSpecifier]  BaseClassName,[[accessSpecifier] BaseClassName]]
{
classBody
};

Not: [] is not part of syntax, it represents optional part
ex:

class Person
{
public:
	string name;
	char gender;
};

class Student:public Person
{
public:
	string clas;
	int roll;
};

In above example Student class is inheriting Person class. All members of class Person is available in class Student.
i.e. Person class has two memmbers (name and gender), and Student class has 4 members (name,gender,clas and roll)
 
 Here Person is Base class and Student is Derived Class
 
 Whenever a class is inherited by any class, all members(private, protected or public) of Base class is available 
 in Derived class but only protected and public members are accessable in derived class.
 
 A derived class can't access the private member of its Base class.
 */
 #include<iostream>
using namespace std;
class Person
{
	private:
		string name;
	public:
		Person()
		{
			name="";
		}
		void setName(string name)
		{
			this->name=name;
		}
		string getName()
		{
			return name;
		}
		void showPerson()
		{
			cout<<"Name:"<<name;
		}
			
} ;
class Employee:public Person
{
	private:
		string designation;
	public:
		Employee()
		{
			designation="";
		}
		void setDesignation(string deg)
		{
			designation=deg;
		}
		string getDesignation()
		{
			return designation;
		}
		void show()
		{
			//display name
			//cout<<name;//Error! name is not accessible here
			
			cout<<"Name:"<<getName()<<", Designation:"<<designation;
		}
};
int main()
{
	Person p1;
	Employee e1;
	
	p1.setName("Aaryan Raj");
	e1.setName("Abhishek Kumar");
	e1.setDesignation("MTS");
	
	cout<<endl;
	p1.showPerson();
	
	cout<<endl<<endl;
	e1.show();
	return 0;
}