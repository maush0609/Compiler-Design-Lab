
%{
	#include<stdio.h>
	int vowels=0;
	int consonants=0;
%}
%%
[aeiouAEIOU]	{
		vowels++;
}
[a-zA-Z]	{
		consonants++;
}
%%

int main(){
	FILE*infile=fopen("inp.txt","r");
	FILE*outfile=fopen("oup.txt","w");
	
	yyin=infile;
	yylex();
	
	fprintf(outfile,"no vowels %d\n",vowels);
	fprintf(outfile,"no of consonants %d\n",consonants);
	
	fclose(infile);
	fclose(outfile);
	return 0;
}
int yywrap(){
	return 1;
}

INPUT
maushmi is here

OUTPUT
no vowels 6
no of consonants 7
