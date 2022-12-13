/* Three list insert*/
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

int main()
{
	struct Node *brilliant=NULL,*moderate=NULL,*normal=NULL,*nnode=NULL,*lnode=NULL,*dnode=NULL;
	int choice,pos,nodeNo,i;
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
		printf("\n10. Exit");
		printf("\n ente your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			
			case 1://Insert at Specific Location In Brilliant List
			{
			
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
					//accept the position 
					printf("Enter the position to insert node:");
					scanf("%d",&pos);
					pos=abs(pos);
					if(pos==0)pos=1;
					//make pos 1 if list is empty
					if(!brilliant)pos=1;
					
					//is given position is 1
					if(pos==1)
					{
						//follow insert at first operation
						nnode->next=brilliant;
						brilliant=nnode;
						nnode=NULL;
						printf("%s at first in brilliant List",NNISMESSAGE);
						break;					
					}	
					//find the address of (pos-i)th node
					lnode=brilliant;
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
					 printf("%s at position %d in Brilliant List",NNISMESSAGE,nodeNo+1);	
				
				break;
			}
			case 2://code for delete at specific position in brilliant list
			{
				//Check empty 
				if(brilliant==NULL)
				{
					printf("\nList is empty.\n");
					break;
				}
				//Accept position
				printf("Enter the position to delete node");
				scanf("%d",&pos);
				pos=abs(pos);
				
				//Delete 1st position node
			    if(pos==1)
				{
					lnode=brilliant;
			    	brilliant=brilliant->next;
				    free(lnode);
				    printf("1st student deleted successfully from brilliant list");
					break;
				}
				//3: Find the address of (position-1)th node
				lnode=brilliant;
				nodeNo=1;
				while(nodeNo<(pos-1)&&lnode->next!=NULL)
				{
				lnode=lnode->next;
				nodeNo=nodeNo+1;
				}
				if(lnode->next==NULL)
				{
					printf("\nInvalid record position given");
					break;
				}
				dnode=lnode->next;
				lnode->next=dnode->next;
				free(dnode);
				printf("\n Record at position %d is  delete successfully from brilliant List \n",pos);
				break;
			}
			case 3://code for display brilliant list
			{
				if(brilliant==NULL)
				{
					printf("\nBrilliant List is Empty!");
					break;
				}
				printf("\nBrilliant List:");
				lnode=brilliant;
				while(lnode!=NULL)
					{
						//print the data
						printData(lnode->data);
						//move on next node
						lnode=lnode->next;
					}
					printf("\nEnd");
					break;
			}
		    case 4://Insert at Specific Location in Moderate list
		    {
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
					//accept the position 
					printf("Enter the position to insert node:");
					scanf("%d",&pos);
					pos=abs(pos);
					if(pos==0)pos=1;
					//make pos 1 if list is empty
					if(!moderate)pos=1;
					
					//is given position is 1
					if(pos==1)
					{
						//follow insert at first operation
						nnode->next=moderate;
						moderate=nnode;
						nnode=NULL;
						printf("%s at first in moderate List",NNISMESSAGE);
						break;					
					}	
					//find the address of (pos-i)th node
					lnode=moderate;
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
					 printf("%s at position %d in Brilliant List",NNISMESSAGE,nodeNo+1);	
				
		    	break;
			}
		    case 5://delete at specific location in ModerateList
		    {
		    	//Check empty 
				if(moderate==NULL)
				{
					printf("\nList is empty.\n");
					break;
				}
				//Accept position
				printf("Enter the position to delete node");
				scanf("%d",&pos);
				pos=abs(pos);
				
				//Delete 1st position node
			    if(pos==1)
				{
					lnode=moderate;
			    	moderate=moderate->next;
				    free(lnode);
				    printf("1st student deleted successfully from moderate list");
					break;
				}
				//3: Find the address of (position-1)th node
				lnode=moderate;
				nodeNo=1;
				while(nodeNo<(pos-1)&&lnode->next!=NULL)
				{
				lnode=lnode->next;
				nodeNo=nodeNo+1;
				}
				if(lnode->next==NULL)
				{
					printf("\nInvalid record position given");
					break;
				}
				dnode=lnode->next;
				lnode->next=dnode->next;
				free(dnode);
				printf("\n Record at position %d is  delete successfully from moderate List \n",pos);
		    	break;
			}
		    case 6://display moderate list
		    {
		    	if(moderate==NULL)
				{
					printf("\nBrilliant List is Empty!");
					break;
				}
				printf("\nBrilliant List:");
				lnode=moderate;
				while(lnode!=NULL)
					{
						//print the data
						printData(lnode->data);
						//move on next node
						lnode=lnode->next;
					}
					printf("\nEnd");
			break;
			}
		    case 7://insert at specific location in normal list
		    {
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
					//accept the position 
					printf("Enter the position to insert node:");
					scanf("%d",&pos);
					pos=abs(pos);
					if(pos==0)pos=1;
					//make pos 1 if list is empty
					if(!normal)pos=1;
					
					//is given position is 1
					if(pos==1)
					{
						//follow insert at first operation
						nnode->next=normal;
						normal=nnode;
						nnode=NULL;
						printf("%s at first in normal List",NNISMESSAGE);
						break;					
					}	
					//find the address of (pos-i)th node
					lnode=normal;
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
					 printf("%s at position %d in Brilliant List",NNISMESSAGE,nodeNo+1);	
				
		    	break;
			}
		    case 8://delete at specifie location in normal list
		    {	
		    //Check empty 
				if(normal==NULL)
				{
					printf("\nList is empty.\n");
					break;
				}
				//Accept position
				printf("Enter the position to delete node");
				scanf("%d",&pos);
				pos=abs(pos);
				
				//Delete 1st position node
			    if(pos==1)
				{
					lnode=normal;
			    	normal=normal->next;
				    free(lnode);
				    printf("1st student deleted successfully from normal list");
					break;
				}
				//3: Find the address of (position-1)th node
				lnode=normal;
				nodeNo=1;
				while(nodeNo<(pos-1)&&lnode->next!=NULL)
				{
				lnode=lnode->next;
				nodeNo=nodeNo+1;
				}
				if(lnode->next==NULL)
				{
					printf("\nInvalid record position given");
					break;
				}
				dnode=lnode->next;
				lnode->next=dnode->next;
				free(dnode);
				printf("\n Record at position %d is  delete successfully from normal List \n",pos);
		    	break;
			}
		    case 9://display normal List
		    {
		    	if(normal==NULL)
				{
					printf("\nBrilliant List is Empty!");
					break;
				}
				printf("\nBrilliant List:");
				lnode=normal;
				while(lnode!=NULL)
					{
						//print the data
						printData(lnode->data);
						//move on next node
						lnode=lnode->next;
					}
					printf("\nEnd");
		    	break;
			}
		    case 10://exit
		    {
		    	exit(0);
			}
		}
		printf("\n");
		system("pause");
	 } while(1);
}