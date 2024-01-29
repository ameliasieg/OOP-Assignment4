#include "student.h"

class Course
{
    friend ostream& operator<<(ostream&, const Course&);

    public:

    Course(); // Default constructor
    ~Course(); // Destructor
   
    void AddStudent();
    void UpdateStudent();
    void RemoveCourse();
    int FindStudentName(char* aName); 
    int FindStudentID(int StudentID);
    //int FindCourseName(char* aCName);
    
    const char* GetCourseName() const;
    const char* GetCourseCode() const;
    const char* GetLocation() const;
    Student* GetRoster() const;
    
    void operator=(const Course&);
    void SetCourseName(const char* cname);
    void SetCourseCode(const char* newCode);
    void SetLocation(const char* newLocation);
    void SetRoster(Student* newRoster);

    void LoadCourse();
 
    private:

    char* CourseName; 
    char CourseCode[7];
    char Location[10];
    Student* Roster;
    int maxSize;
    int currentSize;
    Student* studentList;
    void GrowStudent();
    int StudentID;

};

///////////////////////////////////////////////////////////////////////////////////////////////////////////

class CourseList
{
    friend ostream& operator<<(ostream&, const CourseList&); // ????

    public:

    CourseList();
    ~CourseList();
    
    void AddCourse();
    void UpdateCourse();

    void FindStudentByName();
    void FindStudentByID();
    
    int FindCourseName(char* aCName);
    void FindCourseByName();
   
    int FindCourseCode(char* courseCode);
    void FindCourseByCode();

    //int FindCourseLoc();
    void FindCourseByLoc();


    private:

    char* CourseName; 
    Course* courseList;
    int currentCourseSize;
    int maxCourseSize;
    void GrowCourseList();
    int StudentID;
    int newStudentID;

};