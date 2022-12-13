#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;
int main()
{
    ifstream file("data.txt");
    istringstream mstring("Piyush kumar is a good boy");
    if(!file.is_open())
    {
        cout<<"Error in opening file.";
        return 0;
    }
    cout<<"Enter a character:";
    char ch1,ch2;
    cin>>ch1;
    char ch;
    file>>ch;
    mstring>>ch2;
    cout<<"Character from File="<<ch;
    cout<<endl<<"Character from user="<<ch1;
    cout<<endl<<"Character from string="<<ch2;

    cin>>ch1;
    file>>ch;
    mstring>>ch2;
    cout<<"\n\nCharacter from File="<<ch;
    cout<<endl<<"Character from user="<<ch1;
    cout<<endl<<"Character from string="<<ch2;

    cin.get(ch1);
    file.get(ch);
    mstring.get(ch2);
    cout<<"\n\nCharacter from File="<<ch;
    cout<<endl<<"Character from user="<<ch1;
    cout<<endl<<"Character from string="<<ch2;

    cout<<endl<<endl<<"File get pointer position="<<file.tellg();
    cout<<endl<<"keyboard stream get pointer position="<<cin.tellg();
    cout<<endl<<"string stream get pointer position="<<mstring.tellg();

    //seek  get pointer
    file.seekg(1,file.cur);
    cin.seekg(1,cin.cur);
    mstring.seekg(1,mstring.cur);
    cout<<endl<<endl<<"File get pointer position="<<file.tellg();
    cout<<endl<<"keyboard stream get pointer position="<<cin.tellg();
    cout<<endl<<"string stream get pointer position="<<mstring.tellg();

    cin.get(ch1);
    file.get(ch);
    mstring.get(ch2);
    cout<<"\n\nCharacter from File="<<ch;
    cout<<endl<<"Character from user="<<ch1;
    cout<<endl<<"Character from string="<<ch2;





    return 0;
    


}