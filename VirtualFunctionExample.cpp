/*Virtual Function Example*/
#include<iostream>
using namespace std;
class Thing
{
    public:
    virtual void show()
    {
        cout<<"\n I am Thing";
    }
};

class LivingThing:public Thing
{
    public:
    void show()
    {
        cout<<"\nI am Living Thing";
    }
};

class NonLivingThing:public Thing
{
    public :
    void show()
    {
        cout<<"\nI am NonLiving Thing";
    }
};
class Human:public LivingThing
{
 public:
 void show()
 {
    cout<<"\nI am Human";
 } 

};

void tellAboutYourself(Thing &obj)
{
    obj.show();   
}

int main()
{
    Thing t;
    LivingThing lt;
    NonLivingThing nlt;
    Human h;

    tellAboutYourself(t);
    tellAboutYourself(lt);
    tellAboutYourself(nlt);
    tellAboutYourself(h);
    
}