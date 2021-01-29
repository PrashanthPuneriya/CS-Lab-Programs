#include<stdio.h>
#include<stdlib.h>

// Assume all the processes are in ready state i.e. they have arrived.

struct Process {
	char pID[10];
	int order;
	int bt;
	int wt;
	int tat;
};

void findWaitingTime(struct Process p[], int n){
	p[0].wt=0;
	for(int i=1; i<n; i++)
		p[i].wt = p[i-1].wt + p[i-1].bt;
}

void findTurnAroundTime(struct Process p[], int n){
	for(int i=0; i<n; i++)
		p[i].tat = p[i].wt + p[i].bt;
}

void findAvgTime(struct Process p[], int n){
	float totalWT = 0, totalTAT = 0;
	
	findWaitingTime(p, n);
	findTurnAroundTime(p, n);
	
	printf("ProcessID \t Burst Time \t Waiting Time \t TurnAround Time\n");
	for(int i=0; i<n; i++){
		totalWT += p[i].wt;
		totalTAT += p[i].tat;
		printf("%s \t\t %d \t\t %d \t\t %d\n", p[i].pID, p[i].bt, p[i].wt, p[i].tat);
	}
	printf("Average waiting time = %.2f\n", (float)totalWT/(float)n);
	printf("Average turn around time = %.2f\n", (float)totalTAT/(float)n);
}

int main() {
	int n;
	printf("Enter no. of processes :\n");
	scanf("%d", &n);
	struct Process p[n];

	for(int i=0; i<n; i++){
		printf("Enter the processID: ");
		scanf("%s", p[i].pID);
		printf("Enter the order of arrival: ");
		scanf("%d", &p[i].order);
		printf("Enter the burst time: ");
		scanf("%d", &p[i].bt);
	}

	// sort all the processes acc to the order of arrival
	for(int i=0; i<n-1; ++i)
		for(int j=0; j<n-i-1; ++j)
			if(p[j+1].order < p[j].order)
			{
				struct Process tempProcess = p[j];
				p[j] = p[j+1];
				p[j+1] = tempProcess;
			}

	findAvgTime(p, n);
	return 0;
}
