// Vedha Mahadevan
// B23CS1262
// Stack & Queue using Singly LinkList

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *link;
};	

struct node *stackTop = NULL;
struct node *queueFront = NULL;
struct node *queueRear = NULL;

void push(int data){
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->link = stackTop;
	stackTop = newNode;
}

void pop(){
	if(stackTop == NULL){
		printf("Stack UNDERFLOW: Cannot POP\n");
		return ;
	}
	else {
		struct node *temp = stackTop;
		stackTop = stackTop->link;
		printf("Popped Element : %d\n",temp->data);
		free(temp);
	}
}

void displayStack(){
	if(stackTop == NULL){
		printf("Stack is Empty : Cannot DISPLAY\n");
		return ;
	}
	else{
		struct node *temp = stackTop;
		printf("Stack Elements : "); 
		while(temp != NULL){ 
			printf("%d ",temp->data);
			temp = temp->link;
		}
	}
}
	
void enqueue(int data){
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->link = NULL;
	
	if(queueRear==NULL){
		queueFront = queueRear = newNode ; 
	}
	else {
		queueRear->link = newNode;
		queueRear = newNode;
		printf("Enqueued Element = %d",data);
	}
}

void dequeue(){
	if(queueFront == NULL){
		printf("Queue is Empty : Cannot Dequeue");
		return ;
	}
	else{
		struct node *temp = queueFront;
		queueFront = queueFront->link;
		printf("Dequeued Elements : %d",temp->data);
		free(temp);
		if(queueFront == NULL){
			queueRear = NULL;
		}
	}
}

void displayQueue(){
	if(queueFront==NULL){
		printf("Queue is Empty : Cannot Display");
		return ;
	}
	else{
		struct node *temp = queueFront;
		printf("Queue Elements : "); 
		while(temp != NULL){
			printf("%d ",temp->data);
			temp= temp->link;
		}
	}
}

void sop(){
	int choice , data;
	while(1){
		printf("\nStack Operations :");
		printf("\n1. PUSH values to Stack");
		printf("\n2. POP values from Stack");
		printf("\n3. Display Stack");
		printf("\n4. Exit");
		
		printf("\nEnter your choice : ");
		scanf("%d",&choice);	
		
		if(choice==1)
		{
			printf("Enter the data to PUSH : ");
			scanf("%d",&data);
			push(data);
		}
		else if(choice==2)
		{
			pop();
		}
		else if(choice==3)
		{
			displayStack();
		}
		else if(choice==4)
		{
			printf("Exiting the MENU");
			break;
		}
		else
		{
			printf("Invalid Choice");
		}
	}
}

void qop(){
	int choice , data;
	while(1){
		printf("\nQueue Operations :");
		printf("\n1. Enqueue values to Queue");
		printf("\n2. Dequeue values from Queue");
		printf("\n3. Display Queue");
		printf("\n4. Exit");
		
		printf("\nEnter your choice : ");
		scanf("%d",&choice);	
		
		if(choice==1)
		{
			printf("Enter the data to ENQUEUE : ");
			scanf("%d",&data);
			enqueue(data);
		}
		else if(choice==2)
		{
			dequeue();
		}
		else if(choice==3)
		{
			displayQueue();
		}
		else if(choice==4)
		{
			printf("Exiting the MENU");
			break;
		}
		else
		{
			printf("Invalid Choice");
		}
	}
}				

int main() {
	int choice , data;
	
	while(1){
		
		printf("Menu : \n");
		printf("1. Stack Operations\n");
		printf("2. Queue Operations\n");
		printf("3. Exit\n");
		
		printf("Enter Choice : \n");
		scanf("%d" , &choice);
		
		if(choice == 1){
			sop();
		}
		else if(choice == 2){
			qop();
		}
		else if(choice == 3){
			printf("Exiting Main Menu\n");
			break;
		}
		else {
			printf("Invalid CHoice !!\n");
		}
	}
	return 0;
}


