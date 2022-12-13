#include<stdio.h>
#include<math.h>
#include"InfixToPostfixConversion.c"
#include"Split_String_Function.c"

int strReplace(char *str,char replaceChar,char replaceWith)
{
    int i,totalReplacement=0;
    for(i=0;str[i];i++)
    {
        if(str[i]==replaceChar)
        {
            str[i]=replaceWith;
            totalReplacement++;
        }
    }
    return totalReplacement;
}




int main()
{
    char expression[500],postfix[500],temp[500];
    int i,pos;
    printf("\n Enter a valid expression:");
    gets(expression);
    pos=isValidExpressin(expression);
    if(pos==-1)
    {
    	strcpy(temp,expression);
        strrev(temp);
        strReplace(temp,'(','`');
    	strReplace(temp,')','(');
    	strReplace(temp,'`',')');
        infixToPostfix(temp,postfix);
        strrev(postfix);
        printf("\nInfix Expression %s",expression);
       printf("\nPrefix Expression %s",postfix);
       
    	
    
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