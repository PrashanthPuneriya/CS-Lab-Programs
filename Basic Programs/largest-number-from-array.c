/******************************************************************************

Max number from array

*******************************************************************************/
#include <stdio.h>
#include <limits.h>

int main()
{
    int n;
    printf("Enter length of the array: ");
    scanf("%d", &n);
    int arr[n], max=INT_MIN;
    printf("Enter numbers\n");
    for(int i=0; i<n; ++i) {
        scanf("%d", &arr[i]);
        if(arr[i] > max)
            max = arr[i];
    }
    printf("The largest number is %d", max);
    
    return 0;
}
