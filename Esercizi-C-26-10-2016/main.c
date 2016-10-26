//
// Created by clemente on 26/10/16.
//
#include <stdio.h>

void showFloatArray(float numbers[], int dim);

void esercizio1(int numbers[], int dim);

void esercizio2(int numbers[], int dim);

void esercizio3(int numbers[], int dim);

void esercizio4();

void esercizio5();

void esercizio6();

void esercizio7();

void esercizio8();

void esercizio9();

float floatNumbers[] = {35.4, 46.7, 77.55, 11.1, 9.04, 0.75 };


int main(){
    int dim = 10;
    int numbers[dim];

    int i;
    //riempio l'array con valori da 1-10 ma mi scoccio di scriverli a mano
    for (i = 0; i < dim; i++){
        numbers[i] = i + 1;
    }

    esercizio1(numbers, dim);

    esercizio2(numbers, dim);

    esercizio3(numbers, dim);

    esercizio4();

    esercizio5();

    esercizio6();

    esercizio7();

    esercizio8();

    esercizio9();


    return 0;
}


void esercizio1(int numbers[], int dim){
    int i;
   // int dim = sizeof(numbers) / sizeof(int);
    for (i = 0; i < dim; i++){
        printf("[%d] =  %d \n", i, numbers[i]);
    }
}

void esercizio2(int numbers[], int dim){
    int i;

   // int dim = sizeof(numbers) / sizeof(int);
    int sum = 0;

    for (i = 0; i < dim; i++){
       sum += numbers[i];
    }

    printf("La somma e' %d \n", sum);

}

void esercizio3(int numbers[], int dim){

   // int dim = sizeof(numbers) / sizeof(int);
    int i;
    int diff = numbers[0];
    for (i = 1; i < dim; i++){
        diff -= numbers[i];
    }

    printf("La differenza e' %d \n", diff);

}

void esercizio4(){
    float tot = 1;
    int i;

    int dim = sizeof(floatNumbers) / sizeof(int);
    for(i = 0; i < dim; i++){
        tot *= floatNumbers[i];
    }

    printf("Il prodotto dei numeri float e' %.2f \n", tot);
}

void esercizio5(){

    float tot = floatNumbers[0];
    int dim = sizeof(floatNumbers) / sizeof(int);
    int i;
    for(i = 1; i < dim; i++){
        tot -= floatNumbers[i];
    }

    printf("La DIFFERENZA dei numeri float e' %.2f \n", tot);
}


void esercizio6(){

    float tot = floatNumbers[0];
    int i;
    for(i = 1; i < 6; i++){
        tot += floatNumbers[i];
    }

    tot /= 6;

    printf("La MEDIA dei numeri float e' %.2f \n", tot);
}

void esercizio7(){

    float tot = 0;
    int dim = sizeof(floatNumbers) / sizeof(int);
    int divisore = 0;
    int i;
    for(i = 0; i < dim; i++){
        tot += floatNumbers[i] * (5 - i);
        divisore += (5 - i);
    }

    tot /= divisore;

    printf("La MEDIA PONDERATA e' %.2f \n " , tot);


}

void esercizio8(){
    float tot = floatNumbers[0];
    float max = tot;
    float min = tot;
    int i;
    int dim = sizeof(floatNumbers) / sizeof(int);
    for(i = 1; i < dim; i++){
        tot += floatNumbers[i];
        if(max < floatNumbers[i]){
            max = floatNumbers[i];
        } else if(min > floatNumbers[i]){
            min = floatNumbers[i];
        }
    }

    tot /= dim;

    printf("La MEDIA e' %.2f il MASSIMO e' %.2f il MINIMO e' %.2f \n", tot, max, min);
}

void esercizio9(){
    int i,j;
    int dim = sizeof(floatNumbers) / sizeof(int);;
    float tmp;

    for(i = 0; i < dim; i++) {
        for (j = 0; j < dim - 1; j++) {
            if (floatNumbers[j] > floatNumbers[j + 1]) {
                tmp = floatNumbers[j];
                floatNumbers[j] = floatNumbers[j + 1];
                floatNumbers[j + 1] = tmp;
            }
        }
    }

    printf("Arrai crescente\n");

    showFloatArray(floatNumbers, dim);

    printf("------------------------\n");

    for(i = 0; i < dim; i++) {
        for (j = 0; j < dim - 1; j++) {
            if (floatNumbers[j]<floatNumbers[ j + 1 ]) {
                tmp = floatNumbers[j];
                floatNumbers[j] = floatNumbers[j + 1];
                floatNumbers[j + 1] = tmp;
            }
        }
    }

    printf("Arrai decrescente\n");

    showFloatArray(floatNumbers, dim);

}


void showFloatArray(float numbers[], int dim){
    int i;
    for (i = 0; i < dim; i++){
        printf("%d =  %.2f \n", i, numbers[i]);
    }
}