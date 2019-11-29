#include<iostream>
#include<math.h>
using namespace std;
// Can overload inline functions
inline long long int square(int n)
{
	return n*n;
}
inline int square(float n)
{	

	return sqrt(n);
}
int main()
{
	int n;
	float num;
	num=n;
	cout<<"Enter a number"<<endl;
	cin>>n;
	cout<<"Square of number->"<<n<<" is:"<<square(n)<<endl;
	cout<<"Root of number->"<<n<<" is:"<<square(num)<<endl;
	return 0;
}
