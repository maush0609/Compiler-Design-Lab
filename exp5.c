%{
	#include<stdio.h>
	int lines=0;
	int words=0;
	int capital_letter=0;
	int small_letter=0;
	int special_char=0;
	int characters=0;
	int number=0;
%}
%%
[a-z]	{
	small_letter++;
}
[A-Z]	{
	capital_letter++;
}
[0-9]	{
	number++;
}
[*+^&!#.]	{
	special_char++;
}			
[\n\t]	{
	words++;
	if(yytext[0]=='\n') lines++;
}
%%
int main(){
		FILE *infile=fopen("ip.txt","r");
		FILE *outfile=fopen("op.txt","w");
		int total;
		yyin=infile;
		yylex();
		
		total=small_letter+capital_letter+number+special_char;
		fprintf(outfile," no. of lines%d\n",lines);
		fprintf(outfile," no. of words%d\n",words);
		fprintf(outfile," no. of characters%d\n",total);
		fprintf(outfile," no. of small letters%d\n",small_letter);
		fprintf(outfile," no. of capital letters%d\n",capital_letter);
		fprintf(outfile," no. of special characters%d\n",special_char);
		fprintf(outfile," no. of numbers%d\n",number);
		fclose(infile);
		fclose(outfile);
		return 0;
		
}
int yywrap(){
return 1;
}	


INPUT
dazai
is
good

OUTPUT
 no. of lines3
 no. of words3
 no. of characters11
 no. of small letters11
 no. of capital letters0
 no. of special characters0
 no. of numbers0
