//
// Created by charbel on 11/21/25.
//

#include "DocumentFile.h"

#include <iostream>

void DocumentFile::displayInfo() {
    cout << "[Document] " << this->name << " - Size: " <<
        this->sizeMB << " MB - Number of pages: " << this->_numberOfPages
     << endl;
}

void DocumentFile::exportFile() {
    cout << "Exporting Document as PDF..." << endl;
}

double DocumentFile::getFileSize() {
    return this->sizeMB;
}