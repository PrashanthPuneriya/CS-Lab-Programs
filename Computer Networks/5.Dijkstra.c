#include <stdio.h>
#define INFINITY 9999
#define MAX 10

void dijkstra(int G[MAX][MAX], int n, int startNode);

int main()
{
	int G[MAX][MAX], i, j, n, u;
	printf("Enter no. of vertices:");
	scanf("%d", &n);
	printf("\nEnter the adjacency matrix:\n");

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			scanf("%d", &G[i][j]);

	printf("\nEnter the starting node:");
	scanf("%d", &u);
	dijkstra(G, n, u);

	return 0;
}

void dijkstra(int G[MAX][MAX], int n, int startNode)
{
	int cost[MAX][MAX], distance[MAX], visited[MAX], pred[MAX];
	int count, minDist, nextNode, i, j;

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (G[i][j] == 0)
				cost[i][j] = INFINITY;
			else
				cost[i][j] = G[i][j];

	//initialize pred[], distance[] and visited[]
	for (i = 0; i < n; i++)
	{
		distance[i] = cost[startNode][i];
		pred[i] = startNode;
		visited[i] = 0;
	}

	distance[startNode] = 0;
	visited[startNode] = 1;
	count = 1;

	while (count < n - 1)
	{
		minDist = INFINITY;

		//nextNode gives the node at minimum distance
		for (i = 0; i < n; i++)
			if (distance[i] < minDist && !visited[i])
			{
				minDist = distance[i];
				nextNode = i;
			}

		//check if a better path exists through nextNode
		visited[nextNode] = 1;
		for (i = 0; i < n; i++)
			if (!visited[i])
				if (minDist + cost[nextNode][i] < distance[i])
				{
					distance[i] = minDist + cost[nextNode][i];
					pred[i] = nextNode;
				}
		count++;
	}

	//print the path and distance of each node
	for (i = 0; i < n; i++)
		if (i != startNode)
		{
			printf("\nDistance of node%d = %d. ", i, distance[i]);
			printf("Path = %d", i);

			j = i;
			do
			{
				j = pred[j];
				printf("<-%d", j);
			} while (j != startNode);
		}
}