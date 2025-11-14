//
// Created by charbel on 11/14/25.
//

#ifndef LAB8_14_NOV_2025_CAR_H
#define LAB8_14_NOV_2025_CAR_H
#include <string>
#include <utility>
using namespace std;

class Car {
    string Brand;
    string Model;
    int Year{};
    double Price{};

public:
    Car() : Car("Unknown", "N/A", 0,0) {  }
    Car(const Car &car) : Car(car.Brand, car.Model, car.Year, car.Price) {  }
    Car(string Brand, string Model, const int Year, const double Price) {
        this->Brand = std::move(Brand);
        this->Model = std::move(Model);
        this->Year = Year;
        this->Price = Price;
    }
    ~Car() {
        // Nothing to do here
    };
    void Display() const;
    string GetBrand();
};


#endif //LAB8_14_NOV_2025_CAR_H