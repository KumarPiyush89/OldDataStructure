#include<iostream>
#include<vector>
#include<iterator>
#include<string>
using namespace std;
class Student
{
    public:
    string name;
    int roll;
    public:
    Student (string name="",int roll=0)
    {
        this->name=name;
        this->roll=roll;
    }
};
int main()
{
    vector<int> nums={3,4,5,6,7};
    //traversal
    for(auto i:nums)
    cout<<i,", ";

    vector<Student> students;
    Student s1("Abhishek kumar",1);
    students.push_back(s1);
    Student s2("Ankit kumar",2);
    students.push_back(s2);
    Student s3("Shubham kumar",3);
    students.push_back(s3);
    Student s4("Piyush kumar",4);
    students.push_back(s4);
    Student s5("Aaryan raj",5);
    students.push_back(s5);

    s1.name="Rakesh kumar";
    for(auto st:students)
    cout<<endl<<"Name: "<<st.name<<", roll: "<<st.roll;

    /*for(auto st:students)
    {
        st.roll*=2;//it will change in copy, not in vector's object.
    }*/
/*for(auto st=students.begin();st<students.end();st++)
    {
        st->roll*=2;// it will change in container's object.
    }*/

    for(auto &st:students)
    {
        st.roll*=2;
    }
    cout<<endl;
    for(auto st:students)
    cout<<endl<<"Name: "<<st.name<<", roll: "<<st.roll;

    s1.name="Raj sir";
    s1.roll=1;
    students.insert(students.begin(),s1);

    s1.name="Piyush kumar sinha";
    s1.roll=2;
    students.insert(students.begin()+2,s1);

    s1.name="Kumar Piyush";
    s1.roll=1;
    students.assign(0,s1);

    cout<<endl;
    for(auto st:students)
    cout<<endl<<"Name: "<<st.name<<", roll: "<<st.roll;


    return 0;
}
/*
 write a cpp program that will accepts the name, roll and marks of five
 subjects of N students and print all records with total marks and division.

*/