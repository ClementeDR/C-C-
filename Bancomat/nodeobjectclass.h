//
// Created by clemente on 16/11/16.
//


#ifndef BANCOMAT_NODEOBJECTCLASS_H
#define BANCOMAT_NODEOBJECTCLASS_H
#include "operationstruct.h"

typedef struct node {
    struct operation operation;
    struct node * next;
} operationNode;


#endif //BANCOMAT_NODEOBJECTCLASS_H
