#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void Exercise1();
void Exercise2();
vector<int> BuildVectorFromString(const string &userInput);
void DisplayVector(const vector<int> &v, string message);
void DisplayStringVector(const vector<string> &v, string message);
string BuildString(const vector<int> &v);
vector<string> BuildStringVectorFromString(const string &userInput);
bool DoesStringExistInVector(const vector<string> &v, string searchString);

int main() {
    //Exercise1();
    Exercise2();
    return 0;
}

void Exercise1() {
    vector<int> vect = {};
    vector<int> vect2 = {};
    string vectInput;
    string vectInput2;
    cout << "Input 10 integers for V separated by space: \n";
    getline(cin, vectInput);
    //cout << "Input 10 integers for v2 separated by space: ";
    //getline(cin, vectInput2);

    // Vector 1
    vect = BuildVectorFromString(vectInput);
    if (vect.size() <= 9) {
        cout << "Must be at least 10 \n" << endl;
        return;
    }
    DisplayVector(vect, "Original Vector:");
    sort(vect.begin(), vect.end());
    DisplayVector(vect, "Sorted Vector:");
    vect.insert(vect.begin() + 6, 50);
    DisplayVector(vect, "Vecteur après insertion de 50 à l’index 7 \n");
    vect.erase(vect.begin() + 2);
    DisplayVector(vect, "Vecteur après suppression de l’élément à l’index 3 \n");

    // Finding index of 7 only
    vector<int> indexToRemove = {};
    for (int i = 0; i < vect.size(); i++) {
        if (vect[i] == 7) {
            indexToRemove.push_back(i);
        }
    }

    sort(indexToRemove.begin(), indexToRemove.end());
    reverse(indexToRemove.begin(), indexToRemove.end());

    for (int index : indexToRemove) {
        if (index >= 0 && index < vect.size()) {
            vect.erase(vect.begin() + index);
        }
    }
    DisplayVector(vect, "Vecteur après suppression de toutes les occurrences de 7 \n");
}

vector<int> BuildVectorFromString(const string &userInput) {
    vector<int> vect = {};
    int startIndex = 0;
    int endIndex = 0;
    constexpr char spaceDelimiter = ' ';
    for (int i = 0; i < userInput.length(); i++, ++endIndex) {
        if (userInput[i] == spaceDelimiter) {
            vect.push_back(stoi(userInput.substr(startIndex, endIndex - startIndex)));
            startIndex = i+1;
        }
    }
    // Last element - or force space
    vect.push_back(stoi(userInput.substr(startIndex, endIndex)));
    return vect;
}

string BuildString(const vector<int> &v) {
    string result;
    for (const int i : v) {
        result += to_string(i) + " ";
    }
    return result;
}

string BuildStringFromVectorString(const vector<string> &v) {
    string result;
    for (const string& i : v) {
        result += i + " ";
    }
    return result;
}

void DisplayVector(const vector<int> &v, string message) {
    cout << message << " \n";
    string vectorString = BuildString(v);
    cout << vectorString << " \n";
}

void Exercise2() {
    cout << "Enter five cities separated by space: \n";
    string userInput;
    getline(cin, userInput);
    vector<string> cities = BuildStringVectorFromString(userInput);
    DisplayStringVector(cities, "Cities: \n");
    string cityToFind;
    cout << "Enter city to search for: \n";
    cin >> cityToFind;
    string searchResult = DoesStringExistInVector(cities, cityToFind)? "City Found" : "City not Found";
    cout << searchResult << "\n";
    cout << "Enter city to remove \n";
    string cityToRemove;
    cin >> cityToRemove;
    vector<int> indexToRemove = {};
    for (int i = 0; i < cities.size(); i++) {
        if (cities[i] == cityToRemove) {
            indexToRemove.push_back(i);
        }
    }
    sort(indexToRemove.begin(), indexToRemove.end());
    reverse(indexToRemove.begin(), indexToRemove.end());

    for (int index : indexToRemove) {
        if (index >= 0 && index < cities.size()) {
            cities.erase(cities.begin() + index);
        }
    }
    DisplayStringVector(cities, "Cities after deletion: \n");
    sort(cities.begin(), cities.end());
    DisplayStringVector(cities, "Cities after sorting: \n");
}

vector<string> BuildStringVectorFromString(const string &userInput) {
    vector<string> vect = {};
    int startIndex = 0;
    int endIndex = 0;
    constexpr char spaceDelimiter = ' ';
    for (int i = 0; i < userInput.length(); i++, ++endIndex) {
        if (userInput[i] == spaceDelimiter) {
            vect.push_back(userInput.substr(startIndex, endIndex - startIndex));
            startIndex = i+1;
        }
    }
    // Last element - or force space
    vect.push_back(userInput.substr(startIndex, endIndex));
    return vect;
}

void DisplayStringVector(const vector<string> &v, string message) {
    cout << message << " \n";
    const string vectorString = BuildStringFromVectorString(v);
    cout << vectorString << " \n";
}

bool DoesStringExistInVector(const vector<string> &v, string searchString) {
    int count = count_if(v.begin(), v.end(),
        [&](const std::string& s) {
            return s.find(searchString) != std::string::npos;
        });
    return count != 0;
}
