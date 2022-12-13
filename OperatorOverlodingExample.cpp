/* Operator Overloading*/
#include<iostream>
using namespace std;
class FractionNumber
{
	private:
		int num;
		int dnum;
	public:
		FractionNumber(int num=0,int dnum=1)
		{
			this->num=num;
			if(dnum==0)dnum=1;
			this->dnum=dnum;
			if(this->dnum<0)
			{
				this->num*=-1;
				this->dnum*=-1;
			}
		}
	void set(int num,int dnum=1)
	{
		this->num=num;
			if(dnum==0)dnum=1;
			this->dnum=dnum;
			if(this->dnum<0)
			{
				this->num*=-1;
				this->dnum*=-1;
			}
	}
	void setNum(int num)
	{
		this->num=num;
	}
	void setdNum(int dnum)
	{
		if(dnum==0)dnum=1;
		this->dnum=dnum;
		if(this->dnum<0)
		{
			this->num*=-1;
			this->dnum*=-1;
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
	void show(char *name)
	{
		cout<<name<<"=";
		show();
	}
	
	FractionNumber add(const FractionNumber &ob2)
	{
		FractionNumber ob3;
		//find the LCM of both denum
		int a,b;
		a=this->dnum;
		b=ob2.dnum;
		while(a!=b)
		{
			if(a<b)
			a+=this->dnum;
			else
			b+=ob2.dnum;
		}
		ob3.dnum=a;
		ob3.num=a/this->dnum*this->num+a/ob2.dnum*ob2.num;
		return ob3;
	}
	//overloading + for adding two fraction number
		FractionNumber operator+(const FractionNumber &ob2)
	{
		FractionNumber ob3;
		//find the LCM of both denum
		int a,b;
		a=this->dnum;
		b=ob2.dnum;
		while(a!=b)
		{
			if(a<b)
			a+=this->dnum;
			else
			b+=ob2.dnum;
		}
		ob3.dnum=a;
		ob3.num=a/this->dnum*this->num+a/ob2.dnum*ob2.num;
		return ob3;
	}	
		
};

int main()
{
	FractionNumber ob1(5,2),ob2(7);
	cout<<endl;
	ob1.show("ob1");
	cout<<endl;
	ob2.show("ob2");
	ob2.setdNum(-2);
	cout<<endl;
	ob1.show("ob1");
	cout<<endl;
	ob2.show("ob2");
	FractionNumber ob3=ob1.add(ob2);
	cout<<endl;
	ob1.show();
	cout<<"+";
	ob2.show();
	cout<<"=";
	ob3.show();
	FractionNumber ob4(5,3),ob5(13,7),ob6;
	ob6=ob4+ob5;
	cout<<endl<<endl;
	ob4.show();
	cout<<"+";
	ob5.show();
	cout<<"=";
	ob6.show();
	
	return 0;
}

/*
Syntax Of Operator Function

retunType operator#(argument)
{
//function defination
}
at the place of # ,overloading operator symbol should be written
ex:
for operloading + function name will be:
return type operator+(argument)
{
}

for overloadin * function name will be:
returnType operator*(argument)
{
}

*/