#include <iostream>
#include <string>
using namespace std;

class Student {
protected:
    int roll_no;
    string name;

public:
    void accept() {
        cout << "Enter Roll Number: ";
        cin >> roll_no;
        cin.ignore(); // to ignore the newline character after inputting roll_no
        cout << "Enter Name: ";
        getline(cin, name);
    }

    void display() {
        cout << "Roll Number: " << roll_no << endl;
        cout << "Name: " << name << endl;
    }
};

class Marks : public Student {
    int m1, m2, m3;
    int total;
    float percentage;

public:
    void accept() {
        Student::accept();
        cout << "Enter marks for Subject 1: ";
        cin >> m1;
        cout << "Enter marks for Subject 2: ";
        cin >> m2;
        cout << "Enter marks for Subject 3: ";
        cin >> m3;
        // Calculate total and percentage
        total = m1 + m2 + m3;
        percentage = (float)total / 3;
    }

    void display() {
        Student::display();
        cout << "Marks in Subject 1: " << m1 << endl;
        cout << "Marks in Subject 2: " << m2 << endl;
        cout << "Marks in Subject 3: " << m3 << endl;
        cout << "Total Marks: " << total << endl;
        cout << "Percentage: " << percentage << "%" << endl;
    }
};

int main() {
    Marks student;
    cout << "Enter details of the student:" << endl;
    student.accept();
    cout << "\nDetails of the student are:" << endl;
    student.display();
    return 0;
}
