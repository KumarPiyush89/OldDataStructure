/*C program to store n numbers in Linked List form*/
#include<stdio.h>
#include<malloc.h>
struct Node
{
	int data;
	struct Node *next;
};
int main()
{
	struct Node *start,*nnode;
	char choice;
	//create 1st node
	nnode=(struct Node*)malloc(sizeof(struct Node));
	if(nnode==NULL)
	{
		printf("\nUnable to allocate memory!");
		return 0;
	}
	printf("Enter number:");
	scanf("%d",&nnode->data);
	nnode->next=NULL;
	
	//make it 1st node
	start=nnode;
	do
	{
		printf("\nWant to store more data(Y/N):");
		fflush(stdin);
		scanf("%c",&choice);
		if(!(choice=='y'||choice=='Y'))break;
		
		//allocate memory for new node
		nnode->next=(struct Node*)malloc(sizeof(struct Node));
		if(nnode->next==NULL)
		{
			printf("Unable to allocate memory!");
			break;
		}
		//move on new node
		nnode=nnode->next;
		//put data in data part of nenw node
		printf("Enter number:");
		scanf("%d",&nnode->data);
		//put NULL in address part of new node
		nnode->next=NULL;
		
		
	}while(1);
	printf("\n All eneterd numbers are:");
	//traverse the list
	nnode=start;
	while(nnode!=NULL)
	{
		printf("%d",nnode->data);
		if(nnode->next==NULL);
		else if(nnode->next->next==NULL)
		printf(" and ");
		else
		printf(", ");
		
		//move on next node
		nnode=nnode->next;
	}
	printf("\nThank You");
	return 0;
}
