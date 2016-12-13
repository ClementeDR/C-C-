//
// Created by cdr on 13/12/16.
//


#include <iostream>
#include <iomanip>
#include "esercizi.h"
using namespace std;

float floatNumbers[] = {35.4, 46.7, 77.55, 11.1, 9.04, 0.75 };

void esercizio1(int numbers[], int dim){
    int i;
    // int dim = sizeof(numbers) / sizeof(int);
    for (i = 0; i < dim; i++){
        cout<<"["<<i<<"] =  " <<numbers[i]<<endl;
    }
}

void esercizio2(int numbers[], int dim){
    int i;

    // int dim = sizeof(numbers) / sizeof(int);
    int sum = 0;

    for (i = 0; i < dim; i++){
        sum += numbers[i];
    }

    cout<<"La somma e' "<<sum<<endl;

}

void esercizio3(int numbers[], int dim){

    // int dim = sizeof(numbers) / sizeof(int);
    int i;
    int diff = numbers[0];
    for (i = 1; i < dim; i++){
        diff -= numbers[i];
    }

    cout<<"La differenza e' "<<diff<<endl;

}

void esercizio4(){
    float tot = 1;
    int i;

    int dim = sizeof(floatNumbers) / sizeof(int);
    for(i = 0; i < dim; i++){
        cout<<"tot "<<tot<<" number "<<floatNumbers[i]<<endl;
        tot *= floatNumbers[i];
    }

    cout<<"Il prodotto dei numeri float e' "<<tot<<endl;
}

void esercizio5(){

    float tot = floatNumbers[0];
    int dim = sizeof(floatNumbers) / sizeof(int);
    int i;
    for(i = 1; i < dim; i++){
        tot -= floatNumbers[i];
    }

    cout<<"La DIFFERENZA dei numeri float e' "<< setprecision(3)<<tot<<endl;
}


void esercizio6(){

    float tot = floatNumbers[0];
    int i;
    for(i = 1; i < 6; i++){
        tot += floatNumbers[i];
    }

    tot /= 6;

    cout<<"La MEDIA dei numeri float e' "<<tot<<endl;
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

    cout<<"La MEDIA PONDERATA e' "<<tot<<endl;


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

   cout<<"La MEDIA e' "<<tot<<" il MASSIMO e' "<<max<<" il MINIMO e' "<<min<<endl;
}

void showFloatArray(float numbers[], int dim){
    int i;
    for (i = 0; i < dim; i++){
        cout<<i<<" = "<<numbers[i]<<endl;
    }
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

    cout<<"------------------------\n";

    for(i = 0; i < dim; i++) {
        for (j = 0; j < dim - 1; j++) {
            if (floatNumbers[j]<floatNumbers[ j + 1 ]) {
                tmp = floatNumbers[j];
                floatNumbers[j] = floatNumbers[j + 1];
                floatNumbers[j + 1] = tmp;
            }
        }
    }

    cout<<"Arrai decrescente"<<endl;

    showFloatArray(floatNumbers, dim);

}


