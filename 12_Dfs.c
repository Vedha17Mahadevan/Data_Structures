//Vedha Mahadevan
//B23CS1262
//Depth First Search Traversal in Directed Graph

#include <stdio.h>
#include<stdlib.h>

int stack[100];
int top=-1;

struct node{
	int info;
	struct node* link;
};

struct graph{
	int totalVertices;
	int *visited;
	struct graph **adjList;
};

struct node* createNode(int vertex){
	struct node* new = (struct node*)malloc(sizeof(struct node));
	new->info = vertex;
	new->link=NULL;
	return new;
}

struct graph* createGraph(int num_vert){
	struct graph* G =  (struct graph*)malloc(sizeof(struct graph));
	
	G->totalVertices = num_vert;
	G->visited = malloc(num_vert*sizeof(int));
	G->adjList = malloc(num_vert*sizeof(struct node*));
	
	for(int i=0;i<num_vert;i++){
		G->visited[i] = 0;
		G->adjList[i] = NULL;
	}
	return G;
}

void addEdge(struct graph*G,int src,int dest){
	struct node* new = createNode(dest);
	new->link = G->adjList[src];
	G->adjList[src]=new;
}

void dfs(struct graph* G , int source){
	struct node* trav = G->adjList[source];
	struct node* temp = trav;
	G->visited[source]=1;
	stack[++top]=source;
	printf("%d ", stack[top--]);
	while(temp!=NULL){
		stack[++top] = temp->link;
		if(G->visited[temp->info] == 0){
			dfs(G,temp->info);
		}
		temp = temp->link;
	}
}
	
int main(){

	int num_vert,edges,v1,v2,source;
	
	printf("\nEnter number of vertices : "); 
	scanf("%d",&num_vert);
	
	struct graph *G = createGraph(num_vert);
	
	printf("\nEnter number of edges : ");
	scanf("%d",&edges);
	
	printf("\nEnter the edges (v1 v2) \n");
	for(int i=0;i<edges;i++){
		printf("Edge v1 v2 : ");
		scanf("%d%d",&v1,&v2);
		addEdge(G,v1,v2);
	}
	
	printf("\nEnter the source to start the traversal : ");
	scanf("%d",&source);
	
	printf("\nDFS Traversal : ");
	dfs(G,source);
	
	return 0;
}

/* OUTPUT 

Enter number of vertices : 8

Enter number of edges : 11

Enter the edges (v1 v2) 
Edge v1 v2 : 1 2
Edge v1 v2 : 1 3
Edge v1 v2 : 2 4
Edge v1 v2 : 2 5
Edge v1 v2 : 3 4
Edge v1 v2 : 3 6
Edge v1 v2 : 4 8 
Edge v1 v2 : 5 7
Edge v1 v2 : 6 7
Edge v1 v2 : 7 4
Edge v1 v2 : 8 1

Enter the source to start the traversal : 1

DFS Traversal : 1 3 6 7 4 8 2 5


Enter number of vertices : 8

Enter number of edges : 11

Enter the edges (v1 v2) 
Edge v1 v2 : 1 3
Edge v1 v2 : 1 2
Edge v1 v2 : 2 4
Edge v1 v2 : 2 5
Edge v1 v2 : 3 4
Edge v1 v2 : 3 6
Edge v1 v2 : 4 8
Edge v1 v2 : 5 7
Edge v1 v2 : 6 7
Edge v1 v2 : 7 4
Edge v1 v2 : 8 1

Enter the source to start the traversal : 1

DFS Traversal : 1 2 5 7 4 8 3 6


Enter number of vertices : 5

Enter number of edges : 5

Enter the edges (v1 v2) 
Edge v1 v2 : 0 1
Edge v1 v2 : 0 2
Edge v1 v2 : 1 3
Edge v1 v2 : 2 3
Edge v1 v2 : 3 4

Enter the source to start the traversal : 0

DFS Traversal : 0 2 3 4 1


Enter number of vertices : 5

Enter number of edges : 5

Enter the edges (v1 v2) 
Edge v1 v2 : 0 2
Edge v1 v2 : 0 1
Edge v1 v2 : 1 3
Edge v1 v2 : 2 3
Edge v1 v2 : 3 4

Enter the source to start the traversal : 0

DFS Traversal : 0 1 3 4 2

*/
