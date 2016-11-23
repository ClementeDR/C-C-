//
// Created by clemente on 23/11/16.
//

#include "esercizi.h"

void esercizio6(char *fileName){

    FILE *file;
    file = fopen(fileName, "r");
    if(file != NULL) {
        int value = 0;
        int min, max;
        int total = 0;
        double count = 0;
        while (!feof(file)) {
            fscanf(file, "%d\n",&value);
            if(total == 0){
                min = value;
                max = total;
            }
            if(min > value){
                min = value;
            }
            if(max < value){
                max = value;
            }

            total += value;
            count++;

        }

        printf("Minimo:  %d, Massimo: %d, Media: %.2f \n",min, max,(total / count));
        fclose(file);
    } else {
        printf("No file \n");
    }
}
