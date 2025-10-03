#include <iostream>
using namespace std;

struct Student {
    string name;
    int age{};
    float grade{};
};

void PartOne();
int* ReadArray(int );
void DisplayArray(int*, int);
int FindIndex(int *, int, int);
void FindAllOccurrences(int *, int, int);
void Statistics(int*, int);
void SortArray(int*, int);
void ConcatTwoArrays();

// Part II
void PartTwo();
Student* ReadStudentArray(int);
void DisplayStudentArray(Student*, int);
int FindStudentByName(Student*, string, int);



int main() {
    //PartOne();
    PartTwo();
    return 0;
}

void PartOne() {
    // Exercise 1
    int arr_size;
    cout << "Enter the size of the array \n";
    cin >> arr_size;
    if (arr_size <= 0) {
        cout << "The array size must be greater than 0 \n";
        cout << "Exiting...\n";
        return;
    }
    int* arr = ReadArray(arr_size);
    DisplayArray(arr, arr_size);

    // Exercise 2
    cout << "Enter the element to find in the array \n";
    int element_to_find;
    cin >> element_to_find;
    int lookup_index = FindIndex(arr, element_to_find, arr_size );
    cout << "The element is at index " << lookup_index << endl;

    // Exercise 3
    FindAllOccurrences(arr, element_to_find, arr_size);

    // Exercise 4
    Statistics(arr, arr_size);

    // Exercise 5
    cout << "Array before sorting: \n";
    DisplayArray(arr, arr_size);
    SortArray(arr, arr_size);
    DisplayArray(arr, arr_size);
    delete[] arr;

    // Exercise 6
    ConcatTwoArrays();
}

int* ReadArray(int arr_size) {
    int* arr = new int[arr_size];
    for (int i = 0; i < arr_size; i++) {
        cout << "Enter element " << i+1 << " : ";
        cin >> arr[i];
        cout << endl;
    }
    return arr;
}

int FindIndex(int *arr, int element, int arr_size) {
    for (int i = 0; i < arr_size; i++) {
        if (arr[i] == element) {
            return i;
        }
    }
    return -1;
}

void DisplayArray(int* arr, int arr_size) {
    cout << "Displaying the array \n";
    for (int i = 0; i < arr_size; i++) {
        cout << "Element " << i + 1 << ": " << arr[i] << " " << endl;
    }
}

void FindAllOccurrences(int* arr, int element, int arr_size) {
    cout << "Finding all occurrences.. \n";
    bool found = false;
    for (int i = 0; i < arr_size; i++) {
        if (arr[i] == element) {
            found = true;
            cout << "Found occurrence at index: " << i << "\n";
        }
    }
    if (!found) {
        cout << "No occurrences found.\n";
    }
}

void Statistics(int * arr, int arr_size) {
    // Finding minimum & Maximum
    int minimum = arr[0];
    int maximum = arr[0];
    int sum = 0;
    for (int i = 0; i < arr_size; i++) {
        if (arr[i] < minimum) {
            minimum = arr[i];
        }
        if (arr[i] > maximum) {
            maximum = arr[i];
        }
        sum += arr[i];
    }
    float average = sum / arr_size;
    cout << "Minimum is: " << minimum << endl;
    cout << "Maximum is: " << maximum << endl;
    cout << "Average is: " << average << endl;
}

void SortArray(int* arr, const int arr_size) {
    // Insertion: Fix element 0
    for (int i = 1; i < arr_size; i++) {
        const int currentIteration = arr[i];
        int previousIndex = i - 1;
        while (previousIndex >= 0 && arr[previousIndex] > currentIteration) {
            arr[previousIndex + 1] = arr[previousIndex];
            previousIndex--;
        }
        arr[previousIndex + 1] = currentIteration;
    }
}

void ConcatTwoArrays() {
    cout << "Enter size of array 1 to concat: \n";
    int array_one_size;
    cin >> array_one_size;
    if (array_one_size <= 0) {
        cout << "The array size must be greater than 0 \n";
        cout << "Exiting...\n";
        return;
    }
    cout << "Enter size of array 2 to concat: \n";
    int array_two_size;
    cin >> array_two_size;
    if (array_two_size <= 0) {
        cout << "The array size must be greater than 0 \n";
        cout << "Exiting...\n";
        return;
    }
    int* array_one = ReadArray(array_one_size);
    int* array_two = ReadArray(array_two_size);
    int concatinate_array_size = array_one_size + array_two_size;
    int* concatinated_array = new int[array_one_size];

    // Copying array 1
    for (int i = 0; i < array_one_size; i++) {
        concatinated_array[i] = array_one[i];
    }
    // Copying array 2
    for (int i = array_one_size,j = 0; i < concatinate_array_size; i++,j++) {
        concatinated_array[i] = array_two[j];
    }
    cout << "Concatenated Array: \n";
    DisplayArray(concatinated_array, concatinate_array_size);

    delete[] array_one;
    delete[] array_two;
    delete[] concatinated_array;
}

// Part II

void PartTwo() {
    int arr_size;
    cout << "Enter the size of the array \n";
    cin >> arr_size;
    if (arr_size <= 0) {
        cout << "The array size must be greater than 0 \n";
        cout << "Exiting...\n";
        return;
    }
    Student* students = ReadStudentArray(arr_size);
    DisplayStudentArray(students, arr_size);
    cout << "Enter student name to find in the array \n";
    string student_name;
    cin >> student_name;
    FindStudentByName(students, student_name, arr_size);
    delete[] students;
}

Student* ReadStudentArray(int arr_size) {
    auto* students = new Student[arr_size];
    for (int i = 0; i < arr_size; i++) {
        cout << "Student " << i+1 << " Information : \n";
        cout << "Enter Name: \n";
        cin >> students[i].name;
        cout << "Enter Age: \n";
        cin >> students[i].age;
        cout << "Enter Grade: \n";
        cin >> students[i].grade;
    }
    return students;
}

void DisplayStudentArray(Student* students, int arr_size) {
    for (int i = 0; i < arr_size; i++) {
        cout << "Student " << i+1 << " Information : \n";
        cout << "Student Name: \n";
        cout << students[i].name << endl;
        cout << "Student Age: \n";
        cout << students[i].age << endl;
        cout << "Student Grade: \n";
        cout << students[i].grade << endl;
        cout << endl;
    }
}

int FindStudentByName(const string &name, const Student* students, int arr_size) {
    for (int i = 0; i < arr_size; i++) {
        if (students[i].name == name) {
            return i;
        }
    }
    return -1;
}

