//
// Created by clemente on 23/11/16.
//
#include "esercizi.h"

void mulNumbersFromFile(char *fileName){
    FILE *file;
    file = fopen(fileName, "r");
    if(file != NULL) {
        int value = 0;
        double total = 1;
        while (!feof(file)) {
            fscanf(file, "%d\n",&value);
            if (total == 1){
                total = value;
            } else
                total *= value;
        }
        if(total == 0){
            printf("Il totale e' 0 \n");
        } else {
            printf("Il totale e' %e \n", total);
        }

        fclose(file);
    } else {
        printf("No file \n");
    }
}