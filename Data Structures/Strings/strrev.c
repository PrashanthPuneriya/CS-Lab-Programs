#include<stdio.h>
int main()
{
	int i=0;
	char str1[50],str2[30];
	printf("Enter a string\n");
	scanf("%s",str1);
	while(str1[i]!='\0')
		i++;
	
	int j;
	for(j=0;j<i;j++)
		str2[j]=str1[i-j-1];
	
	str2[j] = '\0';
		
	printf("%s", str2);
	
	return 0;
}

