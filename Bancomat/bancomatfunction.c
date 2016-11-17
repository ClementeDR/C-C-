//
// Created by clemente on 16/11/16.
//

#include "bancomatfunction.h"

void menu(){
    printf("Selezionare l'operazione desiderata \n");
    printf("1. Prelievo \n");
    printf("2. Versamento \n");
    printf("3. Estratto conto \n");
    printf("0. Exit \n");
}

void withdrawal(operationNode * head, int * aBalance){
    printf("Hai selezionato prelievo \n");
    printf("Attendere... \n");

    int vAmount = 0;

    do{
        printf("Inserire l'importo da prelevare \n");
        scanf("%i", &vAmount);
        if (vAmount <= 0) {
            printf("Hai inserito un importo errato \n");
        }
    }while(vAmount <= 0);

    if (vAmount > *aBalance){
        printf("Non e' possibile prelevare poiche' ha inserito un importo maggiore rispetto al suo saldo \n");
    } else {
        *aBalance -= vAmount;
        struct operation * withdrawal_operation = malloc(sizeof(struct operation));

        withdrawal_operation->amount = vAmount;
        withdrawal_operation->current_time = time(NULL);
        withdrawal_operation->operationType = WITHDRAWAL;

        saveOperation(head, *withdrawal_operation);

        printf("Importo: %i \n", withdrawal_operation->amount);
        printf("Data:  %s \n", ctime(&withdrawal_operation->current_time));
        printf("Tipo Operazione: %s \n", withdrawal_operation->operationType);

        free(withdrawal_operation);
    }
    endOperationMessages();
}


void deposit(operationNode * head, int * aBalance){
    printf("Hai selezionato deposito \n");
    printf("Attendere... \n");

    int vAmount;
    printf("Inserire l'importo da versare \n");
    scanf("%i", &vAmount);

    *aBalance += vAmount;

    struct operation * deposit_operation = malloc(sizeof(struct operation));
    deposit_operation->amount = vAmount;
    deposit_operation->current_time = time(NULL);
    deposit_operation->operationType = DEPOSIT;

    saveOperation(head, *deposit_operation);

    printf("Saldo corrente: %i \n", *aBalance);

    free(deposit_operation);

    endOperationMessages();
}

void bankStatement(operationNode * head, int * aBalance){
    printf("Hai selezionato estratto conto \n");
    printf("Attendere... \n");

    operationNode * current = head;
    while (current->next != NULL) {
        printf("     Tipo operazione %s \n", current->operation.operationType);
        printf("     Importo %d € \n",current->operation.amount);
        printf("     Data : %s \n", ctime(&current->operation.current_time));
        printf("     ---------------- \n");
        current = current->next;
    }
    printf("Saldo corrente: %d \n", *aBalance );

    endOperationMessages();
}

void endOperationMessages(){
    printf("Operazione terminata \n");
    printf("Reindirizzamento al menu' principale. Attendere... \n");
    printf("-----------------  \n");
}

void saveOperation(operationNode * head, struct operation aOperation){
    operationNode * newOperationNode;
    newOperationNode = malloc(sizeof(operationNode));
    newOperationNode->operation = head->operation;
    newOperationNode->next = head->next;
    head->operation = aOperation;
    head->next = newOperationNode;
    printf(" \n Operazione avvenuta con successo \n");
}