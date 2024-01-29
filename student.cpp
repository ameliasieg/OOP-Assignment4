#include <iostream>
#include <cstring> // For strlen, strcpy
#include "student.h" // For class Student
using namespace std;

Student::Student() // This constructor for class Student initializes the Name, Classification, Major, and StudentID to be blank
{
    StudentName = new char[2];
    strcpy(StudentName, " ");
   
    Classification = ' ';
    
    Major = new char[2];
    strcpy(Major, " ");
    
    StudentID = 0;

}

Student::~Student() // Destructor for class Student 
{
    // Deallocates the student's list of Name objects
    delete [] StudentName;

    // Deallocates the student's list of Major objects
    delete [] Major;
}

ostream& operator<<(ostream& out, const Student& student)
{
    out << "Student Name: " << student.GetStudentName() << endl;
    out << "Classification: " << student.GetClassification() << endl;
    out << "Major: " << student.GetMajor() << endl;
    out << "Student ID: " << student.GetStudentID() << endl;

    return out;
}

void Student::Load()
{
    cin.ignore();
    cout << "\nType Student Name: ";
    cin.getline(StudentName, 20); // Gets a Name; discards newline

    cout << "\nType Classification: ";
    cin >> Classification; // Gets a Classification; discards newline

    cin.ignore();
    cout << "\nType Major: ";
    cin.getline(Major, 20); // Gets a Major; discards newline

    cout << "\nType StudentID: ";
    cin >> StudentID; // Gets a StudentID; discards newline
}

const char* Student::GetStudentName() const
{
    // Return the Name part of an entry
    return StudentName; 
}

const char Student::GetClassification() const
{
    return Classification;
}

const char* Student::GetMajor() const
{
    return Major;
}

const int Student::GetStudentID() const
{
    return StudentID;
}

void Student::SetStudentName(const char* name)
{
    StudentName = new char[strlen(name) + 1];
    strcpy(StudentName, name);
}

void Student::SetClassification(const char newClassification)
{
    Classification = newClassification;
}

void Student::SetMajor(const char* major)
{
    Major = new char[strlen(major) + 1];
    strcpy(Major, major);
}

void Student::SetStudentID(int newstudentID)
{
    StudentID = newstudentID;
}

void Student::operator=(const Student& s)
{
    SetStudentName(s.GetStudentName());
    SetClassification(s.GetClassification());
    SetMajor(s.GetMajor());
    SetStudentID(s.GetStudentID());
}
