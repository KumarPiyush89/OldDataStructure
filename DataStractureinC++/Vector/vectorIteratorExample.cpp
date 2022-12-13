#include<iostream>
#include<vector>
#include<iterator>
#include<string>
using namespace std;
int main()
{
    vector<string> list;
    list.push_back("Abhishek");
    list.push_back("Sudhanshu");
    list.push_back("Shubham");
    list.push_back("Ankit");
    cout<<"All names are: ";
    for(int i=0;i<list.size();i++)
    cout<<list[i];
    //accessing vector all element using iterator.
    vector<string>::iterator ptr;
    for(ptr=list.begin();ptr<list.end();ptr++)
    cout<<endl<<*ptr;
    return 0;
}