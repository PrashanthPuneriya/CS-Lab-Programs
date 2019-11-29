#include<iostream>
using namespace std;

namespace value
{
	int val=500;
}

//Global
int val=250;

int main()
{
	int val=100;
	cout<<"Value in Namespace:"<<value::val<<endl;
	cout<<"Value of Global variable:"<<::val<<endl;
	cout<<"Value in the main function:"<<val<<endl;
	return 0;
}
