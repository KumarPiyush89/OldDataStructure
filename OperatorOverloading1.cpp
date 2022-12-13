/* Operator Overloading*/
#include<iostream>
#include<cmath>
#include<cstring>
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
		FractionNumber(double op2)
		{
			char numberString[20]="";
			int found=0,digitsAfterDecimal=-1,i;
			//copy the value of double in string variable.
			sprintf(numberString,"%lf",op2);
			//cout<<endl<<numberString;
			//count the digits after decimal.
			for(i=0;numberString[i];i++)
			{
				if(found||numberString[i]=='.')
				{
					found=1;
					digitsAfterDecimal++;
				}
			}
			int dnum=1;
			for(i=1;i<=digitsAfterDecimal;i++)
			dnum*=10;
			
			this->num=(int)(op2*dnum);
			this->dnum=dnum;
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
		
		//find hcf of ob3's num and dnum.
		a=abs(ob3.num);
		b=abs(ob3.dnum);
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
	//overloading + for adding two fraction number
		FractionNumber operator+(const FractionNumber &ob2)
	{
				return add(ob2);
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
	//overloading add For FractionNumber+Double
	FractionNumber add(double op2)
	{
		FractionNumber ob2(op2);
		return add(ob2);
	}
	//overloading + for FractionNumber+int
	FractionNumber operator+(int ob2)
	{
		return add(ob2);
	}
	//overloading add For FractionNumber+float
	FractionNumber operator+(double op2)
	{
		return add(op2);
	}
	
	//Overloading + for int+FractionNumber
	/* It can't be performed using member function
	because, when operator function is called, always left operand of expression
	is invoking object and right operand is passed as argument to operator function.
	And int type is not an object so a method can't be called using int data
	
	C++ supports non member function so,we can solve this problem using non member function
	*/
	
	
	/*
	29-06-2022
	===========================
	Overloading Unary Operator
	-------------------------------------
	We can also overload unary operator
	------------------------------------
	Note: In binary operation there is no changes in operand but unary operator always changes its operand
	Overloading pre-increment operator
	
	Unary Operator function always returns invoking object reference.
	*/
	FractionNumber& operator++()
	{
		//Add 1 in invoking object
		num+=dnum;
		//return the reference of invoking object
		return *this;
	}
	/* overloading post increment operator
	post increment is also a unary operator, but to identify post increment version function takes a dummy int argument
	*/
	FractionNumber operator++(int)
	{
		FractionNumber ob;
		//copy the invoking object in ob
		ob=*this;
		//aad 1 in invoking object
		num+=dnum;
		//return copied value (old value)
		return ob;
	}
	// overloading ~ as reciprocal
	FractionNumber operator~()
	{
		FractionNumber ob;
		if(num!=0)
		{
			ob.num=this->dnum;
			ob.dnum=this->num;
			return ob;
		}
		else
		return *this;
	}
	
	/*Overloading Relational Operator
	=================================
	Relational operator function will return bool value
	*/
	bool operator<(FractionNumber ob2)
	{
		FractionNumber ob1=*this;
		//make ob1 and ob2 like fractions
		ob1.num*=ob2.dnum;
		//ob1.dnum*=ob2.dnum;
		
		ob2.num*=dnum;
		//ob2.dnum*=dnum;
		
		if(ob1.num<ob2.num)
		return true;
		else
		return false;
		
	}
	
	FractionNumber& operator--()
	{
		//sub 1 in invoking object
		num-=dnum;
		//return the reference of invoking object
		return *this;
	}
	
	FractionNumber operator--(int)
	{
		FractionNumber ob;
		//copy the invoking object in ob
		ob=*this;
		//aad 1 in invoking object
		num-=dnum;
		//return copied value (old value)
		return ob;
	}
	
	//next topic friend function
				
};
//overloading + operator for (int+FractionNumber), using non member function
FractionNumber operator+(int x,FractionNumber& ob)
{
	return ob+x;
}
FractionNumber operator+(double f,FractionNumber& ob)
{
	return ob+f;
}

//overloading << for ostream<<FractionNumber
ostream& operator<<( ostream &out,FractionNumber& ob)
{
	out<<ob.getNum()<<"/"<<ob.getDnum();
	return out;
}
//overloading >> for istream>>FractionNumber
void operator>>(istream &in,FractionNumber& ob)
{
	int n,d;
	cout<<"Enter value of Numerator: ";
	in>>n;
	cout<<"Enter value of Denominator: ";
	in>>d;
	ob.set(n,d);
}
	

 
int main()
{
	FractionNumber ob1(5,2),ob2(7);
	cout<<endl<<"ob1= "<<ob1;
	cout<<endl<<"ob2= "<<ob2;
	
	ob2.setdNum(-2);
	cout<<endl<<"ob2= "<<ob2;

	FractionNumber ob3=ob1.add(ob2);
	cout<<endl<<"ob3= "<<ob1<<"+"<<ob2<<"= "<<ob3;

	FractionNumber ob4(5,3),ob5(13,7),ob6;
	ob6=ob4+ob5;
	cout<<endl<<"ob6="<<ob4<<" + "<<ob5<<"= "<<ob6<<endl;
	
	ob1.set(4,2);
	cout<<endl<<"ob1= "<<ob1;
	ob2.set(6,2);
	cout<<endl<<"ob2= "<<ob2;
	ob3=ob1-ob2;
	cout<<endl<<"ob3= "<<ob1<<" - "<<ob2<<" = "<<ob3;

	ob1.set(4,2);
	cout<<endl<<endl<<"ob1= "<<ob1;
	ob2.set(6,2);
	cout<<endl<<"ob2= "<<ob2;
	ob3=ob1*ob2;
		cout<<endl<<"ob3= "<<ob1<<" * "<<ob2<<" = "<<ob3;
	
	ob1.set(4,2);
	cout<<endl<<endl<<"ob1= "<<ob1;
	ob2.set(6,2);
	cout<<endl<<"ob2= "<<ob2;
	ob3=ob1/ob2;
		cout<<endl<<"ob3= "<<ob1<<" / "<<ob2<<" = "<<ob3;

	FractionNumber n1(22,7);
	cout<<endl<<endl<<"n1="<<n1<<".";
	FractionNumber n2;
	n2=n1+1;
	cout<<endl<<n1<<"+1="<<n2<<endl<<endl;
	
	//cin>>ob6;
	ob6.set(20,5);
	cout<<endl<<"ob6= "<<ob6;
	//float f=0;
	//cout<<endl<<"Enter value of float: ";
	//cin>>f;
	cout<<endl<<"ob6= "<<ob6;
	ob6=ob6+0.5;
	
	cout<<" + "<<0.5<<" = "<<ob6;
	
	FractionNumber ob7(23,18);
	cout<<"\nob7="<<ob7;
	
	FractionNumber ob8;
	ob8=++ob7;
	cout<<"\n\nob7="<<ob7<<"\nob8="<<ob8;
	
	FractionNumber ob9;
	ob9=ob7++;
	cout<<"\n\nob7="<<ob7<<"\nob9="<<ob9;
	
	FractionNumber ob10(15,20);
	cout<<"\nob10="<<ob10;
	
	FractionNumber ob11;
	ob11=--ob10;
	cout<<"\n\nob10="<<ob10<<"\nob11="<<ob11;
	
	FractionNumber ob12;
	ob12=ob10--;
	cout<<"\n\nob10="<<ob10<<"\nob12="<<ob12;
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


