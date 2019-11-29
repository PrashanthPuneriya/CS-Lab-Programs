//Overloading Binary opertaor (*)
#include<iostream>
using namespace std;
class Rectangle
{	
	int length,breadth;
	public:
		Rectangle () {
		}
		Rectangle (int l,int b) {	//Parameterized Constructor
			length = l;
			breadth = b;
		}
		Rectangle operator * (Rectangle obj); //return and takes an object of class Rectangle
		void display();
};

Rectangle Rectangle::operator * (Rectangle obj) {
	Rectangle temp;
	temp.length = length * obj.length;
	temp.breadth = breadth * obj.breadth;
	return temp;
}

void Rectangle::display() {
	cout<<length<<"*"<<breadth<<endl;
}
	
int main() {
	Rectangle r1(5,10);
	r1.display();
	Rectangle r2(20,30);
	r2.display();
	Rectangle r3 = r1 * r2;
	r3.display();
	return 0;
}
