/*Function overloading Example*/
#include<iostream>
#include<cstring>
using namespace std;
int compare(char s1[],char s2[])
{
	return strcmp(s1,s2);
}
int compare(char s1[],char s2[],int length)
{
	return strncmp(s1,s2,length);
}
int compare(char s1[],int fromOfFirstString,char s2[],int fromOfSecondString)
{
	return strcmp(s1+fromOfFirstString,s2+fromOfSecondString);
}
int compare(char s1[],int fromOfFirstString,char s2[],int fromOfSecondString,int length)
{
	return strncmp(s1+fromOfFirstString,s2+fromOfSecondString,length);
}
int compare(char s1[],int i)
{
	char s[100];
	sprintf(s,"%d",i);
	return strcmp(s1,s);
}
int compare(int i,char s1[])
{
	return compare(s1,i);
}
int compare(char s1[],float i)
{
	char s[100];
	sprintf(s,"%f",i);
	return strcmp(s1,s);
}
int compare(float i,char s1[])
{
	return compare(s1,i);
}
int main()
{
	char s1[]="Rahul Kumar",s2[]="Rahul singh";
	if(compare(s1,s2)==0)
	std::cout<<endl<<"Both string has same content";
	else
	std::cout<<endl<<"Both String has different content";
	
	if(compare(s1,s2,5)==0)
	std::cout<<endl<<endl<<"Both string has same content";
	else
	std::cout<<endl<<"Both string has different content";
	
	char s3[]="Aaryan Raj",s4[]="Rahul Raj";
	
	if(compare(s3,s4)==0)
	std::cout<<endl<<endl<<"Both string has same content";
	else
	std::cout<<endl<<"Both string has different content";
	
	if(compare(s3,7,s4,6)==0)
	std::cout<<endl<<endl<<"Both string has same content";
	else
	std::cout<<endl<<"Both string has different content";
	
	
	char s5[]="Ankit Kumar Singh",s6[]="Abhishek Kumar raj";
	if(compare(s1,6,s2,9,5))
	std::cout<<endl<<endl<<"Both string has same content";
	else
	std::cout<<endl<<"Both string has different content";
	
	char str[]="123";
	if(compare(str,124)==0)
	std::cout<<endl<<endl<<"Both string has same content";
	else
	std::cout<<endl<<"Both string has different content";
	
	return 0;
}
