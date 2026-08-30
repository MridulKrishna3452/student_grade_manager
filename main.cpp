#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Structure to store student information
struct Student {
    string name;
    int rollNumber;
    float marks[5];
    float total;
    float average;
    char grade;
};

// Function to calculate total and average
void calculateResult(Student &student) {
    student.total = 0;

    for (int i = 0; i < 5; i++) {
        student.total += student.marks[i];
    }

    student.average = student.total / 5;

    // Calculate grade
    if (student.average >= 90)
        student.grade = 'A';
    else if (student.average >= 80)
        student.grade = 'B';
    else if (student.average >= 70)
        student.grade = 'C';
    else if (student.average >= 60)
        student.grade = 'D';
    else if (student.average >= 50)
        student.grade = 'E';
    else
        student.grade = 'F';
}

// Function to display a student's result
void displayStudent(const Student &student) {
    cout << "\n----------------------------------------\n";
    cout << "          STUDENT RESULT\n";
    cout << "----------------------------------------\n";

    cout << "Name       : " << student.name << endl;
    cout << "Roll Number: " << student.rollNumber << endl;

    cout << fixed << setprecision(2);

    cout << "\nSubject Marks:\n";

    for (int i = 0; i < 5; i++) {
        cout << "Subject " << i + 1 << " : "
             << student.marks[i] << endl;
    }

    cout << "\nTotal      : " << student.total << " / 500" << endl;
    cout << "Average    : " << student.average << "%" << endl;
    cout << "Grade      : " << student.grade << endl;

    if (student.grade == 'F')
        cout << "Status     : FAIL" << endl;
    else
        cout << "Status     : PASS" << endl;

    cout << "----------------------------------------\n";
}

int main() {

    int n;

    cout << "========================================\n";
    cout << "       STUDENT GRADE MANAGER\n";
    cout << "========================================\n";

    cout << "\nEnter number of students: ";
    cin >> n;

    // Validate number of students
    if (n <= 0) {
        cout << "Invalid number of students.\n";
        return 0;
    }

    Student students[n];

    // Input student details
    for (int i = 0; i < n; i++) {

        cout << "\n========================================\n";
        cout << "Enter details for Student " << i + 1 << endl;
        cout << "========================================\n";

        cin.ignore();

        cout << "Enter name: ";
        getline(cin, students[i].name);

        cout << "Enter roll number: ";
        cin >> students[i].rollNumber;

        cout << "\nEnter marks for 5 subjects:\n";

        for (int j = 0; j < 5; j++) {

            do {
                cout << "Subject " << j + 1 << ": ";
                cin >> students[i].marks[j];

                if (students[i].marks[j] < 0 ||
                    students[i].marks[j] > 100) {

                    cout << "Marks must be between 0 and 100.\n";
                }

            } while (students[i].marks[j] < 0 ||
                     students[i].marks[j] > 100);
        }

        // Calculate result
        calculateResult(students[i]);
    }

    // Display all student results
    cout << "\n\n========================================\n";
    cout << "          ALL STUDENT RESULTS\n";
    cout << "========================================\n";

    for (int i = 0; i < n; i++) {
        displayStudent(students[i]);
    }

    // Find topper
    int topperIndex = 0;

    for (int i = 1; i < n; i++) {

        if (students[i].average >
            students[topperIndex].average) {

            topperIndex = i;
        }
    }

    cout << "\n========================================\n";
    cout << "              CLASS TOPPER\n";
    cout << "========================================\n";

    cout << "Name    : "
         << students[topperIndex].name << endl;

    cout << "Roll No : "
         << students[topperIndex].rollNumber << endl;

    cout << "Average : "
         << fixed << setprecision(2)
         << students[topperIndex].average << "%" << endl;

    cout << "Grade   : "
         << students[topperIndex].grade << endl;

    cout << "========================================\n";

    cout << "\nThank you for using Student Grade Manager!\n";

    return 0;
}