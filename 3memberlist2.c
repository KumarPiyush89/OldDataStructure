#include<stdio.h>
#include<malloc.h>
#include<process.h>
#include<math.h>
#define UCNNMESSAGE "\nUnable to create new node\n"
#define NNISMESSAGE "\nNew Node Inserted Successfully"

struct Data
{
	char name[30];
	char gender;
	char mobile[11];
};

struct Data InputData()
{
	struct Data data; 
	printf("Enter name:");
	fflush(stdin);
	gets(data.name);
	printf("\Enter gender(M/F)");
	fflush(stdin);
	scanf("%c",&data.gender);
	printf("\nEnter Mob no.");
	fflush(stdin);
	gets(data.mobile);
	return data;
};

void PrintData(struct Data data)
{
	printf("\n%30s %c %10s",data.name,data.gender,data.mobile);
}

//create node 
struct Node
{
	struct Data data;
	struct Node* next;
};

//InsertAtAnyWhere
void InsertAnyWhereInList(struct Node **start,char* listname)
{
	struct Node *lnode,*nnode;
	int pos,nodeno;
	
	//create node
	nnode=(struct Node*) malloc(sizeof(struct Node));
	if(!nnode)
	{
	printf(UCNNMESSAGE);
	return;
	}
	//put data in data part and NULL in address part of new node
	nnode->data=InputData();
	nnode->next=NULL;
	//accept the position 
	printf("Enter the position to insert node:");
	scanf("%d",&pos);
	
	//make postive if pos negative
	pos=abs(pos);
	//make pos 1 if enter pos is 0;
	if(pos==0)pos=1;
	//make pos 1 if liist is empty
	if(!(*start))pos=1;
	//is given position 1
	if(pos==1)
	{
		nnode->next=*start;
		*start=nnode;
		nnode=NULL;
		printf("%s at first in %s List",NNISMESSAGE,listname);
		return;					
	}
	//find the address of (pos-1)th node
	lnode=*start;
	nodeno=1;
	while(nodeno<pos-1&&lnode->next)
	{
		lnode=lnode->next;
		nodeno++;
	}
	//put the address of (pos)th node in address part of new node
	nnode->next=lnode->next;
	//put the address of new node in address part of (pos-1)th address part
	lnode->next=nnode;
	 //put NULL in nnode
	 nnode=NULL;
	 printf("%s at position %d in %s List",NNISMESSAGE,nodeno+1,listname);
	 				
}

//DeleteAtAnywhere
void DeleteAtAnyWhereInList(struct Node **Start,char* listname)
{
	int pos,nodeNo;
	struct Node *lnode,*dnode;
	
	//check empty or not
	if(*Start==NULL)
	{
	printf("\n List is Empty");
	return;
	}
	//Accept position for delete
	printf("Enter the position to delete node");
	scanf("%d",&pos);
	pos=abs(pos);
	// if pos is 1
	if(pos==1)
	{
		lnode=*Start;
		*Start=(*Start)->next;
		free(lnode);
		printf("1st student deleted successfully from %s list",listname);
		return;
	}
	//Find the address of (position-1)th node
	lnode=*Start;
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
	printf("\n Record at position %d is  delete successfully from %s List \n",pos,listname);
	
}
//display three member list on screen
void PrintList(struct Node *start,char* listname)
{
	if(start==NULL)
	{
		printf("\n%s List is Empty",listname);
		return;
	}
	printf("\n%s List:",listname);
	
	while(start)
	{
		//print the data
		PrintData(start->data);
		//move on next node
		start=start->next;
	}
	printf("\nEnd");			
}
//code for whole list deleted
void WholeListDeleted(struct Node **Start,char* listname)
{
	struct Node *lnode;

	while(*Start!=NULL)
	{
		lnode=*Start;
		*Start=(*Start)->next;
		free(lnode);
	}
	printf("Whole %s list deleted Successfully",listname);
}
//code for display by Traversal of single circular link list mehtod(from First to last node)
void PrintList2(struct Node *start,char* listname)
{
	struct Node *tnode;
	
	tnode=start;
	
	if(tnode==NULL)
	{
		printf("\n%s List is Empty",listname);
		return;
	}
	printf("\n%s List:",listname);
	
	//traversal of single circular linked list
	do
	{
		//print the data
		PrintData(tnode->data);
		//move on next node
		tnode=tnode->next;
	}while(tnode!=start);
	printf("\nEnd");
}

