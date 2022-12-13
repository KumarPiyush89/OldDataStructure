/* string class*/
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str;
	cout<<"My length is"<<str.length();
	cout<<"\nMy capacity is:"<<str.capacity();
	str="Hello Mr.";
	cout<<"\nMy length is"<<str.length();
	cout<<"\nMy capacity is:"<<str.capacity();
	str="Mr.";
	cout<<"\nMy length is"<<str.length();
	cout<<"\nMy capacity is:"<<str.capacity();
	/*cout<<"Enter any string:";
	cin>>str;
	cout<<endl<<"you have enterd:"<<str<<", it has "<<str.length()<<" Characters.";
	*/
	cout<<endl<<"Enter any string:";
	
	getline(cin,str);
	
	cout<<endl<<"You have entered:"<<str<<" . It has "<<str.length()<<" Character";
	
	string str1;
	str1=str;
	cout<<endl<<"str="<<str<<", str1="<<str1;
	str.append(" xyz")	;
	cout<<endl<<"str="<<str<<", str1="<<str1;
	
	
	return 0;
}