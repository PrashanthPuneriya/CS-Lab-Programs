// Single Inheritance
#include<iostream>
using namespace std;
// Base Class
class Details {
	public:
		string name,id;
		Details (string n, string i) {
			name = n;
			id = i;
		}
		virtual void display() {
			cout<<"Name : " << name << endl;
			cout<<"ID : " << id << endl;
		}
};
// Derived Class
class Test : public Details {
	public:
		int subj1, subj2, total;
		Test (string n, string i, int m1, int m2) : Details(n,i) {   // Inheriting constructor of base class
			subj1 = m1;
			subj2 = m2;
			total = m1 + m2;
		}
		void display() {
			cout<<"Name : " << name << endl;
			cout<<"ID : " << id << endl;
			cout<<"Total : " << total << endl;
		}
};

int main() {
	Test t1("Prashanth", "1", 90, 95);
	t1.display();
	return 0;
}
