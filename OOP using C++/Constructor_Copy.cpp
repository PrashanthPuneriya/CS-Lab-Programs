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
		construct(construct &c2)
		{
			data1=c2.data1;
			data2=c2.data2;
		}
		void display();
};


void construct::display()
{
	cout<<"Value of data1 is:"<<data1<<endl;
	cout<<"Value of data2 is:"<<data2<<endl;
}

int main()
{	
	int a,b;
	cout<<"Enter a value for data-1 and data-2:"<<endl;
	cin>>a>>b;
	construct c1(a,b);
	construct c2(c1);
	
	cout<<"Values in c1:"<<endl;
	c1.display();
	cout<<"Values in c2:"<<endl;
	c2.display();
	return 0;
}
