#include<iostream>
using namespace std;
class construct
{
	int x,y,z;
	public:
		construct()
		{
			x = y = z = 0;
			cout<<"Printed when object is created i.e when default constructor is called"<<endl;
		}
		construct(int a,int b,int c)
		{
			x = a;
			y = b;
			z = c;
		}
		construct(construct &c)
		{
			x = c.x;
			y = c.y;
			z = c.z;
		}
		display();
};

construct::display()
{
	cout<<"Value of x is :"<<x<<endl;
	cout<<"Value of y is :"<<y<<endl;
	cout<<"Value of z is :"<<z<<endl;
}

int main()
{	
	int a,b,c;
	cout << "Enter values for a,b and c :" << endl;
	cin >> a >> b >> c;
	
	construct c1; //Default Constructor
	
    construct c2(a,b,c); //Parameterized Constructor
 
 	construct c3(c2); //Copy Constructor
//  construct c3 = c2;
 	
 	cout<<"Values in c1:"<<endl;
	c1.display();
	cout<<"Values in c2:"<<endl;
	c2.display();
	cout<<"Values in c3:"<<endl;
	c3.display();
	
	return 0;
}
