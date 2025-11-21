//
// Created by charbel on 11/21/25.
//

#include "AudioFile.h"

#include <iostream>


void AudioFile::displayInfo() {
    cout << "[Audio] " << this->name << " - Size: " <<
        this->sizeMB << " MB - Duration in seconds: " << this->_durationSec
    << " sec" << endl;
}

void AudioFile::exportFile() {
    cout << "Exporting Audio as MP3..." << endl;
}

double AudioFile::getFileSize() {
    return this->sizeMB;
}