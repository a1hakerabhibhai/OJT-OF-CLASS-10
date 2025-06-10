#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// Define the Student class
class Student {
public:
    int id;
    string name;
    int age;
    string grade;

    void input() {
        cout << "Enter ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Age: ";
        cin >> age;
        cin.ignore();
        cout << "Enter Grade: ";
        getline(cin, grade);
    }

    void display() const {
        cout << "ID: " << id << ", Name: " << name
             << ", Age: " << age << ", Grade: " << grade << endl;
    }
};

// File Functions
void saveToFile(const Student& student) {
    ofstream file("students.txt", ios::app);
    file << student.id << "," << student.name << "," << student.age << "," << student.grade << endl;
    file.close();
}

void viewStudents() {
    ifstream file("students.txt");
    string line;
    cout << "\n--- Student List ---\n";
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

// Main Menu
void showMenu() {
    cout << "\n--- School Management System ---\n";
    cout << "1. Add Student\n";
    cout << "2. View Students\n";
    cout << "3. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    int choice;
    do {
        showMenu();
        cin >> choice;
        cin.ignore(); // clear newline
        switch (choice) {
            case 1: {
                Student s;
                s.input();
                saveToFile(s);
                cout << "Student added successfully.\n";
                break;
            }
            case 2:
                viewStudents();
                break;
            case 3:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 3);

    return 0;
}
