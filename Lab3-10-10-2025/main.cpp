#include <iostream>
#include <string>

using namespace std;
void Exercise1();
void Exercise2();
tuple<string, string> GetData();
void DisplayData(const tuple<string, string> &);
void DisplayDataInformation(const tuple<string, string> &);
void ConcatenateDataAndDisplay(const tuple<string, string> &);
unsigned long SearchForWord(const tuple<string, string> &);
void ExtractWordAndDisplay(const tuple<string, string> &, unsigned long );
tuple<string, string> ReplaceWord(const tuple<string, string> &, unsigned long index);
void CompareDataAndDisplay(const tuple<string, string> &);

int main() {
    Exercise1();
    Exercise2();
    return 0;
}

void Exercise1() {
    // Part 0
    auto data = GetData();
    string sentence = std::get<0>(data);
    string word = std::get<1>(data);

    // Part 1
    DisplayData(data);

    // Part 2
    DisplayDataInformation(data);

    // Part 3
    ConcatenateDataAndDisplay(data);

    // Part 4
    const auto wordIndex = SearchForWord(data);
    cout << "Found word at index: " + (wordIndex != -1 ? to_string(wordIndex) : "Word Not Found")
    << endl;

    // Part 5
    if (wordIndex != -1) {
        ExtractWordAndDisplay(data, wordIndex);
        // Part 6
        data = ReplaceWord(data, wordIndex);
        DisplayData(data);
        cout << "Removing first three characters... \n";
        std::get<0>(data).erase(0,3);
        DisplayData(data);
    }
    CompareDataAndDisplay(data);
}

tuple<string, string> GetData() {
    cout << "Enter the sentence \n";
    string sentence;
    getline(cin, sentence);
    cout << "Enter the word \n";
    string word;
    getline(cin, word);
    return {sentence, word};
}

void DisplayData(const tuple<string, string> &data) {
    cout << "Sentence is : " << get<0>(data) << endl;
    cout << "Word is : " << get<1>(data) << endl;
}

void DisplayDataInformation(const tuple<string, string> &data) {
    const auto sentence = get<0>(data);
    const auto word = get<1>(data);
    cout << "Length of the sentence is: " << sentence.length() << endl;
    cout << "Length of the word is: " << word.length() << endl;
    if (sentence.empty()) {
        cout << "Sentence is empty" << endl;
    }
    if (word.empty()) {
        cout << "Word is empty" << endl;
    }
}

void ConcatenateDataAndDisplay(const tuple<string, string> &data) {
    const auto sentence = get<0>(data);
    const auto word = get<1>(data);
    const string concatenated = sentence + " " + word;
    cout << "Concatenated sentence is : " << concatenated << "\n";
}

unsigned long SearchForWord(const tuple<string, string> &data) {
    const auto sentence = get<0>(data);
    const auto word = get<1>(data);
    return sentence.find(word);
}

void ExtractWordAndDisplay(const tuple<string, string> &data, const unsigned long index) {
    const auto sentence = get<0>(data);
    const string extractedWord = sentence.substr(index, 10);
    cout << "Extracted word is: " << extractedWord << "\n";
}

tuple<string, string> ReplaceWord(const tuple<string, string> & data, const unsigned long index) {
    cout << "Enter the word to replace with: \n";
    string newWord;
    getline(cin, newWord);
    string sentence = get<0>(data);
    const string word = get<1>(data);
    sentence.replace(index, word.length(), newWord);
    return {sentence, newWord };
}

void CompareDataAndDisplay(const tuple<string, string> &data) {
    const auto sentence = get<0>(data);
    switch (const auto word = get<1>(data); sentence.compare(word)) {
        case 0:
            cout << "Sentence is same as the word \n";
            break;
        case 1:
            cout << "Word is greater \n";
            break;
        default:
            cout << "Sentence is greater \n";
    }
}

void Exercise2() {
    cout << "Enter your full name \n";
    string name;
    getline(cin, name);
    constexpr char spaceDelimiter = ' ';
    const auto firstSpaceIndex = name.find_first_of(spaceDelimiter);
    const string firstNameSubString = name.substr(0, firstSpaceIndex);
    cout << "Your first name is: " << firstNameSubString << endl;
    for (int i = 0; i < name.length(); i++) {
        if (name[i] == spaceDelimiter) {
            constexpr char underscore = '_';
            name.replace(i,1,1,underscore);
        }
    }
    cout << "After replacement, we will have: " << name << " \n";
}