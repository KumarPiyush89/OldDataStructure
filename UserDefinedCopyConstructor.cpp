#include<iostream>
#include<cmath>
using namespace std;

class IntStack
{
	
	private :
		int *array;
		int size;
		int tos;
	public:
		IntStack(int size=10)
		{
			size=abs(size);
			if(size==0)size=10;
			this->size=size;
			array=new int[this->size];
			tos=-1;
		}
		//creating Copy constructor
		IntStack(IntStack &ob)
		{
			this->size=ob.size;
			this->tos=ob.tos;
			array=new int[this->size];
			//copy array data
			for(int i=0;i<=tos;i++)
			array[i]=ob.array[i];
		}
		bool push(int data)
		{
			if(tos==size-1)return false;
			array[++tos]=data;
			return true;
		}
		bool pop(int &data)
		{
			if(tos==-1)return false;
			data=array[tos--];
			return true;
		}
		bool pick(int &data)
		{
			if(tos==-1)return false;
			data=array[tos];
			return true;
		}
		void show()
		{
			if(tos==-1)
			{
				cout<<"Stack is empty";
				return;
			}
			for(int i=0;i<=tos;i++)
			{
				cout<<array[i];
				if(i<tos)cout<<">";
			}
		}
		int getSize()
		{
			return size;
		}
		bool isEmpty()
		{
			if(tos==-1)
			return true;
			else
			return false;
		}
		//Destructor
		~IntStack()
		{
		//code for destroy object
		delete[]array;	
		}
		
};
int main()
{
	IntStack s1(5);
	s1.push(1);
	s1.push(2);
	s1.push(3);
	
	IntStack s2(6);
	s2.push(10);
	s2.push(20);
	
	cout<<endl<<"s1=";
	s1.show();
	cout<<endl<<"s2=";
	s2.show();
	
	IntStack s3=s1;//ccopy constructor will be called
	
	cout<<"\ns3=";
	s3.show();
	
	cout<<endl<<"Size of s1="<<s1.getSize()<<" and s3="<<s3.getSize();
	int data;
	s1.pop(data);
	s1.push(4);
	cout<<endl<<"s1=";
	s1.show();
	cout<<endl<<"s3=";
	s3.show();
	
	return 0;
}