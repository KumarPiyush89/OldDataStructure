/*
C program to demonstrate the insertion operation in Array
*/
#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<dos.h>
#define CAP 10
int main()
{
	int array[CAP],totalElement=0;
	int i,newData,choice,pos;
do
{
    system("cls");
    printf("Menu\n========\n1.Insert at last\n2.Insert At first\n3.Display\n4.Insert at specific position\n5.Delete at last\n6.Exit\nEnter your choice:");
    scanf("%d",&choice);
    if(choice==1)
    {
        //code for inser at last
        if(totalElement==CAP)
        {
            printf("\nSorry!List is full.");

        }
        else
        {
            printf("Enter number you Want to insert:");
            scanf("%d",&newData);
            array[totalElement]=newData;
            totalElement++;
            printf("\n%d is inserted successfully at the end of list",newData);
        }
    }
    else if(choice==2)
    {
        //code for inser at first
        if(totalElement==CAP)
        {
            printf("\nSorry!List is full.");
        }
        else
        {
          printf("Enter number you Want to insert:");
            scanf("%d",&newData);
            //insert newData at first
            //empty the first element
            printf("\nPerforming Insertion...");
            for(i=totalElement-1;i>=0;i--)array[i+1]=array[i];
            array[0]=newData;
            totalElement++;
            printf("\n%d is inserted successfully at first in list",newData);   
        }
    }
    else if(choice==3)
    {
        //code for display array content
        if(totalElement==0)
        printf("\nList is Empty!");
        else
        {
            printf("\nList data:\n");
            for(i=0;i<totalElement;i++)
            {
                printf("%d",array[i]);
                //print seperator
                if(i<totalElement-1)
                printf(",");
            }
            printf("\nTotal Data=%d, Remaining Space=%d",totalElement,CAP-totalElement);

        }
    }
    else if(choice==4)
    {
    	//code for insertion at specific position
    	if(totalElement==CAP)
		{
			printf("\nList is full");
		}
		else
		{
			printf("Enter valid position:");
			scanf("%d",&pos);
			if(pos<1)
			{
				printf("\nNot a valid position for insertion in Array");
			}
			else
			{
				//if(pos>totalElement+1)
				//pos=totalElement+1;
				pos=pos>totalElement+1?totalElement+1:pos;
				printf("Enter a number you want to Insert:");
				scanf("%d",&newData);
				for(i=totalElement;i>=pos-1;i--)
				array[i+1]=array[i];
				array[pos-1]=newData;
				totalElement++;
				printf("\n%d is succesfully added to %d position",newData,pos);
			}
		}
	}
	else if(choice==5)
    {
    	//code for deleted of last Element of an list.
    	
		if(totalElement==0)
      	{
    		printf("\nList is Already Empty!");
	  	}
	  	else
	  	{
	  		totalElement--;
	  		printf("\nLast Element Deleted succesfully");
	  	}
    }
    else if(choice==6)
    {
    	//code for exit from code
        exit(0);
	}
	else
    {
        //code for invalid option
        printf("\nSorry! you have entered invalid option");
    }
    getch();
} while (1);

}