#include<iostream>
#include<fstream>
 using namespace std;
 int main()
{
    //create an object of ifstream and associate a file with it
    ifstream myfile("data.txt");
    if(!myfile.is_open())
    {
        cout<<"Error in opening file.";
        system("pause");
        return 0;
    }
    //read a character from file
    char ch;
    myfile>>ch;
    cout<<"File's first character is :"<<ch;
    
    //read a line from file
    char str[100];
    myfile.getline(str,'\n');
    cout<<"\nFile's 1st line is :"<<str;
   myfile.close();
    return 0;

}