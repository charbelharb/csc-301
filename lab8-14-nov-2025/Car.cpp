//
// Created by charbel on 11/14/25.
//

#include "Car.h"

#include <iostream>

using namespace std;
void Car::Display() const {
    cout << "Car Info \n";
    cout << "Brand: " << this->Brand << "\n";
    cout << "Model: " << this->Model << "\n";
    cout << "Year: " << this->Year << "\n";
    cout << "Price: " << this->Price << "\n";
}

string Car::GetBrand() {
    return this->Brand;
}
