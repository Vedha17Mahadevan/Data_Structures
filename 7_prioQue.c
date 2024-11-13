// Vedha Mahadevan
// B23CS1262
// Priority Queue using a Singly LinkList


#include <stdio.h>
#include <stdlib.h>

struct node {
	int info;
	int p;
	struct node *link;
};

int main() {
	int choice ; 
	struct node *head = (struct node*)malloc(sizeof(struct node));
	
	if(head == NULL){
		printf("Memory allocation FAILED!!!");
	}
	else {
		head->link = NULL;
	}
	
	while(1){
	
		printf("Select Queue Operation\n");
		printf("1. Enqueue\n");
		printf("2. Dequeue\n");
		printf("3. Display Queue\n");
		printf("4. Exit\n");
		
		printf("Enter choice : ");
		scanf("%d",&choice);
		
		if(choice == 1){
			struct node *rear = (struct node*)malloc(sizeof(struct node));
			
			if(head==NULL){
				printf("Memory allocation FAILED!!!");
			}
			
			else{
				int num=0 , pr=0;
				
				printf("Enter value to be enqueued : ");
				scanf("%d",&num);
				rear->info=num;
				
				printf("Enter priority of enqueued value : ");
				scanf("%d",&pr);
				rear->p = pr;
				rear->link = NULL;
				
				if(head->link == NULL){
					head->link = rear;
				}
				else {
					struct node *ptr;
					struct node *ptr1;
					
					ptr = head->link;
					ptr1 = head;
					
					while (ptr != NULL && ptr->p<=rear->p){
						ptr1 = ptr;
						ptr = ptr->link;
					}
					rear->link = ptr;
					ptr1 -> link = rear;
				}
			}
		}
		
		else if(choice ==2){
			struct node *ptr;
			ptr = head->link;
			
			if(ptr==NULL){
				printf("Queue is Empty : Cannot Dequeue\n");
			}
			
			else{
				printf("Deququed element : %d\n",ptr->info);
				head->link = ptr->link;
				free(ptr);
			}
		}	
		
		
		else if(choice == 3){
			struct node *ptr;
			ptr = head->link;
			
			if(ptr==NULL){
				printf("Queue is Empty : Cannot Display\n");
			}
			
			else {
				printf("Queue Elements : \n");
				while (ptr != NULL){
					printf("Info : %d , Priority : %d",ptr->info , ptr->p);
					ptr=ptr->link;
					printf("\n");
				}
			}
			
		}
		
		else if (choice == 4 ){
			printf("Exiting the MENU\n");
			break;
		}
		
		else {
			printf("Invalid Choice !!\n");
		}
	}
	return 0;
}

/* OUTPUT

Select Queue Operation
1. Enqueue
2. Dequeue
3. Display Queue
4. Exit
Enter choice : 2
Queue is Empty : Cannot Dequeue
Select Queue Operation
1. Enqueue
2. Dequeue
3. Display Queue
4. Exit
Enter choice : 3
Queue is Empty : Cannot Display
Select Queue Operation
1. Enqueue
2. Dequeue
3. Display Queue
4. Exit
Enter choice : 1
Enter value to be enqueued : 10
Enter priority of enqueued value : 2
Select Queue Operation
1. Enqueue
2. Dequeue
3. Display Queue
4. Exit
Enter choice : 1
Enter value to be enqueued : 20
Enter priority of enqueued value : 3
Select Queue Operation
1. Enqueue
2. Dequeue
3. Display Queue
4. Exit
Enter choice : 1
Enter value to be enqueued : 30
Enter priority of enqueued value : 1
Select Queue Operation
1. Enqueue
2. Dequeue
3. Display Queue
4. Exit
Enter choice : 3
Queue Elements : 
Info : 30 , Priority : 1
Info : 10 , Priority : 2
Info : 20 , Priority : 3
Select Queue Operation
1. Enqueue
2. Dequeue
3. Display Queue
4. Exit
Enter choice : 2
Deququed element : 30
Select Queue Operation
1. Enqueue
2. Dequeue
3. Display Queue
4. Exit
Enter choice : 3
Queue Elements : 
Info : 10 , Priority : 2
Info : 20 , Priority : 3
Select Queue Operation
1. Enqueue
2. Dequeue
3. Display Queue
4. Exit
Enter choice : 1
Enter value to be enqueued : 40
Enter priority of enqueued value : 2
Select Queue Operation
1. Enqueue
2. Dequeue
3. Display Queue
4. Exit
Enter choice : 3
Queue Elements : 
Info : 10 , Priority : 2
Info : 40 , Priority : 2
Info : 20 , Priority : 3
Select Queue Operation
1. Enqueue
2. Dequeue
3. Display Queue
4. Exit
Enter choice : 2
Deququed element : 10
Select Queue Operation
1. Enqueue
2. Dequeue
3. Display Queue
4. Exit
Enter choice : 3
Queue Elements : 
Info : 40 , Priority : 2
Info : 20 , Priority : 3
Select Queue Operation
1. Enqueue
2. Dequeue
3. Display Queue
4. Exit
Enter choice : 2
Deququed element : 40
Select Queue Operation
1. Enqueue
2. Dequeue
3. Display Queue
4. Exit
Enter choice : 3
Queue Elements : 
Info : 20 , Priority : 3
Select Queue Operation
1. Enqueue
2. Dequeue
3. Display Queue
4. Exit
Enter choice : 2
Deququed element : 20
Select Queue Operation
1. Enqueue
2. Dequeue
3. Display Queue
4. Exit
Enter choice : 3
Queue is Empty : Cannot Display
Select Queue Operation
1. Enqueue
2. Dequeue
3. Display Queue
4. Exit
Enter choice : 2
Queue is Empty : Cannot Dequeue
Select Queue Operation
1. Enqueue
2. Dequeue
3. Display Queue
4. Exit
Enter choice : 1
Enter value to be enqueued : 40
Enter priority of enqueued value : 1
Select Queue Operation
1. Enqueue
2. Dequeue
3. Display Queue
4. Exit
Enter choice : 3
Queue Elements : 
Info : 40 , Priority : 1
Select Queue Operation
1. Enqueue
2. Dequeue
3. Display Queue
4. Exit
Enter choice : 4
Exiting the MENU

*/			
