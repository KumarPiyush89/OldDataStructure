/* Single Linked List's operations  Example*/
#include<stdio.h>
#include<malloc.h>
#include<process.h>
struct Data
{
	char name[30];
	char gender;
	int age;
};
struct Data inputData()
{
	struct Data data;
	printf("Enter name:");
	fflush(stdin);
	gets(data.name);
	printf("\nEnte gender(M/F):");
	fflush(stdin);
	scanf("%c",&data.gender);
	printf("\nEnter age:");
	scanf("%d",&data.age);
	return data;
}
void printData(struct Data data)
{
	printf("\n%30s %c %3d",data.name,data.gender,data.age);
}

//create node
struct Node
{
	struct Data data;
	struct Node* next;
};

int main()
{
	struct Node *start=NULL,*nnode=NULL,*lnode=NULL;
	int choice;
	int nodenumber,pos;
	do
	{
		system("cls");
		printf("\n\tMenu\n=======================================");
		printf("\n1. Create List");
		printf("\n2. Insert at Last");
		printf("\n3. Insert at First");
		printf("\n4. Insert at Specific Loction");
		printf("\n5. Display List");
		printf("\n6. Exit");
		printf("\n ente your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1://code for create list
			if(start==NULL)
			{
			
				nnode=(struct Node*)malloc(sizeof(struct Node));
				if(nnode==NULL)
				{
					printf("\nUnable to allocate memory");
					break;
				}
				//accept data
				nnode->data=inputData();
				nnode->next=NULL;
				//make it 1st node
				start=nnode;
				
				//ask for more nodes
				do
				{
					printf("\nWant more nodes(Yes:1,No:0):");
					scanf("%d",&choice);
					if(choice==1)
					{
						//create new node and keep ists address in previous new nodes address part
						nnode->next=(struct Node*)malloc(sizeof(struct Node));
						if(nnode->next==NULL)
						{
							printf("Unable to allocate memory for node");
							break;
						}
						nnode=nnode->next;
						//accept data in new node
						nnode->data=inputData();
						nnode->next=NULL;
					}
					else
					break;
					
				}while(1);
			}else
			{
				printf("\n List is already created!");
				
			}
				
			break;
			case 2://code for insert at last in list
			//1 creat new node
			nnode=(struct Node*)malloc(sizeof(struct Node));
			//2. Check node is created or not
			if(nnode==NULL)
			{
				printf("\nUnable To create new Node.\n");
				break;
			}
			//3: put data in data part and null in address part of new node
			nnode->data=inputData();
			nnode->next=NULL;
			//4. check if list is empty
			if(start==NULL)
			{
				//4.1: put address of new node in start
				start=nnode;
				nnode=NULL;
				printf("\n New node inserted successfully at the end of List.\n");
				break;
			}
			//step 5: find the address of last node
			lnode=start;
			while(lnode->next!=NULL)
			lnode=lnode->next;
			//step 6: put the address iof new node in address part of last node
			lnode->next=nnode;
			//step 7:
			nnode=NULL;
			printf("\nNew Node Inserted successfully at the end of list\n");
			
			break;
			case 3://code for insert at first
			nnode=(struct Node*)malloc(sizeof(struct Node));
			//check is node created?
			if(nnode==NULL)
			{
				printf("Error in creating node");
				break;
			}
			//put data in data part and put the address of 1st node of list in address part of new node.
			nnode->data=inputData();
			nnode->next=start;
			//put the address of new node in start.
			start=nnode;
			//put null in nnode
			nnode=NULL;
			break;
			case 4://Code for insert at specific location
			nnode=(struct Node*)malloc(sizeof(struct Node));
			//check node is created or not?
			if(nnode==NULL)
			{
				printf("Unable allocate a memory");
				break;
			}
			//accept position for insert
			printf("Enter postion for inserting in list:");
			scanf("%d",&pos);
			//put the address of 1st node in lnode
			lnode=start;
			nodenumber=1;
			while(nodenumber<pos-1&&lnode!=NULL)
			{
				lnode=lnode->next;
				//increase Node number by 1
				nodenumber++;
			}
			if(lnode!=NULL)
			{
				//accept data from user
				nnode->data=inputData();
				nnode->next=NULL;
				//shifting data
				nnode->next=lnode->next;
				lnode->next=nnode;
				lnode=NULL;
				printf("Data successfully Entered.");
				
			}
			else
			printf("Invalid postion");
			break;	
			case 5://code for display list
			if(start==NULL)
			{
				printf("\nList is Empty!");
				break;
			}
			else
			{
				lnode=start;
				while(lnode!=NULL)
				{
					//print the data
					printData(lnode->data);
					//move on next node
					lnode=lnode->next;
				}
				printf("\nEnd");
			}
			break;
			case 6:// exit from program
			printf("\nOK bye.\n");
			system("pause");
			exit(0);
			default://print invalid option message
			printf("\nSoeey you have selected invalid choice.");
		}
		printf("\n");
		system("pause");
	 } while(1);
}