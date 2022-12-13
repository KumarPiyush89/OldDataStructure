/* Write a C program in which accept any integer number and print all digit in ascending order as:
Number 		Output
3456 -		3456
18627-		12678
965271-		125679

Soln:
1: accept number
2: put numbers all digits in an array
3: sort array
4: display array
*/
#include<stdio.h>
#include<malloc.h>

int main()
{
	int n,*digits,i,j,td;
	char sn[100];
	printf("Enter any positive number:");
	scanf("%d",&n);
	//count total number of digit in entered number
	i=n;
	td=0;
	while(i)
	{
		td++;
		i/=10;
	}
	//create array of total digit size to store all digits
	digits=(int*)malloc(sizeof(int)*td);
	if(!digits)/*if(digits==NULL)*/
	{
		printf("\nSorry! Memory Allocation Failure.");
		return 0;
	}
	
	//extract all digit from number and store in array
	i=n;
	j=0;
	while(i)
	{
		digits[j++]=i%10;
		i/=10;
	}
	//now sort the digits array
	//linear sort
	for(i=0;i<td-1;i++)
	{
		for(j=i+1;j<td;j++)
		{
			if(digits[i]>digits[j])
			{
				digits[i]^=digits[j];
				digits[j]^=digits[i];
				digits[i]^=digits[j];
			}
		}
	}
	//print the sorted array
	printf("\n%d -",n);
	for(i=0;i<td;i++)printf("%d",digits[i]);
	//delete array
	free(digits);
	return 0;
}