// Vedha Mahadevan
// B23CS1262
// Binary Tree

#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int tree[MAX];

void initializeTree() {
	for(int i=0;i<MAX;i++){
	tree[i] = -1;
	}
}

void insertNode(int data , int index){
	if(index >= MAX){
		printf("Position OUT of Bounds!!");
		return ;
	}
	if( tree[index] = -1){
		tree[index] = data;
		printf("Data %d inserted at %d" , data , index);
	}
	else{
		printf("Position Occupied");
	}
}

void inorderTraversal(int index){
	if(index>=MAX || tree[index] <= 0){
		return;
	}
	else{
		inorderTraversal(2*index+1); //leftsubtree
		printf("%d ",tree[index]);
		inorderTraversal(2*index+2); //rightsubtree
	}
}

void preorderTraversal(int index){
	if(index>=MAX || tree[index] <= 0){
		return;
	}
	else{
		printf("%d ",tree[index]);
		preorderTraversal(2*index+1); //leftsubtree
		preorderTraversal(2*index+2); //rightsubtree
	}
}

void postorderTraversal(int index){
	if(index>=MAX || tree[index] <=0){
		return;
	}
	else{
		postorderTraversal(2*index+1); //leftsubtree
		postorderTraversal(2*index+2); //rightsubtree
		printf("%d ",tree[index]);
	}
}

void levelorderTraversal(){
	printf("Level Order : \n");
	for(int i=0 ; i<=MAX ; i++){
		if(tree[i] > 0){
			printf("%d ",tree[i]);
		}
	}
}

void displayTree(){
	printf("Binary Tree [Array Representation] : \n");
	for(int i=0 ; i<=MAX ; i++){
		if(tree[i] > 0){
			printf("Index : %d | Data : %d\n",i ,tree[i]);
		}
		/*else { 
			printf("Binary Tree : EMPTY\n");
		}*/
	}
}

int main(){
	int choice , data , index;
	while (1){
		printf("\nMenu : \n");
		printf("1. Insert Node\n");
		printf("2. Inorder Traversal\n");
		printf("3. Preorder Traversal\n");
		printf("4. Postorder Traversal\n");
		printf("5. Level Order Traversal\n");
		printf("6. Display Queue\n");
		printf("7. Exit\n");
		
		printf("Enter Choice : ");
		scanf("%d" , &choice);
		
		if (choice==1){
			printf("\nEnter the data value : ");
			scanf("%d",&data);
			printf("\nEnter index : ");
			scanf("%d",&index);
			insertNode(data,index);
		}
		
		else if (choice == 2){
			inorderTraversal(0);
		}
		
		else if(choice == 3){
			preorderTraversal(0);
		}
		
		else if(choice==4){
			postorderTraversal(0);
		}
		
		else if (choice==5){
			levelorderTraversal(0);
		}
		
		else if(choice == 6){
			displayTree();
		}
		
		else if(choice == 7){
			printf("Exiting Menu...\n");
			break;
		}
		
		else{ 
			printf("INVALID choice !!\n");
		}
	}
	return 0;
}

