#include<stdio.h>
#include<stdlib.h>

struct Queue { 
    int front, rear; 
    int capacity; 
    int* array; 
};
// Create Queue
struct Queue* CreateQueue(int capacity) { 
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    if(!queue) // Queue is not Created
        return NULL; 
	
    queue->front = 0;  	 //Dequeue
	queue->rear = -1;    //Enqueue
    queue->capacity = capacity;

    queue->array = (int*)malloc(queue->capacity*sizeof(int)); //Integer Array
    if(!queue->array) // Array is not Created 
        return NULL;
	
    return queue;
}

void EnQueue(struct Queue* queue, int node) {
	queue->rear++;
	queue->array[queue->rear] = node;
}

int DeQueue(struct Queue* queue) {
	int node=0;
	node = queue->array[queue->front];
	queue->front++;
	return node;
}

int isEmpty(struct Queue* queue) {
    if(queue->front > queue->rear)
        return 1;
    else 
        return 0;
}

int main() 
{
	int n_vertices=0, n_edges=0, node=0;
	printf("Enter no.of vertices and edges:\n");
	scanf("%d %d", &n_vertices, &n_edges);
	
	// Adjaceny Matrix
	int Cost[n_vertices][n_vertices];
	int i=0, j=0, visited[n_vertices];
	
    // Initializing the 2D-Matrix to value 0
	for(i=0; i<n_vertices; i++) 
    {
        visited[i] = 0;
		for(j=0; j<n_vertices; j++)
			Cost[i][j] = 0;
	}

	printf("Enter the connected vertices index where indexing starts from zero:\n");
	for(i=0; i<n_edges; i++)
    {
        int a=0, b=0;
		scanf("%d%d", &a, &b);
		Cost[a][b] = 1; // Un-directed Graph
		Cost[b][a] = 1;
	}

	// Create Queue
	struct Queue* queue = CreateQueue(n_vertices); //Queue size won't be more than the no.of vertices

	printf("Enter Starting Vertex:\n");
	scanf("%d", &node);

    EnQueue(queue, node);
	visited[node] = 1;
	
	while(!isEmpty(queue)) 
    {	
        node = DeQueue(queue);
        printf("%d ", node);

		for(i=0; i<n_vertices; i++) // Enqueue all the vertices which are connected to i
			if(Cost[node][i] == 1 /*Are connected*/ && visited[i] == 0 /*Not visited*/)
			{
				EnQueue(queue, i);
				visited[node] = 1;
			}
	}

    return 0;
}