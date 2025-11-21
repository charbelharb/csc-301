//
// Created by charbel on 11/21/25.
//

#ifndef LAB9_21_NOV_25_AUDIOFILE_H
#define LAB9_21_NOV_25_AUDIOFILE_H
#include "File.h"


class AudioFile final : File {
int _durationSec;
    public:
    AudioFile(const string &fileName, const double size, const int duration)
            : File(fileName, size) {
        _durationSec = duration;
    }

    void displayInfo() override;
    void exportFile() override;
    double getFileSize() override;
};


#endif //LAB9_21_NOV_25_AUDIOFILE_H