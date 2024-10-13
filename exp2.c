#include<stdio.h>
#include<string.h>
int i;
char s[10];
int A()
{
if(s[i]=='a')
{
	printf("A->aA\n");
	i++;
	A();
}
else
{
	printf("A->e\n");
}
}
int B()
{
if(s[i]=='b')
{	
	i++;
	if(s[i]=='b')
	{
	printf("B->bbB\n");
	i++;
	B();
	}
	else
	{
	return 1;
	}
}
else
{
printf("B->e\n");
return 0;
}
}
int S()
{
int temp=3;
if(s[i]=='a')
{
	
	i++;
	if(s[i]=='a')
	{
		
		i++;
		if(s[i]=='b')
		{
			printf("S->aab\n");
			i++;
			A();
			temp=B();
			if(temp==1)
			{
				return 0;
			}
			if(s[i]=='$')
			{
				printf("\nString Accepted\n");
				return 1;
			}
			else
			{
			return 0;
			}
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}
else
{
	return 0;
}
}
void main()
{
char c;
printf("Enter the String:");
scanf("%s",s);
int z;
z=S();
if(z==0)
{
printf("\nNot accepted\n");
}
}






#include<stdio.h>
#include<string.h>
int i;
char s[10];
int A()
{
if(s[i]=='a')
{
	printf("A->aA\n");
	i++;
	A();
}
else
{
	printf("A->e\n");
}
}
int B()
{
if(s[i]=='b')
{	
	i++;
	if(s[i]=='b')
	{
	printf("B->bbB\n");
	i++;
	B();
	}
	else
	{
	return 1;
	}
}
else
{
printf("B->e\n");
return 0;
}
}
int S()
{
int temp=3;
if(s[i]=='a')
{
	
	i++;
	if(s[i]=='a')
	{
		
		i++;
		if(s[i]=='b')
		{
			printf("S->aab\n");
			i++;
			A();
			temp=B();
			if(temp==1)
			{
				return 0;
			}
			if(s[i]=='$')
			{
				printf("\nString Accepted\n");
				return 1;
			}
			else
			{
			return 0;
			}
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}
else
{
	return 0;
}
}
void main()
{
char c;
printf("Enter the String:");
scanf("%s",s);
int z;
z=S();
if(z==0)
{
printf("\nNot accepted\n");
}
}








