//
// Created by charbel on 11/14/25.
//

#ifndef LAB8_14_NOV_2025_PARKING_H
#define LAB8_14_NOV_2025_PARKING_H
#include "Car.h"


class Parking {
    int _capacity;
    int _addedCarIndex = 0;
    Car * _cars;

public:
    Parking() : _capacity(10) {
        _cars = new Car[_capacity];
    }

    explicit Parking(const int capacity) {
        _capacity = capacity;
        _cars = new Car[_capacity];
    }

    Parking(const Parking& copy) {
        _capacity = copy._capacity;
        _cars = new Car[_capacity];
        _addedCarIndex = copy._addedCarIndex;
        _cars = copy._cars;
    }

    ~Parking() {
        delete[] _cars;
    }

    void AddCar(const Car& car);
    void DisplayAll() const;
    tuple<int, Car*> FindCarsByBrand(const string& Brand) const;
};


#endif //LAB8_14_NOV_2025_PARKING_H