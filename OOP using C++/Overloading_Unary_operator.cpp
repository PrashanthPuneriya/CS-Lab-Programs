//Overloading Unary operator
#include<iostream>
using namespace std;
class Minus {
	int x, y, z;
	public:
		Minus (int a, int b, int c) {
			x = a;
			y = b;
			z = c;
		}
		void operator - ();
		void display();
};
	
void Minus::operator - ()  {
	x = -x;
	y = -y;
	z = -z;
}
	
void Minus::display() {
	cout<<"\n x: "<< x;
	cout<<"\n y: "<< y;
	cout<<"\n z: "<< z;
}

int main() {
	Minus m1(10, 20, -30);
	cout<<"m1:"; m1.display();
	- m1;
	cout<<"\n-m1:"; m1.display();
}
