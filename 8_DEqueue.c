// Vedha Mahadevan
// B23CS1262
// DEqueue using Doubly Linked List

#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *prev;
	struct node *next;
};

struct node* front = NULL;
struct node* rear = NULL;

void addFront(int data){
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	if(newNode == NULL){
		printf("Memory allocation failed!\n");
		return ;
	}
	else{
		newNode->data = data;
		newNode->prev = NULL;
		newNode->next = front;
		
		if(front == NULL){
			rear = newNode;
		}
		else {
			front->prev = newNode;
		}
		front = newNode;
		printf("\n %d has been inserted at the FRONT\n",data);		 
	}
}

void addRear(int data){
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	if(newNode == NULL){
		printf("Memory allocation failed!\n");
		return ;
	}
	else{
		newNode->data = data;
		newNode->next = NULL;
		newNode->prev = rear;
		
		if(rear == NULL){
			front = newNode;
		}
		else {
			rear->next = newNode;
		}
		rear = newNode;
		printf("\n %d has been inserted at the REAR",data);		 
	}
}

void removeFront(){
	if(front == NULL){
		printf("DeQueue : EMPTY!!!\n");
		return ;
	}
	struct node* temp = front ;
	front = front->next;
	if(front == NULL){
		rear = NULL;
	}else{
		front->prev = NULL;
	}
	printf("\n %d has been deleted from FRONT\n",temp->data);
	free(temp);
}

void removeRear(){
	if(rear == NULL){
		printf("DeQueue : EMPTY!!!\n");
		return ;
	}
	struct node* temp = rear ;
	rear = rear->prev;
	if(rear == NULL){
		front = NULL;
	}else{
		rear->next = NULL;
	}
	printf("\n %d has been deleted from REAR\n",temp->data);
	free(temp);
}


void display (){
	struct node* temp = front;
	if(front==NULL){
		printf("DeQueue : EMPTY\n");
	}
	else{ 
		while(temp != NULL){
			printf("%d",temp->data);
			temp = temp->next;
		}
	}
}

int main() {
	int choice , data;
	
	while(1){
		
		printf("Menu : \n");
		printf("1. Enqueue at FRONT\n");
		printf("2. Enqueue at REAR\n");
		printf("3. Dequeue at FRONT\n");
		printf("4. Dequeue at REAR\n");
		printf("5. Display Queue\n");
		printf("6. Exit\n");
		
		printf("Enter Choice : ");
		scanf("%d" , &choice);
		
		if(choice == 1){
			printf("Enter the data value to ENQUEUE at Front : ");
			scanf("%d",&data);
			addFront(data);
		}
		else if(choice == 2){
			printf("Enter the data value to ENQUEUE at Rear : ");
			scanf("%d",&data);
			addRear(data);
		}
		else if(choice == 3){
			removeFront();
		}
		else if(choice == 4){
			removeRear();
		}
		else if(choice == 5){
			display();
		}
		else if(choice == 6){
			printf("Exiting Main Menu\n");
			break;
		}
		else {
			printf("Invalid Choice !!\n");
		}
	}
	return 0;
}

