#include<iostream>
using namespace std;

class ABC
{
	int x,y;
	public:
		ABC()
		{
		}
		ABC(int a,int b)
		{
			x=a;
			y=b;
		}
		friend ABC add(ABC,ABC);
		void display();
};

ABC add(ABC o1,ABC o2)
{
	ABC o3;
	o3.x = o1.x + o2.x;
	o3.y = o2.y + o2.y;
	return o3;
}
void ABC::display()
{
	cout<<"Value of x is :"<<x<<endl;
	cout<<"Value of y is :"<<y<<endl;
}
int main()
{	
	int x,y;
	cout << "Enter x and y values for obj-1:" << endl;
	cin >> x >> y;
	ABC o1(x,y);
	cout << "Enter x and y values for obj-2:" << endl;
	cin >> x >> y;
	ABC o2(x,y);
	ABC o3;
	o3 = add(o1,o2);
	cout<<"Values in obj-3 are: "<<endl;
	o3.display();	
	return 0;
}
	
