#include<iostream>
using namespace std;
class A
{
    public:
    A()
    {
        cout<<"\nA's constructor called";
    }
};
class B
{
    public:
    B()
    {
        cout<<endl<<"B's constructor called";
    }
};
class C:public B,public A
{
    public:
    C()
    {
        cout<<endl<<"C's constructor called";
    }
};

/* Above Class C is inheriting two classes A and B at a time. It is called multiple inheritance*/
int main()
{
    C ob1;
    
    return 0;
}