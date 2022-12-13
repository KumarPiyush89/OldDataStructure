#include<stdio.h>
#include<math.h>
#include"InfixToPostfixConversion.c"
int main()
{
    char expression[SZ]="",postfix[SZ]="",numberString[30]="";
    int i,pos;
    float operandStack[50]={0},operand1,operand2;
    int tos=-1;
    system("cls");
    printf("Jai Sri Ganesh  \n");
    printf("\n Enter a valid expression:");
    fflush(stdin);
    gets(expression);
    pos=isValidExpression(expression);
    if(pos==-1)
    printf("\nValid Expression\n");
    else
    {
        printf("\n%d",pos);
        printf("\nInvalid Expression\n%s\n",expression);
        for(i=0;i<pos-1;i++)printf(" ");
        printf("^\n");
       return 0;
    }
    
    // find the the postfix of the expression.
    InfixToPostfix(expression,postfix);
    printf("postfix = %s",postfix);
    // finding the result.
    i=0;
    while(postfix[i])
    {
        if(isOperand(postfix[i]))
        {
            do
            {
                append(numberString,postfix[i]);
            } while (postfix[++i]!=',');
           sscanf(numberString,"%f",&operandStack[++tos]);
           numberString[0]='\0';
           i++;    
        }

        if(isOperator(postfix[i]))
        {
           operand2=operandStack[tos];
           tos--;
           operand1=operandStack[tos];
           tos--;
            if(postfix[i]=='+')
            operandStack[++tos]=operand1+operand2;
            else if(postfix[i]=='-')
            operandStack[++tos]=operand1-operand2;
            else if(postfix[i]=='*')
            operandStack[++tos]=operand1*operand2;
            else if(postfix[i]=='/')
            {
                if(operandStack[tos]==0)
                {
                    printf("\ncan't be divide by 0.");
                    return 0;
                }
                operandStack[++tos]=operand1/operand2;
            }
            else if(postfix[i]=='^')
            operandStack[++tos]=pow(operand1,operand2);
            i+=2;
        }
    }
    printf("\n(%s) = %.2f and tos=%d\n\n\n\n",expression,operandStack[tos],tos);
    return 0;
}