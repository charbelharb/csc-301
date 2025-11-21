//
// Created by charbel on 11/21/25.
//

#ifndef CTE572_DATABASE_CON_PRINTOUTUTILITY_H
#define CTE572_DATABASE_CON_PRINTOUTUTILITY_H
#include <vector>

#include "Dto/Carrier.h"


class PrintOutUtility {
public:
    static void DisplayCarriers(const vector<Dto::Carrier>& carriers);
};


#endif //CTE572_DATABASE_CON_PRINTOUTUTILITY_H