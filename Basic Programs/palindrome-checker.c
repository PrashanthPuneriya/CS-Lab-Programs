/******************************************************************************

Palindrome checker

*******************************************************************************/
#include <stdio.h>
#include <string.h>

int main()
{
    char str[10000];
    printf("Enter a string:\n");
    scanf("%s", str);
    int i=0, j=strlen(str)-1, isPalindrome=1;
    while(i<=j) {
        if(str[i] != str[j])
            isPalindrome = 0;
        ++i; --j;
    }
    if(isPalindrome)
        printf("%s is a Palindromic string", str);
    else
        printf("%s is not a Palindromic string", str);
}
