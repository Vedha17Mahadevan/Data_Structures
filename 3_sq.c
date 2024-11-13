// Vedha Mahadevan
// B23CS1262
// Menu Driven : STACK & QUEUE

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
	if(rear>=queue_size)
	{
		printf("Queue Overflow : Cannot ENQUEUE value");
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
		printf("Queue Underflow : Cannot DEQUEUE value");
		front=0;
		rear=0;
		return -1;
		
	}
	else
	{	
		return queue[front++];
		if(front==rear){
			front=0;
			rear=0;
		}
	}

}

void printQueue()				//Print Queue
{
	if(front==rear)
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

/* OUTPUT

Enter the size of Stack : 5
Enter the size of Queue : 5
Menu : 
1. STACK
2. QUEUE
3. Exit
Enter your choice : 1

Stack Operations :
1. PUSH values to Stack
2. POP values from Stack
3. Display Stack
4. Exit
Enter your choice : 2
Stack Underflow : Cannot POP value
Do you wish to continue?(0=yes/1=no)0

Stack Operations :
1. PUSH values to Stack
2. POP values from Stack
3. Display Stack
4. Exit
Enter your choice : 3
Stack is empty
Do you wish to continue?(0=yes/1=no)0

Stack Operations :
1. PUSH values to Stack
2. POP values from Stack
3. Display Stack
4. Exit
Enter your choice : 1
Enter the value : 1
Pushed value : 1
Do you wish to continue?(0=yes/1=no)0

Stack Operations :
1. PUSH values to Stack
2. POP values from Stack
3. Display Stack
4. Exit
Enter your choice : 1
Enter the value : 2
Pushed value : 2
Do you wish to continue?(0=yes/1=no)0

Stack Operations :
1. PUSH values to Stack
2. POP values from Stack
3. Display Stack
4. Exit
Enter your choice : 1
Enter the value : 3
Pushed value : 3
Do you wish to continue?(0=yes/1=no)0

Stack Operations :
1. PUSH values to Stack
2. POP values from Stack
3. Display Stack
4. Exit
Enter your choice : 1 
Enter the value : 4
Pushed value : 4
Do you wish to continue?(0=yes/1=no)0

Stack Operations :
1. PUSH values to Stack
2. POP values from Stack
3. Display Stack
4. Exit
Enter your choice : 1
Enter the value : 5
Pushed value : 5
Do you wish to continue?(0=yes/1=no)0

Stack Operations :
1. PUSH values to Stack
2. POP values from Stack
3. Display Stack
4. Exit
Enter your choice : 1
Enter the value : 6
Stack Overflow : Cannot PUSH value
Do you wish to continue?(0=yes/1=no)0

Stack Operations :
1. PUSH values to Stack
2. POP values from Stack
3. Display Stack
4. Exit
Enter your choice : 3
Stack : 5 4 3 2 1 
Do you wish to continue?(0=yes/1=no)0

Stack Operations :
1. PUSH values to Stack
2. POP values from Stack
3. Display Stack
4. Exit
Enter your choice : 2
The Popped element is : 5
Do you wish to continue?(0=yes/1=no)0

Stack Operations :
1. PUSH values to Stack
2. POP values from Stack
3. Display Stack
4. Exit
Enter your choice : 3
Stack : 4 3 2 1 
Do you wish to continue?(0=yes/1=no)0

Stack Operations :
1. PUSH values to Stack
2. POP values from Stack
3. Display Stack
4. Exit
Enter your choice : 2
The Popped element is : 4
Do you wish to continue?(0=yes/1=no)0

Stack Operations :
1. PUSH values to Stack
2. POP values from Stack
3. Display Stack
4. Exit
Enter your choice : 2
The Popped element is : 3
Do you wish to continue?(0=yes/1=no)0

Stack Operations :
1. PUSH values to Stack
2. POP values from Stack
3. Display Stack
4. Exit
Enter your choice : 2
The Popped element is : 2
Do you wish to continue?(0=yes/1=no)0

Stack Operations :
1. PUSH values to Stack
2. POP values from Stack
3. Display Stack
4. Exit
Enter your choice : 2
The Popped element is : 1
Do you wish to continue?(0=yes/1=no)0

Stack Operations :
1. PUSH values to Stack
2. POP values from Stack
3. Display Stack
4. Exit
Enter your choice : 2
Stack Underflow : Cannot POP value
Do you wish to continue?(0=yes/1=no)0

Stack Operations :
1. PUSH values to Stack
2. POP values from Stack
3. Display Stack
4. Exit
Enter your choice : 3
Stack is empty
Do you wish to continue?(0=yes/1=no)0

Stack Operations :
1. PUSH values to Stack
2. POP values from Stack
3. Display Stack
4. Exit
Enter your choice : 1
Enter the value : 6
Pushed value : 6
Do you wish to continue?(0=yes/1=no)0

Stack Operations :
1. PUSH values to Stack
2. POP values from Stack
3. Display Stack
4. Exit
Enter your choice : 1
Enter the value : 7
Pushed value : 7
Do you wish to continue?(0=yes/1=no)0

Stack Operations :
1. PUSH values to Stack
2. POP values from Stack
3. Display Stack
4. Exit
Enter your choice : 3
Stack : 7 6 
Do you wish to continue?(0=yes/1=no)0

Stack Operations :
1. PUSH values to Stack
2. POP values from Stack
3. Display Stack
4. Exit
Enter your choice : 2
The Popped element is : 7
Do you wish to continue?(0=yes/1=no)0

Stack Operations :
1. PUSH values to Stack
2. POP values from Stack
3. Display Stack
4. Exit
Enter your choice : 3
Stack : 6 
Do you wish to continue?(0=yes/1=no)0

Stack Operations :
1. PUSH values to Stack
2. POP values from Stack
3. Display Stack
4. Exit
Enter your choice : 2
The Popped element is : 6
Do you wish to continue?(0=yes/1=no)0

Stack Operations :
1. PUSH values to Stack
2. POP values from Stack
3. Display Stack
4. Exit
Enter your choice : 3
Stack is empty
Do you wish to continue?(0=yes/1=no)0

Stack Operations :
1. PUSH values to Stack
2. POP values from Stack
3. Display Stack
4. Exit
Enter your choice : 4
Exiting the MENU
Do you wish to continue?(0=yes/1=no)0
Menu : 
1. STACK
2. QUEUE
3. Exit
Enter your choice : 2
Menu : 
Queue Operations : 
1. Enqueue values to Queue
2. Dequeue values from Queue
3. Display Queue
4. Exit
Enter your choice : 2
Queue Underflow : Cannot DEQUEUE value
Do you wish to continue?(0=yes/1=no)0
Menu : 
Queue Operations : 
1. Enqueue values to Queue
2. Dequeue values from Queue
3. Display Queue
4. Exit
Enter your choice : 3
Queue is empty
Do you wish to continue?(0=yes/1=no)0
Menu : 
Queue Operations : 
1. Enqueue values to Queue
2. Dequeue values from Queue
3. Display Queue
4. Exit
Enter your choice : 1
Enter the value : 1
Enqueued value : 1
Do you wish to continue?(0=yes/1=no)0
Menu : 
Queue Operations : 
1. Enqueue values to Queue
2. Dequeue values from Queue
3. Display Queue
4. Exit
Enter your choice : 1
Enter the value : 2
Enqueued value : 2
Do you wish to continue?(0=yes/1=no)0
Menu : 
Queue Operations : 
1. Enqueue values to Queue
2. Dequeue values from Queue
3. Display Queue
4. Exit
Enter your choice : 3
Queue : 1 2 

Do you wish to continue?(0=yes/1=no)0
Menu : 
Queue Operations : 
1. Enqueue values to Queue
2. Dequeue values from Queue
3. Display Queue
4. Exit
Enter your choice : 1
Enter the value : 3
Enqueued value : 3
Do you wish to continue?(0=yes/1=no)0
Menu : 
Queue Operations : 
1. Enqueue values to Queue
2. Dequeue values from Queue
3. Display Queue
4. Exit
Enter your choice : 1
Enter the value : 4
Enqueued value : 4
Do you wish to continue?(0=yes/1=no)0
Menu : 
Queue Operations : 
1. Enqueue values to Queue
2. Dequeue values from Queue
3. Display Queue
4. Exit
Enter your choice : 1
Enter the value : 5
Enqueued value : 5
Do you wish to continue?(0=yes/1=no)0
Menu : 
Queue Operations : 
1. Enqueue values to Queue
2. Dequeue values from Queue
3. Display Queue
4. Exit
Enter your choice : 3
Queue : 1 2 3 4 5 

Do you wish to continue?(0=yes/1=no)0
Menu : 
Queue Operations : 
1. Enqueue values to Queue
2. Dequeue values from Queue
3. Display Queue
4. Exit
Enter your choice : 1
Enter the value : 6
Queue Overflow : Cannot ENQUEUE value
Do you wish to continue?(0=yes/1=no)0
Menu : 
Queue Operations : 
1. Enqueue values to Queue
2. Dequeue values from Queue
3. Display Queue
4. Exit
Enter your choice : 2
The Dequeued element is : 1
Do you wish to continue?(0=yes/1=no)0
Menu : 
Queue Operations : 
1. Enqueue values to Queue
2. Dequeue values from Queue
3. Display Queue
4. Exit
Enter your choice : 3
Queue : 2 3 4 5 

Do you wish to continue?(0=yes/1=no)0
Menu : 
Queue Operations : 
1. Enqueue values to Queue
2. Dequeue values from Queue
3. Display Queue
4. Exit
Enter your choice : 2
The Dequeued element is : 2
Do you wish to continue?(0=yes/1=no)0
Menu : 
Queue Operations : 
1. Enqueue values to Queue
2. Dequeue values from Queue
3. Display Queue
4. Exit
Enter your choice : 2
The Dequeued element is : 3
Do you wish to continue?(0=yes/1=no)0
Menu : 
Queue Operations : 
1. Enqueue values to Queue
2. Dequeue values from Queue
3. Display Queue
4. Exit
Enter your choice : 2
The Dequeued element is : 4
Do you wish to continue?(0=yes/1=no)0
Menu : 
Queue Operations : 
1. Enqueue values to Queue
2. Dequeue values from Queue
3. Display Queue
4. Exit
Enter your choice : 2
The Dequeued element is : 5
Do you wish to continue?(0=yes/1=no)0
Menu : 
Queue Operations : 
1. Enqueue values to Queue
2. Dequeue values from Queue
3. Display Queue
4. Exit
Enter your choice : 2
Queue Underflow : Cannot DEQUEUE value
Do you wish to continue?(0=yes/1=no)0
Menu : 
Queue Operations : 
1. Enqueue values to Queue
2. Dequeue values from Queue
3. Display Queue
4. Exit
Enter your choice : 1
Enter the value : 7
Enqueued value : 7
Do you wish to continue?(0=yes/1=no)0
Menu : 
Queue Operations : 
1. Enqueue values to Queue
2. Dequeue values from Queue
3. Display Queue
4. Exit
Enter your choice : 3
Queue : 7 

Do you wish to continue?(0=yes/1=no)0
Menu : 
Queue Operations : 
1. Enqueue values to Queue
2. Dequeue values from Queue
3. Display Queue
4. Exit
Enter your choice : 2
The Dequeued element is : 7
Do you wish to continue?(0=yes/1=no)0
Menu : 
Queue Operations : 
1. Enqueue values to Queue
2. Dequeue values from Queue
3. Display Queue
4. Exit
Enter your choice : 3
Queue is empty
Do you wish to continue?(0=yes/1=no)0
Menu : 
Queue Operations : 
1. Enqueue values to Queue
2. Dequeue values from Queue
3. Display Queue
4. Exit
Enter your choice : 2
Queue Underflow : Cannot DEQUEUE value
Do you wish to continue?(0=yes/1=no)0
Menu : 
Queue Operations : 
1. Enqueue values to Queue
2. Dequeue values from Queue
3. Display Queue
4. Exit
Enter your choice : 4
Exiting the MENU
Do you wish to continue?(0=yes/1=no)0
Menu : 
1. STACK
2. QUEUE
3. Exit
Enter your choice : 3
Exiting the MENU

*/
