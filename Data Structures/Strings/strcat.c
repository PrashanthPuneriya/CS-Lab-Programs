#include<stdio.h>
int main()
{
	int i=0,j=0;
	char str1[50],str2[30];
	printf("Enter a string\n");
	scanf("%s",str1);
	printf("Enter another string\n");
	scanf("%s",str2);
	
	while(str1[i]!='\0')
		i++;
		
	while(str2[j]!='\0')
	{
		str1[i]=str2[j];
		i++;
		j++;
	}
		
	
	printf("Concatenated string is %s",str1);
	
	return 0;
}

