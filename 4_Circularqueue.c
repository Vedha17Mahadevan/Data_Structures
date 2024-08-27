// Vedha Mahadevan
// B23CS1262
// Circular Queue

# include <stdio.h>
# include <stdlib.h>

int isFull(int front,int rear,int n);
int isEmpty(int front);
void enqueue(int value,int n,int queue[]);
int dequeue(int n,int queue[]);
void display(int queue[],int n);

int front=-1,rear=-1;

int main(){
	int n,ch,value,ans;
	
	printf("Enter the no. of elements : ");
	scanf("%d",&n);
	
	int queue[n];
	
	do{
		printf("Menu");
		printf("\n1. Enqueue");
		printf("\n2. Dequeue");
		printf("\n3. Display");
		printf("\n4. Exit");
		
		printf("\nEnter choice : ");
		scanf("%d",&ch);
		
		if(ch==1){
			printf("\nEnter value : ");
			scanf("%d",&value);
			enqueue(value,n,queue);
		}
		
		else if(ch==2){
			value=dequeue(n,queue);
			if(value!=-1){
				printf("\nDequeued element : %d",value);
			}
		}
		
		else if(ch==3){
			display(queue,n);
		}
		else if(ch==4){
			printf("\nExiting");
			break;
		}
		else{
			printf("\nInvalid choice");
		}
		
		printf("\nDo you wish to continue : 1=YES , 0=NO");
		scanf("%d",&ans);
	}
	while(ans==1);
}

int isFull(int front,int rear,int n){
	return (front==(rear+1)%n);
}

int isEmpty(int front){
	return (front==-1);
}

void enqueue(int value,int n,int queue[]){
	if(isFull(front,rear,n)){
		printf("Queue is full");
		return;
	}
	if(isEmpty(front)){
		front=0;
	}
	rear=(rear+1)%n;
	queue[rear]=value;
	printf("Enqueued Value : %d",value);
	/*else{
		rear=(rear+1)%n;
		queue[rear]=value;
		printf("Enqueued Value : %d",value);
	}*/
}

int dequeue(int n,int queue[]){
	if(isEmpty(front)){
		printf("Queue is Empty");
		return -1;
	}
	int value=queue[front];
	if(front==rear){
		front=-1;
		rear=-1;
	}
	else{
		front=(front+1)%n;
	}
	return value;
	
}

void display(int queue[],int n){

	if(isEmpty(front)){
		printf("Queue is Empty");
		return; 
	}
	else{
		printf("Queue Elements : ");
		int i=front;
		while(1){
			printf("%d ",queue[i]);
			if(i==rear){
				break;
			}
			else{
				i=(i+1)%n;
			}
		}
		printf("\n");
	}
}

