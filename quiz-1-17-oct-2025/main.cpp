#include <algorithm>
#include <iostream>
using namespace std;

void display(const int*, int);
int get_sum(const int*, int);
double get_average(const int*, int);
int find_max(const int*, int);
void sort_arr(int*, int);

int main() {
    int arr_size;
    cout << "Enter size of array: \n";
    cin >> arr_size;
    const auto arr = new int[arr_size];
    for (int i = 0; i < arr_size; i++) {
        cout << "Enter element #" << i + 1 << " : \n";
        cin >> arr[i];
    }
    display(arr, arr_size);
    const int sum = get_sum(arr, arr_size);
    cout << "The sum of all elements is " << sum << " \n";
    const double average = get_average(arr, arr_size);
    cout << "The average of all element is " << average << " \n";
    const int max = find_max(arr, arr_size);
    cout << "The max of all element is " << max << " \n";
    sort_arr(arr, arr_size);
    cout << "The sorted array is: \n";
    display(arr, arr_size);
    delete[] arr;
    return 0;
}

void display(const int* tab, const int n) {
    cout << "Printing array elements \n";
    for (int i = 0; i < n; i++) {
        cout << "Element # " << i+ 1 << " " << tab[i] << " \n";
    }
}

int get_sum(const int* tab, const int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += tab[i];
    }
    return sum;
}

double get_average(const int* tab, const int n) {
    const int sum = get_sum(tab, n);
    return static_cast<double>(sum) / n;
}

int find_max(const int* tab, const int n) {
    int max = tab[0];
    for (int i = 1; i < n; i++) {
        if (tab[i] > max) {
            max = tab[i];
        }
    }
    return max;
}

void sort_arr(int* arr, const int arr_size) {
    // Insertion: Fix element 0
    sort(arr, arr + arr_size);
}