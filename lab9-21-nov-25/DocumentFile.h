//
// Created by charbel on 11/21/25.
//

#ifndef LAB9_21_NOV_25_DOCUMENTFILE_H
#define LAB9_21_NOV_25_DOCUMENTFILE_H
#include "File.h"


class DocumentFile final : File {
    int _numberOfPages;

public:
    DocumentFile(const string &fileName, const double size, const int numberOfPages)
        : File(fileName, size) {
        _numberOfPages = numberOfPages;
    }

    void displayInfo() override;
    void exportFile() override;
    double getFileSize() override;
};


#endif //LAB9_21_NOV_25_DOCUMENTFILE_H