/*OUTPUT

Enter the no. of elements : 5
Menu
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice : 2
Queue is Empty
Do you wish to continue : 1=YES , 0=NO1
Menu
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice : 3
Queue is Empty
Do you wish to continue : 1=YES , 0=NO1
Menu
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice : 1

Enter value : 1
Enqueued Value : 1
Do you wish to continue : 1=YES , 0=NO1
Menu
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice : 1

Enter value : 2
Enqueued Value : 2
Do you wish to continue : 1=YES , 0=NO1
Menu
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice : 1

Enter value : 3
Enqueued Value : 3
Do you wish to continue : 1=YES , 0=NO1
Menu
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice : 1

Enter value : 4
Enqueued Value : 4
Do you wish to continue : 1=YES , 0=NO1
Menu
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice : 1

Enter value : 5
Enqueued Value : 5
Do you wish to continue : 1=YES , 0=NO1
Menu
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice : 1

Enter value : 6
Queue is full
Do you wish to continue : 1=YES , 0=NO1
Menu
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice : 3
Queue Elements : 1 2 3 4 5 

Do you wish to continue : 1=YES , 0=NO1
Menu
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice : 2

Dequeued element : 1
Do you wish to continue : 1=YES , 0=NO1
Menu
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice : 3
Queue Elements : 2 3 4 5 

Do you wish to continue : 1=YES , 0=NO1
Menu
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice : 2

Dequeued element : 2
Do you wish to continue : 1=YES , 0=NO1
Menu
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice : 3
Queue Elements : 3 4 5 

Do you wish to continue : 1=YES , 0=NO1
Menu
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice : 1

Enter value : 6
Enqueued Value : 6
Do you wish to continue : 1=YES , 0=NO1
Menu
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice : 3
Queue Elements : 3 4 5 6 

Do you wish to continue : 1=YES , 0=NO1
Menu
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice : 1

Enter value : 7
Enqueued Value : 7
Do you wish to continue : 1=YES , 0=NO1
Menu
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice : 3
Queue Elements : 3 4 5 6 7 

Do you wish to continue : 1=YES , 0=NO1
Menu
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice : 2

Dequeued element : 3
Do you wish to continue : 1=YES , 0=NO1
Menu
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice : 3
Queue Elements : 4 5 6 7 

Do you wish to continue : 1=YES , 0=NO1
Menu
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice : 2

Dequeued element : 4
Do you wish to continue : 1=YES , 0=NO1
Menu
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice : 2

Dequeued element : 5
Do you wish to continue : 1=YES , 0=NO1
Menu
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice : 2

Dequeued element : 6
Do you wish to continue : 1=YES , 0=NO1
Menu
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice : 3
Queue Elements : 7 

Do you wish to continue : 1=YES , 0=NO1
Menu
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice : 2

Dequeued element : 7
Do you wish to continue : 1=YES , 0=NO1
Menu
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice : 2
Queue is Empty
Do you wish to continue : 1=YES , 0=NO1
Menu
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice : 3
Queue is Empty
Do you wish to continue : 1=YES , 0=NO1
Menu
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice : 1

Enter value : 8
Enqueued Value : 8
Do you wish to continue : 1=YES , 0=NO1
Menu
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice : 3
Queue Elements : 8 

Do you wish to continue : 1=YES , 0=NO1
Menu
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice : 2

Dequeued element : 8
Do you wish to continue : 1=YES , 0=NO1
Menu
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice : 2
Queue is Empty
Do you wish to continue : 1=YES , 0=NO1
Menu
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice : 3
Queue is Empty
Do you wish to continue : 1=YES , 0=NO1
Menu
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice : 4

Exiting

*/


*****************************************************************************************************************************

