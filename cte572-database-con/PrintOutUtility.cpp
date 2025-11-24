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
    constexpr int nameWidth = 40;
    constexpr int addressWidth = 50;
    constexpr int dotNumberWidth = 16;
    constexpr int mcnNumberWidth = 16;
    constexpr int totalWidth = idWidth + codeWidth + nameWidth + addressWidth + dotNumberWidth + mcnNumberWidth + 3;

    // Print table header
    std::cout << std::setfill('-') << std::setw(totalWidth) << "" << std::endl;
    std::cout << std::setfill(' ');
    std::cout << "| " << std::left << std::setw(idWidth - 2) << "Id"
              << "| " << std::left << std::setw(codeWidth - 2) << "Code"
              << "| " << std::left << std::setw(nameWidth - 2) << "Name"
              << "| " << std::left << std::setw(addressWidth - 2) << "Address"
              << "| " << std::left << std::setw(dotNumberWidth - 2) << "Dot Number"
              << "| " << std::left << std::setw(mcnNumberWidth - 2) << "Mcn number"
              << "|" << std::endl;
    std::cout << std::setfill('-') << std::setw(totalWidth) << "" << std::endl;
    std::cout << std::setfill(' ');

    // Printing records
    for (auto carrier : carriers) {
        std::cout << "| " << std::left << std::setw(idWidth - 2) << carrier.GetId()
                  << "| " << std::left << std::setw(codeWidth - 2) << carrier.GetCode()
                  << "| " << std::left << std::setw(nameWidth - 2) << carrier.GetName()
                  << "| " << std::left << std::setw(addressWidth - 2) << carrier.GetAddress()
                  << "| " << std::left << std::setw(dotNumberWidth - 2) << carrier.GetDotNumber()
                  << "| " << std::left << std::setw(mcnNumberWidth - 2) << carrier.GetMcnNumber()
                  << "|" << std::endl;
    }
    // Print table footer
    std::cout << std::setfill('-') << std::setw(totalWidth) << "" << std::endl;
}
