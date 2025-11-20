#include <iostream>
#include <memory>

#include "Repository.h"
#include "Dto/Carrier.h"
using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    const auto repository = std::make_unique<Repository>(
"dbname=uls user=postgres password=123 host=127.0.0.1 port=5432"
    );
    auto data = repository->GetAllCarriers();
    return 0;
}