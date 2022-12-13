/* Write a C++  program in which create a class to represent a person that will store the
name, gender and age of person. Aslo create a class to represent  a student that will
store name, gender, age, class, roll and marks of student. create object of both class and 
assign value in both object and print both object on screen.*/

#include<iostream>
#include<string>
#include<cmath>
using namespace std;

class Person
{
	private :
		string name;
		char gender;
		int age;
	public :
		Person(string name="",char gender='m',int age=0)
		{
			this->name=name;
			if(gender=='m'||gender=='M')
			this->gender='m';
			else
			this->gender='f';
			this->age=abs(age);
		}
		void set(string name,char gender,int age)
		{
			this->name=name;
			if(gender=='m'||gender=='M')
			this->gender='m';
			else
			this->gender='f';
			this->age=abs(age);
			
		}
		void setName(string name)
		{
			this->name=name;
		}
		void setGender(char gender)
		{
			if(gender=='m'||gender=='M')
			this->gender='m';
			else
			this->gender='f';
		}
		void setAge(int age)
		{
			this->age=abs(age);
		}
		string getName()
		{
			return name;
		}
		char getGender()
		{
			return gender;
		}
		int getAge()
		{
			return age;
		}
		void show()
		{
			cout<<endl<<"Name:"<<name<<", Gender:"<<gender<<", Age:"<<age;
		}
};

class Student
{
	private:
		string name;
		char gender;
		int age;
		int clas;
		int roll;
		int marks;
	public:
		Student(string name="",char gender='m',int age=0,int clas=0,int roll=0,int marks=0)
		{
			this->name=name;
			if(gender=='m'||gender=='M')
			this->gender='m';
			else
			this->gender='f';
			this->age=abs(age);
			this->clas=abs(clas);
			this->roll=abs(roll);
			this->marks=abs(marks);
		}
		void set(string name,char gender,int age,int clas,int roll,int marks)
		{
			this->name=name;
			if(gender=='m'||gender=='M')
			this->gender='m';
			else
			this->gender='f';
			this->age=abs(age);
			this->clas=abs(clas);
			this->roll=abs(roll);
			this->marks=abs(marks);
		}
		void setName(string name)
		{
			this->name=name;
		}
		void setGender(char gender)
		{
			if(gender=='m'||gender=='M')
			this->gender='m';
			else
			this->gender='g';
		}
		void setAge(int age)
		{
			this->age=abs(age);
		}
		void setClass(int clas)
		{
			this->clas=abs(clas);
		}
		void setRoll(int roll)
		{
			this->roll=abs(roll);
		}
		void setMarks(int marks)
		{
			this->marks=abs(marks);
		}
		string getName()
		{
			return name;
		}
		char getGender()
		{
			return gender;
		}
		int getAge()
		{
			return age;
		}
		int getClass()
		{
			return clas;
		}
		int getRoll()
		{
			return roll;
		}
		int getMarks()
		{
		return marks;
		}
		
		void show()
		{
			cout<<endl<<"Name:"<<name<<", Gender:"<<gender<<", Age:"<<age
			<<", Class:"<<clas<<", Roll:"<<roll<<", Marks:"<<marks;
					}
};
int main()
{
	Person p1("Rakesh Kumar",'m',21);
	Student s1("Aaryan Raj",'m',20);
	p1.show();
	s1.show();
	p1.setName("Rakesh Kumar raj");
	s1.setName("Raj Aaryan");
	
	cout<<endl<<endl;
	p1.show();
	s1.show();
	}