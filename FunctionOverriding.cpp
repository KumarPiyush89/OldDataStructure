/* Function Overriding*/
#include<iostream>
using namespace std;
class Person
{
	protected:
		string name;
		int age;
	public:
		Person(string name="",int age=0)
		{
			this->name=name;
			this->age=age;
		}
		void show()
		{
			cout<<"\nPerson, Name:"<<name<<", Age:"<<age;
		}
			
};

class Student:public Person
{
	protected:
		int clas;
		int roll;
	public:
		Student(string name="",int age=0,int clas=0,int roll=0):Person(name,age)
		{
			this->clas=clas;
			this->roll=roll;
		}
		
		/* show function is inherited from class Person but that function will only print name and age
		it will not print class and roll.
		If we want to chane the defination of show() in this class we can change it without changing the signature of show()*/
		
		/*Overriding show()*/
		void show()
		{
			cout<<"\nStudent: Name:"<<name<<", Age:"<<age<<", Class:"<<clas<<", Roll:"<<roll;
		}
};
int main()
{
	Person p("Rakesh Kumar",20);
	Student s("Aaryan Raj",21,12,45);
	p.show();
	s.show();
	return 0;
}
