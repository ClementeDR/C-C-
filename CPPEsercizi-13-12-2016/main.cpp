
#include <iostream>
#include "esercizi.h"
#include "matrix.h"

using namespace std;

#define MATRIX_LENGTH 20

int main() {
    int command;
  //  std::cout << "Hello, World!" << std::endl;
    int dim;
   // cout<<"inserisci il numero di elementi"<<endl;
   //// cin>>dim;
    dim = 50;

    int numbers[dim];
    for (int i = 0; i < dim; i++){
        numbers[i] = i + 1;
    }

    int matrix_length = MATRIX_LENGTH;
    int matrix[MATRIX_LENGTH][MATRIX_LENGTH];

    srand((unsigned)time(NULL));
    int i = 0;
    // scorro le righe
    for (i=0; i <matrix_length; i++) {
        int j = 0;
        // scorro le colonne
        for (j=0;j<matrix_length;j++)
            // assegno all'elemento [X][Y] il valore
            matrix[i] [j] = rand() % 50;
    }

    // scorro le righe
    for (i=0; i <matrix_length; i++) {
        int j = 0;
        // scorro le colonne
        for (j=0;j<matrix_length;j++)
            // assegno all'elemento [X][Y] il valore
           cout<<matrix[i][j]<<"\t";
    }


    int total = 0;
    for (i = 0 ; i < matrix_length ; i++) {
        cout<<"dim"<<matrix_length<<endl;
        for (int j = 0 ; j < matrix_length ; j++){
            total += matrix[i][j];
            cout<<"total "<<total<< " i = "<<i<<" j = "<<j<<" value = "<<matrix[i][j]<<endl;
        }
    }
    cout<<"Il totale e' "<<total<<endl;


    do{
        cout<<"Inserisci il comando per: \n";
        cout<<"1) Per Esercizio  1 \n";
        cout<<"2) Per Esercizio  2 \n";
        cout<<"3) Per Esercizio  3 \n";
        cout<<"4) Per Esercizio  4 \n";
        cout<<"5) Per Esercizio  5 \n";
        cout<<"6) Per Esercizio  6 \n";
        cout<<"7) Per Esercizio  7 \n";
        cout<<"8) Per Esercizio  8 \n";
        cout<<"9) Per Esercizio  9 \n";
        cout<<"Esercizi delle matrici \n";
        cout<<"11) Per Esercizio  1 \n";
        cout<<"12) Per Esercizio  2 \n";
        cout<<"13) Per Esercizio  3 \n";
        cout<<"14) Per Esercizio  4 \n";
        cout<<"15) Per Esercizio  5 \n";
        cout<<"16) Per Esercizio  6 \n";
        cout<<"17) Per Esercizio  7 \n";
        cout<<"18) Per Esercizio  8 \n";
        cout<<"19) Per Esercizio  9 \n";
        cout<<"0) Per Uscire \n";

        cin>>command;
        switch (command){
            case 1:
                cout<<"Esercizio "<<command<<endl;
                esercizio1(numbers, dim);
                break;
            case 2:
                cout<<"Esercizio "<<command<<endl;
                esercizio2(numbers, dim);
                break;
            case 3:
                cout<<"Esercizio "<<command<<endl;
                esercizio3(numbers, dim);
                break;
            case 4:
                cout<<"Esercizio "<<command<<endl;
                esercizio4();
                break;
            case 5:
                cout<<"Esercizio "<<command<<endl;
                esercizio5();
                break;
            case 6:
                cout<<"Esercizio "<<command<<endl;
                esercizio6();
                break;
            case 7:
                cout<<"Esercizio "<<command<<endl;
                esercizio7();
                break;
            case 8:
                cout<<"Esercizio "<<command<<endl;
                esercizio8();
                break;
            case 9:
                cout<<"Esercizio "<<command<<endl;
                esercizio9();
                break;


            case 11:
                cout<<"Esercizio "<<command<<" dime "<<matrix_length<<endl;

                int (*m)[MATRIX_LENGTH][MATRIX_LENGTH] = &matrix;


                matrix_ex1(m, matrix_length);
                break;
            case 12:
                cout<<"Esercizio "<<command<<endl;
                matrix_ex2((int **) matrix, matrix_length);
                break;
            case 13:
                cout<<"Esercizio "<<command<<endl;
                matrix_ex3((int **) matrix, matrix_length);
                break;
            case 14:
                cout<<"Esercizio "<<command<<endl;
                matrix_ex4((int **) matrix, matrix_length);
                break;
            case 15:
                cout<<"Esercizio "<<command<<endl;
                matrix_ex5((int **) matrix, matrix_length);
                break;
            case 0:
                cout<<"Alla prossima \n";
                break;

            case 69:
                cout<<"Porcellino \n";
                break;

            default:
                cout<<"Bischero -.- \n";
                break;

        }
        cout<<"---------------------\n";

    }while(command != 0);



    return 0;

}

