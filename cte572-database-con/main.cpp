#include <iostream>
#include <memory>

#include "PrintOutUtility.h"
#include "Repository.h"
#include "Dto/Carrier.h"
using namespace std;

int main() {
    const auto repository = std::make_unique<Repository>(
"dbname=uls user=postgres password=123 host=127.0.0.1 port=5432"
    );
    const auto carriers = repository->GetAllCarriers();
    PrintOutUtility::DisplayCarriers(carriers);
    return 0;
}