/* OUTPUT 

Menu : 
1. Stack Operations
2. Queue Operations
3. Exit
Enter Choice : 
1

Stack Operations :
1. PUSH values to Stack
2. POP values from Stack
3. Display Stack
4. Exit
Enter your choice : 2
Stack UNDERFLOW: Cannot POP

Stack Operations :
1. PUSH values to Stack
2. POP values from Stack
3. Display Stack
4. Exit
Enter your choice : 3
Stack is Empty : Cannot DISPLAY

Stack Operations :
1. PUSH values to Stack
2. POP values from Stack
3. Display Stack
4. Exit
Enter your choice : 1
Enter the data to PUSH : 1

Stack Operations :
1. PUSH values to Stack
2. POP values from Stack
3. Display Stack
4. Exit
Enter your choice : 1
Enter the data to PUSH : 2

Stack Operations :
1. PUSH values to Stack
2. POP values from Stack
3. Display Stack
4. Exit
Enter your choice : 1
Enter the data to PUSH : 3

Stack Operations :
1. PUSH values to Stack
2. POP values from Stack
3. Display Stack
4. Exit
Enter your choice : 3
Stack Elements : 3 2 1 
Stack Operations :
1. PUSH values to Stack
2. POP values from Stack
3. Display Stack
4. Exit
Enter your choice : 2
Popped Element : 3

Stack Operations :
1. PUSH values to Stack
2. POP values from Stack
3. Display Stack
4. Exit
Enter your choice : 3
Stack Elements : 2 1 
Stack Operations :
1. PUSH values to Stack
2. POP values from Stack
3. Display Stack
4. Exit
Enter your choice : 2
Popped Element : 2

Stack Operations :
1. PUSH values to Stack
2. POP values from Stack
3. Display Stack
4. Exit
Enter your choice : 3
Stack Elements : 1 
Stack Operations :
1. PUSH values to Stack
2. POP values from Stack
3. Display Stack
4. Exit
Enter your choice : 2
Popped Element : 1

Stack Operations :
1. PUSH values to Stack
2. POP values from Stack
3. Display Stack
4. Exit
Enter your choice : 3
Stack is Empty : Cannot DISPLAY

Stack Operations :
1. PUSH values to Stack
2. POP values from Stack
3. Display Stack
4. Exit
Enter your choice : 2
Stack UNDERFLOW: Cannot POP

Stack Operations :
1. PUSH values to Stack
2. POP values from Stack
3. Display Stack
4. Exit
Enter your choice : 1
Enter the data to PUSH : 4

Stack Operations :
1. PUSH values to Stack
2. POP values from Stack
3. Display Stack
4. Exit
Enter your choice : 3
Stack Elements : 4 
Stack Operations :
1. PUSH values to Stack
2. POP values from Stack
3. Display Stack
4. Exit
Enter your choice : 4
Exiting the MENUMenu : 
1. Stack Operations
2. Queue Operations
3. Exit
Enter Choice : 
2

Queue Operations :
1. Enqueue values to Queue
2. Dequeue values from Queue
3. Display Queue
4. Exit
Enter your choice : 2
Queue is Empty : Cannot Dequeue
Queue Operations :
1. Enqueue values to Queue
2. Dequeue values from Queue
3. Display Queue
4. Exit
Enter your choice : 3
Queue is Empty : Cannot Display
Queue Operations :
1. Enqueue values to Queue
2. Dequeue values from Queue
3. Display Queue
4. Exit
Enter your choice : 1
Enter the data to ENQUEUE : 1

Queue Operations :
1. Enqueue values to Queue
2. Dequeue values from Queue
3. Display Queue
4. Exit
Enter your choice : 2
Dequeued Elements : 1
Queue Operations :
1. Enqueue values to Queue
2. Dequeue values from Queue
3. Display Queue
4. Exit
Enter your choice : 1
Enter the data to ENQUEUE : 1

Queue Operations :
1. Enqueue values to Queue
2. Dequeue values from Queue
3. Display Queue
4. Exit
Enter your choice : 1
Enter the data to ENQUEUE : 2
Enqueued Element = 2
Queue Operations :
1. Enqueue values to Queue
2. Dequeue values from Queue
3. Display Queue
4. Exit
Enter your choice : 1
Enter the data to ENQUEUE : 3
Enqueued Element = 3
Queue Operations :
1. Enqueue values to Queue
2. Dequeue values from Queue
3. Display Queue
4. Exit
Enter your choice : 3
Queue Elements : 1 2 3 
Queue Operations :
1. Enqueue values to Queue
2. Dequeue values from Queue
3. Display Queue
4. Exit
Enter your choice : 2
Dequeued Elements : 1
Queue Operations :
1. Enqueue values to Queue
2. Dequeue values from Queue
3. Display Queue
4. Exit
Enter your choice : 3
Queue Elements : 2 3 
Queue Operations :
1. Enqueue values to Queue
2. Dequeue values from Queue
3. Display Queue
4. Exit
Enter your choice : 2
Dequeued Elements : 2
Queue Operations :
1. Enqueue values to Queue
2. Dequeue values from Queue
3. Display Queue
4. Exit
Enter your choice : 3
Queue Elements : 3 
Queue Operations :
1. Enqueue values to Queue
2. Dequeue values from Queue
3. Display Queue
4. Exit
Enter your choice : 2
Dequeued Elements : 3
Queue Operations :
1. Enqueue values to Queue
2. Dequeue values from Queue
3. Display Queue
4. Exit
Enter your choice : 3
Queue is Empty : Cannot Display
Queue Operations :
1. Enqueue values to Queue
2. Dequeue values from Queue
3. Display Queue
4. Exit
Enter your choice : 2
Queue is Empty : Cannot Dequeue
Queue Operations :
1. Enqueue values to Queue
2. Dequeue values from Queue
3. Display Queue
4. Exit
Enter your choice : 1
Enter the data to ENQUEUE : 4

Queue Operations :
1. Enqueue values to Queue
2. Dequeue values from Queue
3. Display Queue
4. Exit
Enter your choice : 3
Queue Elements : 4 
Queue Operations :
1. Enqueue values to Queue
2. Dequeue values from Queue
3. Display Queue
4. Exit
Enter your choice : 4
Exiting the MENUMenu : 
1. Stack Operations
2. Queue Operations
3. Exit
Enter Choice : 
3
Exiting Main Menu

*/
