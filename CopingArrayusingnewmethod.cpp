#include<iostream>
#include"ClassOfArray2.cpp"
using namespace std;
int main()
{
	int arr[5]={34,78,23,34,67};
	IntArray arrOb(arr,5);
	arrOb.print();
	IntArray arrOb2;
	cout<<endl<<"value of arrOb2 = ";
	arrOb2.print();
	//copy arr in arrOb2
	arrOb2.copy(arr,5);
	cout<<endl<<" After copy value of arrOb2 = ";
	arrOb2.print();
	//again create an empty object
	IntArray arrOb3;
	cout<<endl<<"value of arrOb3 = ";
	arrOb3.print();
	// copy arrOb2 in arrOb3;
	arrOb3=arrOb2;
	cout<<endl<<"After copy value of arrOb3 = ";
	arrOb3.print();
	arrOb2.put(0,10);
	cout<<endl<<"After copy value of arrOb3 = ";
	arrOb3.print();
	cout<<endl<<"After copy value of arrOb2 = ";
	arrOb2.print();
	return 0;
}