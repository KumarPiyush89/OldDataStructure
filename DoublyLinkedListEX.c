#include<stdio.h>
#include<malloc.h>
#include<process.h>
#include<math.h>
#define UCNNMESSAGE "\nUnable to create new node\n"
#define NNISMESSAGE "\nNew Node Inserted Successfully"

typedef struct {
	char name[30];
	char gender;
	char mobile[11];
} Data;

Data InputData()
{
	Data data; 
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

void PrintData(Data data)
{
	printf("\n%30s %c %10s",data.name,data.gender,data.mobile);
}

//create node 
struct NNode
{
	struct NNode* pre;
	 Data data;
	struct NNode* next;
};
typedef struct NNode Node;

//Insert at first
void InsertAtFirst(Node **start)
{
	Node *nnode=NULL;
	Data data;
	//Create node
	nnode=(Node*)malloc(sizeof(Node));
	//check memory allocate yes or not
	if(nnode==NULL)
	{
		printf(UCNNMESSAGE);
		return;
	}
	//accept data of new node
	nnode->data=InputData();
	nnode->pre=nnode->next=NULL;
	//if list is already empty
	if((*start)==NULL)
	{
		*start=nnode;
		nnode==NULL;
	}
	else
	{
	nnode->next=*start;
	(*start)->pre=nnode;
	*start=nnode;
	nnode==NULL;
	}
	printf("\nNew node inserted successfully at First");
	return;
}

//InsertAtAnyWhere
void InsertAnyWhereInList(Node **start)
{
	Node *tnode,*nnode;
	int pos,cnodeno;
	Data data;
	//accept the position 
	printf("Enter the position to insert node:");
	scanf("%d",&pos);
	
	//make postive if pos negative
	pos=abs(pos);
	//make pos 1 if enter pos is 0;
	if(pos==0)pos=1;
	//make pos 1 if list is empty(Or)is given position 1
	if(pos==1||(!*start)) {InsertAtFirst(start);return;}

	//create node
	nnode=(Node*)malloc(sizeof(Node));
	if(!nnode)
	{
	printf(UCNNMESSAGE);
	return;
	}
	//put data in data part and NULL in both address part of new node
	nnode->data=InputData();
	nnode->pre=nnode->next=NULL;
	
	//Traverse the list and reach at (p-1)th node
	tnode=*start;
	cnodeno=1;
	while(tnode->next!=NULL&&cnodeno<pos-1)
	{
		tnode=tnode->next;
		cnodeno++;
	}
	//Check insertion is performed at last or before last
	if(tnode->next==NULL)
	{
		//Follow insert at last operation
		//put the address of new node in next part of last node
		tnode->next=nnode;
		//put the address of current last node is pre part of new node
		nnode->pre=tnode;
		nnode=NULL;
		
	}
	else
	{
	//put the address of tnode's in address part of new nodes address in next part on new node
	nnode->next=tnode->next;
	//put the address of new node in address part of (pos-1)th address part
	tnode->next->pre=nnode;
	//put the address of new node in next part of tnode
	tnode->next=nnode;
	//put the address of tnode in pre part of new node
	nnode->pre=tnode;
	//put NULL in nnode
	nnode=NULL;
	}
	printf("%s at position %d in List",NNISMESSAGE,cnodeno+1);
	 				
}

//Delete at first
void DeleteAtFirst(Node **start)
{
	Node *tnode=NULL;
	
	if(*start==NULL)
	{
		printf("List is Empty");
		return;
	}
	
    if((*start)->next==NULL)
	{
		*start=NULL;
		printf("Delete Successfully at first");
		return;
	}
	
	tnode=*start;
	*start=(*start)->next;
	(*start)->pre=NULL;
	free(tnode);
	printf("Delete Successfully at first");
	
}

//Delete at specific position
void DdeleteAT(Node **start)
{
	Node *tnode=NULL,*dnode=NULL;
	int pos,cnodeno;
	
	if(*start==NULL)
	{
		printf("list is already Empty");
		return;
	}
	
	printf("Enter position for delete:");
	scanf("%d",&pos);
	
	pos=abs(pos);
	if(pos==0)
	{
		printf("\n Invalid position");
		return;
	}
	if(pos==1)
	{
		DeleteAtFirst(start);
		return;
	}
	else
	{
	
	tnode=*start;
	cnodeno=2;
	while(cnodeno<pos&&tnode->next!=NULL)
	{
		tnode=tnode->next;
		cnodeno++;
	}
	if(tnode->next==NULL)
	{
		
		printf("Invalid position");
		return;
	}
	dnode=tnode->next;
	tnode->next=dnode->next;
	if(dnode->next!=NULL)
	dnode->next->pre=tnode;
	//tnode->pre->next=tnode->next;
	//tnode->next->pre=tnode->pre;
	free(dnode);
	printf("\n Record at position %d is  delete successfully",pos);
   }
}

//display three member list on screen
void PrintList(Node *start)
{
	
	if(start==NULL)
	{
		printf("\nList is Empty");
		return;
	}
	
	while(start)
	{
		//print the data
		PrintData(start->data);
		//move on next node
		start=start->next;
	}
	printf("\nEnd");			
}

int main()
{
    Node *start=NULL;
	int choice;
	do
	{
		system("cls");
		printf("\n\tMenu\n===============================");
		printf("\n1. Insert at First in list ");
		printf("\n2. Insert at anywhere in list");
		printf("\n3. Viem List");
		printf("\n4. Delete at first");
		printf("\n5. Delete at specific postion");
		printf("\n6. Exit");
		printf("\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1://Insert at First in list
			InsertAtFirst(&start);break;
			case 2://Insert at specific location in list
			InsertAnyWhereInList(&start);break;
			case 3://Viem list
			PrintList(start);break;
			case 4://delete at first
			DeleteAtFirst(&start);break;
			case 5://delete at specific position
			DdeleteAT(&start);break;
			case 6://Exit
			{
				exit(0);
			}
		}
		printf("\n");
		system("pause");
	}while(1);
}
