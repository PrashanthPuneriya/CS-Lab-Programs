#include<stdio.h>
#include<string.h>

int main() {
    char data[100];
    scanf("%s", data);
    printf("Bits before stuffing: ");
    printf("%s\n", data);
    int count = 0;
    printf("Bits after stuffing: ");
    // after every 5 consecutives 1s we need to add one 0 after it
    for(int i=0; i<strlen(data); ++i) {
        if(data[i] == '1')
            count++;
        else
            count = 0;
        printf("%c", data[i]);
        if(count == 5) {
            printf("0");
            count = 0;
        }
    }
    return 0;
}
