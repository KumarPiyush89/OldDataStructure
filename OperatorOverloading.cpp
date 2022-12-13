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
	//overloading + fro addinf two fraction number
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
	
	//for subtraction FractionNumber-FractionNumber	
	FractionNumber operator-(const FractionNumber &ob2)
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
		ob3.num=a/this->dnum*this->num-a/ob2.dnum*ob2.num;
		return ob3;
	}
	
	//for multiplication FractionNumber*FractionNumber
	FractionNumber operator*(const FractionNumber &ob2)
	{
		FractionNumber ob3;
		ob3.num=this->num*ob2.num;
		ob3.dnum=this->dnum*ob2.dnum;
		//find hcf of ob3's num and dnum.
		int a,b;
		a=ob3.num;
		b=ob3.dnum;
		while(a!=b)
		{
			if(a>b)
			a-=b;
			else
			b-=a;
		}
		if(a!=1)
		{
			ob3.dnum=ob3.dnum/a;
			ob3.num=ob3.num/a;
		}
		return ob3;
	}
	
	//for division FractionNumber/FractionNumber
	FractionNumber operator/(const FractionNumber &ob2)
	{
		FractionNumber ob3;
		ob3.num=this->num*ob2.dnum;
		ob3.dnum=this->dnum*ob2.num;
		//find hcf of ob3's num and dnum.
		int a,b;
		a=ob3.num;
		b=ob3.dnum;
		while(a!=b)
		{
			if(a>b)
			a-=b;
			else
			b-=a;
		}
		if(a!=1)
		{
			ob3.dnum=ob3.dnum/a;
			ob3.num=ob3.num/a;
		}
		return ob3;
	}
			
	//overloading add For FractionNumber+int
	FractionNumber add(int op2)
	{
		FractionNumber ob2(op2);
		return add(ob2);
	}
	//overloading + for FractionNumber+int
	FractionNumber operator+(int ob2)
	{
		return add(ob2);
	}
	
	//Overloading + for int+FractionNumber
	/* It can't be performed using member function
	because, when operator function is called, always left operand of expression
	is invoking object and right operand is passed as argument to operator function.
	And int type is not an object so a method can't be called using int data
	
	C++ supports non member function so,we can solve this problem using non member function
	*/
			
};
//overloading + operator for (int+FractionNumber), using non member function
FractionNumber operator+(int x,FractionNumber& ob)
{
	return ob+x;
}

//overloading << for ostream<<FractionNumber
ostream& operator<<( ostream &out,FractionNumber& ob)
{
	out<<ob.getNum()<<"/"<<ob.getDnum();
	return out;
}


 
int main()
{
	/*FractionNumber ob1(5,2),ob2(7);
	cout<<endl;
	ob1.show("ob1");
	cout<<endl;
	ob2.show("ob2");
	ob2.setdNum(-2);
	cout<<endl;
	ob1.show("ob1");
	FractionNumber ob3=ob1.add(ob2);
	cout<<endl;
	ob1.show();
	cout<<"+";
	ob2.show();
	cout<<"=";
	ob3.show();
	cout<<endl;
	ob1.show();
	FractionNumber ob4(5,3),ob5(13,7),ob6;
	ob6=ob4+ob5;
	cout<<endl<<endl;
	ob4.show();
	cout<<"+";
	ob5.show();
	cout<<"=";
	ob6.show();
	
	ob1.set(4,2);
	cout<<endl;
	ob1.show("ob1");
	ob2.set(6,2);
	cout<<endl;
	ob2.show("ob2");
	ob3=ob1-ob2;
	cout<<endl;
	ob3.show("ob3");
	
	cout<<endl<<endl;
	ob1.set(4,2);
	cout<<endl;
	ob1.show("ob1");
	ob2.set(6,2);
	cout<<endl;
	ob2.show("ob2");
	ob3=ob1*ob2;
	cout<<endl;
	ob3.show("ob3");
	
	cout<<endl<<endl;
	ob1.set(4,2);
	cout<<endl;
	ob1.show("ob1");
	ob2.set(6,2);
	cout<<endl;
	ob2.show("ob2");
	ob3=ob1/ob2;
	cout<<endl;
	ob3.show("ob3");*/
	FractionNumber n1(22,7);
	cout<<"n1="<<n1<<".";
	FractionNumber n2;
	n2=n1+1;
	cout<<endl<<n1<<"+1="<<n2;
	
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


