#include<iostream>
using namespace std;
//declare a class for fraction value
class FractionNumber
{
public:
int num;
int dnum;
};

int main()
{
//create an object of Fraction Number
FractionNumber x;
//put values in members of object x
x.num=34;
x.dnum=80;

//print the value of x
cout<<x.num<<"/"<<x.dnum;
return 0;

}
