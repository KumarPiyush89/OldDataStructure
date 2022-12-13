#include<iostream>
using namespace std;
class Person
{
	public:
		Person()
		{
			cout<<"Person object is created with default value";
		}
		Person(int color)
		{
			cout<<"Person object is created with given color";
		}
		Person(int color, int weight)
		{
			cout<<"Person object is created with given color and weight";
		}
		~Person()
		{
			cout<<"Person destroyed";
		}
		
		
};
int main()
{
	Person p1,p2(3),p3(4,5);
	
}