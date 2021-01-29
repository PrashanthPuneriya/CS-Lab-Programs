//Fibonacci series using recursion

#include<iostream>
using namespace std;

int fibo(int a,int b,long long int c,int range)
{	
	
	if(c>=range)
	return 1;
	
	else
	{
		c=a+b;
		a=b;
		b=c;
		if(c<=range)
		cout<<c<<" ";
	
	return(fibo(a,b,c,range));
	}
	
}

int main()
{
	int range;
	cout<<"Enter a range to print the series till that number:"<<endl;
	cin>>range;
	int a=0,b=1;
	long long int c=0;
	cout<<a<<" "<<b<<" ";
	fibo(a,b,c,range);
	
	return 0;
}
