// Vedha Mahadevan
// B23CS1262
// Polynomial - Sum and Product

#include<stdio.h>

void main()
{
	int a[100],b[100],aexp[100],bexp[100],acoe[100],bcoe[100],r[100],p[200];
	int n1,n2,max1=0,max2=0,d,i,j;
	//reading no.of terms
	printf("Enter the number of terms of Polynomial_1 : ");
	scanf("%d",&n1);
	printf("Enter the number of terms of Polynomial_2 : ");
	scanf("%d",&n2);
	
	//reading terms
	printf("Enter the Coefficients and Exponents for Polynomial_1 : ");
	for(i=0;i<n1;i++){
		printf("\nEnter the Coefficient of term %d : ",i+1);
		scanf("%d",&acoe[i]);
		printf("Enter the Exponent of term %d : ",i+1);
		scanf("%d",&aexp[i]);
		if(aexp[i]>max1){
			max1=aexp[i];
		}
	}	
	printf("Enter the Coefficients and Exponents for Polynomial_2 : ");
	for(i=0;i<n2;i++){
		printf("\nEnter the Coefficient of term %d : ",i+1);
		scanf("%d",&bcoe[i]);
		printf("Enter the Exponent of term %d : ",i+1);
		scanf("%d",&bexp[i]);
		if(bexp[i]>max2){
			max2=bexp[i];
		}
	}
	
	d = (max1>max2)? max1:max2;
	
	for(i=d;i>=0;i--)
	{	
		a[i]=0;
		b[i]=0;
	}
	
	for(i=0;i<= max1+max2;i++)
	{	
		p[i]=0;
	}
	
	for(i=0;i<n1;i++)
	{
		a[aexp[i]] = acoe[i];
	
	}
	
	for(i=0;i<n2;i++)
	{
		b[bexp[i]] = bcoe[i];
	
	}
	
	for(i=0;i<=d;i++)
	{
		r[i]=a[i]+b[i];
	}
	
	for(i=0;i<=max1;i++){
		for(j=0;j<=max2;j++){
			p[i+j]+=a[i]*b[j];
		}
	}
	
	printf("\n Polynomial Addition : ");
	int flag=1;
	for(i=d;i>=0;i--){
		if(r[i]!=0){
			if(flag){
				if(i==0){
					printf("%d",r[i]);
				}
				else if(i==1){
					printf("%dx",r[i]);
				}
				else{
					printf("%dx^%d",r[i],i);
				}
				flag=0;
			}else{
				if(r[i]>0){
					if(i==0){
						printf("+%d",r[i]);
					}
					else if(i==1){
						printf("+%dx",r[i]);
					}
					else{
						printf("+%dx^%d",r[i],i);
					}
				}
				else{
					if(i==0){
						printf("%d",r[i]);
					}
					else if(i==1){
						printf("%dx",r[i]);
					}
					else{
						printf("%dx^%d",r[i],i);
					}
				}
			}
		}
	}
		
	
	printf("\n Polynomial Multiplication : ");
	int flag1 = 1;
	for(i=max1+max2;i>=0;i--){
		if(p[i]!=0){
			if(flag1){
				if(i==0){
					printf("%d",p[i]);
				}
				else if(i==1){
					printf("%dx",p[i]);
				}
				else{
					printf("%dx^%d",p[i],i);
				}
				flag1=0;
			}else{
				if(p[i]>0){
					if(i==0){
						printf("+%d",p[i]);
					}
					else if(i==1){
						printf("+%dx",p[i]);
					}
					else{
						printf("+%dx^%d",p[i],i);
					}
				}
				else{
					if(i==0){
						printf("%d",p[i]);
					}
					else if(i==1){
						printf("%dx",p[i]);
					}
					else{
						printf("%dx^%d",p[i],i);
					}
				}
			}
		}
	}
}


/* OUTPUT

Enter the number of terms of Polynomial_1 : 2
Enter the number of terms of Polynomial_2 : 4
Enter the Coefficients and Exponents for Polynomial_1 : 
Enter the Coefficient of term 1 : -2
Enter the Exponent of term 1 : 8

Enter the Coefficient of term 2 : -5
Enter the Exponent of term 2 : 4
Enter the Coefficients and Exponents for Polynomial_2 : 
Enter the Coefficient of term 1 : 1
Enter the Exponent of term 1 : 7

Enter the Coefficient of term 2 : 2
Enter the Exponent of term 2 : 4

Enter the Coefficient of term 3 : -3
Enter the Exponent of term 3 : 2

Enter the Coefficient of term 4 : 2
Enter the Exponent of term 4 : 0

 Polynomial Addition : -2x^8+1x^7-3x^4-3x^2+2
 Polynomial Multiplication : -2x^15-4x^12-5x^11+6x^10-14x^8+15x^6-10x^4
 
*/


/*
// Vedha Mahadevan
// B23CS1262
// Infix to Postfix Conversion & Evaluation (2)

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
			}
			else if (postfix[i]=='-'){
				num = op1 - op2;
			}
			else if (postfix[i]=='*'){
				num = op1 * op2;
			}
			else if (postfix[i]=='/'){
				num = op1 / op2;
			}
			else if (postfix[i]== '^'){
				num=1;
				for(j=0;j<op2;j++){
					num*=op1;
				}
			}
			stack[++top] = num;
			}
			i++;
	}
	return stack[top];
}

int main() {
	char infix[MAX] , postfix[MAX];
	
	printf("Enter expression : ");
	scanf("99%s",infix);
	ip(infix,postfix);
	printf("Postfix Expression : %s\n",postfix);
	
	int num = evaluate(postfix);
	printf("Evaluation : %d\n" , num);
	
	return 0;
}

*/
