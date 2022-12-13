#include<stdio.h>
//Function to insert an item in integer queue
int insertInQueue(int *queue,int capacity,int *rear,int data)
{
    if(*rear==capacity-1)
    return 0;

    (*rear)++;
    queue[*rear]=data;
    return 1;
}

int  deleteFromQueue(int *queue,int *front,int *rear,int *data)
{
    if(*rear==-1)return 0;
    (*front)++;
    *data=queue[*front];
    if(*front==*rear)*front=*rear=-1;
    return 1;
}
void displayQueue(int *queue,int front,int rear,int cap)
{
    int i;
   
    printf("\n");
    for(i=0;i<=front;i++)printf("X<");
    for(front++;front<=rear;front++)
    {
        printf("%d",queue[front]);//12<34<56<78
        if(front!=rear)
        printf("<");

    }
    for(i=rear+1;i<cap;i++)
    {
        if(i<cap-1)
        printf("<");
        printf("X");
    }
}