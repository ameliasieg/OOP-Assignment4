#include <iostream>
#include <cstring> // For strcmp
#include "course.h"
using namespace std;

Course::Course()
{
    CourseName = new char[2];
    strcpy(CourseName, " ");
    
    strcpy(CourseCode," ");
    
    strcpy(Location, " ");
    
    Roster = new Student[2];

    int maxSize;
    int currentSize = 1;
}

Course::~Course()
{
    delete [] CourseName;
    delete [] Roster;
}

CourseList::CourseList()
{
    courseList = new Course[2];
    maxCourseSize = 2;
    currentCourseSize = 0;

}

CourseList::~CourseList()
{
    delete [] courseList;
    delete [] CourseName;

}

ostream& operator<<(ostream& out, const Course& course) // For Course
{
    out << "Course Name: " << course.GetCourseName() << endl;
    out << "Course Code: " << course.GetCourseCode() << endl;
    out << "Location: " << course.GetLocation() << endl;
    out << "Roster: " << endl;
    
    for (int  i = 0; i < course.currentSize; i++)
    {
        cout << course.Roster[i];
    }

    return out;
}


ostream& operator<<(ostream& out, const CourseList& courseList1) // For CourseList
{
    for(int i = 0; i < courseList1.currentCourseSize; i++)
        out << courseList1.courseList[i];

    return out;
}

void Course::GrowStudent()
{
    maxSize = currentSize + 10;                 
    Student* newList = new Student[maxSize];    // NEED A DELETE - or do I have it below with studentList?
    for (int i = 0; i < currentSize; i++)       
        newList[i] = studentList[i];            
    
    delete [] studentList;
    studentList = newList; 
}

void Course::AddStudent()
{
    if (currentSize == maxSize) // If the directory is full, grow it
        GrowStudent();
    
    studentList[currentSize++].Load();
}

int Course::FindStudentName(char* aName)
{
    for (int i = 0; i < currentSize; i++)
        if (strcmp(Roster[i].GetStudentName(), aName) == 0)
            return i; // If found, return position and exit
    
    return -1; // Return -1 if never found
}

int Course::FindStudentID(int newStudentID)
{
    for (int i = 0; i < currentSize; i++)
        if (newStudentID == StudentID)
            return i; // If found, return position and exit
    
    return -1; // Return -1 if never found
}

int CourseList::FindCourseName(char* aCName)
{
    for (int i = 0; i < currentCourseSize; i++)
        if (strcmp(courseList[i].GetCourseName(), aCName) == 0)
            return i; // If found, return position and exit
    
    return -1; // Return -1 if never found
}

void Course::RemoveCourse()
{
    // Prompt the user for the name to be removed
    char aName[20];
    
    cout << "\nType a name to be removed: ";
    cin.getline(aName, 20);
    
    int thisStudent = FindStudentName(aName); // Locate the name in the course
    
    if (thisStudent == -1)
        cout << aName << " not found in directory"; 
    
    else
    {
        for (int j = thisStudent + 1; j < currentSize; j++)
            studentList[j - 1] = studentList[j];
        
        currentSize--; // Decrement the current number of entries
        cout << "Entry removed. \n";
    }
}

void Course::UpdateStudent() // Update an existing student entry by reentering each of its values
{
    cout << "\nPlease enter the name of the entry to be modified: ";
    char aName[20];
    cin.getline(aName, 20);
    int thisStudent = FindStudentName(aName);
   
    if (thisStudent == -1)
        cout << aName << " not found in current directory\n";
    
    else
    {
        cout << "\nCurrent entry is: \n";
        cout << studentList[thisStudent]; // Display the current entry
        
        cout << "\nReplace with new entries as follows: \n";
        studentList[thisStudent].Load(); // Get new values for entry
    }
}

void CourseList::UpdateCourse() // Update an existing course entry by reentering each of its values
{
    cout << "\nPlease enter the name of the entry to be modified: ";
    char aName[20];
    cin.getline(aName, 20);
    
    int thisCourse = FindCourseName(aName);
   
    if (thisCourse == -1)
        cout << aName << " not found in current directory\n";
    
    else
    {
        cout << "\nCurrent entry is: \n";
        cout << courseList[thisCourse];
        
        cout << "\nReplace with new entries as follows: \n";
        courseList[thisCourse].LoadCourse(); // Get new values for entry
   }
}

void CourseList::GrowCourseList()
{
    maxCourseSize = currentCourseSize + 1;          
    Course* newList = new Course[maxCourseSize];        // NEED A DELETE - or do I have it below with courseList?
    for (int i = 0; i < currentCourseSize; i++)     
        newList[i] = courseList[i];                 
    
    delete [] courseList; // Remove the old array
    courseList = newList; // Point old name to new array
}

