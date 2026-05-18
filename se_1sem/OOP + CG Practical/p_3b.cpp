#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    int emp_no;
    string emp_name;
    string emp_designation;

public:
    void accept() {
        cout << "Enter Employee Number: ";
        cin >> emp_no;
        cin.ignore(); // to ignore the newline character after inputting emp_no
        cout << "Enter Employee Name: ";
        getline(cin, emp_name);
        cout << "Enter Employee Designation: ";
        getline(cin, emp_designation);
    }

    void display() {
        cout << "Employee Number: " << emp_no << endl;
        cout << "Employee Name: " << emp_name << endl;
        cout << "Employee Designation: " << emp_designation << endl;
    }
};

class Salary : public Employee {
    float basic, hra, da, gross_sal;

public:
    void accept() {
        Employee::accept();
        cout << "Enter Basic Salary: ";
        cin >> basic;
        cout << "Enter HRA: ";
        cin >> hra;
        cout << "Enter DA: ";
        cin >> da;
        // Calculate gross salary
        gross_sal = basic + hra + da;
    }

    void display() {
        Employee::display();
        cout << "Basic Salary: " << basic << endl;
        cout << "HRA: " << hra << endl;
        cout << "DA: " << da << endl;
        cout << "Gross Salary: " << gross_sal << endl;
    }
};

int main() {
    Salary employee;
    cout << "Enter details of the employee:" << endl;
    employee.accept();
    cout << "\nDetails of the employee are:" << endl;
    employee.display();
    return 0;
}
