#include<stdio.h>
#include<math.h>
#include<malloc.h>
/*Circular Linked List*/
typedef struct{
	char name[30];
	char gender;
	int age;
} Data;
//function for input data
Data readData()
{
	Data data;
	printf("Enter name:");
	fflush(stdin);
	gets(data.name);
	printf("Enter Gender(M/F):");
	scanf("%c",&data.gender);
	//validate entered data
	printf("Enter age:");
	scanf("%d",&data.age);
	return data;
	
}
void printData(Data data)
{
	printf("\n%30s %c %02d",data.name,data.gender,data.age);
}

struct NNode
{
	Data data;
	struct NNode *next;
};
typedef struct NNode Node;

int cLLInsertAtFirst(Node **start,Data data)
{
	
	Node *newNode=NULL,*tNode=NULL;
	newNode=(Node*)malloc(sizeof(Node));
	if(!newNode)return 0;
	
	newNode->data=data;
	newNode->next=*start;
	
	//find the address of last node
	tNode=*start;
	if(tNode)
	{
		//move on the last node.
		while(tNode->next!=*start)tNode=tNode->next;
		//put the address of newNode in last node's next part.
		tNode->next=newNode;
	}
	else
	newNode->next=newNode;
	
	*start=newNode;
	return 1;
	
}

int cLLInsertAt(Node **start,Data data,int pos)
{
	/*
	return value 
	0->Not inserted
	positive integer->insertiojn position
	*/
	Node *newNode=NULL,*tNode=NULL;
	int nodePosition;
	pos=abs(pos);
	if(pos==0)pos=1;
	if(pos==1||(!*start)) return cLLInsertAtFirst(start,data);
	
	/*create new node*/
	newNode=(Node*)malloc(sizeof(Node));
	if(!newNode)return 0;
	
	newNode->data=data;
	//find the address of (pos-1)th node
	nodePosition=1;
	tNode=*start;
	while((tNode->next!=*start)&&(++nodePosition<pos))tNode=tNode->next;
	
	if(tNode->next==*start)nodePosition++;
	
	newNode->next=tNode->next;
	tNode->next=newNode;
	return nodePosition;
}

void printList(Node*start)
{
	
	Node*tNode=start;
	if(!start)
	{	
	printf("\nList is Empty!");
	return;
    }
	
	do
	{
		printData(start->data);
		start=start->next;
	}while(start!=tNode);
	return;
}
int  cLLDeleteAtFirst(Node **start)
{
	Node *dnode=NULL,*lnode=NULL;
	if(!*start)return -1;
    
    //1.find the address of last node.
        dnode=*start;
        lnode=*start;
        if(lnode->next==*start)
        *start=NULL;
        else
        {
         while(lnode->next!=*start)lnode=lnode->next;
   		 //2.put the address of 2nd node in last node's next part.
		lnode->next=(*start)->next;
		//3.make 2nd to 1st node.
		*start=(*start)->next;	
		}	
	//4.free the address of dnode.
		free(dnode);
	return 1;			    
}
int cLLDeleteAt(Node **start,int pos)
{
	
	/*
	   return value.
	  -1 =List is empty.
	   0 =Invalid position.
	   1 =Data deletd sucessfully from list.
	*/
	int nodeNo;
	Node *dnode=NULL,*lnode=NULL;
	pos=abs(pos);
	if(!*start)return -1;
	if(pos==0)return 0;
	if(pos==1)return cLLDeleteAtFirst(start);
	
	//1.find the address of (pos-1)th element.
	lnode=*start;
	nodeNo=1;
	while(++nodeNo<pos&&lnode->next!=*start)lnode=lnode->next;
	//2.check if position is valid or not.
	if(lnode->next==*start)return 0;
	//3.put the address of lnode's next in donde.
	dnode=lnode->next;
	//4.put the address of dnode's next in lnode's next.
	lnode->next=dnode->next;
	//5.free the address of dnode.
	free(dnode);
	return 1;
}
void cLLEmptyList(Node **start)
{
	Node *dnode=*start,*lnode=*start;
	if(!*start)return;
	do
	{
		dnode=lnode;
		lnode=lnode->next;
		free(dnode);
	}while(lnode!=*start);
	*start=NULL;
	return;
}
