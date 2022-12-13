/*My Array Class*/
#include<iostream>
using namespace std;
#include<cmath>
class IntArray{
	private:
		int *array;
		int capacity;
		int size;
	public:
		IntArray(int capacity=10)
		{
			if(capacity<=0)capacity=10;
			this->capacity=capacity;
			//allocate memory for array
			array=new int[capacity];
			size=0;
		}
		//destructor
		~IntArray()
		{
			delete []array;
		}
		//copy constructor
		IntArray(IntArray &ob)
		{
			this->capacity=ob.capacity;
			//allocate memory for array
			array=new int[capacity];
			this->size=ob.size;
			//copy array content
			for(int i=0;i<size;i++)
			this->array[i]=ob.array[i];
		}
		bool insert(int data)//insert given data at end of list
		{
			return insert(data,size);	
		}
		bool insert(int data,int pos)
		{
			if(pos<0||pos>size||size==pos)return false;
			for(int i=size-1;i>=pos;i--)array[i+1]=array[i];
			array[pos]=data;
			size++;
			return true;
		}
		bool inserAtFirst(int data)
		{
			return insert(data,0);
		}
		bool remove(int position=0)
		{
			if(size==0||position>=size||position<0)return false;
			for(int i=position;i<size-1;i++)array[i]=array[i+1];
			size--;
			return true;
		}
		bool removeLast()
		{
			return remove(size-1);
		}
		bool put(int index,int data)
		{
			if(index<0||index>=size)return false;
			array[index]=data;
		}
		bool get(int index,int &data)
		{
			if(index<0||index>=size)return false;
			data=array[index];
		}
		bool isEmpty()
		{
			if(size==0)
			return true;
			else
			return false;
		}
		int getSize()
		{
			return size;
		}
		int getCapacity()
		{
			return capacity;
		}
		void print()
		{
			if(size==0)
			{
				cout<<"Liat is empty.";
				return;
			}
			for(int i=0;i<size;i++)
			{
				cout<<array[i];
				if(i<size-1)
				cout<<", ";
			}
		}
		//void sort()
		//reverse
		//find
		//merge
		//copy
		
		
		
};