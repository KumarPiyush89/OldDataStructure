#include<iostream>
using namespace std;
class Point
{
	private :
		int x;
		int y;
	public:
		Point()
		{
			x=0;
			y=0;
		}
		Point(int x,int y)
		{
			this->x=x;
			this->y=y;	
		}
		Point(int x)
		{
			this->x=this->y=x;
		}
		void set(int x,int y)
		{
			this->x=x;
			this->y=y;
		}
		void set(int x)
		{
			this->x=this->y=x;
		}
		void setx(int x)
		{
			this->x=x;
		}
		void sety(int y)
		{
			this->y=y;
		}
		int getx()
		{
			return x;
		}
		int gety()
		{
			return y;
		}
		void show()
		{
			cout<<x<<", "<<y;
		}
		void show(char *name,bool changeLine=false)
		{
			cout<<name<<"="<<x<<","<<y;
			if(changeLine)cout<<endl;
		}
		void swap()
		{
			int a=x;
			x=y;
			y=a;
		}		
		
};

int main ()
{
	Point p1,p2(23,56),p3(10),p4=p2;
	p1.show("p1",true);
	p2.show("p2",true);
	p3.show("p3",true);
	p4.show("p4",true);
	
	cout<<"Object p4 and p2 are different object but having same data. If we change data in p2 it will not affect p4";
	p2.set(p2.gety(),p2.getx());
	p2.show("p2",true);
	p4.show("p4",true);
	return 0;
	
	
}
