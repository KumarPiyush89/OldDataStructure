/*
Function Oveloading (Polymorphism-> One Interface Multiple Method)
------------------------------------------------------------------------
The process of defining multiple function /method with same name.
 When overloading function its name must be same but argument of all version must be differ in type or size or both.
 there is no impact of return type in operloading function.*/
 #include<iostream>
 using namespace std;
 int largest(int a,int b,int c)
 {
 	if(a>b&&a>c)
 	return a;
 	else if(b>c)
 	return b;
 	else
 	return c;
 }
 int largest(int a,int b,int c,int d)
 {
 	
 if(a>b&&a>c&&a>d)
 return a;
 else if(b>c&&b>d)
 return b;
 else if(c>d)
 return c;
 else
 return d;
}
int largest(int a,int b,int c,int d,int e)
{
	if(a>b&&a>c&&a>d&&a>e)
	return a;
	else if(b>c&&b>d&&b>e)
	return b;
	else if(c>d&&c>e)
	return c;
	else if(d>e)
	return d;
	else
	return e;
}

int main()
{
	cout<<"Largest of 3,4,7 is:"<<largest(3,4,7);
	cout<<endl<<"largest of 7,34,5,6 is:"<<largest(7,34,5,6);
	cout<<endl<<"largest of 65,25,78,63,55: "<<largest(65,25,78,63,55);
return 0;
}