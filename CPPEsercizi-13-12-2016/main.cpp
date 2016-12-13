
#include <iostream>
#include "esercizi.h"

using namespace std;

int main() {
    int command;
    std::cout << "Hello, World!" << std::endl;
    int dim;
    cout<<"inserisci il numero di elementi"<<endl;
    cin>>dim;

    int numbers[dim];
    for (int i = 0; i < dim; i++){
        numbers[i] = i + 1;
    }

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

