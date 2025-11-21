//
// Created by charbel on 11/21/25.
//

#ifndef LAB9_21_NOV_25_IMAGEFILE_H
#define LAB9_21_NOV_25_IMAGEFILE_H
#include "File.h"


class ImageFile final : File {
    int _resolution;

    public:
        ImageFile(const string &fileName, const double size, const int resolution)
            : File(fileName, size) {
            _resolution = resolution;
        }

    void displayInfo() override;
    void exportFile() override;
    double getFileSize() override;
};


#endif //LAB9_21_NOV_25_IMAGEFILE_H