//
// Created by clemente on 23/11/16.
//
#include "esercizi.h"

void printNumbers(char *fileName){
    FILE *file;
    file = fopen(fileName, "r");
    if(file != NULL) {
        int value = 0;
        while (!feof(file)) {
            fscanf(file, "%d\n",&value);
            printf("%d \n", value);
        }
        fclose(file);
    } else {
        printf("No file \n");
    }

}