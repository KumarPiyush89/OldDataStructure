/* Single Linked List's operations  Example*/
#include<stdio.h>
#include<malloc.h>
#include<process.h>
#define NCFMESSAGE "\nUnable To Create New Node\n"
#define NNISMESSAGE "\nNew Node Inserted Successfully"
#define LNDMESSAGE "\nLast Node Delete Successfully"
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
	int choice,pos,nodeNo;
	do
	{
		system("cls");
		printf("\n\tMenu\n=======================================");
		printf("\n1. Create List");
		printf("\n2. Insert at Last");
		printf("\n3. Insert at specific Location");
		printf("\n4. Delete at last");
		printf("\n5. Delete at first");
		printf("\n6. Display List");
		printf("\n7. Exit");
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
					printf(NCFMESSAGE);
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
							printf(NCFMESSAGE);
							break;
						}
						nnode=nnode->next;
						//accept data in new node
						nnode->data=inputData();
						nnode->next=NULL;
						printf(NNISMESSAGE);
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
				printf(NCFMESSAGE);
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
				printf("%s at the end of List.\n",NNISMESSAGE);
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
			printf("%s at the end of list\n",NNISMESSAGE);
			
			break;
			case 3://Insert at Specific Location
				//1. Create new node
				nnode=(struct Node*) malloc(sizeof(struct Node));
				if(!nnode)
				{
					printf(NCFMESSAGE);
					break;					
				}
				//put data in data part and NULL in address part of new node
				nnode->data=inputData();
				nnode->next=NULL;
				//accet th position 
				printf("Enter the position to insert node:");
				scanf("%d",&pos);
				pos=abs(pos);
				if(pos==0)pos=1;
				//make pos 1 if list is empty
				if(!start)pos=1;
				
				//is given position is 1
				if(pos==1)
				{
					//follow insert at first operation
					nnode->next=start;
					start=nnode;
					nnode=NULL;
					printf("%s at first",NNISMESSAGE);
					break;					
				}	
				//find th address of (pos-i)th node
				lnode=start;
				nodeNo=1;
				while(nodeNo<pos-1&&lnode->next)
				{
					lnode=lnode->next;
					nodeNo++;
				}
				//put the address of (pos)th node in address part of new node
				nnode->next=lnode->next;
				//put the address of new node in address part of (pos-1)th address part
				lnode->next=nnode;
				 //put NULL in nnode
				 nnode=NULL;
				 printf("%s at position %d",NNISMESSAGE,nodeNo+1);	
			
			break;
			case 4://code for last node
			//check list is empty or not
			if(start==NULL)
			{
				printf("List is Empty");
				break;
			}
			//Check if list has only one node
			if(start->next==NULL)
			{
				//delete 1st node
				start=NULL;
				printf(LNDMESSAGE);
				break;
			}
			//Now list has more than one node.So find the address of 2nd last node.
			
			lnode=start;
			while(lnode->next->next!=NULL)
			{
				lnode=lnode->next;
				//HERE lnode is represent 2nd last node
			}
			//Now delete last node
			//put NULL in address part of 2nd last node
			lnode->next=NULL;
			printf(LNDMESSAGE);
			break;
			case 5:
			//Code for Delete at 1st node
			printf("Work in progress");
			break;
			case 6://code for display list
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
			case 7:// exit from program
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