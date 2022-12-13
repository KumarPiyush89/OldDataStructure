#include<iostream>
using namespace std;
class FractionNumber
{
	private :
		int num;
		int dnum;
	public:
		void set(int n=0,int d=1)
		{
			num=n;
			if(d!=0)
				dnum=d;
			else
				dnum=1;
				
				if(dnum<0)
				{
					num*=-1;
					dnum*=-1;
				}
		}
		void setNum(int n)
		{
			num=n;
		}
		void setDnum(int d=1)
		{
			if(d!=0)
			dnum=d;
			else
			dnum=1;
			
			if(dnum<0)
			{
				num*=-1;
				dnum*=-1;
			}
		}
		int getNum()
		{
			return num;
		}
		int getDnum()
		{
			return dnum;
		}
		void show()
		{
			cout<<num<<"/"<<dnum;
		}
		void  show(char* objectName)
		{
			cout<<objectName<<"="<<num<<"/"<<dnum;
		}
		FractionNumber add(FractionNumber fn2)
		{
			FractionNumber fn3;
			int x,y;
			x=dnum;
			y=fn2.dnum;
			while(x!=y)
			{
				if(x<y)
				x+=dnum;
				else
				y+=fn2.dnum;
			}
			fn3.dnum=x;
			fn3.num=x/dnum*num+x/fn2.dnum*fn2.num;
			return fn3;
		}
		
		FractionNumber add(int data)
		{
			FractionNumber f;
			f.set(data);
			return add(f);
		}
		
		
};
int main()
{
	//create 4 different object of FractionNumber
	FractionNumber ob1,ob2,ob3,ob4;
	//all objects are containing garbage value
	ob1.show("ob1");
	cout<<endl;
	ob2.show("ob2");
	cout<<endl;
	ob3.show("ob3");
	cout<<endl;
	ob4.show("ob4");
	//assign 23/5, 22/1, 45/2,18/6 in ob1,ob2,ob3 and ob4 respectively
	ob1.set(23,5);
	ob2.set(22);
	ob3.set(45,2);
	ob4.setNum(18);
	ob4.setDnum(6);
	cout<<endl<<endl;
	ob1.show("ob1");
	cout<<endl;
	ob2.show("ob2");
	cout<<endl;
	ob3.show("ob3");
	cout<<endl;
	ob4.show("ob4");
	//replace the num value of ob4 by 19
	ob4.setNum(19);
	cout<<endl<<endl;
	ob4.show("ob4");
	//repace the num value of ob3 by 70 using set()
	ob3.set(70,ob3.getDnum());
	cout<<endl<<endl;
	ob3.show("ob3");
	//add ob1 and ob2 and store result in ob3
	ob3=ob1.add(ob2);
	cout<<endl<<endl;
	ob1.show();
	cout<<"+";
	ob2.show();
	cout<<"=";
	ob3.show();
	
	//add 10 in ob3 and store result in ob4
	ob4=ob3.add(10);
	cout<<endl;
	ob3.show();
	cout<<"+ 10 = ";
	ob4.show();
	
	
	
	
	return 0;
}
/*
Reference in C++
*/