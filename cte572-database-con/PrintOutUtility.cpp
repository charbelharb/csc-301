//
// Created by charbel on 11/21/25.
//

#include "PrintOutUtility.h"

#include <iomanip>
#include <iostream>

void PrintOutUtility::DisplayCarriers(const vector<Dto::Carrier>& carriers) {
    cout << "Printing carriers ..." << endl;
    constexpr int idWidth = 39;
    constexpr int codeWidth = 16;
    constexpr int totalWidth = idWidth + codeWidth + 3;

    // Print table header
    std::cout << std::setfill('-') << std::setw(totalWidth) << "" << std::endl;
    std::cout << std::setfill(' ');
    std::cout << "| " << std::left << std::setw(idWidth - 2) << "Id"
              << "| " << std::left << std::setw(codeWidth - 2) << "Code"
              << "|" << std::endl;
    std::cout << std::setfill('-') << std::setw(totalWidth) << "" << std::endl;
    std::cout << std::setfill(' ');

    // Printing records
    for (auto carrier : carriers) {
        std::cout << "| " << std::left << std::setw(idWidth - 2) << carrier.GetId()
                  << "| " << std::left << std::setw(codeWidth - 2) << carrier.GetCode()
                  << "|" << std::endl;
    }
    // Print table footer
    std::cout << std::setfill('-') << std::setw(totalWidth) << "" << std::endl;
}
