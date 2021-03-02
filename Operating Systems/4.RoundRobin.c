#include<stdio.h>
#include<stdlib.h>

// Assume all the processes are in ready state i.e. they have arrived.

struct Process {
	char pID[10];
	int bt;
    int rembt;
	int wt;
	int tat;
};

void findWaitingTime(struct Process p[], int n, int tq) {
    int time = 0;
    while(1) {
        int done = 1;    
        
        for(int i=0; i<n; ++i)
            if(p[i].rembt > 0) {
                done = 0;
                if(p[i].rembt > tq) {
                    time += tq;
                    p[i].rembt -= tq;
                }
                else { // i.e. p[i].rembt is <= tq
                    time += p[i].rembt;
                    p[i].rembt = 0;
                    p[i].wt = time - p[i].bt;
                }
            }

        if(done == 1)
            break;
    }
}

void findTurnAroundTime(struct Process p[], int n){
	for(int i=0; i<n; i++)
		p[i].tat = p[i].wt + p[i].bt;
}

void findAvgTime(struct Process p[], int n, int tq){
	float totalWT = 0, totalTAT = 0;
	
	findWaitingTime(p, n, tq);
	findTurnAroundTime(p, n);
	
	printf("ProcessID \t Burst Time \t Waiting Time \t TurnAround Time\n");
	for(int i=0; i<n; i++){
		totalWT += p[i].wt;
		totalTAT += p[i].tat;
		printf("%s \t\t %d \t\t %d \t\t %d\n", p[i].pID, p[i].bt, p[i].wt, p[i].tat);
	}
	printf("Average waiting time = %f\n", (float)totalWT/(float)n);
	printf("Average turn around time = %f\n", (float)totalTAT/(float)n);
}

int main() {
	int n;
	printf("Enter no. of processes :\n");
	scanf("%d", &n);
	struct Process p[n];

	for(int i=0; i<n; i++){
		printf("Enter the processID :\n");
		scanf("%s", p[i].pID);
		printf("Enter the burst time :\n");
		scanf("%d", &p[i].bt);
        p[i].rembt = p[i].bt;
	}
    int tq;
    printf("Enter the time quantum: ");
    scanf("%d", &tq);
	findAvgTime(p, n, tq);
	return 0;
}