#include <iostream>

#include "Car.h"
#include "Parking.h"

int main() {
    const auto unknownCar = new Car();
     Car* toyota = new Car("Toyota", "Corolla", 2015, 8000);
     auto volvo = new Car("Volvo", "240",1980, 1000);
     auto toyotaCopy = new Car(*toyota);

     auto parking = new Parking(4);
    parking->AddCar(*unknownCar);
    parking->AddCar(*toyota);
    parking->AddCar(*toyotaCopy);
    parking->AddCar(*volvo);
    // Test skipping
    parking->AddCar(*toyotaCopy);

    //parking->DisplayAll();

    // Testing copy
    auto parking2 = new Parking(*parking);
    parking2->DisplayAll();

    auto volvoCar = parking2->FindCarsByBrand("Volvo");
    for (int i = 0; i < std::get<0>(volvoCar); i++) {
        cout << "Found Car: " << i + 1 << endl;
        std::get<1>(volvoCar)[i].Display();
    }

    delete unknownCar;
    delete toyota;
    delete toyotaCopy;
    delete parking;
    delete parking2;
    delete std::get<1>(volvoCar);
    return 0;
}
