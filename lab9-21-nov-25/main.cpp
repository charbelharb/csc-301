#include <iostream>
#include <memory>
#include <vector>

#include "AudioFile.h"
#include "DocumentFile.h"
#include "ImageFile.h"

int main() {
    const auto firstImageTest = new ImageFile(
        "Test-1", 2, 1000);
    const auto secondAudioTest = new AudioFile("Gavotte II -- Bach", 10, 120);
    const auto thirdDocumentTest = new DocumentFile("The C++ programming language - Bjarne Stroustrup.",
        20, 1336);

    vector<File*> library = {};
    library.push_back(reinterpret_cast<vector<File *>::value_type>(firstImageTest));
    library.push_back(reinterpret_cast<vector<File *>::value_type>(secondAudioTest));
    library.push_back(reinterpret_cast<vector<File *>::value_type>(thirdDocumentTest));
    for (const auto f : library) {
        f->displayInfo();
        f->exportFile();
    }
    int userInputMinSize;

    cout << "Enter minimum file size \n";
    cin >> userInputMinSize;
    for (const auto f : library) {
        if (f->getFileSize() >= userInputMinSize) {
            f->displayInfo();
            f->exportFile();
        }
    }

    for (const auto f : library) {
        delete f;
    }
    return 0;
}
