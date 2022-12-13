#include<iostream>
#include<string>
using namespace std;
class Person
{
    private :
    string name;
    char gender;
    public:
    Person()
    {
        name="";
        gender='m';
    }
    Person(string name,char gender)
    {
        this->name=name;
        if(gender=='m'||gender=='M')
        this->gender=gender;
        else
        this->gender='f';
    }
    void setName(string name)
    {
        this->name=name;
    }
    string getName()
    {
        return name;
    }
    void setGender(char gender)
    {
        if(gender=='m'||gender=='M')
        this->gender=gender;
        else
        this->gender='f';
    }
    char getGender()
    {
        return gender;
    }
    void showPerson()
    {
        cout<<"Person:Name:"<<name<<"Gender:"<<gender;
      }
};

class Student:public Person
{
    private:
        int clas;
        int roll;
    public:
        Student()
        {
            clas=0;
            roll=0;
        }
        Student(string name,char gender,int clas,int roll):Person(name,gender)
        {
            this->clas=clas;
            this->roll=roll;
        }
        void setClass(int clas)
        {
            this->clas=clas;
        }
        int getClass()
        {
            return clas;
        }
        void setRoll(int roll)
        {
            this->roll=roll;
        }
        int getRoll()
        {
            return roll;
        }
        void showStudent()
        {
            cout<<"student:Name:"<<getName()<<", Gender:"<<getGender()<<", Class:"<<clas<<", Roll:"<<roll;
        }

};

int main()
{
    Person p1,p2("Abhishek Kumar",'m');
    cout<<endl;
    p1.showPerson();
    cout<<endl;
    p2.showPerson();

    cout<<endl<<endl;
    Student s1,s2("Rakesh Kumar",'m',12,50);
    s1.showStudent();
    cout<<endl;
    s2.showStudent();
    return 0;
}