// Vedha Mahadevan
// B23CS1262
// Infix to Postfix Conversion & Evaluation 

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

int precedence(char op){
	if((op == '+') || (op == '-')){
		return 1;
	}
	else if((op == '*') || (op == '/')){
		return 2;
	}
	else if (op == '^'){
		return 3;
	}
	else{
		return 0;
	}
}

void ip(char infix[],char postfix[]){
	char stack[MAX];
	int top=-1,i=0,j=0;
	while(infix[i] != '\0'){
		if(isalnum(infix[i])){
			postfix[j++] = infix[i];
		}
		else if(infix[i] == '('){
			stack[++top] = infix[i];
		}
		else if (infix[i] == ')'){
			while((top != -1) && (stack[top] != '(')){
				postfix[j++] = stack[top--];
			}
			top--;
		}
		else {
			while(((top != -1) && precedence(stack[top])) >= precedence(infix[i])) {
				postfix[j++] = stack[top--];
			}
			stack[++top] = infix[i];
		}
			i++;
	}
	while (top != -1){
		postfix[j++] = stack[top--];
	}
	postfix[j] = '\0';
}
	

int evaluate(char postfix[]){
	int stack[MAX];
	int top=-1, i=0,j,op1,op2,num=0;
	while(postfix[i] != '\0'){
	 	if(isdigit(postfix[i])){
	 		stack[++top] = postfix[i] - '0';
	 	}
		else {
			op2 = stack[top--];
			op1 = stack[top--];
			
			if (postfix[i]=='+'){
				num = op1 + op2;
				stack[++top] = num;
				printf("sum : %d  ",num);
			}
			else if (postfix[i]=='-'){
				num = op1 - op2;
				stack[++top] = num;
				printf("diff : %d  ",num);
			}
			else if (postfix[i]=='*'){
				num = op1 * op2;
				stack[++top] = num;
				printf("prod : %d  ",num);
			}
			else if (postfix[i]=='/'){
				num = op1 / op2;
				stack[++top] = num;
				printf("div : %d  ",num);
			}
			else if (postfix[i]== '^'){
				num=1;
				for(j=0;j<op2;j++){
					num*=op1;
				}
			stack[++top] = num;
			printf("exp : %d  ",num);
			}
		}
		i++;
	}
	return stack[top];
}

int main() {
	char infix[MAX] , postfix[MAX];
	
	printf("Enter expression : ");
	scanf("%99s",infix);
	ip(infix,postfix);
	printf("Postfix Expression : %s\n",postfix);
	
	int num = evaluate(postfix);
	printf("\nEvaluation : %d\n" , num);
	
	return 0;
}

/* OUTPUT

Enter expression : 3+5*(2-8)
Postfix Expression : 3528-*+
Evaluation : -27

Enter expression : 3+5*(2-8)
Postfix Expression : 3528-*+
Evaluation : -27

Enter expression : 7+(3*(2+1))            
Postfix Expression : 7321+*+
Evaluation : 16

Enter expression : (2+2)^2-(3*2)/2
Postfix Expression : 22+2^32*2/-
Evaluation : 13

Enter expression : (2+2)^2-(3*2)/2
Postfix Expression : 22+2^32*2/-
Evaluation : 13

*/
