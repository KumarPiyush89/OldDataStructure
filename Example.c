#include"QueueOperations.c"
#include<process.h>
#define QCAP 10
int main()
{
    int q[QCAP],front=-1,rear=-1;
    int choice,data;
    do
    {
        system("cls");
       printf("\n\t\tQqeue Operation Menu\n1.Insert New\n2.Delete\n3.Display Queue\n4.Exit\nEnter Choice:");
       scanf("%d",&choice);
       switch(choice)
       {
           case 1:
           printf("Enter data to insert:");
           scanf("%d",&data);
           if(insertInQueue(q,QCAP,&rear,data)==1)
           printf("\n%d is inserted successfully in Queue",data);
           else
           printf("Insertion failure! Queue is FULL");
           break;
           case 2:
           if(deleteFromQueue(q,&front,&rear,&data)==1)
            printf("%d is deleted successfully from queue",data);
            else
            printf("Deletion Failure! List Is empty.");
           break;
           case 3:
            displayQueue(q,front,rear,QCAP);
           break;
           case 4:
           exit(0);
           case 5:
           printf("\nPlease enter valid option");
       }
       printf("\n");
       system("pause");
    } while (1);
    
}