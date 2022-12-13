/* write a  C program that will ask an integer number from user and accept differnt 
given number integer number and print the all entered number and sum of all entered numbers*/
#include<stdio.h>
#include<math.h>
#include<malloc.h>
int main()
{
	int totalNumbersToBeAccepted,sum,i,*numbers=NULL;
	printf("How many numbers you want to enter:");
	scanf("%d",&totalNumbersToBeAccepted);
	totalNumbersToBeAccepted=abs(totalNumbersToBeAccepted);
	//Allocate memory for array
	numbers=(int*)malloc(sizeof(int)*totalNumbersToBeAccepted);
	if(numbers==NULL)
	{
		printf("\nSoory! no memory available.");
		return 0;
	}
	//printf("\n%u",numbers);
	
	for(i=0;i<totalNumbersToBeAccepted;i++)
	{
		printf("Enter number %d:",i+1);
		scanf("%d",&numbers[i]);
	}
	//find the sum of all entered numbers
	sum=0;
	for(i=0;i<totalNumbersToBeAccepted;i++)sum+=numbers[i];
	//print all entered numbers
	printf("\nAll entered Numbers are:");
	for(i=0;i<totalNumbersToBeAccepted;i++)
	{
		printf("%d",numbers[i]);
		if(i<totalNumbersToBeAccepted-2)
		printf(", ");
		else if(i==totalNumbersToBeAccepted-2)
		printf(" and ");
	}
	printf("\nSum of all entered number(s) =%d ",sum);
	//release allocated memory
	free(numbers);
	return 0;
	
}