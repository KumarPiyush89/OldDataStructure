/* Static Member Example*/
/*
Creating a class which total created object can be counted any time
*/
#include<iostream>
using namespace std;
class Point
{
    private:
    int x;
    int y;
    static int objCounter;
    public:
    Point(int x=0,int y=0)
    {
        this->x=x;
        this->y=y;
        objCounter++;
    }
    Point(Point &p)
    {
        x=p.x;
        y=p.y;
        objCounter++;
    }
    void show(char *pname="Point")
    {
        cout<<pname<<"="<<x<<","<<y;
    }
    static void showTotalObject()
    {
        cout<<endl<<"Total "<<objCounter<<" objects created till now.";
    }

};
//Creating/declaring Static Member of class
int Point::objCounter=0;

Point test(Point p)
{
	return p;
}
int main()
{
    Point::showTotalObject();
    Point p1;
    Point::showTotalObject();
    Point p2,p3,p4(10,4);
    Point::showTotalObject();
    test(p4);
    Point::showTotalObject();
    p4.showTotalObject();
    return 0;
}
//Operator Overloading