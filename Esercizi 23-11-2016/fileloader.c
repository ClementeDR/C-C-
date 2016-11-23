//
// Created by clemente on 23/11/16.
//

#include "esercizi.h"

void loadFile(char *fileName){
    srand((unsigned int) time(NULL));
    int maxNumber = 1000;
    int minNumber = 0;
    int numberToSet = rand() % (maxNumber - minNumber + 1);

    int numbers[numberToSet];
    FILE *file;
    file = fopen(fileName, "w");
    if(file != NULL) {
        int vIndexSet = 0;
        for (vIndexSet = 0; vIndexSet < numberToSet; ++vIndexSet) {
            numbers[vIndexSet] = rand() % (maxNumber - minNumber + 1);
            printf("Number: %d \n", numbers[vIndexSet]);
            fprintf(file, "%i \n", numbers[vIndexSet]);
        }
        fclose(file);
    } else {
        printf("No file \n");
    }



}
