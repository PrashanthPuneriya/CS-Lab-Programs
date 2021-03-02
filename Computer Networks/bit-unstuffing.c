#include<stdio.h>
#include<string.h>

int main() {
    char data[100];
    printf("Enter the received stuffed data\n");
    scanf("%s", data);
    int count = 0, shouldSkip = 0;
    for(int i=0; i<strlen(data); ++i) {
        if(shouldSkip)
            shouldSkip=0; // by executing this line we are skipping printf() present in the else block.
        else
            printf("%c", data[i]);
        
        if(data[i] == '1')
            count++;
        else
            count = 0;
        
        if(count == 5) {
            count = 0;
            shouldSkip = 1;
        }
    }
    return 0;
}