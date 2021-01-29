//Program to print factorial of a number using recursion

#include<iostream>
using namespace std;
int fact(int n)
{
	if(n==1 || n==0)
		return 1;
	else
	return(n*fact(n-1));
}
int main()
{
	long long int n;
	cout<<"Enter a number to find its factorial"<<endl;
	cin>>n;
	int res=fact(n);
	cout<<"Factorial of number is:"<<res;
	return 0;
}