/* OUTPUT

Menu : 
1. Enqueue at FRONT
2. Enqueue at REAR
3. Dequeue at FRONT
4. Dequeue at REAR
5. Display Queue
6. Exit
Enter Choice : 3
DeQueue : EMPTY!!!
Menu : 
1. Enqueue at FRONT
2. Enqueue at REAR
3. Dequeue at FRONT
4. Dequeue at REAR
5. Display Queue
6. Exit
Enter Choice : 4
DeQueue : EMPTY!!!
Menu : 
1. Enqueue at FRONT
2. Enqueue at REAR
3. Dequeue at FRONT
4. Dequeue at REAR
5. Display Queue
6. Exit
Enter Choice : 5
DeQueue : EMPTY
Menu : 
1. Enqueue at FRONT
2. Enqueue at REAR
3. Dequeue at FRONT
4. Dequeue at REAR
5. Display Queue
6. Exit
Enter Choice : 1
Enter the data value to ENQUEUE at Front : 1

 1 has been inserted at the FRONT
Menu : 
1. Enqueue at FRONT
2. Enqueue at REAR
3. Dequeue at FRONT
4. Dequeue at REAR
5. Display Queue
6. Exit
Enter Choice : 2
Enter the data value to ENQUEUE at Rear : 2

 2 has been inserted at the REARMenu : 
1. Enqueue at FRONT
2. Enqueue at REAR
3. Dequeue at FRONT
4. Dequeue at REAR
5. Display Queue
6. Exit
Enter Choice : 5
12Menu : 
1. Enqueue at FRONT
2. Enqueue at REAR
3. Dequeue at FRONT
4. Dequeue at REAR
5. Display Queue
6. Exit
Enter Choice : 1
Enter the data value to ENQUEUE at Front : 3

 3 has been inserted at the FRONT
Menu : 
1. Enqueue at FRONT
2. Enqueue at REAR
3. Dequeue at FRONT
4. Dequeue at REAR
5. Display Queue
6. Exit
Enter Choice : 2
Enter the data value to ENQUEUE at Rear : 4

 4 has been inserted at the REARMenu : 
1. Enqueue at FRONT
2. Enqueue at REAR
3. Dequeue at FRONT
4. Dequeue at REAR
5. Display Queue
6. Exit
Enter Choice : 5
3124Menu : 
1. Enqueue at FRONT
2. Enqueue at REAR
3. Dequeue at FRONT
4. Dequeue at REAR
5. Display Queue
6. Exit
Enter Choice : 3

 3 has been deleted from FRONT
Menu : 
1. Enqueue at FRONT
2. Enqueue at REAR
3. Dequeue at FRONT
4. Dequeue at REAR
5. Display Queue
6. Exit
Enter Choice : 5
124Menu : 
1. Enqueue at FRONT
2. Enqueue at REAR
3. Dequeue at FRONT
4. Dequeue at REAR
5. Display Queue
6. Exit
Enter Choice : 4

 4 has been deleted from REAR
Menu : 
1. Enqueue at FRONT
2. Enqueue at REAR
3. Dequeue at FRONT
4. Dequeue at REAR
5. Display Queue
6. Exit
Enter Choice : 5
12Menu : 
1. Enqueue at FRONT
2. Enqueue at REAR
3. Dequeue at FRONT
4. Dequeue at REAR
5. Display Queue
6. Exit
Enter Choice : 3

 1 has been deleted from FRONT
Menu : 
1. Enqueue at FRONT
2. Enqueue at REAR
3. Dequeue at FRONT
4. Dequeue at REAR
5. Display Queue
6. Exit
Enter Choice : 5
2Menu : 
1. Enqueue at FRONT
2. Enqueue at REAR
3. Dequeue at FRONT
4. Dequeue at REAR
5. Display Queue
6. Exit
Enter Choice : 4

 2 has been deleted from REAR
Menu : 
1. Enqueue at FRONT
2. Enqueue at REAR
3. Dequeue at FRONT
4. Dequeue at REAR
5. Display Queue
6. Exit
Enter Choice : 5
DeQueue : EMPTY
Menu : 
1. Enqueue at FRONT
2. Enqueue at REAR
3. Dequeue at FRONT
4. Dequeue at REAR
5. Display Queue
6. Exit
Enter Choice : 3
DeQueue : EMPTY!!!
Menu : 
1. Enqueue at FRONT
2. Enqueue at REAR
3. Dequeue at FRONT
4. Dequeue at REAR
5. Display Queue
6. Exit
Enter Choice : 4
DeQueue : EMPTY!!!
Menu : 
1. Enqueue at FRONT
2. Enqueue at REAR
3. Dequeue at FRONT
4. Dequeue at REAR
5. Display Queue
6. Exit
Enter Choice : 1
Enter the data value to ENQUEUE at Front : 1

 1 has been inserted at the FRONT
Menu : 
1. Enqueue at FRONT
2. Enqueue at REAR
3. Dequeue at FRONT
4. Dequeue at REAR
5. Display Queue
6. Exit
Enter Choice : 2
Enter the data value to ENQUEUE at Rear : 2

 2 has been inserted at the REARMenu : 
1. Enqueue at FRONT
2. Enqueue at REAR
3. Dequeue at FRONT
4. Dequeue at REAR
5. Display Queue
6. Exit
Enter Choice : 5
12Menu : 
1. Enqueue at FRONT
2. Enqueue at REAR
3. Dequeue at FRONT
4. Dequeue at REAR
5. Display Queue
6. Exit
Enter Choice : 6
Exiting Main Menu

*/
