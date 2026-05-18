#include<iostream>
using namespace std;

class Student {
    int roll;
    char name[20], div[5], class_[5], add[30], mob[15], dob[10];

public:
    Student() {
        cout << "This is a student Database";
    }

    void display();
    void getData() {
        cout << "\nPlease enter Name:";
        cin >> name;
        cout << "Please enter Roll number:";
        cin >> roll;
        cout << "Please enter Class:";
        cin >> class_;
        cout << "Please enter Division:";
        cin >> div;
        cout << "Please enter Address:";
        cin >> add;
        cout << "Please enter Date of Birth:";
        cin >> dob;
        cout << "Please enter Mobile number:";
        cin >> mob;
    }

    ~Student() {
        cout << "\nObject is Destroyed\n";
    }
};

void Student::display() {
    cout << "\nName:" << name;
    cout << "\nRoll Number:" << roll;
    cout << "\nClass:" << class_;
    cout << "\nDivision:" << div;
    cout << "\nAddress:" << add;
    cout << "\nDate of Birth:" << dob;
    cout << "\nMobile number:" << mob;
}

int main() {
    Student student1;
    student1.getData();
    student1.display();
    return 0;
}
