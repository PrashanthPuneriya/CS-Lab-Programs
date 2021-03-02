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

int predict(int frame[], int frameSize, int ref_page[], int noOfPages, int index) {
	
	// if pageFault has occured and frame is not yet filled then, find 1st empty frame[i]
	for(int i=0; i<frameSize; ++i)
		if(frame[i] == -1)
			return i;
    
    	int res = -1, farthest = index;
	for(int i = 0; i < frameSize; i++) {
		int j;
		for(j = index; j >= 0; j--) {
			if(frame[i] == ref_page[j]) {
				if (j < farthest) {
					farthest = j;
					res = i;
				}
				break;
			}
		}
	}
	return (res == -1) ? 0 : res;
}

void lruPage(int frame[], int frameSize, int ref_page[], int noOfPages) { 
    int pageFaults = 0;
    
    printf("PageNo\t Frames\t HIT/MISS\n");
	for(int i = 0; i < noOfPages; i++) {
        int flag = 1, page = ref_page[i];
		if(find(frame, frameSize, page) == -1) {
			int j = predict(frame, frameSize, ref_page, noOfPages, i - 1); 
			frame[j] = page;
            pageFaults++;
            flag = 0;
		}
        printf("%d\t", page);
        printFrame(frame, frameSize);
        if(flag==1)
            printf("HIT");
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
    
	lruPage(frame, frameSize, ref_page, noOfPages);
	return 0;
}
