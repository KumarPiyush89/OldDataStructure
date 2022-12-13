// doubly circular linked list.
#include<stdio.h>
#include<math.h>
#include<malloc.h>
/* doubly Circular Linked List*/
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
	struct NNode *pre;
	Data data;
	struct NNode *next;
};
typedef struct NNode Node;

int dcLLInsertAtFirst(Node **start,Data data)
{
	
	Node *newNode=NULL,*tNode=NULL;
	//1.create a new node.
	newNode=(Node*)malloc(sizeof(Node));
	//2.check if node is created or not.
	if(!newNode)return 0;
	//3. put start in newNode's pre & next part.
	newNode->pre=newNode->next=newNode;
	//4. put data in newNode's data part.
	newNode->data=data;
    //5 .check if start is not NULL.
    if(*start)
    {
    	newNode->next=*start;
    	newNode->pre=(*start)->pre;
    	(*start)->pre=newNode;
    	newNode->pre->next=newNode;
	}
	//6. put the address of newNode in start.
	*start=newNode;

	return 1;
}

int dcLLInsertAt(Node **start,Data data,int pos)
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
	if(pos==1||(!*start)) return dcLLInsertAtFirst(start,data);
	
	/*create new node*/
	newNode=(Node*)malloc(sizeof(Node));
	if(!newNode)return 0;
	
	//put data in data part.
	newNode->data=data;
	//put NULL in next & pre part.
	newNode->next=newNode->pre=NULL;
	//find the address of (pos-1)th node
	nodePosition=1;
	tNode=*start;
	while((tNode->next!=*start)&&(++nodePosition<pos))tNode=tNode->next;
	
	if(tNode->next==*start)nodePosition++;
	
	newNode->next=tNode->next;
	newNode->pre=tNode;
	tNode->next->pre=newNode;
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
		printData(tNode->data);
		tNode=tNode->next;
	}while(tNode!=start);
	return;
}
int  dcLLDeleteAtFirst(Node **start)
{
	Node *dnode=NULL;
	if(!*start)return -1;
    
    //put The address of start in dnode.
     dnode=*start;
     // check if list has only one record.
     if(dnode->next==dnode)
     {
     	*start=NULL;
     	free(dnode);
     	return 1;
	 }
	 //put the address of last node in 2nd node pre part.
	 (*start)->next->pre=(*start)->pre;
	 //put the address of 2nd node in start.
	 	*start=(*start)->next;
	// free the address of dnode.
	free(dnode);
    return 1;			    
}
int dcLLDeleteAt(Node **start,int pos)
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
	if(pos==1)return dcLLDeleteAtFirst(start);
	
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
	//5.put the address of lnode in dnode->next->pre.
	lnode->next->pre=lnode;
	//6.free the address of dnode.
	free(dnode);
	return 1;
}
void dcLLEmptyList(Node **start)
{
	Node *dnode=NULL,*lnode=*start;
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
int printReverse(Node *start)
{
	Node *lnode=NULL;
	/*
		return value
		0=List is empty!
		positive number=List printed sucessfully.
	*/
	// check if start is NULL or not
	if(!start)
	return 0;
	// put the address of last node in lnode.
	lnode=start->pre;
	//print the data of Nodes in reverse order.
	while(lnode!=start)
	{
		printData(lnode->data);
		lnode=lnode->pre;
	}
	printData(lnode->data);
	return 1;
}
