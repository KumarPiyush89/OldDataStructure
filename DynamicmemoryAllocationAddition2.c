/*C program to add two numbers using dynamic memory allocation*/
#include<stdio.h>
#include<malloc.h>
int main()
{
	int *p1;
	//Allocate memory to store data
	p1=(int*)malloc(sizeof(int)*3);
	
	printf("Enter 1st number:");
	scanf("%d",p1);
	printf("enter 2nd value:");
	scanf("%d",p1+1);
	*(p1+2)=*p1+*(p1+1);
	//print result
	printf("%d+%d=%d",*p1,*(p1+1),*(p1+2));
	//release allocated memory
	free(p1);
	return 0;
}