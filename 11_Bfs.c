//B23CS1262
//Vedha Mahadevan
//Breadth First Search (BFS) : Traversal of Graph

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX] , queue[MAX];
int front=-1 , rear=-1;

void enqueue(int vertex){
	if(rear == MAX-1){
		printf("Overflow!!!");
		return ;
	}
	if(front == -1){
		front = 0;
	}
	queue[++rear] = vertex;
}

int dequeue(){
	if(front == -1 && front >= rear){
		printf("Queue Underflow\n");
		return -1;
	}
	else{
		return queue[front++];
	}
}

void bfs(int startVertex , int n){
	int i;
	enqueue(startVertex);
	visited[startVertex] = 1;
	printf("\nBFS Traversal : ");
	while(front<=rear){
		int currentVertex = dequeue();
		printf("%d ",currentVertex);
		for(i=0;i<n;i++){
			if(adj[currentVertex][i] = 1 && visited[i] ==0){
				enqueue(i);
				visited[i]=1;
			}
		}
	}
	printf("\n");
}

void main() {
	int i,j,n,startVertex,e1,e;
	
	printf("Enter no. of vertices : ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			adj[i][j]=0;
		}
	}
	
	printf("\nReading Adjacency Matrix : \n");
	for(i=0;i<n;i++){
		printf("Enter the no. of edge from %d : ",i);
		scanf("%d",&e);
		for(j=0;j<e;j++){
			printf("Enter edge : ");
			scanf("%d",&e1);
			adj[i][e1]=1;
		}
	}
	
	printf("\nAdjacency Matrix : \n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d ",adj[i][j]);
		}
		printf("\n");
	}
	
	printf("\nEnter Starting Vertex : ");
	scanf("%d",&startVertex);
	
	for(i=0;i<MAX;i++){
		visited[i] = 0;
	}
	
	bfs(startVertex,n);
}

/* OUTPUT

Enter no. of vertices : 6

Reading Adjacency Matrix : 
Enter the no. of edge from 0 : 1
Enter edge : 1
Enter the no. of edge from 1 : 2
Enter edge : 2
Enter edge : 3
Enter the no. of edge from 2 : 2
Enter edge : 1
Enter edge : 4
Enter the no. of edge from 3 : 2
Enter edge : 1
Enter edge : 4
Enter the no. of edge from 4 : 3
Enter edge : 2
Enter edge : 3
Enter edge : 5
Enter the no. of edge from 5 : 1
Enter edge : 4

Adjacency Matrix : 
0 1 0 0 0 0 
0 0 1 1 0 0 
0 1 0 0 1 0 
0 1 0 0 1 0 
0 0 1 1 0 1 
0 0 0 0 1 0 

Enter Starting Vertex : 0

BFS Traversal : 0 1 2 3 4 5 

*/


