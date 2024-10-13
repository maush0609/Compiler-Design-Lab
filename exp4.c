
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MaxExpessionLen 100
#define MaxTempVariables 50

char expr[MaxExpessionLen];
char temp_vars[MaxTempVariables][4];

int temp_var_count = 0;
FILE *fp;
char* new_temp_var(){

	if(temp_var_count>=MaxTempVariables){
	printf("Error : Too many temporary variables\n");
	exit(1);
	}
	sprintf(temp_vars[temp_var_count],"T%d",temp_var_count+1);
	return temp_vars[temp_var_count++];

}

int precedence(char op){
	switch(op){
	case '-':
	case '+':
		return 1;
	case '/':
	case '*':
		return 2;
	default:
		return 0;
	}

}



char* code_generate(char* expr){
	int len = strlen(expr);
	int paren_count = 0;
	int op_pos = -1;
	int min_preced = 3;
	
	for(int i = len-1;i>=0;i--){
		if(expr[i]==')') paren_count++;
		else if (expr[i]=='(') paren_count--;
		else if(paren_count == 0){
			int prec = precedence(expr[i]);
			if(prec>0 && prec <=min_preced){
				min_preced = prec;
				op_pos = i;
			}
		}
	}
	
	if(op_pos == -1){
		if(expr[0] == '(' && expr[len-1]==')'){
			expr[len-1] = '\0';
			return code_generate(expr+1);
		}
		return expr;
	}
	
	
	char op = expr[op_pos];
	expr[op_pos] = '\0';
	char* left  = code_generate(expr);
	char* right = code_generate(expr+op_pos+1);
	
	char* temp = new_temp_var();
	printf("%s := %s %c %s\t\t\t",temp,left,op,right);
	printf("%c %s %s %s\t\t\t",op,left,right,temp);
	if(strlen(left)>1 && strlen(right)>1)
	    printf("%c (%d) (%d) (%d)\n",op,atoi(left+1)-1,atoi(right+1)-1,atoi(temp+1)-1);
	else if(strlen(left)>1)
	    printf("%c (%d) %s (%d)\n",op,atoi(left+1)-1,right,atoi(temp+1)-1);
	else if(strlen(right)>1)
	    printf("%c %s (%d) (%d)\n",op,left,atoi(right+1)-1,atoi(temp+1)-1);
	else
	    printf("%c %s %s (%d)\n",op,left,right,atoi(temp+1)-1);
	//fclose(fp);
	return temp;
}


int main(){
	fp = fopen("output.txt","w+");
	printf("Intermediate Code Generation\n");
 	printf("Enter expression :\t");
 	if(scanf("%99s",expr)!=1){
 		printf("Error reading input");
 		return 1;
 	}
 	printf("The intermediate code :\n3-address code\t\tQuad\t\t\t\tTriple \n");
 	
 	char* assignment = strchr(expr,'=');
 	
 	if(assignment){
 	
 	*assignment = '\0';
 	char* lhs = expr;
 	char* rhs = assignment + 1;
 	char* result = code_generate(rhs);
 	printf("%s:=%s\n",lhs,result);
 	fprintf(fp,"%s:=%s\n",lhs,result);
 	}else{
 		code_generate(expr);
 	}

return 0;
}

/*	OUTPUT
Intermediate Code Generation
Enter expression :	x+y*z
The intermediate code :
3-address code		Quad				Triple 
T1 := y * z			* y z T1			* y z (0)
T2 := x + T1			+ x T1 T2			+ x (0) (1)
*/
