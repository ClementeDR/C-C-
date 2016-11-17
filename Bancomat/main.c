#include "bancomatfunction.h"

#define INITIAL_BALANCE  10000

int main() {
    int balance = INITIAL_BALANCE;
    int vChoice;

    operationNode * head = NULL;
    head = malloc(sizeof(operationNode));
    head->next = NULL;

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


