//DFA for of language{a,b} which accepts all strings with substring  aba
#include<stdio.h>
void main()
{
	char string[10],f='A';
	int i;
	printf("Enter a string of {a,b}:");
	scanf("%s",string);
	for(i=0;string[i]!='\0';i++)
	{
		switch(f)
	{
		case 'A':
		if(string[i]=='a')f='B';
		else if(string[i]=='b')f='A';
		break;
		
		case 'B':
		if(string[i]=='a')f='B';
		else if(string[i]=='b')f='C';
		break;
		
		case 'C':
		if(string[i]=='a')f='D';
		else if(string[i]=='b')f='A';
		break;
		
		case 'D':
		if(string[i]=='a')f='D';
		else if(string[i]=='b')f='D';
		break;
		
		default:
			break;	
		
	}
}
	if(f=='D')
	{
		printf("String Accepted");
		
	}
	else{
		printf("String Not Accepted\n");
	}
		

	
}
