//exp9 
Yacc.l 
%{ 
#include"y.tab.h" 
%} 
%% 
[a-zA-Z_][a-zA-Z_0-9]* return letter; [0-9] return digit; 
. return yytext[0]; 
\n return 0; 
%% 
int yywrap(){ 
return 1; 
} 
Yacc.y
%{ 
#include<stdio.h> 
int valid =1; 
%} 
%token digit letter 
%% 
start : letter s 
s : letter s 
| digit s 
| 
; 
%% 
int yyerror(){ 
printf("\nIt's not an identifier!!\n"); valid=0; 
return 0; 
} 
int main(){ 
printf("\n Enter the name for testing : "); yyparse(); 
if(valid){ 
printf("\nIt's an identifier!!\n"); 
} 
} 
/*OUTPUT 
Enter the name for testing: abc123 
It’s an identifier 
Enter the name for testing: 123abc 
It’s not an identifier 
