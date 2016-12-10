//
// Created by clemente on 29/11/16.
//






#include <malloc.h>
#include "camping.h"

int main(){

   // Booking head;
   // head = malloc(sizeof(Booking));
   // head->next = NULL;
    int vChoise = NULL;

    do{
        printf("Cosa vuoi fare? \n");
        printf("1.Prenota \n");
        printf("2.Totale per pgni prenotazione \n");

        scanf("%i",&vChoise);

        switch (vChoise){
            case 0:
                printf("Bye\n");
                break;
            case 1:
                makeBooking();
                break;

            case 2:
                totalForEachBooking();
                break;

            default:
                printf("Error \n");

        }

        printf("-----------\n");
    }while(vChoise != 0);

    return 0;
}