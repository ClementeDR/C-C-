//
// Created by clemente on 23/11/16.
//


#include "esercizi.h"

#define FILE_NAME "./numbers.txt"

void menu();

int main(){

    int vChoise = 0;
    loadFile(FILE_NAME);

    do{
        menu();
        scanf("%d", &vChoise);

        switch (vChoise){
            case 0:
                printf("Bye \n");
                break;
            case 1:
                printNumbers(FILE_NAME);
                break;

            case 2:
                sumNumbersFromFile(FILE_NAME);
                break;

            case 3:
                diffNumbersFromFile(FILE_NAME);
                break;

            case 4:
                mulNumbersFromFile(FILE_NAME);
                break;

            case 5:
                average(FILE_NAME);
                break;

            case 6:
                esercizio6(FILE_NAME);
                break;

            default:
                printf("Function not available \n");
                break;
        }

    }while (vChoise != 0);


    return 0;
}

void menu(){
    printf("Scegli l'esercizio \n");
    printf("1. Esercizio 1 \n");
    printf("2. Esercizio 2 \n");
    printf("3. Esercizio 3 \n");
    printf("4. Esercizio 4 \n");
    printf("5. Esercizio 5 \n");
    printf("6. Esercizio 6 \n");


    printf("0. Esci \n");



}