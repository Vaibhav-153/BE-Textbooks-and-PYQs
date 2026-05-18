#include<iostream>
#include<fstream>

class test {
public:
    void writedata();
    void readdata();
};

void test::writedata() {
    std::fstream fp;
    char ch;

    // Open the file for writing
    fp.open("it.txt", std::ios::out);

    std::cout << "Enter data (type '.' to end): ";
    std::cin >> ch;

    // Write data to the file until '.' is entered
    while (ch != '.') {
        fp.put(ch);
        std::cin >> ch;
    }

    // Close the file
    fp.close();
}

void test::readdata() {
    std::fstream fp;
    char ch;

    // Open the file for reading
    fp.open("it.txt", std::ios::in);

    // Read and display data from the file until the end of file is reached
    ch = fp.get();
    while (!fp.eof()) {
        std::cout << ch;
        ch = fp.get();
    }

    // Close the file
    fp.close();
}

int main() {
    test ob;
    int ch;

    do {
        std::cout << "\n1. Write\n2. Read\n3. Exit";
        std::cout << "\nEnter your choice: ";
        std::cin >> ch;

        switch (ch) {
        case 1:
            ob.writedata();
            break;
        case 2:
            ob.readdata();
            break;
        }
    } while (ch != 3);

    return 0;
}
