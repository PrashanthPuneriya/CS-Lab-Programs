#include<stdio.h>
int main()
{
	int i=0;
	char str1[20],str2[20];
	printf("Enter a string:");
	scanf("%s",str1);
	while(str1[i]!='\0')
	{
		str2[i]=str1[i];
		i++;
	}
	printf("Copying str1 to str2 gives: %s",str2);
	
	return 0;
}
