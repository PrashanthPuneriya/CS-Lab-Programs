// Multi-level Inheritance
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
};
// Intermediate Class
class Test : public Details {
	public:
		int subj1, subj2;
		Test (string n, string i, int m1, int m2) : Details(n,i) {   // Inheriting constructor of base class
			subj1 = m1;
			subj2 = m2;
		}
		
};
// Derived Class
class Fitness : public Test {
	public:
		int score, total;
		Fitness (string n, string i, int m1, int m2, int s) : Test(n, i, m1, m2) {
			score = s;
			total = m1 + m2 + score;
		}
		
		void display() {
			cout<<"Name : " << name << endl;
			cout<<"ID : " << id << endl;
			cout<<"Score : " << score << endl;
			cout<<"Total : " << total << endl;
		}
};

int main() {
	Fitness f1("Prashanth", "1", 90, 95, 100);
	f1.display();
	return 0;
}
