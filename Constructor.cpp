/* constructor */
#include<iostream>
using namespace std;
class Point
{
	private :
		int x;
		int y;
	public :
		//Constructor- Called on every object creation
		Point()
		{
			cout<<"\nObject created and Initialized";
			//member initialization can be done here
			x=0;
			y=0;
		}
		void show(char *obname="")
		{
			cout<<obname<<"="<<x<<", "<<y;
		}
		
};
int main()
{
	Point p1,p2,p3,p4,p5,p6;
	cout<<endl;
	cout<<endl;
	p1.show("p1");
	cout<<endl;
	p2.show("p2");
	cout<<endl;
	p3.show("p3");
	cout<<endl;
	p4.show("p4");
	cout<<endl;
	p5.show("p5");
	cout<<endl;
	p6.show("p6");
	return 0;
}