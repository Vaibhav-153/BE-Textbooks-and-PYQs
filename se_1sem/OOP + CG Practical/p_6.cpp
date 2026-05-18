#include <iostream>
#include <list>
#include <string>
using namespace std;

class Record {
private:
    list<string> names, dobs, phones;
    list<string>::iterator it1, it2, it3;

public:
    void getPersonalDetails();
    void displayPersonalRecords();
    void searchPersonalRecord(const string& key);
    void sortPersonalRecords();

    void getItemDetails();
    void displayItemRecords();
    void searchItemRecord(const string& key);
    void sortItemRecords();
};

void Record::getPersonalDetails() {
    int count;
    string name, dob, phone;

    cout << "Enter the number of members in the record: ";
    cin >> count;

    for (int i = 0; i < count; ++i) {
        cout << "Enter name: ";
        cin >> name;
        names.push_back(name);

        cout << "Enter date of birth: ";
        cin >> dob;
        dobs.push_back(dob);

        cout << "Enter phone number: ";
        cin >> phone;
        phones.push_back(phone);
    }
}

void Record::searchPersonalRecord(const string& data) {
    int flag = 0;
    it1 = names.begin();
    it2 = dobs.begin();
    it3 = phones.begin();

    while (it1 != names.end() && it2 != dobs.end() && it3 != phones.end()) {
        if (*it1 == data || *it2 == data || *it3 == data) {
            cout << "Record found!" << endl;
            cout << "Name: " << *it1 << endl;
            cout << "Date of Birth: " << *it2 << endl;
            cout << "Phone Number: " << *it3 << endl;
            flag = 1;
            break;
        }

        ++it1;
        ++it2;
        ++it3;
    }

    if (flag == 0)
        cout << "Record not found." << endl;
}

void Record::displayPersonalRecords() {
    it1 = names.begin();
    it2 = dobs.begin();
    it3 = phones.begin();

    while (it1 != names.end()) {
        cout << "Name: " << *it1 << "\tDate of Birth: " << *it2 << "\tPhone Number: " << *it3 << endl;
        ++it1;
        ++it2;
        ++it3;
    }
}

void Record::sortPersonalRecords() {
    names.sort();
    dobs.sort();
    phones.sort();
}

void Record::getItemDetails() {
    int count;
    string itemName, itemCode;
    float itemCost;
    int itemQuantity;

    cout << "Enter the number of items: ";
    cin >> count;

    for (int i = 0; i < count; ++i) {
        cout << "Enter item name: ";
        cin >> itemName;
        names.push_back(itemName);

        cout << "Enter item code: ";
        cin >> itemCode;
        dobs.push_back(itemCode);

        cout << "Enter item cost: ";
        cin >> itemCost;
        phones.push_back(to_string(itemCost));

        cout << "Enter item quantity: ";
        cin >> itemQuantity;
        phones.push_back(to_string(itemQuantity));
    }
}

void Record::searchItemRecord(const string& key) {
    it1 = names.begin();
    it2 = dobs.begin();
    it3 = phones.begin();

    while (it1 != names.end()) {
        if (*it2 == key) {
            cout << "Item available!" << endl;
            cout << "Item Name: " << *it1 << endl;
            cout << "Item Quantity: " << *it3 << endl;
            cout << "Item Cost: " << *it3 << endl;
        }
        ++it1;
        ++it2;
        ++it3;
    }
}

void Record::displayItemRecords() {
    it1 = names.begin();
    it2 = dobs.begin();
    it3 = phones.begin();

    while (it1 != names.end()) {
        cout << "Item Name: " << *it1 << "\tItem Code: " << *it2 << "\tItem Cost: " << *it3 << "\tItem Quantity: " << *it3 << endl;
        ++it1;
        ++it2;
        ++it3;
    }
}

void Record::sortItemRecords() {
    dobs.sort();
    names.sort();
    phones.sort();
}

int main() {
    Record obj;
    int ch, chr;
    string x = "y";

    do {
        cout << "1. Personal record\n2. Item record\nEnter choice: ";
        cin >> ch;

        do {
            if (ch == 1) {
                cout << "1. Enter details\n2. Display\n3. Search entry\n4. Sort records\nEnter choice: ";
                cin >> chr;

                switch (chr) {
                    case 1:
                        obj.getPersonalDetails();
                        obj.displayPersonalRecords();
                        break;
                    case 2:
                        obj.displayPersonalRecords();
                        break;
                    case 3:
                        cout << "Enter either name, date of birth, or phone number you want to find: ";
                        cin >> x;
                        obj.searchPersonalRecord(x);
                        break;
                    case 4:
                        obj.sortPersonalRecords();
                        obj.displayPersonalRecords();
                        break;
                    default:
                        cout << "Wrong choice" << endl;
                }
            } else if (ch == 2) {
                cout << "1. Enter details\n2. Display\n3. Search entry\n4. Sort records\nEnter choice: ";
                cin >> chr;

                switch (chr) {
                    case 1:
                        obj.getItemDetails();
                        obj.displayItemRecords();
                        break;
                    case 2:
                        obj.displayItemRecords();
                        break;
                    case 3:
                        cout << "Enter the item code you want to find: ";
                        cin >> x;
                        obj.searchItemRecord(x);
                        break;
                    case 4:
                        obj.sortItemRecords();
                        obj.displayItemRecords();
                        break;
                    default:
                        cout << "Wrong choice" << endl;
                }
            } else {
                cout << "Wrong choice" << endl;
                break;
            }

            cout << "Do you wish to continue? Y or N: ";
            cin >> x;
        } while (x == "y" || x == "Y");

        cout << "Do you wish to select another type of record? Y or N: ";
        cin >> x;
    } while (x == "y" || x == "Y");

    return 0;
}
