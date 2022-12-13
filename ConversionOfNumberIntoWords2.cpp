//cpp program that converts digits into word.
#include<iostream>
#include<ctype.h>
#include<string>
using namespace std;
string numberName(int number)
{
	string onesDigit[]={"zero","one","two","three","four","Five","six","seven","eight","Nine","ten"
	,"eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
	
	string tensDigit[]={"","","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
	
	string nName="";
	number=number%100;
	
	if(number<20)
	{
		nName=onesDigit[number];
	}
	else
	{
		nName=tensDigit[number/10];
		if(number%10)
		{
			nName+=" ";
			nName+=onesDigit[number%10];
		}
	}

	return nName;
}
string ConvertIntoWord(string numbers)
{
	
    string digitName[]={"mahashankh","shankh","padma","neel","kharab","arab","crore","lakh","thousand","hundred",""};    
    int num[11]={0},i,j;
    
    char str[20]="";
    //convert string into numbers.
    int length=numbers.length();
    if(length>20)
    length=20;
    
    for(i=0;i<20-length;i++)
    str[i]='0';
    for(j=0;j<length;j++)
    str[i++]=numbers[j];
    str[i]='\0';
    
    
    sscanf(str,"%1d %2d %2d %2d %2d %2d %2d %2d %2d %1d %2d",&num[0],&num[1],&num[2],&num[3],&num[4],&num[5],&num[6],&num[7],&num[8],&num[9],&num[10]);
		
	int ones,tens;
	string wordString;
	for(i=0;i<11;i++)
	{
		if(num[i])
		{
			if(!wordString.empty())
			wordString+=" ";
			
			wordString+=numberName(num[i]);
			wordString+=" ";
			wordString+=digitName[i];
		}
		
	}
	
	if(wordString.empty())
	   	wordString.append("Zero ");
		wordString.append(".");
	return wordString;
}
/*string RemoveCharExceptNumber(string str)
{
	int i=0,j=0;
	do
	{
		if(isdigit(str[i]))
		{
			str[j++]=str[i];
		}
		i++;
		
	}while(str[j]!='\0');
	
	return str;
 }*/ 

int main()
{
	string str;
	cout<<"Enter Number(max 20 char and only numbers): ";
	getline(cin,str);

	//remove characters from string except numeric value.
	//str=RemoveCharExceptNumber(str); 
	
	//check after filtration string is empty or not.
	if(str.empty())
	{
		cout<<endl<<"Sorry, the given string is empty or not any numeric character";
		return 0;
	}
	
	//convert number string into word.
	//the function is only able to convert for max 20chars.
	//str[20]='\0';
	cout<<endl<<str<<" = "<<ConvertIntoWord(str);
	return 0;
}
