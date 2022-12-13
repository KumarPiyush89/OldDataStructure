/* c program to deletiton at specific position in array*/

#include<stdio.h>
#include<process.h>
#define CAP 10

int main()
{
	int array[CAP],totalElement=0;
	int i,newData,pos;
	
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
	
	return 0;
	
}