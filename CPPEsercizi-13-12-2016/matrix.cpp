//
// Created by cdr on 13/12/16.
//

#include <cstdlib>
#include "matrix.h"

using namespace std;


int * init_matrix(int length){
    int matrix[length][length];

    srand((unsigned)time(NULL));
    int i = 0;
    for (i = 0 ; i < length ; i++) {
        int j = 0;
        for (j = 0 ; j < length ; j++)
            matrix[i][j] = rand() % 50;
    }
    return *matrix;
}


void matrix_ex1(int (*matrix)[20][20], int dim){
    int total = 0;
//    cout<<"dim "<<dim<<endl;
//    for (int i = 0 ; i < dim ; i++) {
//        cout<<"dim"<<dim<<endl;
//        for (int j = 0 ; j < dim ; j++){
//            cout<<"total"<<total<<endl;
//            total += matrix[i][j];
//
//        }
//    }
//    cout<<"Il totale e' "<<total<<endl;

    int i = 0;
    for (i = 0 ; i < dim ; i++) {
        cout<<"dim"<<dim<<endl;
        for (int j = 0 ; j < dim ; j++){
            total += (*matrix)[i][j];
            cout<<"total "<<total<< " i = "<<i<<" j = "<<j<<" value = "<<matrix[i][j]<<endl;
        }
    }
    cout<<"Il totale e' "<<total<<endl;
}


void matrix_ex2(int * matrix[], int dim){

}

void matrix_ex3(int * matrix[], int dim){

}

void matrix_ex4(int * matrix[], int dim){

}

void matrix_ex5(int * matrix[], int dim){

}