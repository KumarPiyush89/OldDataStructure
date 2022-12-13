/* c program to insertion new value at specific position in array*/

#include<stdio.h>
#include<process.h>
#define CAP 10

int main()
{
	int array[CAP],totalElement=0;
	int i,newData,pos;
	
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
			printf("Enter a number you want to Insert");
			scanf("%d",&newData);
			for(i=totalElement;i>=pos-1;i--)
			array[i+1]=array[i];
			array[pos-1]=newData;
			totalElement++;
			printf("\n%d Number succesfully added to their position",newData);
		}
	}
	
	return 0;
	
}