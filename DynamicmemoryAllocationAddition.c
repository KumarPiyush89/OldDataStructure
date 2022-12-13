/*C program to add two numbers using dynamic memory allocation*/
#include<stdio.h>
#include<malloc.h>
int main()
{
	int *p1,*p2,*p3;
	//Allocate memory to store data
	p1=(int*)malloc(sizeof(int));
	p2=(int*)malloc(sizeof(int));
	p3=(int*)malloc(sizeof(int));
	printf("Enter 1st number:");
	scanf("%d",p1);
	printf("enter 2nd value:");
	scanf("%d",p2);
	*p3=*p1+*p2;
	//print result
	printf("%d+%d=%d",*p1,*p2,*p3);
	//release allocated memory
	free(p1);
	free(p2);
	free(p3);
	return 0;
}