#include <iostream>
#include <vector>

using namespace std;
constexpr int MAX_STUDENTS = 3;
struct Student {
    string FirstName;
    string LastName;
    int Age;
    string Major;
    double Gpa;
};
void LiveSorting(Student students[MAX_STUDENTS], const Student &currentIteration, int currentPosition);
int main() {
    // vector overkill - using array
    Student students[MAX_STUDENTS] = {};

    for (int i = 0; i < MAX_STUDENTS; i++) {
        Student currentIteration = {};
        cout << "Enter Student #" << i + 1 << " information: \n";
        cout << "First Name: \n";
        cin >> currentIteration.FirstName;
        cout << "Last Name: \n";
        cin >> currentIteration.LastName;
        cout << "Age: \n";
        cin >> currentIteration.Age;
        cout << "Major: \n";
        cin >> currentIteration.Major;
        cout << "Gpa: \n";
        cin >> currentIteration.Gpa;
        // Live sorting (Insertion sort)
        LiveSorting(students, currentIteration, i);
    }

    for (int i = MAX_STUDENTS -1; i>=0; i--) {
        cout << "GPA: " << students[i].Gpa << endl;
    }
}

void LiveSorting(Student students[MAX_STUDENTS], const Student &currentIteration, int currentPosition) {
    while (currentPosition > 0 && students[currentPosition - 1].Gpa > currentIteration.Gpa) {
        students[currentPosition] = students[currentPosition - 1];
        currentPosition--;
    }
    students[currentPosition] = currentIteration;
}

