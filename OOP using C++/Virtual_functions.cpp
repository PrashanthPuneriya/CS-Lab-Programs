#include<iostream>
using namespace std;

class Base {
	public:
		void print() {
			cout<<"Base Class\n";
		}
		virtual void show() {
			cout<<"Base Class\n";
		}
};
class Derived : public Base {
	public:
		void print() {
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
	b->print(); //Prints Base Class print function
	b->show(); //Ignores Base Class show function bcoz of virtual
	d.show();
	return 0;
}
