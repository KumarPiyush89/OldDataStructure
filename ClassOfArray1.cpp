/* write a cpp program that will accept n numbers from users untill
  user enter 0. print the all entered numbers */
#include"ClassOfArray.cpp"
using namespace std;

int main()
{
	IntArray list;
	int data;
	cout<<"\n Total capacity is "<<list.getCapacity()<<"\n And, Total size is : "<<list.getSize();
	while(1)
	{
		cout<<"\nEnter number(0 to stop): ";
		cin>>data;
		
		if(!data)
		break;
		if(!list.isSpace())
		{
			if(!list.updateCapacity())
			break;
		}
		
		if(!list.insert(data))
		break;
					
	}
	cout<<"Entered all data are : ";
	list.print();
	cout<<"\n Total capacity is "<<list.getCapacity()<<"\n And, Total size is : "<<list.getSize();
	return 0;
}