#include <iostream>
using namespace std;

class Student
{
    friend ostream& operator<<(ostream&, const Student&);

    public:

    Student();                              // Default constructor - initializes all values to blanks
    ~Student();                             // Destructor
    
    void Load();                            // Loads data into a student
    const char* GetStudentName() const;     // Returns a name in a student
    const char GetClassification() const;
    const char* GetMajor() const;
    const int GetStudentID() const;
    
    void operator=(const Student&);         //deep copy assignment
    void SetStudentName(const char* name);
    void SetClassification(const char newClassification);
    void SetMajor(const char* major);
    void SetStudentID(int newstudentID);

    private:

    char* StudentName;
    char Classification;
    char* Major;
    int StudentID;
    int maxSize;
    int currentSize;
    Student* studentList;

};