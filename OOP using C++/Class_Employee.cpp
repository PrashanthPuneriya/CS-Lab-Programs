#include<iostream>
using namespace std;

class emp
{
	private:
		int emp_id;
		char emp_name[20];
		float emp_salary;
	public:
		void get_data()
		{
			cout<<"Enter Employee ID:"<<endl;
			cin>>emp_id;
			cout<<"Enter Employee Name:"<<endl;
			cin>>emp_name;
			cout<<"Enter Employee Salary:"<<endl;
			cin>>emp_salary;
		}
		void put_data();
};

void emp::put_data()
{
	cout<<"Employee ID:"<<emp_id<<endl;
	cout<<"Employee Name:"<<emp_name<<endl;
	cout<<"Employee Salary:"<<emp_salary<<endl;
	cout<<"-----------------"<<endl;
}
			
//Main function
int main()
{
	emp e;
	int num;
	cout<<"Enter the number of employee details to scan and print:"<<endl;
	cin>>num;
	while(num--)
	{
		e.get_data();
		e.put_data();
	}
	return 0;
}
							
