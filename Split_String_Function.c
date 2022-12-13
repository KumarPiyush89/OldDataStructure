
#include<stdio.h>
#include<string.h>
int splitString(char *str,char seperator,char splitStrings[][100])
{
    
    char splitedString[100];
   
    char *previousPosition,*foundat;
    int numberOfcharacterTosplit;
    int totalString=0,i;

    previousPosition=str;
    while((*previousPosition)!='\0')
    {
        strcpy(splitedString,"");
        //1.find the position of seperator in string from freviousPosition
        foundat=strchr(previousPosition,seperator);
        
        if(foundat!=NULL)
        {
            //find total number of character to extract
            numberOfcharacterTosplit=foundat-previousPosition;
            if(numberOfcharacterTosplit>0)
            {
                strncpy(splitedString,previousPosition,numberOfcharacterTosplit);
                splitedString[numberOfcharacterTosplit]='\0';
               
            }
             previousPosition=foundat+1;

        }
        else
        {
            strcpy(splitedString,previousPosition);
            previousPosition=previousPosition+strlen(previousPosition);
        }

        //store splited string if found
        if(strcmp(splitedString,"")!=0)
        {
            strcpy(splitStrings[totalString++],splitedString);
        }
    }
    
    return totalString;  
}