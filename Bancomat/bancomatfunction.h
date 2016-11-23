//
// Created by clemente on 16/11/16.
//

#ifndef BANCOMAT_BANCOMATFUNCTION_H
#define BANCOMAT_BANCOMATFUNCTION_H

#define WITHDRAWAL "Prelievo"
#define DEPOSIT "Versamento"

#include <stdio.h>
#include <time.h>
#include <malloc.h>
#include "nodeobjectclass.h"
#include "operationstruct.h"

/***
 * prelievo denaro
 */
void withdrawal(operationNode * head, int * aBalance);

/***
 * deposito denaro
 */
void deposit(operationNode * head, int * aBalance);

/***
 * Estratto contro per mostrare tutti i movimenti
 * in ingresso e in uscita
 * in più mostro i saldo alla data odierna
 */
void bankStatement(operationNode * head, int * aBalance);

/***
 * mostro tutti gli output per il menù
 * Prelievo
 * Versamento
 * Estratto conto
 * Exit
 *
 */
void menu();

/***
 * Inserisco i messaggi di fine operazione
 */
void endOperationMessages();

/***
 * Serve per salvare le operazioni effettuate
 */
void saveOperation(operationNode * head, struct operation  aOperation);

void saveOperationToFile(struct operation *aOperation);

/***
 * Load all operations
 * @param head
 */
void loadOperations(operationNode * head, int *balance);

char* concat(const char *s1, const char *s2);

#endif //BANCOMAT_BANCOMATFUNCTION_H
