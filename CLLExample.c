#include"circularLinkedList.c"
#include<process.h>
int main()
{
	Node*start=NULL;
	Data data;
	int pos;
	char choice;
	do
	{
		system("cls");
		printf("\n1.Insert\n2.Print\n3.Exit\nEnter choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				data=readData();
				printf("Enter the position:");
				scanf("%d",&pos);
				choice=cLLInsertAt(&start,data,pos);
				if(choice!=0)
				printf("Data inserted at %d in list successfully:)",choice);
				else
				printf("OOPS! Error in insertion):");
				break;
			case 2:
				printList(start);
					break;
			case 3:
						return;
			default:
							printf("\nNot a Valid Option:)");
		}
		printf("\n");
		system("pause");
	}while(1);
}