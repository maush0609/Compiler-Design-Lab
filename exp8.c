//arith.l 
//exp8 
%{ 
#include<stdio.h> 
#include"y.tab.h" 
#include<stdlib.h> 
int yyerror(char* s); 
int yylval; 
%} 
%% 
[0-9]+ {return NUMBER;} 
[a-zA-Z]+ {return ID;} 
[ \t]+ {;}/*For skipping whitespaces*/ \n {return 0;} 
. {return yytext[0];} 
%% 
int yywrap() 
{ 
return 1; 
} 
//arith.y 
%{ /* Definition Section*/ 
#include<stdio.h> 
#include<stdlib.h> 
int yylex(void); 
int yyerror(char* s); 
%} 
%token NUMBER ID 
%left '+''-' 
%left '*''/''%' 
%left '('')' 
%% 
/*grammer production rule*/ 
expr: expr '+' expr 
|expr'-'expr 
|expr'*'expr 
|expr'/'expr 
|'-'NUMBER 
|'-'ID 
|'('expr')' 
|NUMBER 
|ID
%% 
int main(){ 
printf("Enter the expression\n"); yyparse(); 
printf("Expression is valid\n"); return 0; 
} 
/* For printing error messages */ 
int yyerror(char* s){ 
printf("\nExpression is invalid"); exit(0); 
} 
//OUTPUT 
1) Enter the expression 
a+b 
Expression is valid 
2) Enter the expression 
)a+b 
Expression is invlid
