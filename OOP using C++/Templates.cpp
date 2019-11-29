#include<iostream>
using namespace std;

template <class T>
T max(T &a, T &b){
	if(a>b) return a;
	else return b;
}

int main() {
	int a,b,c;
	a=10;
	b=20;
	c=max(a,b);
	cout<<c;
	return 0;
}

