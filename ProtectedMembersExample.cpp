/*Protected Members are not accessible by non member function but accessible by Derived Class members*/
#include<iostream>
#include<cmath>
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
			age=abs(age);
			this->age=age;
		}
		void setName(string name)
		{
			this->name=name;
		}
		void setAge(int age)
		{
			
			this->age=abs(age);
		}
		string getName()
		{
			return name;
		}
		int getAge()
		{
			return age;
		}
		void show()
		{
			cout<<"Person:Name:"<<name<<", age:"<<age;
		}
};
class Student:public Person
{
	protected:
		int clas;
		int tmarks;
	public:
		Student(int clas=0,int tmarks=0)
		{
			this->clas=abs(clas);
			this->tmarks=tmarks;
		}
		void setClass(int clas)
		{
			this->clas=clas;
	
		}
		void setTotalMarks(int tmarks)
		{
			this->tmarks=tmarks;
		}
		int getclass()
		{
			return clas;
		}
		int getTotalMarks()
		{
			return tmarks;
		}
		void show()
		{
			cout<<"Student:Name:"<<name<<", age:"<<age<<", class="<<clas<<", Total Marks="<<tmarks;
		}
		
		
};

int main()
{
	Person p1("Aalok Kumar",20);
	Student s1;
	s1.setName("Kundan Kumar");
	s1.setAge(23);
	s1.setClass(10);
	s1.setTotalMarks(390);
	
	cout<<endl;
	p1.show();
	cout<<endl;
	s1.show();
}