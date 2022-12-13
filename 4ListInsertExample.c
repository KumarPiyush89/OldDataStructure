#include<stdio.h>
#include<malloc.h>
#include<process.h>
#include<math.h>
#define NCFMESSAGE "\nUnable To Create New Node\n"
#define NNISMESSAGE "\nNew Node Inserted Successfully"
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

//This function will add a new node in struct Node type list at given position
void insertAnyWhereInList(struct Node **start,char* listName)
{
	struct Node *lnode,*nnode;
	int pos,nodeNo;
					//1. Create new node
					nnode=(struct Node*) malloc(sizeof(struct Node));
					if(!nnode)
					{
						printf(NCFMESSAGE);
						return;					
					}
					//put data in data part and NULL in address part of new node
					nnode->data=inputData();
					nnode->next=NULL;
					//accept the position 
					printf("Enter the position to insert node:");
					scanf("%d",&pos);
					pos=abs(pos);
					if(pos==0)pos=1;
					//make pos 1 if list is empty
					if(!(*start))pos=1;
					//is given position is 1
					if(pos==1)
					{
						//follow insert at first operation
						nnode->next=*start;
						*start=nnode;
						nnode=NULL;
						printf("%s at first in %s List",NNISMESSAGE,listName);
						return;					
					}	
					//find the address of (pos-i)th node
					lnode=*start;
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
					 printf("%s at position %d in %s List",NNISMESSAGE,nodeNo+1,listName);	
				
}

//This function will delete given position node from given list
void deleteAnyNodeFromList(struct Node **start,char* listName)
{
	int pos,nodeNo;
	struct Node *lnode,*dnode;
	//Check empty 
				if(*start==NULL)
				{
					printf("\nList is empty.\n");
					return;
				}
				//Accept position
				printf("Enter the position to delete node");
				scanf("%d",&pos);
				pos=abs(pos);
				
				//Delete 1st position node
			    if(pos==1)
				{
					lnode=*start;
			    	*start=(*start)->next;
				    free(lnode);
				    printf("1st student deleted successfully from %s list",listName);
					return;
				}
				//3: Find the address of (position-1)th node
				lnode=*start;
				nodeNo=1;
				while(nodeNo<(pos-1)&&lnode->next!=NULL)
				{
				lnode=lnode->next;
				nodeNo=nodeNo+1;
				}
				if(lnode->next==NULL)
				{
					printf("\nInvalid record position given");
					return;
				}
				dnode=lnode->next;
				lnode->next=dnode->next;
				free(dnode);
				printf("\n Record at position %d is  delete successfully from %s List \n",pos,listName);
}

//this function will display the contents of list on screen
void printList(struct Node *start,char* listName)
{
	if(start==NULL)
				{
					printf("\n%s List is Empty!",listName);
					return;
				}
				printf("\n%s List:",listName);
				
				while(start)
					{
						//print the data
						printData(start->data);
						//move on next node
						start=start->next;
					}
					printf("\nEnd");			
	
}
int main()
{
	struct Node *brilliant=NULL,*moderate=NULL,*normal=NULL,*extrabrilliant=NULL;
	int choice;
	do
	{
		system("cls");
		printf("\n\tMenu\n=======================================");
		printf("\n1. Add at specific to brilliant list ");
		printf("\n2. Delete at specific from brilliant list");
		printf("\n3. view all brilliant student");
		printf("\n4. Add at specific to moderate");
		printf("\n5. Delete at specific from moderate");
		printf("\n6. view all moderate student");
		printf("\n7. Add at specific to normal list");
	    printf("\n8. Delete at specific from normal list");
		printf("\n9. view all normal student");
		printf("\n10.Add at specific to extrabrilliant list");
		printf("\n11.Delete at specific from extrabrilliant list");
		printf("\n12.View all extrabrilliant student");
		printf("\n13. Exit");
		printf("\n ente your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			

			case 1://Insert at Specific Location In Brilliant List
			insertAnyWhereInList(&brilliant,"Brilliant");break;
			case 2://code for delete at specific position in brilliant list
			deleteAnyNodeFromList(&brilliant,"Brilliant");break;
			case 3://code for display brilliant list
			printList(brilliant,"Brilliant");break;
			case 4://Insert at Specific Location in Moderate list
			insertAnyWhereInList(&moderate,"Moderate");break;
			case 5://delete from moderate list
			deleteAnyNodeFromList(&moderate,"Moderate");break;
		    case 6://display moderate list
		    printList(moderate,"Moderate");break;
		       case 7://insert at specific location in normal list
		       insertAnyWhereInList(&normal,"Normal");break;
		    case 8://delete at specifie location in normal list
		    deleteAnyNodeFromList(&normal,"Normal");break;
		    case 9:
		    	printList(normal,"Normal");break;
		    case 10://Insert at specific Location in extrabrilliant list
		    insertAnyWhereInList(&extrabrilliant,"extrabrilliant");break;
		    case 11://code for delete at specific position in brilliant list
		    deleteAnyNodeFromList(&extrabrilliant,"extrabrilliant");break;
		    case 12://display extrabrilliant list
		    printList(extrabrilliant,"extrabrilliant");break;
		    case 13://exit
		    {
		    	exit(0);
			}
		}
		printf("\n");
		system("pause");
	 } while(1);
}