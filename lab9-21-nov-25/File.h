//
// Created by charbel on 11/21/25.
//

#ifndef LAB9_21_NOV_25_FILE_H
#define LAB9_21_NOV_25_FILE_H
#include <string>
#pragma once
using namespace std;

class File {
protected:
    // Force protected ctor
    File(const string &fileName, const double size) {
        this->name = fileName;
        this->sizeMB = size;
    }
    string name;
    double sizeMB;
public:
    virtual ~File() = default;
    virtual void displayInfo() {};
    virtual void exportFile() {};
    virtual double getFileSize() {};
};


#endif //LAB9_21_NOV_25_FILE_H