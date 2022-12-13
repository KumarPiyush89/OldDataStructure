#include<iostream>
#include<cmath>
using namespace std;

class MyStack
{
    private:
     int *list;
     int tos;
     int capacity;
    public:
        MyStack(int capacity=10)
        {
            this->capacity=abs(capacity);
            if(this->capacity==0)
            this->capacity=10;

            list=new int[this->capacity];
            tos=0;
        }
        ~MyStack()
        {
            if(list!=NULL)
            {
                delete[] list;
                list=NULL;
            }
        }
        bool push(int data)
        {
            if(tos<capacity)
            {
                list[tos++]=data;
                return true;
            }

            //allocate memory
            int *list1=new int[capacity+5];
            if(list==NULL)
            {
                return false;
            }

            //copy current list data into new list
            for(int i=0;i<tos;i++)
            list1[i]=list[i];

            //increase capacity
            capacity+=5;

            //delete old list
            delete[] list;
            //now make list1 as list
            list=list1;

            //push data
            list[tos++]=data;
            return true;
        }

        bool pop(int &data)
        {
            if(tos==0)
            return false;

            data=list[--tos];
            return true;
        }
        bool pop()
        {
            if(tos==0)
            return false;
            --tos;
            return true;
        }
        bool pick(int &data)
        {
            if(tos==0)
            return false;

            data=list[tos-1];
            return true;
        }
        void peep()
        {
            if(tos==0)
            {
                cout<<"Stack is Empty!";
                return;
            }

            cout<<endl;
            for(int i=0;i<tos;i++)
            {
                cout<<list[i];
                if(i<tos-1)
                cout<<">";
            }
        }
        int getCapacity()
        {
            return capacity;
        }
        int getTOS()
        {
            return tos;
        }
};

class MyDoubleStack
{
    private:
     double *list;
     int tos;
     int capacity;
    public:
        MyDoubleStack(int capacity=10)
        {
            this->capacity=abs(capacity);
            if(this->capacity==0)
            this->capacity=10;

            list=new double[this->capacity];
            tos=0;
        }
        ~MyDoubleStack()
        {
            if(list!=NULL)
            {
                delete[] list;
                list=NULL;
            }
        }
        bool push(double data)
        {
            if(tos<capacity)
            {
                list[tos++]=data;
                return true;
            }

            //allocate memory
            double *list1=new double[capacity+5];
            if(list==NULL)
            {
                return false;
            }

            //copy current list data into new list
            for(int i=0;i<tos;i++)
            list1[i]=list[i];

            //increase capacity
            capacity+=5;

            //delete old list
            delete[] list;
            //now make list1 as list
            list=list1;

            //push data
            list[tos++]=data;
            return true;
        }

        bool pop(double &data)
        {
            if(tos==0)
            return false;

            data=list[--tos];
            return true;
        }
        bool pop()
        {
            if(tos==0)
            return false;
            --tos;
            return true;
        }
        bool pick(double &data)
        {
            if(tos==0)
            return false;

            data=list[tos-1];
            return true;
        }
        void peep()
        {
            if(tos==0)
            {
                cout<<"Stack is Empty!";
                return;
            }

            cout<<endl;
            for(int i=0;i<tos;i++)
            {
                cout<<list[i];
                if(i<tos-1)
                cout<<">";
            }
        }
        int getCapacity()
        {
            return capacity;
        }
        int getTOS()
        {
            return tos;
        }
};


int main()
{
    MyStack s1(5),s2;
    MyDoubleStack s3(6);
    cout<<endl<<"Capacity os stack1 is:"<<s1.getCapacity()<<" and capacity of stack s2 is:"<<s2.getCapacity();
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    s1.push(6);

    s2.push(1);
    s2.push(2);
    s2.push(3);


    cout<<endl<<"S1\n";
    cout<<"Capacity="<<s1.getCapacity();
    cout<<"\nTOS="<<s1.getTOS();
    cout<<"Value=";
    s1.peep();
    

    cout<<endl<<endl<<"S1\n";
    cout<<"Capacity="<<s2.getCapacity();
    cout<<"\nTOS="<<s2.getTOS();
    cout<<"Value=";
    s2.peep();


    s3.push(78.6);
    s3.push(10.6);
    s3.push(5);

    cout<<endl<<endl<<"Capacity of s3="<<s3.getCapacity()<<" and TOS="<<s3.getTOS();
    cout<<endl<<"Content=";
    s3.peep();

    return 0;
}