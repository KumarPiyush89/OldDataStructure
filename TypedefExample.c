
/*
typedef ->Used to create new data type
Syntax:

typedef type newName;

ex:
typedef int Integer;

int x;
or
Integer x;

ex 2:
typedef int*  intp;
//create an integer pointer
int *p1;
or
intp p1;

intp *p2;//p2 will be pointer to pointer

//create 5 different array of int type of size 10 each.

int a[10],b[10],c[10],d[10],e[10];

or
typedef int[10] IntArrayOf10;

IntArrayOf10 a,b,c,d,e;

IntArrayOf10 x[10]; //here x is a 2d array of 10X10 elements

ex:3
struct student
{
char name[30];
int class;
int roll;
};

//create variable of student type
struct student s1;

////////
typedef struct student Student;

Student p2;

or

typedef struct{
char name[30];
int class;
int roll;
}  Student;
*/
//C program to accept multiple name and roll of student in single linked list an

#include<stdio.h>
#include<malloc.h>
//create student type
typedef struct{
	char name[30];
	int roll;
} Student;
//fintion taht will accept a student record from keyboard
Student readStudent();
Student readStudent()
{
	Student  s;
	fflush(stdin);
	printf("Enter name:");
	gets(s.name);
	fflush(stdin);
	printf("Enter roll:");
	scanf("%d",&s.roll);
	return s;
}
//function to print a student record
void printStudent(Student s)
{
	printf("\n%s %d",s.name,s.roll);
}
//create Node type
struct node
{
	Student data;
	struct node*next;
};

typedef struct node Node;
int main()
{
	Node*start=NULL,*nnode;
	char choice;
	//create a new node
		nnode=(Node*)malloc(sizeof(Node));
		if(nnode==NULL)return 0;
		nnode->data=readStudent();
		nnode->next=NULL;
		start=nnode;
		printf("Want more node?(Y/N):");
		fflush(stdin);
		scanf("%c",&choice);
		while(choice=='Y'||choice=='y')
		{
			nnode->next=(Node*)malloc(sizeof(Node));
			if(nnode->next==NULL)break;
			nnode=nnode->next;
			nnode->data=readStudent();
			nnode->next=NULL;
			printf("Want more node?(Y/N):");
			fflush(stdin);
			scanf("%c",&choice);
			
		}
printf("\nAll Entered records are:")		;
nnode=start;
while(nnode)
{
	printStudent(nnode->data);
	nnode=nnode->next;
}
printf("\nOk Bye");
return 0;
			
	}


