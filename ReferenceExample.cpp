/*
Reference
*/
#include<iostream>
using namespace std;
int main()
{
	int i=10;
	int &j=i;
	//now j is the alias of i
	cout<<"i="<<i;
	cout<<endl<<"j="<<j;
	i=15;
	cout<<"\n\ni="<<i;
	cout<<endl<<"j="<<j;
	
	j=20;
	cout<<endl<<endl<<"i="<<i;
	cout<<endl<<"j="<<j;
	
	//we can create any number of synonym of a variable
	int &x=i;//here x is also a synonym of variable i
	int &y=x;//here y is also a synonym of variable i
	
	x=100;
	cout<<endl<<endl<<"i="<<i;
	cout<<endl<<"j="<<j;
	cout<<endl<<"x="<<x;
	cout<<endl<<"y="<<y;
	/* Reference is only synonym, it is not a variable
	Proof: Every variable has unique address.
	but reference has not its own address. If we get address from reference then
	it will give the address of variable whose reference it is.
	*/
	cout<<endl<<endl<<"Address of i="<<&i;
	cout<<endl<<"Address of j="<<&j;
	cout<<endl<<"Address of x="<<&x;
	cout<<endl<<"address of y="<<&y;
	
	return 0;
}