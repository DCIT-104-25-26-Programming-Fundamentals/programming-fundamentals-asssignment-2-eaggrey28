// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 8
// =============================================================================
//
// TASK: Student Record Management System
//
// Build a console-based program that stores and manages student information.
// Use a struct to represent each student record containing:
//
//   - name   : the student's full name  (string)
//   - id     : a unique student ID number (int, e.g. 20240001)
//   - scores : a list of scores from multiple assessments (vector<double>)
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Student
//      - Ask the user to enter the student's name and ID.
//      - Ask how many scores to enter, then collect each score one by one.
//      - Save the student record and confirm it was added.
//
//   2. Display All Students
//      - Print a formatted table showing every student's:
//          Name, ID, individual scores, and their average score.
//      - If no students have been added yet, print a message saying so.
//
//   3. Calculate Average Score for a Specific Student
//      - Ask the user to enter a student ID.
//      - Find the student and print their average score.
//      - If the ID is not found, print an error message.
//
//   4. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ================================
//      STUDENT RECORD SYSTEM MENU
//   ================================
//   1. Add student
//   2. Display all students
//   3. Calculate average score
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Student name: Alice Mensah
//   Student ID: 20240001
//   How many scores? 3
//   Enter score 1: 78
//   Enter score 2: 85
//   Enter score 3: 90
//   Student "Alice Mensah" added successfully.
//
//   Enter your choice (1-4): 3
//   Enter student ID: 20240001
//   Alice Mensah's average score: 84.33
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Define a struct called Student (see scaffold below).
// - Store all records in a vector<Student>.
// - Average scores must be rounded to 2 decimal places (use setprecision(2)).
// - Each feature MUST be in its own function.
// - Handle invalid menu choices and missing student IDs gracefully.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct Student {
    string name;
    int id;
    vector<double> scores;
};

void displayMenu() {
    cout << "\n================================" << endl;
    cout << "   STUDENT RECORD SYSTEM MENU" << endl;
    cout << "================================" << endl;
    cout << "1. Add student" << endl;
    cout << "2. Display all students" << endl;
    cout << "3. Calculate average score" << endl;
    cout << "4. Quit" << endl;
    cout << "Enter your choice (1-4): ";
}

double calculateAverage(const Student& student) {
    if (student.scores.empty()) {
        return 0.0;
    }

    double total = 0.0;
    for (double score : student.scores) {
        total += score;
    }
    return total / student.scores.size();
}

bool studentIdExists(const vector<Student>& students, int id) {
    for (const Student& student : students) {
        if (student.id == id) {
            return true;
        }
    }
    return false;
}

void addStudent(vector<Student>& students) {
    Student student;

    cout << "Student name: ";
    getline(cin >> ws, student.name);
    if (student.name.empty()) {
        cout << "Error: Student name cannot be empty." << endl;
        return;
    }

    cout << "Student ID: ";
    if (!(cin >> student.id) || student.id <= 0) {
        cout << "Error: Student ID must be a positive integer." << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        return;
    }

    if (studentIdExists(students, student.id)) {
        cout << "Error: That student ID already exists." << endl;
        return;
    }

    int scoreCount;
    cout << "How many scores? ";
    if (!(cin >> scoreCount) || scoreCount < 1) {
        cout << "Error: Enter at least one score." << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        return;
    }

    for (int index = 0; index < scoreCount; index++) {
        double score;
        cout << "Enter score " << index + 1 << ": ";
        if (!(cin >> score) || score < 0 || score > 100) {
            cout << "Error: Scores must be numbers from 0 to 100." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            return;
        }
        student.scores.push_back(score);
    }

    students.push_back(student);
    cout << "Student \"" << student.name << "\" added successfully." << endl;
}

void displayAllStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No student records have been added yet." << endl;
        return;
    }

    cout << fixed << setprecision(2);
    cout << "\nStudent Records:" << endl;
    for (const Student& student : students) {
        cout << "Name: " << student.name << endl;
        cout << "ID: " << student.id << endl;
        cout << "Scores: ";
        for (size_t index = 0; index < student.scores.size(); index++) {
            if (index > 0) {
                cout << ", ";
            }
            cout << student.scores[index];
        }
        cout << endl;
        cout << "Average: " << calculateAverage(student) << endl;
        cout << "------------------------------" << endl;
    }
}

void calculateStudentAverage(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No student records have been added yet." << endl;
        return;
    }

    int id;
    cout << "Enter student ID: ";
    if (!(cin >> id)) {
        cout << "Error: Please enter a valid student ID." << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        return;
    }

    for (const Student& student : students) {
        if (student.id == id) {
            cout << fixed << setprecision(2);
            cout << student.name << "'s average score: "
                 << calculateAverage(student) << endl;
            return;
        }
    }

    cout << "Error: Student ID not found." << endl;
}

int main() {
    vector<Student> students;
    int choice = 0;

    do {
        displayMenu();

        if (!(cin >> choice)) {
            if (cin.eof()) {
                cout << "\nGoodbye!" << endl;
                break;
            }

            cout << "Error: Please enter a number from 1 to 4." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                displayAllStudents(students);
                break;
            case 3:
                calculateStudentAverage(students);
                break;
            case 4:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Error: Invalid choice. Please select 1 to 4." << endl;
        }
    } while (choice != 4);

    return 0;
}
