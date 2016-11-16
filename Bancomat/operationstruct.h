//
// Created by clemente on 16/11/16.
//

#ifndef BANCOMAT_OPERATIONSTRUCT_H
#define BANCOMAT_OPERATIONSTRUCT_H

#include <time.h>

struct operation {
    int amount;
    char * operationType;
    time_t current_time;
};
#endif //BANCOMAT_OPERATIONSTRUCT_H
