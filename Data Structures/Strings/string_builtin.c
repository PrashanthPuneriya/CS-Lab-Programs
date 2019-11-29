#include<stdio.h>
#include<string.h>
int main()
{
	char arr1[20];
	char arr2[20];
	char arr3[20];
	printf("Enter a string-1\n");
	scanf("%s",arr1);
	//strlen()
	printf("Length of string is: %d\n",strlen(arr1));
	//strcpy()
	strcpy(arr2,arr1);
	printf("After using strcpy fun string-2 has string-1 value i.e string-2 has %s\n",arr2);
	//strcat()
	strcat(arr1,arr2);
	printf("String-1 is concatenated with string-2 and the result is %s\n",arr1);
	//strrev()
	strcpy(arr3,arr2);
	printf("Reversing string-1 gives %s\n",strrev(arr3));
	//strupr()
	strupr(arr2);
	printf("Upper-casing string-1 gives %s\n",arr2);
	//strlwr()
	strlwr(arr2);
	printf("Lower-casing string-1 gives %s\n",arr2);	
	return 0;
}