//code for display by traversal of single circular linked list mehtod(Starting from any Node)
void PrintList3(struct Node *anynode,char* listname)
{
	struct Node *tnode;
	
	tnode=anynode;
	
	if(tnode==NULL)
	{
		printf("\n%s List is Empty",listname);
		return;
	}
	printf("\n%s List:",listname);
	
	//traversal of single circular linked list
	do
	{
		//print the data
		PrintData(tnode->data);
		//move on next node
		tnode=tnode->next;
	}while(tnode!=anynode);
	printf("\nEnd");
}
int main()
{
	struct Node *Teacher=NULL,*Farmer=NULL,*Banker=NULL;
	int choice;
	do
	{
		system("cls");
		printf("\n\tMenu\n===============================");
		printf("\n1. Add at specific to Teacher list ");
		printf("\n2. Delete at specific from Teacher list");
		printf("\n3. view all Teacher List");
		printf("\n4. Whole Teacher List Deleted");
		printf("\n5. viem all Teacher list from first to last by circular linked list");
		printf("\n6. Viem all Teacher list from any node by circular linked list");
		printf("\n7. Add at specific to Farmer List");
		printf("\n8. Delete at specific from Farmer List");
		printf("\n9. view all Farmer List");
		printf("\n10. Whole Farmer List Deleted");
		printf("\n11. viem all Farmer list from first to last by circular linked list");
		printf("\n12. Viem all Farmer list from any node by circular linked list");
		printf("\n13. Add at specific to Banker list");
	    printf("\n14. Delete at specific from Banker list");
		printf("\n15. view all Banker List");
		printf("\n16. Whole Banker List Deleted");
		printf("\n17. viem all Banker list from first to last by circular linked list");
		printf("\n18. Viem all Banker list from any node by circular linked list");
		printf("\n19. Exit");
		printf("\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1://Insert at specific location in Teacher list
			InsertAnyWhereInList(&Teacher,"Teacher");break;
			case 2://Delete at specific location in Teacher list
			DeleteAtAnyWhereInList(&Teacher,"Teacher");break;
			case 3://Viem all record teacher list
			PrintList(Teacher,"Teacher");break;
			case 4://Whole list Delete
			WholeListDeleted(&Teacher,"Teacher");break;
			case 5://viem all record from first to last node by circular single linked list
			PrintList2(Teacher,"Teacher");break;
			case 6://viem all record Strating from any node by circular single linked list
			PrintList3(Teacher,"Teacher");break;
			case 7://Insert at specific location in Farmer list
			InsertAnyWhereInList(&Farmer,"Farmer");break;
			case 8://Delete at specific location in Teacher list
			DeleteAtAnyWhereInList(&Farmer,"Farmer");break;
			case 9://Viem all record Farmer list
			PrintList(Farmer,"Farmer");break;
			case 10://Whole list Delete
			WholeListDeleted(&Farmer,"Farmer");break;
			case 11://viem all record from first to last node by circular single linked list
			PrintList2(Farmer,"Farmer");break;
			case 12://viem all record Strating from any node by circular single linked list
			PrintList3(Farmer,"Farmer");break;
			case 13://Insert at specific location in Banker list
			InsertAnyWhereInList(&Banker,"Banker");break;
			case 14://Delete at specific location in Teacher list
			DeleteAtAnyWhereInList(&Banker,"Banker");break;
			case 15://Viem all record Banker list
			PrintList(Banker,"Banker");break;
			case 16://Whole list Delete
			WholeListDeleted(&Banker,"Banker");break;
			case 17://viem all record from to last node by circular single linked list
			PrintList2(Banker,"Banker");break;
			case 18://viem all record Strating from any node by circular single linked list
			PrintList3(Banker,"Banker");break;
			case 19://Exit
			{
				exit(0);
			}
		}
		printf("\n");
		system("pause");
	}while(1);
}
