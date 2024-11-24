//B23CS1262
//Vedha Mahadevan 
//Binary Search createTree

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};


struct node* createTree() {
    struct node* root = (struct node*)malloc(sizeof(struct node));
    int data, choice;

    printf("Enter the data value: ");
    scanf("%d", &data);
    root->data = data;
    root->left = NULL;
    root->right = NULL;

    printf("Is there a LEFT child of %d? Yes = 1 | No = 0\n", data);
    scanf("%d", &choice);
    if (choice == 1) {
        printf("Left Child: ");
        root->left = createTree();
    }

    printf("Is there a RIGHT child of %d? Yes = 1 | No = 0\n", data);
    scanf("%d", &choice);
    if (choice == 1) {
        printf("Right Child: ");
        root->right = createTree();
    }

    return root;
}

void inOrder(struct node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

void preOrder(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}


void postOrder(struct node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}


struct node* minValue(struct node* node) {
    struct node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}


struct node* deleteNode(struct node* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {

        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        struct node* temp = minValue(root->right);
        root->data = temp->data; 
        root->right = deleteNode(root->right, temp->data); 
    }
    return root;
}

int main() {
    struct node* root = NULL;
    int choice, value;

    while (true) {
        printf("\nBinary Search Tree Menu\n");
        printf("1. Create Tree\n");
        printf("2. Delete Node\n");
        printf("3. Preorder Traversal\n");
        printf("4. Inorder Traversal\n");
        printf("5. Postorder Traversal\n");
        printf("6. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                root = createTree();
                printf("Tree Created\n");
                break;
            case 2:
                if (root == NULL) {
                    printf("Tree is Empty\n");
                } else {
                    printf("Enter the value to be Deleted: ");
                    scanf("%d", &value);
                    root = deleteNode(root, value);
                    printf("Deleted element from Binary Search Tree\n");
                }
                break;
            case 3:
                if (root == NULL) {
                    printf("Tree is Empty\n");
                } else {
                    printf("Preorder Traversal: ");
                    preOrder(root);
                    printf("\n");
                }
                break;
            case 4:
                if (root == NULL) {
                    printf("Tree is Empty\n");
                } else {
                    printf("Inorder Traversal: ");
                    inOrder(root);
                    printf("\n");
                }
                break;
            case 5:
                if (root == NULL) {
                    printf("Tree is Empty\n");
                } else {
                    printf("Postorder Traversal: ");
                    postOrder(root);
                    printf("\n");
                }
                break;
            case 6:
                printf("Exiting Menu...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}


/* OUTPUT


Binary Search Tree Menu
1. Create Tree
2. Delete Node
3. Preorder Traversal
4. Inorder Traversal
5. Postorder Traversal
6. Exit
Enter choice: 1
Enter the data value: 100
Is there a LEFT child of 100? Yes = 1 | No = 0
1
Left Child: Enter the data value: 80
Is there a LEFT child of 80? Yes = 1 | No = 0
1
Left Child: Enter the data value: 70
Is there a LEFT child of 70? Yes = 1 | No = 0
1
Left Child: Enter the data value: 40
Is there a LEFT child of 40? Yes = 1 | No = 0
0
Is there a RIGHT child of 40? Yes = 1 | No = 0
0
Is there a RIGHT child of 70? Yes = 1 | No = 0
0
Is there a RIGHT child of 80? Yes = 1 | No = 0
1
Right Child: Enter the data value: 85
Is there a LEFT child of 85? Yes = 1 | No = 0
0
Is there a RIGHT child of 85? Yes = 1 | No = 0
0
Is there a RIGHT child of 100? Yes = 1 | No = 0
1
Right Child: Enter the data value: 110
Is there a LEFT child of 110? Yes = 1 | No = 0
1
Left Child: Enter the data value: 105
Is there a LEFT child of 105? Yes = 1 | No = 0
0
Is there a RIGHT child of 105? Yes = 1 | No = 0
0
Is there a RIGHT child of 110? Yes = 1 | No = 0
1
Right Child: Enter the data value: 120
Is there a LEFT child of 120? Yes = 1 | No = 0
0
Is there a RIGHT child of 120? Yes = 1 | No = 0
0
Tree Created

Binary Search Tree Menu
1. Create Tree
2. Delete Node
3. Preorder Traversal
4. Inorder Traversal
5. Postorder Traversal
6. Exit
Enter choice: 4
Inorder Traversal: 40 70 80 85 100 105 110 120 

Binary Search Tree Menu
1. Create Tree
2. Delete Node
3. Preorder Traversal
4. Inorder Traversal
5. Postorder Traversal
6. Exit
Enter choice: 2
Enter the value to be Deleted: 40
Deleted element from Binary Search Tree

Binary Search Tree Menu
1. Create Tree
2. Delete Node
3. Preorder Traversal
4. Inorder Traversal
5. Postorder Traversal
6. Exit
Enter choice: 4
Inorder Traversal: 70 80 85 100 105 110 120 

Binary Search Tree Menu
1. Create Tree
2. Delete Node
3. Preorder Traversal
4. Inorder Traversal
5. Postorder Traversal
6. Exit
Enter choice: 2
Enter the value to be Deleted: 110
Deleted element from Binary Search Tree

Binary Search Tree Menu
1. Create Tree
2. Delete Node
3. Preorder Traversal
4. Inorder Traversal
5. Postorder Traversal
6. Exit
Enter choice: 4
Inorder Traversal: 70 80 85 100 105 120 

Binary Search Tree Menu
1. Create Tree
2. Delete Node
3. Preorder Traversal
4. Inorder Traversal
5. Postorder Traversal
6. Exit
Enter choice: 2
Enter the value to be Deleted: 100
Deleted element from Binary Search Tree

Binary Search Tree Menu
1. Create Tree
2. Delete Node
3. Preorder Traversal
4. Inorder Traversal
5. Postorder Traversal
6. Exit
Enter choice: 4
Inorder Traversal: 70 80 85 105 120 

Binary Search Tree Menu
1. Create Tree
2. Delete Node
3. Preorder Traversal
4. Inorder Traversal
5. Postorder Traversal
6. Exit
Enter choice: 6
Exiting Menu...

*/
