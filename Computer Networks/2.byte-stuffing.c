#include<stdio.h>
#include<string.h>

int main() {
    char inp[50];
    printf("Enter input data:- ");
    scanf("%s", inp);
    printf("The stuffed data is:- ");
    for(int i=0; i<strlen(inp); ++i) {
        if(inp[i]=='E' && inp[i+1]=='S' && inp[i+2]=='C')
            printf("ESC");
        else if(inp[i]=='F' && inp[i+1]=='L' && inp[i+2]=='A' && inp[i+3]=='G')
            printf("ESC");
        
        printf("%c", inp[i]);
    }
}