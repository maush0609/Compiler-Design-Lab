#include<stdio.h>
#include<stdbool.h>
#include<string.h>
void main()
{
char buff[100];
char rules[3][10]={"AEA","BEB","C"};
char stack[100];
int top=-1;
printf("INPUT STRING: ");
scanf("%s", buff);
strcat(buff,"$");
int index = 0;
do
{
if(top!=-1)
{
int i;
for(i=0;i<3;++i)
	if(strstr(stack,rules[i])!=NULL)
		break;
if(i<3){
char*p;
p=strstr(stack,rules[i]);

p[0]='E';
p[1]='\0';
top = (int)(p - stack);
printf("reduction: E->%s\n",rules[i]);
printf("stack:");
for(int j=0;j<=top;j++)
{
printf("%c",stack[j]);
}
printf("\n");
}
else
{
stack[++top]=buff[index++];
stack[top+1]='\0';
printf("pushed %c onto stack\n",buff[index-1]);
printf("stack:");
for(int j=0;j<=top;j++)
{
printf("%c",stack[j]);
}
printf("\n");
}
}

else
{
if(buff[index]=='$')
break;
stack[++top]=buff[index++];
stack[top+1]='\0';
printf("pushed %c onto stack\n",buff[index-1]);
printf("stack:");
for(int j=0;j<=top;j++)
{
printf("%c",stack[j]);
}
printf("\n");
}

}
while(index>0 && buff[index-1]!='$');
if(strcmp(stack,"E$")==0)
	printf("\nstring accepted\n");
else
	printf("\nstring rejected");
}




/*
OUTPUT 


INPUT STRING: ABCBA
pushed A onto stack
stack:A
pushed B onto stack
stack:AB
pushed C onto stack
stack:ABC
reduction: E->C
stack:ABE
pushed B onto stack
stack:ABEB
reduction: E->BEB
stack:AE
pushed A onto stack
stack:AEA
reduction: E->AEA
stack:E
pushed $ onto stack
stack:E$

string accepted

*/


