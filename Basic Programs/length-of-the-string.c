/******************************************************************************

Length of a string

*******************************************************************************/
#include <stdio.h>

int main()
{
    char str[1000000];
    printf("Enter an input for string: \n");
    scanf("%s", str);
    
    int len = 0;
    
    for(int i=0; str[i]!='\0'; ++i)
        len++;
    
    printf("\nLength of the string is %d", len);
    
    return 0;
}
