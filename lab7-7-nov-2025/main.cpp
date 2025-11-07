#include <algorithm>
#include <fstream>
#include <iostream>
#include <ranges>
#include <vector>
using namespace std;

void Exercise1();
void Exercise2();
void Exercise3();
void PopulateExercise2(const string &fileName);
void PopulateExercise3(const string &fileName);
struct Produit {
    string nom;
    double prix;
    int quantite;
};
int main() {
    Exercise3();
    return 0;
}

void Exercise1() {
    string fileName = "noms.txt";
    ofstream noms(fileName);
    ifstream nomsReadOnly(fileName);
    if (noms.is_open()) {
        const string BreakString = "STOP";
        cout << "Start entering name - Type " << BreakString << " to exit \n";
        string input;
        cout << "Enter names : ";
        while (input != BreakString) {
            getline(cin, input);
            if (input != BreakString) {
                noms << input << endl;
            }
        }
        noms.close();
    }
    else {
        cout << "I/O Error" << endl;
    }

    if (nomsReadOnly.is_open()) {
        string nomLine;
        while (std::getline(nomsReadOnly, nomLine)) {
            std::cout << nomLine << std::endl;
        }
        nomsReadOnly.close();
    }
}

void Exercise2() {
    const string fileName = "notes.txt";
    const int maxSize = 4;
    PopulateExercise2(fileName);
    ifstream notesReadOnly(fileName);
    if (notesReadOnly.is_open()) {
        auto* noms = new string[maxSize];
        auto* grades = new double[maxSize];
        vector<pair<int, double>> notesUsedForSorting = {};
        string noteLine;
        string delimiter = " ";
        int counter = 0;
        double sumOfNote = 0.0;
        while (std::getline(notesReadOnly, noteLine)) {
            auto delimPos = noteLine.find(delimiter);
            string name = noteLine.substr(0, delimPos);
            string note = noteLine.substr(delimPos + 1);
            noms[counter] = name;
            auto doubleNote = stod(note);
            sumOfNote+= doubleNote;
            notesUsedForSorting.emplace_back(counter, doubleNote);
            grades[counter++] = doubleNote;
            if (doubleNote >= 10) {
                cout << "Student: " << name << " Grade: " << doubleNote << "\n";
                cout << "-------- \n";
            }
        }
        double averageNote = sumOfNote / maxSize;
        cout << "Average Note: " << averageNote << endl;
        // sorting using algorithm sort & lambda; second is to compare based on note
        // and not the index
        sort(notesUsedForSorting.begin(), notesUsedForSorting.end(),
            [](auto &left, auto &right){
                return left.second > right.second;
        });
        cout << "Sorted Notes: " << endl;
        for (int i = 0; i < notesUsedForSorting.size(); i++) {
            int index = notesUsedForSorting[i].first;
            cout << "Student name: " << noms[index] << endl;
            cout << "Studen Grade: " << grades[index] << endl;
            cout << "------------- \n";
        }
        delete[] noms;
        delete[] grades;
    }
    else {
        cout << "I/O Error" << endl;
    }

}

void PopulateExercise2(const string &fileName) {
    ofstream notes(fileName);
    if (notes.is_open()) {
        notes << "Ali 14" << endl;
        notes << "Ibrahim 18" << endl;
        notes << "Majd 12" << endl;
        notes << "Sara 9" << endl;
        notes.close();
    }
    else {
        cout << "I/O Error" << endl;
    }
}

void Exercise3() {
    const string fileName = "produits.txt";
    const string rapportFileName = "rapports.txt";
    vector<Produit> products = {};
    PopulateExercise3(fileName);
    ifstream produitsReadOnly(fileName);
    ofstream rapports(rapportFileName);
    double totalStock = 0.0;
    if (produitsReadOnly.is_open() && rapports.is_open()) {
        string delimiter = " ";
        string productLine;

        while (std::getline(produitsReadOnly, productLine)) {
            vector<string> looperData = {};
            for (const auto& word_view : productLine | std::views::split(delimiter)) {
                looperData.emplace_back(word_view.begin(), word_view.end());
            }
            string name = looperData[0];
            double price = stod(looperData[1]);
            int quantity = stoi(looperData[2]);
            products.push_back({name, price, quantity});
            totalStock += price * quantity;
            if (price > 20) {
                rapports << productLine << endl;
            }
            looperData = {};
        }

        cout << "Displaying products: " << endl;
        for (int i = 0; i < products.size(); i++) {
            cout << "Product # " << i+1 << endl;
            cout << "Name: " << products[i].nom << endl;
            cout << "Quantity: " << products[i].quantite << endl;
            cout << "Price: " << products[i].prix << endl;
            cout << " \n";
        }
    }
}

void PopulateExercise3(const string &fileName) {
    ofstream notes(fileName);
    if (notes.is_open()) {
        notes << "Pain 1.5 10" << endl;
        notes << "Lait 2.0 20" << endl;
        notes << "Café 5.5 8" << endl;
        notes.close();
    }
    else {
        cout << "I/O Error" << endl;
    }
}

