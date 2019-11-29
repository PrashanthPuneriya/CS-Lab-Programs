#include<iostream>
using namespace std;
int main()
{
	int n,sum=0,i;
	cout<<"Enter the range to calculate the summation:"<<endl;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		sum+=i;
	}
	cout<<"Sum of first \""<<n<<"\" Natural numbers is: "<<sum<<endl;
	return 0;
}
