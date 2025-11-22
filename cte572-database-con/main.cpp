#include <iostream>
#include <memory>

#include "PrintOutUtility.h"
#include "Repository.h"
#include "Dto/Carrier.h"
using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    const auto repository = std::make_unique<Repository>(
"dbname=uls user=postgres password=123 host=127.0.0.1 port=5432"
    );
    const auto print_utility = std::make_unique<PrintOutUtility>();
    const auto carriers = repository->GetAllCarriers();
    PrintOutUtility::DisplayCarriers(carriers);
    return 0;
}