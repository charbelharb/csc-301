//
// Created by charbel on 11/21/25.
//

#include "ImageFile.h"

#include <iostream>
#include <ostream>

void ImageFile::displayInfo() {
    cout << "[Image] " << this->name << " - Size: " <<
        this->sizeMB << " MB - Resolution: " << this->_resolution
    << " px" << endl;
}

void ImageFile::exportFile() {
    cout << "Exporting Image as PNG..." << endl;
}

double ImageFile::getFileSize() {
    return this->sizeMB;
}
