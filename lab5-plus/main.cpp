#include <iostream>
using namespace std;

void Exercise1();
void Exercise2();
void Exercise3();
void Exercise4();

int main() {
    Exercise1();
    Exercise2();
    Exercise3();
    Exercise4();
    return 0;
}

void Exercise1() {
    int numberOfElements;
    cout << "Enter number of elements: ";
    cin >> numberOfElements;
    const auto arr = new int[numberOfElements];
    for (int i = 0; i < numberOfElements; i++) {
        cout << "Enter element #" << i + 1 << ": \n";
        cin >> arr[i];
    }
    cout << "Printing elements \n";
    for (int i = 0; i < numberOfElements; i++) {
        cout << "Element #" << i + 1 << ": " << arr[i] << endl;
    }
    delete[] arr;
}

void Exercise2() {
    constexpr int size = 3;
    string* arr [size];
    for (int i = 0; i < size; i++) {
        arr[i] = new string;
        cout << "Enter value for element " << i + 1 << " \n";
        cin >> *arr[i];
    }
    cout << " Printing elements \n";
    for (auto & i : arr) {
        string currentIteration = *i;
        cout << currentIteration << "\n";
    }
    for (auto & i : arr) {
        delete i;
    }
}

void Exercise3() {
    int rows, columns;
    cout << "Enter number of rows: \n";
    cin >> rows;
    cout << "Enter number of columns: \n";
    cin >> columns;
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[columns];
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << "Enter value for element M(" << i << "," << j << ") \n";
            cin >> matrix[i][j];
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << "Element M(" << i << "," << j << ") is: " << matrix[i][j] << " ";
        }
    }
    for (int i = 0; i < rows; i++) {
       delete[] matrix[i];
    }
    delete[] matrix;
}

void Exercise4() {
    int a = 3;
    int* p = &a;
    int** q = &p;
    cout << "a = " << a << "\n";
    cout << "value stored in p = " << p << "\n";
    cout << "value stored in q = " << q << "\n";
    cout << "Dereferenced value in *p = " << *p << "\n";
    cout << "Dereferenced value in *q = " << *q << "\n";
    cout << "Dereferenced value in **q = " << *q << "\n";
}