#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
struct Student
{
    int rollNumber, age;
    string name, address, course;
    void display() const
    {
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Address: " << address << endl;
        cout << "Course: " << course << endl;
    }
};

bool isRollNumberUnique(int rollNumber)
{
    ifstream file("students.txt");
    if (file.is_open())
    {
        Student student;
        while (file >> student.rollNumber)
        {
            file.ignore();
            getline(file, student.name);
            file >> student.age;
            file.ignore();
            getline(file, student.address);
            getline(file, student.course);
            if (student.rollNumber == rollNumber) return false;
        }
        file.close();
    }
    return true;
}

void addStudent()
{
    Student student;
    cout << "Enter roll number: ";
    cin >> student.rollNumber;
    if (!isRollNumberUnique(student.rollNumber))
    {
        cout << "Roll number already exists. Try again.\n";
        return;
    }
    cin.ignore();
    cout << "Enter name of student: ";
    getline(cin, student.name);
    cout << "Enter age of student: ";
    cin >> student.age;
    cin.ignore();
    cout << "Enter address of student: ";
    getline(cin, student.address);
    cout << "Enter course of student: ";
    getline(cin, student.course);
    ofstream file("students.txt", ios::app);
    if (file.is_open())
    {
        file<< student.rollNumber << '\n'
            << student.name << '\n'
            << student.age << '\n'
            << student.address << '\n'
            << student.course << '\n';
        file.close();
        cout << "Student added successfully.\n";
    }
    else cout << "Unable to open file.\n";
}
void displayStudents()
{
    ifstream file("students.txt");
    if (file.is_open())
    {
        Student student;
        while (file >> student.rollNumber)
        {
            file.ignore();
            getline(file, student.name);
            file >> student.age;
            file.ignore();
            getline(file, student.address);
            getline(file, student.course);
            student.display();
            cout << "----------------------\n";
        }
        file.close();
    }
    else cout << "Unable to open file.\n";
}
void searchStudent(int rollNumber)
{
    ifstream file("students.txt");
    if (file.is_open())
    {
        Student student;
        bool found = false;
        while (file >> student.rollNumber)
        {
            file.ignore();
            getline(file, student.name);
            file >> student.age;
            file.ignore();
            getline(file, student.address);
            getline(file, student.course);
            if (student.rollNumber == rollNumber)
            {
                student.display();
                found = true;
                break;
            }
        }
        file.close();
        if (found == false) cout << "Student with roll number " << rollNumber << " not found.\n";
    }
    else cout << "Unable to open file.\n";
}
void updateStudent(int rollNumber)
{
    fstream file("students.txt", ios::in | ios::out);
    if (file.is_open())
    {
        vector<Student> students;
        Student student;
        bool found = false;
        while (file >> student.rollNumber)
        {
            file.ignore();
            getline(file, student.name);
            file >> student.age;
            file.ignore();
            getline(file, student.address);
            getline(file, student.course);
            if (student.rollNumber == rollNumber)
            {
                cout << "Enter new details for the student.\n";
                cout << "Enter name: ";
                getline(cin, student.name);
                cout << "Enter age: ";
                cin >> student.age;
                cin.ignore();
                cout << "Enter address: ";
                getline(cin, student.address);
                cout << "Enter course: ";
                getline(cin, student.course);
                found = true;
            }
            students.push_back(student);
        }
        file.close();
        if (found)
        {
            ofstream outFile("students.txt");
            for (const auto &s : students)
            {
                outFile << s.rollNumber << '\n'
                        << s.name << '\n'
                        << s.age << '\n'
                        << s.address << '\n'
                        << s.course << '\n';
            }
            outFile.close();
            cout << "Student record updated successfully.\n";
        }
        else cout << "Student with roll number " << rollNumber << " not found.\n";
    }
    else cout << "Unable to open file.\n";
}
void deleteStudent(int rollNumber)
{
    ifstream file("students.txt");
    if (file.is_open())
    {
        vector<Student> students;
        Student student;
        bool found = false;
        while (file >> student.rollNumber)
        {
            file.ignore();
            getline(file, student.name);
            file >> student.age;
            file.ignore();
            getline(file, student.address);
            getline(file, student.course);
            if (student.rollNumber != rollNumber) students.push_back(student);
            else found = true;
        }
        file.close();
        if (found)
        {
            ofstream outFile("students.txt");
            for (const auto &s : students)
            {
                outFile << s.rollNumber << '\n'
                        << s.name << '\n'
                        << s.age << '\n'
                        << s.address << '\n'
                        << s.course << '\n';
            }
            outFile.close();
            cout << "Student record deleted successfully.\n";
        }
        else cout << "Student with roll number " << rollNumber << " not found.\n";
    }
    else cout << "Unable to open file.\n";
}

int main()
{
    int choice;
    int rollNumber;
    do
    {
        cout << "\n-----Student Record Management System-----\n";
        cout << "Enter 1. Add Student\n";
        cout << "Enter 2. Display Students\n";
        cout << "Enter 3. Search Student\n";
        cout << "Enter 4. Update Student\n";
        cout << "Enter 5. Delete Student\n";
        cout << "Enter 0. Exit\n";
        cout << "Enter your choice from above menu:- ";
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
            cout << "Enter roll number to search: ";
            cin >> rollNumber;
            searchStudent(rollNumber);
            break;
        case 4:
            cout << "Enter roll number to update: ";
            cin >> rollNumber;
            updateStudent(rollNumber);
            break;
        case 5:
            cout << "Enter roll number to delete: ";
            cin >> rollNumber;
            deleteStudent(rollNumber);
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice);
    return 0;
}
