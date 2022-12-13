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
	IntStack first(5),second,third(12) ;
	cout<<"size of stack first is:"<<first.getSize();
	cout<<endl<<"size of stack sesond is:"<<second.getSize();
	cout<<endl<<"size of stack third is:"<<third.getSize();
	
	cout<<endl<<"content of stack first is:";
	first.show();
	cout<<endl<<"content of stack second is:";
	second.show();
	cout<<endl<<"content of stack third is:";
	third.show();
	
	first.push(10);
	first.push(20);
	first.push(30);
	first.push(56);
	
	second.push(11);
	second.push(12);
	second.push(13);
	second.push(14);
	
	third.push(51);
	third.push(61);
	third.push(56);
	
	cout<<endl<<endl<<"content of stack first is:";
	first.show();
	cout<<endl<<"content of stack second is:";
	second.show();
	cout<<endl<<"content of stack third is:";
	third.show();
	
	first.push(45);
	first.push(89);
	
	int d;
	second.pop(d);
	third.pop(d);
	
	cout<<endl<<endl<<"content of stack first is:";
	first.show();
	cout<<endl<<"content of stack second is:";
	second.show();
	cout<<endl<<"content of stack third is:";
	third.show();
	
	return 0;
}