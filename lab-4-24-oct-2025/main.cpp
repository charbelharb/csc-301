#include <algorithm>
#include <iostream>
using namespace std;

struct Person {
    string FirstName;
    string LastName;
};
struct Student {
    Person Name;
    int Age{};
    string Major;
    double GPA{};
};
struct Student3 {
    string Name;
    int Age{};
    double GPA{};
};
void DisplayStudentElement(const Student &);
void Exercise1();
void Exercise2();
void Exercise3();
void DisplayStudent3Element(const Student3 *student);
void Exercise4();
void Exercise5();

int main() {
    Exercise1();
    Exercise2();
    Exercise3();
    Exercise4();
    Exercise5();
    return 0;
}
;
void Exercise1() {
    cout << "Enter number of student \n";
    int numberOfStudents;
    cin >> numberOfStudents;
    auto* students = new Student[numberOfStudents];

    for (int i = 0; i < numberOfStudents; i++) {
        Student currentStudentIteration = {};
        cout << "Entering Student " << i + 1 << " Information\n";
        cout << "Enter First Name: ";
        cin >> currentStudentIteration.Name.FirstName;
        cout << "Enter Last Name: ";
        cin >> currentStudentIteration.Name.LastName;
        cout << "Enter Age: ";
        cin >> currentStudentIteration.Age;
        cout << "Enter Major: ";
        cin >> currentStudentIteration.Major;
        cout << "Enter GPA: ";
        cin >> currentStudentIteration.GPA;
        students[i] = currentStudentIteration;
    }

    // Display, calculate avg GPA, find student highest GPA
    double SumOfGpa = 0;
    tuple StudentWithHighestGpa = {0, students[0].GPA};
    for (int i = 0; i < numberOfStudents; i++) {
        cout << "Student " << i + 1 << " Information\n";
        DisplayStudentElement(students[i]);
        SumOfGpa += students[i].GPA;
        if (students[i].GPA > get<1>(StudentWithHighestGpa)) {
            StudentWithHighestGpa = {i, students[i].GPA};
        }
    }
    cout << "Average GPA is : " << SumOfGpa / numberOfStudents << " \n";
    cout << "Student with highest GPA is student number: " << get<0>(StudentWithHighestGpa) + 1 << " \n";
    cout << "Student with highest GPA Info: \n";
    DisplayStudentElement(students[get<0>(StudentWithHighestGpa)]);
    delete[] students;
}

void DisplayStudentElement(const Student &student) {
    cout << "First Name: " << student.Name.FirstName << "\n";
    cout << "Last Name: " << student.Name.LastName << "\n";
    cout << "Age: " << student.Age << " \n";
    cout << "Major: " << student.Major << "\n";
    cout << "GPA: " << student.GPA << " \n";
}

void Exercise2() {
    constexpr int size = 2;
    int* arr [size];
    for (auto & i : arr) {
        i = new int;
        cout << "Enter value for element \n";
        cin >> *i;
    }
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += *arr[i];
        cout << "Printing element " << i + 1 << " \n";
        cout << *arr[i] << "\n";
    }
    cout << "Sum of the elements is " << sum << " \n";

    cout << "Printing element addresses \n";
    cout << "First element: " << &arr << " \n";
    for (int i = 0; i < size; i++) {
        // i = 0; same as &arr
        cout << "Element at index " << i+1 << ": " << &arr[i] << "\n";
    }
    for (auto & i : arr) {
        delete i;
    }
}

void Exercise3() {
    constexpr int arr_size = 2;
    Student3* arr [arr_size];
    for (int i = 0; i < arr_size; i++) {
        arr[i] = new Student3;
        cout << "Enter value for Student number " << i + 1 << " \n";
        cout << "Enter First Name: \n";
        cin >> arr[i]->Name;
        cout << "Enter Age: \n";
        cin >> arr[i]->Age;
        cout << "Enter GPA: \n";
        cin >> arr[i]->GPA;
    }
    tuple StudentWithHighestGpa = {0, arr[0]->GPA};
    for (int i = 0; i < arr_size; i++) {
        cout << "Student " << i + 1 << " Information\n";
        DisplayStudent3Element(arr[i]);
        if (arr[i]->GPA > get<1>(StudentWithHighestGpa)) {
            StudentWithHighestGpa = {i, arr[i]->GPA};
        }
    }
    cout << "Student with highest GPA is: \n";
    DisplayStudent3Element(arr[get<0>(StudentWithHighestGpa)]);
    for (auto & i : arr) {
        delete i;
    }
}

void DisplayStudent3Element(const Student3 *student) {
    cout << "First Name: " << student->Name << "\n";
    cout << "Age: " << student->Age << " \n";
    cout << "GPA: " << student->GPA << " \n";
}

void Exercise4() {
    cout << "Enter number of element \n";
    int arr_size;
    cin >> arr_size;
    const auto arr = new int[arr_size];
    for (int i = 0; i < arr_size; i++) {
        cout << "Enter value for element " << i + 1 << " \n";
        cin >> arr[i];
    }
    cout << "Displaying in reverse \n";
    for (int i = arr_size-1 ; i > -1; --i) {
        cout << arr[i] << "\n";
    }
    delete[] arr;
}

void Exercise5() {
    constexpr int size = 3;
    string* arr [size];
    for (int i = 0; i < size; i++) {
        arr[i] = new string;
        cout << "Enter value for student " << i + 1 << " \n";
        cin >> *arr[i];
    }
    cout << "Student name entered \n";
    for (auto & i : arr) {
        string currentIteration = *i;
        transform(currentIteration.begin(),
                  currentIteration.end(),
                  currentIteration.begin(),
                   [](char c){ return toupper(c); });
        cout << currentIteration << "\n";
    }
    for (auto & i : arr) {
        delete i;
    }
}