#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> list;
    cout<<"Capacity of list="<<list.capacity()<<" and size of list is:"<<list.size();
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    cout<<"\n\nCapacity of list="<<list.capacity()<<" and size of list is:"<<list.size();
    list.push_back(40);
    list.push_back(50);
    cout<<"\n\nCapacity of list="<<list.capacity()<<" and size of list is:"<<list.size();
    list.shrink_to_fit();
    cout<<"\n\nCapacity of list="<<list.capacity()<<" and size of list is:"<<list.size();
    return 0;
}