/*Polynomial Addition and Multiplication (code:1)

#include<stdio.h>

void main()
{
	int a[100],b[100],aexp[100],bexp[100],acoe[100],bcoe[100],r[100],p[100];
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
	
	d = max1>max2? max1:max2;
	
	for(i=d;i>=0;i--)
	{	
		a[i]=0;
		b[i]=0;
	}
	
	for(i=0;i<= max1+max2;i++)
	{	
		p[i]=0;
	}
	
	for(i=0;i<=n1;i++)
	{
		a[aexp[i]] = acoe[i];
	
	}
	
	for(i=0;i<=n2;i++)
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
				printf("%dx^%d",r[i],i);
				flag=0;
			}
			else{
				if(r[i]>0)
				{
					printf("+%dx^%d",r[i],i);
				}
				else{
					printf("%dx^%d",r[i],i);
				}
			}
		}
	}
		
	
	printf("\n Polynomial Multiplication : ");
	int flag1 = 1;
	for(i=max1+max2;i>=0;i--){
		if(p[i]!=0){
			if(flag1){
				printf("%dx^%d",p[i],i);
				flag1=0;
			}
			else{
				if(r[i]>0)
				{
					printf("+%dx^%d",p[i],i);
				}
				else{
					printf("%dx^%d",p[i],i);
				}
			}
		}
	}
}

***********************************************************************************************************************************

#include<stdio.h>
#define MAX_SIZE 100

void push(int value);
int pop();
void printStack();
int enqueue(int value);
int dequeue();
void printQueue();

int stack[MAX_SIZE];								//Stack initialization
int top=-1;
int stack_size;

int queue[MAX_SIZE];								//Queue initialization
int front=0,rear=0;	
int queue_size;

int main()
{
	int choice_1,choice_2,ans,value,num_values;
	
	printf("Enter the size of Stack : ");				//sizes of Stack and Queue
	scanf("%d",&stack_size);
	printf("Enter the size of Queue : ");
	scanf("%d",&queue_size);
	
	do{								//Menu-Driven-1
		printf("Menu : ");
		printf("\n1. STACK");
		printf("\n2. QUEUE");
		printf("\n3. Exit");
		
		printf("\nEnter your choice : ");
		scanf("%d",&choice_1);		
		
		if(choice_1==1)
		{
			do{						//Menu-Driven-1				
				printf("\nStack Operations :");
				printf("\n1. PUSH values to Stack");
				printf("\n2. POP values from Stack");
				printf("\n3. Display Stack");
				printf("\n4. Exit");
				
				printf("\nEnter your choice : ");
				scanf("%d",&choice_2);	
				
				if(choice_2==1)
				 {
				 	printf("Enter the value : ");
				 	scanf("%d",&value);
				 	push(value);
				 }
				 else if(choice_2==2)
				 {
				 	value=pop();
				 	if(value!=-1)
				 	{
				 		printf("The Popped element is : %d",value);
				 	}
				 }
				 else if(choice_2==3)
				 {
				 	printStack();
				 }
				 else if(choice_2==4)
				 {
				 	printf("Exiting the MENU");
				 	break;
				 }
				 else
				 {
				 	printf("Invalid Choice");
				 }
				 
				 printf("\nDo you wish to continue?(0=yes/1=no)");
				 scanf("%d",&ans);
			  }
			  
			  while(ans==0);
		}
		
		else if(choice_1==2)
		{
			do
			{
				printf("Menu : ");				
				printf("\nQueue Operations : ");
				printf("\n1. Enqueue values to Queue");
				printf("\n2. Dequeue values from Queue");
				printf("\n3. Display Queue");
				printf("\n4. Exit");
								
				printf("\nEnter your choice : ");
				scanf("%d",&choice_2);
				if(choice_2==1)
				{
				 	printf("Enter the value : ");
				 	scanf("%d",&value);
				 	enqueue(value);
				 }
				 else if (choice_2==2)
				 {
				 	value=dequeue();
				 	if(value!=-1)
				 	{
				 		printf("The Dequeued element is : %d",value);
				 	}
				 }
				 else if(choice_2==3)
				 {
				 	printQueue();
				 }
				 else if(choice_2==4)
				 {
				 	printf("Exiting the MENU");
				 	break;
				 }
				 else
				 {
				 	printf("Invalid Choice");
				 }
				 
				 printf("\nDo you wish to continue?(0=yes/1=no)");
				 scanf("%d",&ans);
			  }
		  
		  	while(ans==0);
		}
		else if(choice_1==3)
		{
		 	printf("Exiting the MENU");
		 	break;
		}
		else
		{
			printf("Invalid Choice");
		}
 
		printf("\nDo you wish to continue?(0=yes/1=no)");
		scanf("%d",&ans);
	}
	while(ans==0);
	return 0;
}

void push(int value)				//PUSH-STACK
{
	if(top==stack_size-1)
	{
		printf("Stack Overflow : Cannot PUSH value");
	}
	else
	{
		top+=1;
		stack[top]=value;
		printf("Pushed value : %d",value);
	}
}

int pop()					//POP-STACK
{
	if(top<0)
	{
		printf("Stack Underflow : Cannot POP value");
		return -1;
	}
	else
	{
		return stack[top--];
	}
}

void printStack()				//Print STACK
{
	if (top<0)
	{
		printf("Stack is empty");
	}
	else
	{
		printf("Stack : ");
		for(int i=top;i>=0;i--)
		{
			printf("%d ",stack[i]);
		}
	}
}

int enqueue(int value)				//ENQUEUE-QUEUE
{
	if(rear>=queue_size-1)
	{
		printf("Queue is full");
		return -1;
	}
	else
	{
		queue[rear++]=value;
		printf("Enqueued value : %d",value);
	}
}

int dequeue()					//DEQUEUE-QUEUE
{
	if(front==rear)
	{
		printf("Queue is empty");
		return -1;
		
	}
	else
	{	
		return queue[front++];
	}

}

void printQueue()				//Print Queue
{
	if(front==0)
	{
		printf("Queue is empty");
	}
	else
	{
		printf("Queue : ");
		for(int i=front;i<rear;i++)
		{
			printf("%d ",queue[i]);
		}
		printf("\n");
	}
}

*/

