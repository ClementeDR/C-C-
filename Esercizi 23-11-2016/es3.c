//
// Created by clemente on 23/11/16.
//

#include "esercizi.h"

void diffNumbersFromFile(char *fileName){
    FILE *file;
    file = fopen(fileName, "r");
    if(file != NULL) {
        int value = 0;
        int total = 0;
        while (!feof(file)) {
            fscanf(file, "%d\n",&value);
            if (total == 0){
                total = value;
            } else
                total -= value;
        }
        printf("Il totale e' %d \n", total);
        fclose(file);
    } else {
        printf("No file \n");
    }
}