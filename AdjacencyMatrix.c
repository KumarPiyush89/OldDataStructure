/*Adjacency Matrix*/
#include<stdio.h>
#include<math.h>
#include<process.h>
#define MAXVERTEX 100
int main()
{
    int a[MAXVERTEX][MAXVERTEX],totalVertex,i,j;
    char vertexName[MAXVERTEX][10];
    printf("Enter total number of vertext in graph:");
    scanf("%d",&totalVertex);
    totalVertex=abs(totalVertex);
    if(totalVertex>MAXVERTEX)
    {
        printf("\nSorry! My maximum capacity is %d",MAXVERTEX);
        return 0;
    }

    //accept name of all vertex
    for(i=0;i<totalVertex;i++)
    {
        printf("Enter name of vertex %d:",i+1);
        fflush(stdin);
        gets(vertexName[i]);
    }

    //accept adjacency matrix
    for(i=0;i<totalVertex;i++)
    {
        for(j=0;j<totalVertex;j++)
        {
            printf("Is there a direct path between %s and %s(0/1):",vertexName[i],vertexName[j]);
            scanf("%d",&a[i][j]);
            a[i][j]=abs(a[i][j]);
            if(a[i][j]>=1)a[i][j]=1;
        }
    }

    //printf adjacency matrix
    system("cls");
    printf("Adjacency Matrix\n     ");
    for(i=0;i<totalVertex;i++)
    printf("%4s ",vertexName[i]);
    for(i=0;i<totalVertex;i++)
    {
        printf("\n%4s ",vertexName[i]);
        for(j=0;j<totalVertex;j++)
        printf("%4d ",a[i][j]);
    }

    printf("\n\nThank you\n");
    return 0;

}