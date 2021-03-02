// Distance Vector Routing

#include <stdio.h>
#define INFINITY 9999
#define MAX 20

struct node
{
    int dist[MAX];
    int from[MAX];
} rt[MAX];

int main()
{
    int costmat[MAX][MAX];
    int n, i, j, k;

    printf("\nEnter the no. of nodes : ");
    scanf("%d", &n);

    printf("\nEnter the cost matrix :\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &costmat[i][j]);
            if (costmat[i][j] == 0)
                costmat[i][j] = INFINITY;

            rt[i].dist[j] = costmat[i][j];
            rt[i].from[j] = j;
        }
        rt[i].dist[i] = 0;
        rt[i].from[i] = i;
    }

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            for (k = 0; k < n; k++)
                if (rt[i].dist[j] > (costmat[i][k] + rt[k].dist[j]))
                {
                    rt[i].dist[j] = costmat[i][k] + rt[k].dist[j];
                    rt[i].from[j] = k;
                }

    for (i = 0; i < n; i++)
    {
        printf("\n\n For router %d\n", i + 1);
        for (j = 0; j < n; j++)
            printf("\t\nnode%d via-%d Distance %d ", j + 1, rt[i].from[j] + 1, rt[i].dist[j]);
    }
}