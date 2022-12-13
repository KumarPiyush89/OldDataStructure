#include<iostream>
#include<vector>
#include<iterator>
using namespace std;
int main()
{
    vector<string> list;
    list.push_back("Apple"); 
    list.push_back("Mango"); 
    list.push_back("Banana"); 
    list.push_back("Papaya"); 
    list.push_back("Grapes"); 
    //traversal
    vector<string>::iterator ptr;
    for(ptr=list.begin();ptr<list.end();ptr++)
    cout<<endl<<*ptr;

    cout<<endl<<endl;
    for(vector<string>::iterator ptr2=list.begin();ptr2<list.end();ptr2++)
    cout<<endl<<*ptr2;

    cout<<endl<<endl;
    for(auto ptr3=list.begin();ptr3<list.end();ptr3++)
    cout<<endl<<*ptr3;

    cout<<endl<<endl;
    for(auto ptr4:list)
    cout<<endl<<ptr4;

    
    return 0;
}