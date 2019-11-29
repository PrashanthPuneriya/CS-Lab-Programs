#include<iostream>
using namespace std;
class e
{
	int e_count=0,o_count=0;
	
	public:
		void countno()
		{	
			int n;
			cout<<"Enter range:"<<endl;
			cin>>n;
			for(int i=1;i<n;i++)
			{
				if(i%2==0)
					e_count++;
				else o_count++;
			}
		}
		void printdata();
}e1;

void e::printdata()
{
	cout<<"Even:"<<e_count<<endl;
	cout<<"Odd:"<<o_count;
}

int main()
{
	e1.countno();
	e1.printdata();
}
