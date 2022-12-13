#include<stdio.h>
#include<math.h>
#include"InfixToPostfixConversion.c"
#include"Split_String_Function.c"

int main()
{
    char expression[500];
    int i,pos;
    printf("Jai Sri Ganesh  \n");
    printf("\n Enter a valid expression:");
    gets(expression);
    pos=isValidExpressin(expression);
    if(pos==-1)
    {
        printf("\nValid Expression\n");
        splitInOperatorAndOperands(expression);
        printf("\n\n");
        infixToPostfix(expression);
    }
    else
    {
        printf("\n%d",pos);
        printf("\nInvalid Expression\n%s\n",expression);
        for(i=0;i<pos;i++)printf(" ");
        printf("^\n");

    }
    return 0;
}