/* OUTPUT

Menu : 
1. Insert Node
2. Inorder Traversal
3. Preorder Traversal
4. Postorder Traversal
5. Level Order Traversal
6. Display Queue
7. Exit
Enter Choice : 1

Enter the data value : 1

Enter index : 0
Data 1 inserted at 0
Menu : 
1. Insert Node
2. Inorder Traversal
3. Preorder Traversal
4. Postorder Traversal
5. Level Order Traversal
6. Display Queue
7. Exit
Enter Choice : 1

Enter the data value : 2

Enter index : 1
Data 2 inserted at 1
Menu : 
1. Insert Node
2. Inorder Traversal
3. Preorder Traversal
4. Postorder Traversal
5. Level Order Traversal
6. Display Queue
7. Exit
Enter Choice : 1

Enter the data value : 3

Enter index : 2
Data 3 inserted at 2
Menu : 
1. Insert Node
2. Inorder Traversal
3. Preorder Traversal
4. Postorder Traversal
5. Level Order Traversal
6. Display Queue
7. Exit
Enter Choice : 1

Enter the data value : 4

Enter index : 3
Data 4 inserted at 3
Menu : 
1. Insert Node
2. Inorder Traversal
3. Preorder Traversal
4. Postorder Traversal
5. Level Order Traversal
6. Display Queue
7. Exit
Enter Choice : 1

Enter the data value : 5

Enter index : 4
Data 5 inserted at 4
Menu : 
1. Insert Node
2. Inorder Traversal
3. Preorder Traversal
4. Postorder Traversal
5. Level Order Traversal
6. Display Queue
7. Exit
Enter Choice : 1

Enter the data value : 6

Enter index : 5
Data 6 inserted at 5
Menu : 
1. Insert Node
2. Inorder Traversal
3. Preorder Traversal
4. Postorder Traversal
5. Level Order Traversal
6. Display Queue
7. Exit
Enter Choice : 1

Enter the data value : 7

Enter index : 6
Data 7 inserted at 6
Menu : 
1. Insert Node
2. Inorder Traversal
3. Preorder Traversal
4. Postorder Traversal
5. Level Order Traversal
6. Display Queue
7. Exit
Enter Choice : 1

Enter the data value : 8

Enter index : 9
Data 8 inserted at 9
Menu : 
1. Insert Node
2. Inorder Traversal
3. Preorder Traversal
4. Postorder Traversal
5. Level Order Traversal
6. Display Queue
7. Exit
Enter Choice : 1

Enter the data value : 9 

Enter index : 13
Data 9 inserted at 13
Menu : 
1. Insert Node
2. Inorder Traversal
3. Preorder Traversal
4. Postorder Traversal
5. Level Order Traversal
6. Display Queue
7. Exit
Enter Choice : 1

Enter the data value : 10

Enter index : 14
Data 10 inserted at 14
Menu : 
1. Insert Node
2. Inorder Traversal
3. Preorder Traversal
4. Postorder Traversal
5. Level Order Traversal
6. Display Queue
7. Exit
Enter Choice : 6
Binary Tree [Array Representation] : 
Index : 0 | Data : 1
Index : 1 | Data : 2
Index : 2 | Data : 3
Index : 3 | Data : 4
Index : 4 | Data : 5
Index : 5 | Data : 6
Index : 6 | Data : 7
Index : 9 | Data : 8
Index : 13 | Data : 9
Index : 14 | Data : 10

Menu : 
1. Insert Node
2. Inorder Traversal
3. Preorder Traversal
4. Postorder Traversal
5. Level Order Traversal
6. Display Queue
7. Exit
Enter Choice : 5
Level Order : 
1 2 3 4 5 6 7 8 9 10 
Menu : 
1. Insert Node
2. Inorder Traversal
3. Preorder Traversal
4. Postorder Traversal
5. Level Order Traversal
6. Display Queue
7. Exit
Enter Choice : 2
4 2 8 5 1 6 3 9 7 10 
Menu : 
1. Insert Node
2. Inorder Traversal
3. Preorder Traversal
4. Postorder Traversal
5. Level Order Traversal
6. Display Queue
7. Exit
Enter Choice : 3
1 2 4 5 8 3 6 7 9 10 
Menu : 
1. Insert Node
2. Inorder Traversal
3. Preorder Traversal
4. Postorder Traversal
5. Level Order Traversal
6. Display Queue
7. Exit
Enter Choice : 4
4 8 5 2 6 9 10 7 3 1 
Menu : 
1. Insert Node
2. Inorder Traversal
3. Preorder Traversal
4. Postorder Traversal
5. Level Order Traversal
6. Display Queue
7. Exit
Enter Choice : 7
Exiting Menu...

*/
