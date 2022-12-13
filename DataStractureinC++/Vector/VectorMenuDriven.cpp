/*
write a cpp program that will accepts the name, roll and marks of five
subjects of N students and print all records with total marks and division.

*/
#include<iostream>
#include<vector>
#include<iterator>
#include<string>
using namespace std;
class Student
{
    public:
    string name;
    int roll;
    int hin,eng,math,sci,sst;
    public:
    Student (string name="",int roll=0,int hin=0, int eng=0,int math=0,int sci=0, int sst=0)
    {
        this->name=name;
        this->roll=roll;
        this->hin=hin;
        this->eng=eng;
        this->math=math;
        this->sci=sci;
        this->sst=sst;
    }
    void setStudent(string name="",int roll=0,int hin=0, int eng=0,int math=0,int sci=0, int sst=0)
    {
        this->name=name;
        this->roll=roll;
        this->hin=hin;
        this->eng=eng;
        this->math=math;
        this->sci=sci;
        this->sst=sst;
    }
    void setFromKb()
    {
        fflush(stdin);
    
        cout<<"Enter students name:";
        getline(cin,name);
        cout<<"Enter Roll No:";
        cin>>roll;
        cout<<"Enter Hindi Marks:";
        cin>>hin;
        cout<<"Enter English marks:";
        cin>>eng;
        cout<<"Enter Mathematics Marks:";
        cin>>math;
        cout<<"Enter Science Marks:";
        cin>>sci;
        cout<<"Enter Socal Science Marks:";
        cin>>sst;

    }
    void show()
    {
        cout<<endl<<"Name= "<<name<<", Roll = "<<roll;
        cout<<endl<<endl<<"Marks Details:"<<endl<<endl;
        cout<<"Hindi = "<<hin<<endl<<"English = "<<eng<<endl<<"Mathematics ="<<math<<endl<<"Science = "<<sci<<endl<<"Socal Science ="<<sst;
    }
};
int main()
{
    vector<Student> students;
    int choice;
    string name;
    int roll;
    int hin,eng,math,sci,sst;
    char ch;
    int total=0;
    Student s1;
    do
    { 
        /*cout<<endl<<"1. Insert .\n2. View \n3. Exit  \n Enter your choice:";*/
        cout<<endl;
        cout<<"  Menu Driven"<<endl;
        cout<<"__________________";
        cout<<endl<<"1. Insert .\n2. View \n3. Exit"<<endl;
        cout<<"__________________"<<endl;
        cout<<" \n Enter your choice:";
        cin >> choice;
        switch(choice)
        {
            case 1:
            do{
                cout<<"You have to selected insert data into the database.\n";
                s1.setFromKb();
                students.push_back(s1);
                cout<<"Add more data in list ? (y|n): ";
                cin>>ch;
            }while(ch=='y'||ch=='Y');
            break;
            case 2:
            for(auto st:students)
            {
                //system("color 1f");
                
                st.show();
                cout<<endl<<"Ruselt:"<<endl;
                total=st.hin+st.eng+st.math+st.sci+st.sst;
                
                cout<<"Total Marks = "<<total<<endl<<"Division   ";
                
                if(st.hin>=30&&st.eng>=30&&st.math>=30&&st.sci>=30&&st.sst>=30)
                {
                    if(total>300)
                    cout<<"First";
                    else if(total>=225)
                    cout<<"Second";
                    else
                    cout<<" Sorry! Try again later."<<endl;
                    
                }

            }
            break;
           
            
            case 3:
            cout<<"Thank You :)";
            system("pause");
            exit(0);
            default:
            cout<<"Enter Valid Option.";
        }
    }while(true);
    return 0;
}

