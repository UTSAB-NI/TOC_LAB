//WAP to find prefixes, suffices and substring from given string.
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

void Prefix(char string []){
char prefix[20];

int i,j;
printf("The possible prefix are:\n");

for(i=strlen(string);i>=0;i--){


    for(j=0;j<i;j++){

        prefix[j]=string[j];

    }
    prefix[j]='\0';
    printf("%s\n",prefix);

}
printf("\n");
}

void Suffix(char string[]){

char suffix[20];

int i,j;
static int k;
printf("The possible Suffix are:\n");

for(i=strlen(string);i>=0;i--){

k=0;
    for(j=i;j<=strlen(string);j++){


        suffix[k]=string[j];
            k++;
    }
    suffix[k]='\0';
    printf("%s\n",suffix);
}
printf("\n");
}


void substring(char string[]){
int string_len;
string_len = strlen(string);
printf("The possible substrings are:\n");
    for (int i = 0; i < string_len; i++) {
        for (int j = i; j < string_len; j++) {
            for (int k = i; k <= j; k++) {
                printf("%c", string[k]);
            }
            printf("\n");
        }
}
printf("\n");
}

void main(){
    int choice;
char string[20];
printf("Enter a string: ");
scanf("%s",&string);
printf("\n");
do{
printf("Operation Menu:\n");
printf(" 1.Prefix \n 2.Suffix \n 3.Substrings\n 4.Exit\n");
printf("\n");
printf("Enter choice:");
scanf("%d",&choice);
printf("\n");
switch(choice){
case 1:
Prefix(string);
break;

case 2:
    Suffix(string);
    break;

case 3:
    substring(string);
    break;

case 4:
    printf("Exiting");
    exit(0);
    break;
default:
    printf("Invalid choice!!!");

}
printf("***************************\n");

}while(1);







}
