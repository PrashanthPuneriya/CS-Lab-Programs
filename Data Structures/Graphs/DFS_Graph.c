#include<stdio.h>
#include<stdlib.h>

struct Stack { 
    int top; 
    int capacity; 
    int* array; 
};
// Create Stack
struct Stack* CreateStack(int capacity) { 
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    if(!stack) // Stack is not Created
        return NULL; 

    stack->top = -1; 
    stack->capacity = capacity; 
    stack->array = (int*) malloc(stack->capacity * sizeof(int)); //Integer Array
  
    if(!stack->array) // Array is not Created 
        return NULL;

    return stack; 
}

// Push to the Stack
void Push(struct Stack* stack, int node) {
    stack->array[++stack->top] = node;
}
// Pop from the Stack
int Pop(struct Stack* stack) {
        return stack->array[stack->top--];
}

int isEmpty(struct Stack* stack) {
    if(stack->top == -1)
        return 1;
    else return 0;
}

int main() {
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

	// Create stack
	struct Stack* stack = CreateStack(n_vertices); //stack size won't be more than the no.of vertices

	printf("Enter Starting Vertex:\n");
	scanf("%d", &node);

    visited[node] = 1;
    Push(stack, node);

	
	while(!isEmpty(stack)) 
    {	
        node = Pop(stack);
        printf("%d ", node);

		for(i=0; i<n_vertices; i++) // Push all the vertices which are connected to i
			if(Cost[node][i] == 1 /*Are connected*/ && visited[i] == 0 /*Not visited*/)
            {   
                visited[node] = 1;
                Push(stack, i);
            }     
	}

    return 0;
}
