#include"doublyCircularLinkedList.c"
int main()
{
	Node*start=NULL;
	Data data;
	int pos;
	char choice;
	do
	{
		system("cls");
		printf("\n1.Insert\n2.Delete\n3.Empty List\n4.Print List\n5.Print reverse list.\n0.Exit\nEnter choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1://code for insert data in list.
				data=readData();
				printf("Enter the position:");
				scanf("%d",&pos);
				choice=dcLLInsertAt(&start,data,pos);
				if(choice!=0)
				printf("Data inserted at %d in list successfully:)",choice);
				else
				printf("OOPS! Error in insertion):");
				break;
			case 2:// code for delete data from list.
				printf("\nEnter position: ");
				scanf("%d",&pos);
				choice=dcLLDeleteAt(&start,pos);
				if(choice==1)
				printf("\nData deleted from list at position %d",pos);
				else if(choice==-1)
				printf("\nList is empty!");
				else
				printf("\nInvalid position!");
			  	break;
			case 3:// code for empty list.
				if(!start)
				{
					printf("\nList is already empty!");
					break;
				}
				printf("\nAre you sure to erase all records from list(Y/N): ");
				fflush(stdin);
				scanf("%c",&choice);
				if(choice!='y'&&choice!='Y')
				{
					printf("\nNo any records deleted %c.",2);
					break;
				}
				dcLLEmptyList(&start);
				printf("List has been emptied sucessfully %c.",1);
				break;		  	
			case 4:// code for print the data of list.
				printList(start);
				break;
			case 5:// code for print the data in revere order.
				if(!printReverse(start))
				printf("\nList is empty!");
				break;
					
			case 0:// code for exit fromm program.
				printf("\n%cThank you%c",1,2);
				return 0;
			default:
				printf("\nNot a Valid Option:)");
		}
		printf("\n");
		system("pause");
	}while(1);
}
