// Multiple Inheritance
#include<iostream>
using namespace std;
// Base Class

// Intermediate Class
class Test {
	public:
		int subj1, subj2;
		Test (int m1, int m2) {   // Inheriting constructor of base class
			subj1 = m1;
			subj2 = m2;
		}
		
};
// Derived Class
class Fitness {
	public:
		int score, total;
		Fitness (int s)	{
			score = s;
		}
};

class Student {
	public:
		string name,id;
		Student (string n, string i) {
			name = n;
			id = i;
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
