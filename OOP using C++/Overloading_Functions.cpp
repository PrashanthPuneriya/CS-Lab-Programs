#include<iostream>
using namespace std;

int area(int s)
{
	return s*s;
}
int area(int l,int b)
{
	return l*b;
}
float area(float r)
{
	return 3.14*r*r;
}
float area(float bs,float ht)
{
	return 0.5*bs*ht;
}

int main()
{
	int s,l,b;
	float r,bs,ht;
	cout<<"Enter side"<<endl;
	cin>>s;
	cout<<"Area of square is:"<<area(s)<<endl;
	cout<<"Enter length and breadth"<<endl;
	cin>>l>>b;
	cout<<"Area of rectangle is:"<<area(l,b)<<endl;
	cout<<"Enter the radius"<<endl;
	cin>>r;
	cout<<"Area of circle is:"<<area(r)<<endl;
	cout<<"Enter base and height of a triangle"<<endl;
	cin>>bs>>ht;
	cout<<"Area of triangle is:"<<area(bs,ht)<<endl;
	return 0;
}

