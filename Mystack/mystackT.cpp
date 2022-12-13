#include<iostream>
#include<cmath>
using namespace std;

template <class T>
class MyStack
{
    private:
     T *list;
     int tos;
     int capacity;
    public:
        MyStack(int capacity=10)
        {
            this->capacity=abs(capacity);
            if(this->capacity==0)
            this->capacity=10;

            list=new T[this->capacity];
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
        bool push(T data)
        {
            if(tos<capacity)
            {
                list[tos++]=data;
                return true;
            }

            //allocate memory
            T *list1=new T[capacity+5];
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

        bool pop(T &data)
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
        bool pick(T &data)
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
    //creating object of template class
    MyStack<int> is1;
    MyStack<double> ds1;
    MyStack<char> cs1;
    MyStack<float> fs1;

    is1.push(10);
    is1.push(20);

    ds1.push(56.6);
    ds1.push(89.9);

    cs1.push('A');
    cs1.push('B');
    cs1.push('C');

    fs1.push(5.9f);
    fs1.push(98.96f);
    fs1.push(4.8f);

    cout<<endl<<"is1 content=";
    is1.peep();

    cout<<endl<<"ds1 content=";
    ds1.peep();

    cout<<endl<<endl<<"cs1 content=";
    cs1.peep();

    cout<<endl<<endl<<"fs1 content=";
    fs1.peep();

    return 0;



    return 0;
}