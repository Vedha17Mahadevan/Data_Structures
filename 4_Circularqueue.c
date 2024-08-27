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
