 int pushChar(char *stack,int *tos,int cap,char ch)
{
if(*tos==cap-1)return 0;//stack overflow
++(*tos);
stack[*tos]=ch;
return 1;
}

int popChar(char *stack,int *tos,char *ch)
{
    if(*tos==-1)return 0;//stack underflow
    *ch=stack[*tos];
    --(*tos);
    return 1;
}

char peekChar(char *stack,int tos)
{
    return stack[tos];
}