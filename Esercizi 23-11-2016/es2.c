//
// Created by clemente on 23/11/16.
//



#include "esercizi.h"

void sumNumbersFromFile(char *fileName){
    FILE *file;
    file = fopen(fileName, "r");
    if(file != NULL) {
        int value = 0;
        int total = 0;
        while (!feof(file)) {
            fscanf(file, "%d\n",&value);
            total += value;
        }
        printf("Il totale e' %d \n", total);
        fclose(file);
    } else {
        printf("No file \n");
    }
}