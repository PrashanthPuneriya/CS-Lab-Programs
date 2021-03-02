#include<stdio.h>
#include<string.h>

int main() {
    char recData[1000]; //receivedData
    printf("Enter the stuffed data which we have received:- ");
    scanf("%s", recData);
    printf("Unstuffed data is:- ");
    printf("a");
    int shouldPrintNext=0;
    for(int i=0; i<strlen(recData); ++i) {
        if(recData[i]=='E' && recData[i+1]=='S' && recData[i+2]=='C') {
            // next byte contains the original data
            shouldPrintNext = 1;
            i += 3;
        }
        if(shouldPrintNext) {
            printf("%c", recData[i]);
            if(recData[i]=='C' || recData[i]=='G')
                shouldPrintNext = 0;
        }
    }
    printf("b");
    
}