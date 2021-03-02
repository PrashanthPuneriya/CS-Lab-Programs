#include<stdio.h>
#include<stdlib.h>

// COMPLETED

struct Process {
	char pID[10]; // process ID
	int at; // arrival time
	int bt; // burst time
    int ct; // completion time
	int tat; // turn around time
    int wt; // waiting time
};

void findCompletionTime(struct Process p[], int n) {
    // compute from gantt char
    p[0].ct = p[0].at + p[0].bt;
    for(int i=1; i<n; ++i) {
        if(p[i].at < p[i-1].ct) {
            // wait until p[i-1] has completed its execution
            p[i].ct = p[i-1].ct + p[i].bt;
        }
        else {
            p[i].ct = p[i].at + p[i].bt;
        }
    }
}

void findTurnAroundTime(struct Process p[], int n){
	for(int i=0; i<n; ++i)
		p[i].tat = p[i].ct - p[i].at;
}

void findWaitingTime(struct Process p[], int n){
	for(int i=0; i<n; ++i)
		p[i].wt = p[i].tat - p[i].bt;
}


void findAvgTime(struct Process p[], int n){
	float totalWT = 0, totalTAT = 0;

    findCompletionTime(p, n);
	findTurnAroundTime(p, n);	
	findWaitingTime(p, n);
	
	printf("ProcessID \t Arrival Time \t Burst Time \t Completion Time \t Turn Around Time \t Waiting Time\n");
	for(int i=0; i<n; ++i){
		totalWT += p[i].wt;
		totalTAT += p[i].tat;
		printf("%s \t\t %d \t\t %d \t\t %d \t\t\t %d \t\t\t %d\n", p[i].pID, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
	}
	printf("Average waiting time = %.2f\n", (float)totalWT/(float)n);
	printf("Average turn around time = %.2f\n", (float)totalTAT/(float)n);
}

int main() {
	int n;
	printf("Enter no. of processes :");
	scanf("%d", &n);
	struct Process p[n];

	for(int i=0; i<n; ++i){
		printf("Enter the processID: ");
		scanf("%s", p[i].pID);
		printf("Enter the arrival time: ");
		scanf("%d", &p[i].at);
		printf("Enter the burst time: ");
		scanf("%d", &p[i].bt);
	}

	// sort all the processes acc to the arrival time.
	for(int i=0; i<n-1; ++i)
		for(int j=0; j<n-i-1; ++j)
			if(p[j+1].at < p[j].at)
			{
				struct Process tempProcess = p[j];
				p[j] = p[j+1];
				p[j+1] = tempProcess;
			}

	findAvgTime(p, n);
	return 0;
}
