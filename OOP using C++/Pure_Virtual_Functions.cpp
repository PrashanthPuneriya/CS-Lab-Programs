#include<iostream>
using namespace std;
// Abstract Class
class Base {
	public:
		virtual void print() = 0; // Virtual helps in ignoring
};
class Derived : public Base {
	public:
		void print() { // Must define the print function
			cout<<"Derived Class\n";
		}
		void show() {
			cout<<"Derived Class\n";
		}
};

int main() {
	Base *b;
	Derived d;
	b = &d;
	b->print(); //Ignores Base class print function
	d.show();
	return 0;
}
