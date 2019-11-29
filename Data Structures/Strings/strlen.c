#include<stdio.h>
int main()
{
	int i=0,len=0;
	char arr[20];
	printf("Enter a string:");
	scanf("%s",arr);
	while(arr[i]!='\0')
	{
		i++;
		len++;
	}
	printf("Length of the string is: %d",len);
	
	return 0;
}
