#include<stdio.h>
int main()
{
	int i=0;
	char str1[20];
	printf("Enter a string\n");
	scanf("%s",str1);
	
	while(str1[i]!='\0')
	{
		if(str1[i] >= 'A' && str1[i] <= 'Z')
        	str1[i]+=32;
		i++;
	}
	
	printf("%s",str1);
	
	return 0;
}
