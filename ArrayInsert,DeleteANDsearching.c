/*
C program to insertion deletion and searching operation in Array
*/
#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<dos.h>
#define CAP 10
int main()
{
	int array[CAP],totalElement=0,found,frequency;
	int i,newData,choice,pos,d,j,se,yes,no;
do
{
    system("cls");
    printf("Menu\n========\n1.Insert at last\n2.Insert At first\n3.Display\n4.Insert at specific position\n5.Delete at last\n6.Delete at specific position\n7.delete multiple element\n8.Insert Multiply element\n9.Search Element is availabe in list or not.\n10.Total occurance of Search Element in list\n11.Total occurance of Search Element in list with position\n12.Exit\nEnter your choice:");
    scanf("%d",&choice);
    if(choice==1)
    {
        //code for insert at last
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
    	//code for deletion specific position element of list
    	
    	if(totalElement==0)
		{
			printf("List is Already Empty");
		}
		else
		{
			printf("Enter valid position:");
			scanf("%d",&pos);
			if(pos<1||pos>totalElement+1)
			{
				printf("Not a valid position for deletion in Array");
			}
			else
			{
				for(i=pos-1;i<totalElement;i++)
				array[i]=array[i+1];
				totalElement--;
				printf("\nElement is succesfully deleted to their position");
			}
		}
	}
	else if(choice==7)
	{
	 	//code for Multiply Element	Deleted at a time 
    	if(totalElement==0)
		{
			printf("List is Already Empty");
		}
		else
		{
			printf("Enter valid position:");
			scanf("%d",&pos);
			if(pos<1||pos>totalElement+1)
			{
				printf("Not a valid position for deletion in Array");
			}
			else
			{   
				printf("Enter number How many you want to Deleted Element");
				scanf("%d",&d);
				for(i=pos-1;i<totalElement;i++)
				array[i]=array[i+d];
				totalElement=totalElement-d;
				printf("\nElement is succesfully deleted to their position");
			}
		}
	}
	else if(choice==8)
	{
		//code for multiply Element insert at a time
	 	if(totalElement==CAP)
		{
			printf("List is full");
		}
		else
		{
			printf("Enter valid position:");
			scanf("%d",&pos);
			if(pos<1||pos>totalElement+1)
			{
				printf("Not a valid position for insertion in Array");
			}
			else
			{
				printf("Enter number how many you want to insert Element:");
				scanf("%d",&d);
				for(j=d;j>0;j--)
				/*j=d;
				
				do*/
				{
					printf("Enter a number you want to Insert:");
					scanf("%d",&newData);
					for(i=totalElement;i>=pos-1;i--)
					array[i+1]=array[i];
					array[pos-1]=newData;
					totalElement++;
					pos++;
					//j--;
				}//while(j>0);
				printf("\nElement succesfully added to their position:");
			}
		}
	
	}
	else if(choice==9)
    {
    	//code for find an element is available in list or not.
    	
    	printf("Enter search Element:");
    	scanf("%d",&se);
    	
    	found=no;
    	
    	for(i=0;i<totalElement;i++)
    	{
    		if(se==array[i])
    		{
    			found=yes;
    			i=totalElement;
			}
		}
		if(found==yes)
		printf("%d found in list",se);
		else
		printf("%d not found in list",se);
		
	}
	else if(choice==10)
	{
		//code for find the total occurance of SE in list.
		
		printf("Enter Search Element");
		scanf("%d",&se);
		
		frequency=0;
		
		for(i=0;i<totalElement;i++)
		{
			if(se==array[i])
			frequency++;
		}
		
		if(frequency==0)
		printf("%d is not available in list",se);
		else
		printf("%d is available in list %d times.",se,frequency);
	}
	else if(choice==11)
	{
		//code for find the total occurance of SE in list with position.
		printf("Enter Search Element");
		scanf("%d",&se);
		
		frequency=0;
		
		for(i=0;i<totalElement;i++)
		{
			if(se==array[i])
			{
				frequency++;
				printf("\n%d Times at %d position",frequency,i+1);
			}
		}
		
		if(frequency==0)
		printf("\n%d is not available in list",se);
		else
		printf("\n%d is available in list %d times with positions",se,frequency);
	}
	else if(choice==12)
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