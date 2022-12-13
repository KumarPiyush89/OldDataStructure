/* Template Functions*/
#include<iostream>
using namespace std;
template<class T>
void mswap(T &x,T &y)
{
    T t;
    t=x;
    x=y;
    y=t;
}
class MyType
{
    public:
    int x;
    int y;
    MyType(int x=0,int y=0)
    {
        this->x=x;
        this->y=y;
    }
    void show()
    {
        cout<<"x="<<x<<"and y="<<y;
    }
};

int main()
{
    int a=10,b=20;
    cout<<"a="<<a<<", b="<<b;
    mswap(a,b);
    cout<<endl<<"a="<<a<<", b="<<b;

    float c=10.5,d=20.5;
    cout<<"c="<<c<<", d="<<d;
    mswap(c,d);
    cout<<endl<<"c="<<c<<", d="<<d;

    MyType t1(10,15),t2(30,50);
    cout<<endl<<"t1=";
    t1.show();
    cout<<endl<<"t2=";
    t2.show();
    mswap(t1,t2);
    cout<<endl<<endl<<"t1=";
    t1.show();
    cout<<endl<<"t2=";
    t2.show();
    return 0;
}
