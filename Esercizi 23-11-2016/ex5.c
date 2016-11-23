//
// Created by clemente on 23/11/16.
//
#include "esercizi.h"

void average(char *fileName){
    FILE *file;
    file = fopen(fileName, "r");
    if(file != NULL) {
        int count = 0;
        int value = 0;
        double total = 0;
        while (!feof(file)) {
            fscanf(file, "%d\n",&value);
            total += value;
            count++;
        }
        printf("La media e' %.2f \n", (total / count));
        fclose(file);
    } else {
        printf("No file \n");
    }
}