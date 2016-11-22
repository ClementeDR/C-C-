#include <thread_db.h>
#include "bancomatfunction.h"

#define INITIAL_BALANCE  0

int main() {
    int balance = INITIAL_BALANCE;
    int vChoice;

    operationNode * head = NULL;
    head = malloc(sizeof(operationNode));
    head->next = NULL;


    printf("Caricamento");
    int vTempIndex;
    for (vTempIndex = 0; vTempIndex < 5; ++vTempIndex) {
        printf(".");
    }
    printf("\n");

    loadOperations(head, &balance);

    do{
        menu();
        scanf("%i", &vChoice);
        printf("------------------------ \n");

        switch (vChoice){
            case 0:
                printf("Arrivederci \n");
                break;

            case 1:
                withdrawal(head, &balance);
                break;

            case 2:
                deposit(head, &balance);
                break;

            case 3:
                bankStatement(head, &balance);
                break;
            default:
                printf("Operazione non permessa \n");
                break;
        }
    }while(vChoice != 0);

    return 0;
}


