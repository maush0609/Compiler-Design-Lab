%{
	#include<stdio.h>
	char a[10];
	int count=0;
%}
%%

[a-z]	{yytext[0]=yytext[0]-32;
	printf("%c",yytext[0]);	
	a[count]=yytext[0];
	count++;
}
[A-Z] {yytext[0]=yytext[0]+32;
	printf("%c",yytext[0]);
	a[count]=yytext[0];
	count++;
}	
%%

int main(){
	FILE*infile=fopen("ip2.txt","r");
	FILE*outfile=fopen("op2.txt","w");
	
	yyin=infile;
	yylex();
	
	fprintf(outfile,"%s\n",a);
	
	fclose(infile);
	fclose(outfile);
	return 0;
}
int yywrap(){
	return 1;
}

INPUT
maushMi

OUTPUT
MAUSHmI