void CourseList::AddCourse()
{
    if (maxCourseSize == currentCourseSize)
        GrowCourseList();

    courseList[currentCourseSize++].LoadCourse();
    
}

void Course::LoadCourse()
{
    cout << "\nType Course Name, followed by RETURN or ENTER: ";
    cin.getline(CourseName, 20); 

    cout << "\nType Course Code, followed by RETURN or ENTER: ";
    cin.getline(CourseCode, 20); 

    cout << "\nType Course Location, followed by RETURN or ENTER: ";
    cin.getline(Location, 20);  

    char choice;                                            // Do I need to do all of this???? BELOW
    cout << "\nWould you like to add students? (Y for Yes, N for No) ";
    cin >> choice;
    
    while(choice == 'y' || choice == 'Y')
    {
        if(currentSize == maxSize)
            GrowStudent();
        Roster[currentSize++].Load();
        cout << "\nWould you like to add more students? ";
        cin >> choice;
    }
}

const char* Course::GetCourseName() const
{
    return CourseName; 
}

const char* Course::GetCourseCode() const
{
    char* tempCode = new char[7];
    for(int i = 0; i < 7; i++) 
        tempCode[i] = CourseCode[i];
    return tempCode;
}

const char* Course::GetLocation() const
{
    char* tempLoc = new char[10];
    for(int i = 0; i < 7; i++) 
        tempLoc[i] = Location[i];
    return tempLoc;
}

Student* Course::GetRoster() const
{
    return Roster;
}

void Course::operator=(const Course& c)
{
    SetCourseName(c.GetCourseName());
    SetCourseCode(c.GetCourseCode());
    SetLocation(c.GetLocation());
    SetRoster(c.GetRoster());
}

void Course::SetCourseName(const char* cname)
{
    CourseName = new char[strlen(cname) + 1];
    strcpy(CourseName, cname);
}

void Course::SetCourseCode(const char* newCode)
{
    for(int i = 0; i < 7; i++) 
        CourseCode[i] = newCode[i];
}

void Course::SetLocation(const char* newLocation)
{
    for(int i = 0; i < 7; i++) 
        Location[i] = newLocation[i];
}

void Course::SetRoster(Student* newRoster)
{
    Roster = newRoster;
}

void CourseList::FindStudentByName()
{
    char aName[20]; // Make an array
    
	for(int i = 0; i < 20; i++)
	    aName[i] = '\0';

    cout << "Which name do you want to search for? ";
    cin >> aName;

    for(int i = 0; i < currentCourseSize; i++) // Looping through list of courses
    {
        int j = courseList[i].FindStudentName(aName);
        cout << "j is: " << j << endl;
        if(j != -1)
        {
            Student* Roster = courseList[i].GetRoster();
            cout << Roster[j];
        }
    }

}

void CourseList::FindStudentByID()
{
    cout << "Which ID do you want to search for? ";
    cin >> StudentID;

    for(int i = 0; i < currentCourseSize; i++) // Looping through list of courses
    {
        int j = courseList[i].FindStudentID(newStudentID);
        
        if(j != -1) 
        {
            Student* Roster = courseList[i].GetRoster();
            cout << Roster[j];
        }

    }

}

void CourseList::FindCourseByName()
{
    char aCName[30];
    cout << "Which course name do you want to search for? ";
    cin >> aCName;

    for(int i = 0; i < currentCourseSize; i++) // Looping through list of courses
    {
        if(strcmp(courseList[i].GetCourseName(), aCName) == 0)
        {
            cout << courseList[i];
            return;
        }
    }

}

int CourseList::FindCourseCode(char* courseCode)
{
    for (int i = 0; i < currentCourseSize; i++)
        if (strcmp(courseList[i].GetCourseCode(), courseCode) == 0)
            return i; // If found, return position and exit
    
    return -1; // Return -1 if never found
}

void CourseList::FindCourseByCode()
{   
    char courseCode[7];
    cout << "Which course code do you want to search for? ";
    cin >> courseCode;

    for(int i = 0; i < currentCourseSize; i++) // Looping through list of courses
    {
        if(strcmp(courseList[i].GetCourseCode(), courseCode) == 0)
            cout << courseList[i];
            return;
    }
}

void CourseList::FindCourseByLoc()
{   
    char location[10];
    cout << "Which course location do you want to search for? ";
    cin >> location;

    for(int i = 0; i < currentCourseSize; i++) // Looping through list of courses
    {
        if(strcmp(courseList[i].GetLocation(), location) == 0)
            cout << courseList[i];
            return;
    }
}
