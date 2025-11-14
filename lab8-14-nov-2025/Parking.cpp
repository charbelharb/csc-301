//
// Created by charbel on 11/14/25.
//

#include "Parking.h"

#include <iostream>

using namespace std;
void Parking::AddCar(const Car& car) {
    if (this->_addedCarIndex >= this->_capacity) {
        cout << "Capacity Reached - skipping \n";
        return;
    }
    this->_cars[this->_addedCarIndex] = car;
    this->_addedCarIndex++;
}

void Parking::DisplayAll() const {
    for (int i = 0; i < this->_addedCarIndex; i++) {
        this->_cars[i].Display();
    }
}

tuple<int, Car*> Parking::FindCarsByBrand(const string& Brand) const {
    auto foundCars = new Car[this->_addedCarIndex]; // using max capacity
    int j = 0;
    for (int i = 0; i < this->_addedCarIndex; i++) {
        if (this->_cars[i].GetBrand() == Brand) {
            foundCars[j++] = this->_cars[i];
        }
    }
    return {j, foundCars};
}





