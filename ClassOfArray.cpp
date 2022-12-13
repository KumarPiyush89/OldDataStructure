//ClassOfArray2.cpp
/*My Array Class*/
#include<iostream>
#include<cmath>
using namespace std;
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
		//increase size of an array
		bool updateCapacity(int newCap=0)
		{
			/*size=abs(size);
			if(size==0)
			{
				delete []array;
				array=NULL;
				return true;
			}*/
			if(newCap<0)
			return false;
			
			if(newCap==0)
			newCap=capacity+10;
			// allocate memory of new cap.
			int *data=new int[newCap];
			if(!(*data))
			return false;
			//update capacity
			this->capacity=newCap;
			//update size
			 if(newCap<size)
			 size=newCap;
			//copy old memory data into new memory data.
			for(int i=0;i<size;i++)
			data[i]=array[i];
			
			delete []array;
			 array=data;
			 return true;
		}
		bool isSpace()
		{
			if(size<capacity)
			return true;
			else
			return false;
		}
		bool insert(int data)//insert given data at end of list
		{
			return insert(data,size);	
		}
		bool insert(int data,int pos)
		{
			if(pos<0||pos>size||size==capacity)return false;
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
				cout<<"List is empty.";
				return;
			}
			for(int i=0;i<size;i++)
			{
				cout<<array[i];
				if(i<size-1)
				cout<<", ";
			}
		}
		//swap
		void swap(int &x,int &y)
		{
			int t=x;
			x=y;
			y=t;
		}
		//void sort()
		bool sortAsc(int start=0,int end=0)
		{
			end=getSize();
			if(!start>=0&&end<size&&start<size-1&&end>=1)
			return false;
			
			if(start>end)
			{
				swap(start,end);
			}
			int i,j;
			for(i=start;i<=end;i++)
			{
				for(j=i+1;j<=end;j++)
				{
					if(array[i]>array[j])
					swap(array[i],array[j]);
				}
			}
			return true;
		}
		
		//void sort()
		bool sortDesc(int start=0,int end=10)
		{
			end=getSize();
			if(!start>=0&&end<size&&start<size-1&&end>=1)
			return false;
			
			if(start>end)
			{
				swap(start,end);
			}
			int i,j;
			for(i=start;i<=end;i++)
			{
				for(j=i+1;j<=end;j++)
				{
					if(array[i]<array[j])
					swap(array[i],array[j]);
				}
			}
			return true;
		}
		//reverse
		void reverse()
		{
			int i;
			for(i=0;i<size/2;i++)
			swap(array[i],array[size-i-1]);
		}
		//find
		int find(int data)
		{
			for(int i=0;i<size;i++)
			{
				if(data==array[i])
				return i;
			}
			return -1;
		}
		//merge
		/*bool merge(int pos,int *data,int size)
		{
			
		}*/
		//copy
		
		
		
};
/*int main()
{
	IntArray ar(10);
	ar.insert(1);
	ar.insert(2);
	ar.insert(3);
	ar.insert(4);
	ar.insert(5);
	ar.insert(6);
	ar.insert(7);
	ar.insert(8);
	ar.insert(9);
	ar.insert(10);
	int s=ar.getSize();
	cout<<s<<endl;
	ar.print();
	ar.updateCapacity(5);
	cout<<endl;
	ar.print();
	ar.updateCapacity(3);
	cout<<endl;
	ar.print();
	//ar.updateCapacity(0);
	ar.updateCapacity(3);
	cout<<endl;
	return 0;
}*/