#include <stdio.h>
int main()
{
	// P0, P1, P2, P3, P4 are the Process names here

	int n, m, i, j, k;
	int alloc[100][100], max[100][100], avail[100];

	printf("Enter no. of processes: ");
	scanf("%d", &n);
	printf("Enter no. of resources :");
	scanf("%d", &m);

	printf("Enter Allocation Matrix");
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			scanf("%d", &alloc[i][j]);
	
	printf("Enter Max Matrix");
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			scanf("%d", &max[i][j]);

	printf("Enter Avail:");
	for (i = 0; i < m; i++)
		scanf("%d", &avail[i]);

	// Need Matrix
	int need[n][m];
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			need[i][j] = max[i][j] - alloc[i][j];

	// f[n] == finished process or not?
	int f[n], ans[n], ind = 0;
	for (k = 0; k < n; k++)
		f[k] = 0;

	int y = 0;
	for (k = 0; k < n; k++)
		for (i = 0; i < n; i++)
			if (f[i] == 0) // process is not finished
			{
				int flag = 1; // resources are available or not?
				for (j = 0; j < m; j++)
					if (avail[j] < need[i][j])
					{
						flag = 0; // resources are not available so we can't execute process[i]
						break;
					}

				if (flag == 1)
				{
					ans[ind++] = i;
					for (y = 0; y < m; y++)
						avail[y] += alloc[i][y]; // release the resources
					f[i] = 1;
				}
			}

	printf("Following is the SAFE Sequence\n");
	for (i = 0; i < n; i++)
		printf(" P%d ->", ans[i]);

	return 0;
}