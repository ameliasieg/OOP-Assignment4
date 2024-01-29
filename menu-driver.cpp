
#include "course.h"
#include <iostream>
using namespace std;

void ShowMenu() // Display the main program menu
{
    cout << "\n \t \t *** CANVAS DIRECTORY ***" << endl;
    cout << "\n \t C \t Add a course to the list";
    cout << "\n \t U \t Update a course";
    cout << "\n \t L \t List courses";
    cout << "\n \t F \t Find a student by Name";
    cout << "\n \t I \t Find a student by ID";
    cout << "\n \t X \t Find a course by name";
    cout << "\n \t A \t Find a course by code";
    cout << "\n \t B \t Find a course by location";
    cout << "\n \t R \t Remove a course from the list by course code";
    cout << "\n \t ? \t Display this menu" << endl;
}

char GetAChar(const char* promptString)
{
    char response; 
    cout << "\nPlease enter the capital letter of the menu choice you would like to select: ";
    cin >> response;
    cin.get();
    
    return response;
}

bool Legal(char c) // Determine if a particular character, c, corresponds to a legal menu command
{
    return ((c == 'C') || (c == 'S') || (c == 'U') || (c == 'L') ||
    (c == 'F') || (c == 'I') || (c == 'X') || (c == 'A') || (c == 'B') ||(c == 'R') || (c == '?'));
}

char GetCommand() // Prompts the user for a menu command until a legal command character is entered
{
    char cmd = GetAChar("\n \n >"); // Get a command character
    
    while (!Legal(cmd)) // As long as it's not a legal command, display menu and try again
    {
        cout << "\n Illegal command, please try again...";
        ShowMenu();
        cmd = GetAChar("\n \n >");
    }

    return cmd;
}

int main()
{
    ShowMenu(); // Display menu 
    char command;
    Course c;
    CourseList l;

    do
    {
        command = GetCommand();
        
        switch (command)
        {
            case 'C': l.AddCourse();                    break;
            case 'U': l.UpdateCourse();                 break; 
            case 'L': cout << "\nList of Courses: \n\n" << l << endl;              break;
            case 'F': l.FindStudentByName();            break;
            case 'I': l.FindStudentByID();              break;
            case 'X': l.FindCourseByName();             break;
            case 'A': l.FindCourseByCode();             break;
            case 'B': l.FindCourseByLoc();              break;
            case 'R': c.RemoveCourse();                 break;
            case '?': ShowMenu();                       break;
        }

    } while (command != 'Q');

}
