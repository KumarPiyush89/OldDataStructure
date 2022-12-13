#include<string.h>
#include"charstack.c"
/*
This file will contain the function for converting Infix expression Into Postfix Expression
Steps:
1. Accept an expression in string form
2. check expression is valid or not
3. convert infix to postfix notation
*/
//function to check a symbol is operator of operand?
int isOperator(char symbol)
{
    char operators[]="+-*/^()";
    int i;
    for(i=0;operators[i];i++)
    {
        if(symbol==operators[i])return 1;
    }
    return 0;
}
int isOperand(char symbol)
{
    char operands[]="0123456789.";
    int i;
    for(i=0;operands[i];i++)if(symbol==operands[i])return 1;
    return 0;
}

// for to check an expression is valid or not
int isValidExpressin(char *expression)
{
    /* it will return -1 if expression is valid and a +ve number if invalid
    positive number=position at which error found

    /*
    The form of expression will be as:
    12+45*789
    That means an expression will consist of  0-9,+,-,*,/,^,(,) and .
    2. two operators can't be continuous except ( and  )
    3. ('s left symbol must be an operator and right symbol must be an operand or (
    4. )'s left symbol must be an operand and right symbol must be an  operator
    5. ( and ) must be equal in number.
    6. an expression can't begin with operator except ( and ).
    
    */
   int totalOpeningParenthesis=0,totalclosingParanthesis=0;
   int i,totalSymbols;
   int totalDot=0;
   totalSymbols=strlen(expression);
   //check is operation is empty
   if(!expression[0])return 0;

    if(expression[0]!='(' && isOperator(expression[0]))return 0;


    //check is last symbol is operator except )?
    if(expression[totalSymbols-1]!=')' && isOperator(expression[totalSymbols-1]))return totalSymbols-1;

    if(expression[0]=='(')totalOpeningParenthesis++;
    if(expression[totalSymbols-1]==')')totalclosingParanthesis++;
    if(!(isOperator(expression[0])||isOperand(expression[0])))return 0;
    if(!(isOperator(expression[totalSymbols-1])||isOperand(expression[totalSymbols-1])))return totalSymbols-1;

   for(i=1;i<totalSymbols-1;i++)
   {
       if(isOperator(expression[i]))
       {
            if(expression[i]=='(')
            {
                totalOpeningParenthesis++;
                if(!isOperator(expression[i-1])||(expression[i+1]!='('&&isOperator(expression[i+1])))return i;
             }
             else if(expression[i]==')')
             {
                 totalclosingParanthesis++;
                 if(isOperator(expression[i-1])||!isOperator(expression[i+1]))return i;
             }
             else{
                  if(isOperator(expression[i-1])||(expression[i+1]!='('&&isOperator(expression[i+1])))return i;
             }

             totalDot=0;
       }
       else if(!isOperand(expression[i])) return i;
       else
       {
           if(expression[i]=='.')
           {
               totalDot++;
                if(expression[i+1]=='.'||expression[i-1]=='.')return i+1;
                if(totalDot>1)return i;
           }
           
       }
   }
   if(totalOpeningParenthesis!=totalclosingParanthesis)return totalSymbols;

   return -1;

    

    
}

void append(char *string,char ch)
{
    int len=strlen(string);
    string[len]=ch;
    string[len+1]='\0';
}

int getPrecedenceOf(char op)
{
    if(op=='-'||op=='+')
    return 1;
    else if(op=='*'||op=='/')
    return 2;
    else
    return 3;
}

void splitInOperatorAndOperands(char *expression)
{
    /* 
    12+456*2-86=12,+,456,*,2,-,86
    */
   int i;
   char operand[50]="";
   for(i=0;expression[i];i++)
   {
       if(isOperand(expression[i]))
        append(operand,expression[i]);
        else
        {
            if(stricmp(operand,"")!=0)
            printf("%s,",operand);
            printf("%c,",expression[i]);
            strcpy(operand,"");
        }
   }
   printf("%s\n",operand);
}

void infixToPostfix(char *expression,char *postfix)
{
   // char postfix[500]="";
    char operatorStack[50];
    int tos=-1;
    /* 
    12+456*2-86=12,+,456,*,2,-,86
    */
   int i,status;
   char operand[50]="";
   char operator,poppedOperator;
   for(i=0;expression[i];i++)
   {
       if(isOperand(expression[i]))
        append(operand,expression[i]);
        else
        {
            if(stricmp(operand,"")!=0)
            {
                //operand is availabel so append it to postfix
                strcat(postfix,operand);
                strcat(postfix,",");
            }

            //put expression[i] to operator stack
            operator=expression[i];
            if(operator=='(')
            {
                pushChar(operatorStack,&tos,50,operator);
            }
            else if(operator==')')
            {
                //pop symbols from operator stack untill opening paranthesis is found ,
                //append  all popped operator to postfix except opening paranthesis
                status=popChar(operatorStack,&tos,&poppedOperator);
                while(status!=-1&&poppedOperator!='(')
                {
                    //append popped symbol to postfix
                    append(postfix,poppedOperator);
                    append(postfix,',');
                    status=popChar(operatorStack,&tos,&poppedOperator);

                }

            }
            else{
                status=0;
                while(status!=1)
                {
                if(tos==-1||peekChar(operatorStack,tos)=='('||getPrecedenceOf(operator)>getPrecedenceOf(peekChar(operatorStack,tos)))//operator stack is empty
                status=pushChar(operatorStack,&tos,50,operator);
                else                 
                {
                    //pop an operator from stack and append it to postfix
                    popChar(operatorStack,&tos,&poppedOperator);
                    append(postfix,poppedOperator);
                    append(postfix,',');
                }
                }
            }


            strcpy(operand,"");
        }
   }
   strcat(postfix,operand);
   strcat(postfix,",");

   //pop all operator from stack and append it to postfix
   do
   {
    status=popChar(operatorStack,&tos,&poppedOperator);
    if(status)
	{
		append(postfix,poppedOperator);
		append(postfix,',');
	} 
	} while (status!=0);

printf("\n%s",postfix);
  
}