#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int a,b;
	char ch;
	cout<<endl<<"Enter two numbers seperated by(-):";
	cin>>a>>ch>>b;
	cout<<endl<<"You have entered "<<a<<" and "<<b;
	cout <<endl<<"Subtracted value = "<<a-b;
	for(int i=1;i<=10;i++)
	{
		cout<<endl<<setfill((char)4)<<right<<setw(3)<<(a-b)<<"*"<<setw(3)<<i<<" = "<<setw(5)<<(a-b)*i;
	}
	
	return 0;
	
}