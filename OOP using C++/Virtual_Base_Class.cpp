#include<iostream>
using namespace std;
class Personal {
	public:
		void display() {
			cout<<"Personal Class"<<endl;
		}
};

class Test : virtual public Personal {
	public:
		void display() {
			cout<<"Test Class\n";
		}
};

class Sports : public virtual Personal {
	public:
		void display() {
			cout<<"Sports Class\n";
		}
};

class Result : public Test, public Sports {
	public:
		void display() {
			cout<<"Result Class\n";
			Personal::display();
			Test::display();
			Sports::display();
		}
};

int main() {
	Result r;
	r.display();
	return 0;
}

