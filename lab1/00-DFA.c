//DFA for of language{0,1} which accepts all strings ending with 00
#include<stdio.h>
int main()
{
	char string[10],f='A';
	int i;
	printf("Enter a string of {0,1}:");
	scanf("%s",string);
	for(i=0;string[i]!='\0';i++)
	{
		switch(f)
	{
		case 'A':
		if(string[i]=='0')f='B';
		else if(string[i]=='1')f='A';
		break;
		
		case 'B':
		if(string[i]=='0')f='C';
		else if(string[i]=='1')f='A';
		break;
		
		case 'C':
		if(string[i]=='0')f='C';
		else if(string[i]=='1')f='A';
		break;
		
		default:
			break;	
		
	}
}
	if(f=='C')
	{
		printf("String Accepted");
		
	}
	else{
		printf("String Not Accepted\n");
	}
		return 0;

	
}
