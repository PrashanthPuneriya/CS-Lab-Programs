#include<stdio.h>

int find(int frame[], int frameSize, int page) {
    for(int i=0; i<frameSize; ++i)
        if(frame[i] == page)
            return i;
    return -1;
}

void printFrame(int frame[], int n) {
    for(int i=0; i<n; ++i)
        printf("%d ", frame[i]);
    printf("\t");
}

void fifoPage(int frame[], int frameSize, int ref_page[], int noOfPages) {
	int pageFaults = 0;
	
    printf("PageNo\t Frames\t HIT/MISS\n");
    for(int i=0; i<noOfPages; ++i) {
        int page = ref_page[i], flag = 1; // flag=1 --> PageHIT
        if(find(frame, frameSize, page) == -1) {
            // replace the page using fifo policy
            frame[pageFaults%frameSize] = page;
            pageFaults++;
            flag = 0;
        }
        printf("%d\t", page);
        printFrame(frame, frameSize);
        if(flag)
            printf("HIT"); // i.e. no page fault
        else
            printf("MISS");
        printf("\n");
    }

    printf("No. of page faults = %d", pageFaults);
}

int main() {
    int frameSize, noOfPages;
    printf("Enter the frame size: ");
    scanf("%d", &frameSize);
	int frame[frameSize];
    for(int i=0; i<frameSize; ++i)
        frame[i] = -1; // -1 indicates frame is empty at frame[i]

    printf("Enter no. of pages: ");
    scanf("%d", &noOfPages);
    int ref_page[noOfPages];
    printf("Enter the pages: \n");
    for(int i=0; i<noOfPages; ++i)
        scanf("%d", &ref_page[i]);
    
	fifoPage(frame, frameSize, ref_page, noOfPages);
	return 0;
}