#include<iostream>
using namespace std;

class construct
{	
	int data1,data2;
	public:
		construct(int a,int b)
		{
			data1=a;
			data2=b;
		}
		display();
};

construct::display()
{
	cout<<"Value of data-1 is:"<<data1<<endl;
	cout<<"Value of data-2 is:"<<data2;
}

int main()
{	
	int a,b;
	cout<<"Enter a value for data-1 and data-2:"<<endl;
	cin>>a>>b;
	construct c1(a,b); 
	//construct c1=construct(a,b);
	c1.display();
	return 0;
}
