/******************************************************************************

Concatenation of two strings

*******************************************************************************/
#include <stdio.h>
#include <limits.h>

int main()
{
    char str1[1000], str2[1000], result_str[100000];
    printf("Enter two strings:\n");
    scanf("%s %s", str1, str2);
    
    int i, j;
    for(i=0; str1[i]!='\0'; ++i)
        result_str[i] = str1[i];
    
    for(j=0; str2[j]!='\0'; ++j, ++i)
        result_str[i] = str2[j];
    
    printf("Concatenating the above two strings gives:-\n");
    printf("%s", result_str);
    
    return 0;
}

