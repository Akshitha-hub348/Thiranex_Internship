#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

class Student
{
public:
    int rollNo;
    char name[50];
    float marks;

    void input()
    {
        cout << "Enter Roll Number: ";
        cin >> rollNo;

        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter Marks: ";
        cin >> marks;
    }

    void display()
    {
        cout << "\nRoll Number: " << rollNo << endl;
        cout << "Name: " << name << endl;
        cout << "Marks: " << marks << endl;
        cout << "--------------------------" << endl;
    }
};

void addStudent()
{
    Student s;

    ofstream file("students.dat", ios::binary | ios::app);

    if (!file)
    {
        cout << "Error opening file!\n";
        return;
    }

    s.input();

    file.write((char*)&s, sizeof(s));

    file.close();

    cout << "\nStudent added successfully!\n";
}

void displayStudents()
{
    Student s;

    ifstream file("students.dat", ios::binary);

    if (!file)
    {
        cout << "\nNo student records found.\n";
        return;
    }

    cout << "\n========== Student Records ==========\n";

    while (file.read((char*)&s, sizeof(s)))
    {
        s.display();
    }

    file.close();
}

void updateStudent()
{
    Student s;
    int roll;
    int found = 0;

    cout << "Enter Roll Number to update: ";
    cin >> roll;

    fstream file("students.dat", ios::binary | ios::in | ios::out);

    if (!file)
    {
        cout << "\nNo student records found.\n";
        return;
    }

    while (file.read((char*)&s, sizeof(s)))
    {
        if (s.rollNo == roll)
        {
            cout << "\nEnter new details:\n";
            s.input();

            file.seekp(-static_cast<int>(sizeof(s)), ios::cur);
            file.write((char*)&s, sizeof(s));

            found = 1;
            break;
        }
    }

    file.close();

    if (found)
        cout << "\nStudent updated successfully!\n";
    else
        cout << "\nStudent not found!\n";
}

void deleteStudent()
{
    Student s;
    int roll;
    int found = 0;

    cout << "Enter Roll Number to delete: ";
    cin >> roll;

    ifstream file("students.dat", ios::binary);
    ofstream temp("temp.dat", ios::binary);

    if (!file)
    {
        cout << "\nNo student records found.\n";
        return;
    }

    while (file.read((char*)&s, sizeof(s)))
    {
        if (s.rollNo == roll)
        {
            found = 1;
        }
        else
        {
            temp.write((char*)&s, sizeof(s));
        }
    }

    file.close();
    temp.close();

    remove("students.dat");
    rename("temp.dat", "students.dat");

    if (found)
        cout << "\nStudent deleted successfully!\n";
    else
        cout << "\nStudent not found!\n";
}

int main()
{
    int choice;

    do
    {
        cout << "\n====================================\n";
        cout << "      STUDENT MANAGEMENT SYSTEM\n";
        cout << "====================================\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Update Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";
        cout << "====================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addStudent();
            break;

        case 2:
            displayStudents();
            break;

        case 3:
            updateStudent();
            break;

        case 4:
            deleteStudent();
            break;

        case 5:
            cout << "\nThank you for using Student Management System!\n";
            break;

        default:
            cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}
