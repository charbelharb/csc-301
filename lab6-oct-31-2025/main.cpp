#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

void Exercise1();
void Exercise2();
void Exercise3();
void Exercise4();
void Exercise5();

int main() {
    //Exercise1();
    //Exercise2();
    //Exercise3();
    //Exercise4();
    Exercise5();
    return 0;
}

void Exercise1() {
    char* names[5];
    const int maxSize = 50;
    for (int i = 0; i < 5; i++) {
        cout << "Enter name for iteration " << i << endl;
        names[i] = new char[maxSize];
        cin.getline(names[i], maxSize);
    }
    for (int i = 0; i < 5; i++) {
        cout << "Name for iteration " << i << ":" << names[i] << endl;
    }
}

void Exercise2() {
    int a = 1, b = 1, c = 1;
    int* ptrs[3] = { &a, &b, &c };
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        sum += *ptrs[i];
    }
    cout << "Sum is: " << sum << endl;
}

void Exercise3() {
    constexpr int SquareMatrixSize = 3;
    int sum = 0;
    int matrix [SquareMatrixSize][SquareMatrixSize];
    for (int i = 0; i < SquareMatrixSize; i++) {
        for (int j = 0; j < SquareMatrixSize; j++) {
            cout << "Enter value for element M(" << i << "," << j << ") \n";
            cin >> matrix[i][j];
            sum += matrix[i][j];
        }
    }
    cout << "Sum is: " << sum << endl;
}

void Exercise4() {
    int rows, columns;
    cout << "Enter number of rows: \n";
    cin >> rows;
    cout << "Enter number of columns: \n";
    cin >> columns;
    if (rows == 0 && columns == 0) {
        cout << "Null Matrix \n";
        return;
    }
    int sum = 0;
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[columns];
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << "Enter value for element M(" << i << "," << j << ") \n";
            cin >> matrix[i][j];
            sum += matrix[i][j];
        }
    }
    setprecision(2);
    float average = 0.f;
    float numberOfElements = 0.f;
    numberOfElements = rows * columns;
    average = sum / numberOfElements;
    cout << "Average is: " << average;
    // cleanup
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void Exercise5() {
    int rows;
    vector<int> namesWithGradesOver10;
    cout << "Enter number of Students: \n";
    cin >> rows;
    if (rows == 0) {
        cout << "No student added \n";
        return;
    }
    char** studentArray = new char*[rows];

    for (int i = 0; i < rows; i++) {
        cout << "Enter name for student " << i+1 << ":\n";
        string studentName;
        cin >> studentName;
        studentArray[i] = new char[100];
        cout << "Enter grade for student " << i+1 << ":\n";
        double grade_value;
        cin >> grade_value;

        char* data = studentName.data();
        studentArray[i] = data;
        if (grade_value < 10) {
            continue;
        }
        namesWithGradesOver10.push_back(i);
    }

    cout << "Student with grade over 10: " << endl;
    for (int i = 0; i < namesWithGradesOver10.size(); i++) {
        cout << "Student " << studentArray[namesWithGradesOver10[i]] << endl;
    }

    // Cleanup
    delete[] studentArray;
}