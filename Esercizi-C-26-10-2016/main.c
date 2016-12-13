//
// Created by clemente on 26/10/16.
//

#include <stdio.h>
#include "esercizic.c"


int main(){
    int dim = 10;
    int numbers[dim];
    int command;

    int i;
    //riempio l'array con valori da 1-10 ma mi scoccio di scriverli a mano
    for (i = 0; i < dim; i++){
        numbers[i] = i + 1;
    }

    do{
        printf("Inserisci il comando per: \n");
        printf("1) Per esercizio 1 \n");
        printf("2) Per esercizio 2 \n");
        printf("3) Per esercizio 3 \n");
        printf("4) Per esercizio 4 \n");
        printf("5) Per esercizio 5 \n");
        printf("6) Per esercizio 6 \n");
        printf("7) Per esercizio 7 \n");
        printf("8) Per esercizio 8 \n");
        printf("9) Per esercizio 9 \n");
        printf("0) Per Uscire \n");

        scanf("%i", &command);
        switch (command){
            case 1:
                printf("Esercizio %d \n", command);
                esercizio1(numbers, dim);
                break;
            case 2:
                printf("Esercizio %d \n", command);
                esercizio2(numbers, dim);
                break;
            case 3:
                printf("Esercizio %d \n", command);
                esercizio3(numbers, dim);
                break;
            case 4:
                printf("Esercizio %d \n", command);
                esercizio4();
                break;
            case 5:
                printf("Esercizio %d \n", command);
                esercizio5();
                break;
            case 6:
                printf("Esercizio %d \n", command);
                esercizio6();
                break;
            case 7:
                printf("Esercizio %d \n", command);
                esercizio7();
                break;
            case 8:
                printf("Esercizio %d \n", command);
                esercizio8();
                break;
            case 9:
                printf("Esercizio %d \n", command);
                esercizio9();
                break;
            case 0:
                printf("Alla prossima \n");
                break;

            case 69:
                printf("Porcellino \n");
                break;

            default:
                printf("Bischero -.- \n");
                break;

        }


        printf("---------------------\n");
    }while(command != 0);


    return 0;
}

