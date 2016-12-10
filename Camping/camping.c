//
// Created by clemente on 29/11/16.
//

#include <malloc.h>
#include <memory.h>
#include "camping.h"

Booking *head;
int big_room = 7;
int small_room = 3;

void makeBooking() {
    char cabin;
    int days;
    int people_number;
    char vehicle;

    do {
        printf("Inserire il numero di giorni di soggiorno \n");
        scanf("%i[0-9]", &days);
    } while (days <= 0);

    do {
        printf("Inserire il numero di persone [2 o 4]\n");
        scanf("%i[0-9]", &people_number);
    } while ((people_number != 2 && people_number != 4));


    while ((cabin != 'T' && cabin != 'R')) {
        printf("Inserire il tipo di alloggio [T/R]\n");
        scanf(" %c[a-zA-Z]", &cabin);
    }

    while (vehicle != 'M' && vehicle != 'C') {
        printf("Inserire il tipo di veicolo [M/C]\n");
        scanf(" %c[a-zA-Z]", &vehicle);
    }

    Person person = registry();
    Booking *newBooking = malloc(sizeof(Booking));
    newBooking->person_information = &person;
    newBooking->people_number = people_number;
    newBooking->cabin = cabin;
    newBooking->days = days;
    newBooking->vehicle = vehicle;
    newBooking->next = NULL;

    int save = 0;
    int find = 0;

    if (small_room == 0 && big_room == 0) {
        printf("non vi sono camere disponibili \n");
        save = 0;
    } else {
        switch (people_number) {
            case 2:
                if (small_room != 0) {
                    small_room--;
                    newBooking->type_room = SMALL_ROOM;
                } else {
                    big_room--;
                    newBooking->type_room = BIG_ROOM;
                }

                save = 1;
                break;

            case 4:
                if (big_room != 0) {
                    big_room--;
                    newBooking->type_room = BIG_ROOM;
                    save = 1;
                } else {
                    printf("Non vi sono camere disponibili per 4 persone\n");
                    save = 0;
                }
                break;

            default:
                printf("error\n");
                break;
        }
    }

    //controllo se ha già prenotato


    int insert = 0;
    if (save == 1 && hasBooking(head, newBooking->person_information->name) == 0){
        if(head == NULL){
            head = newBooking;
        } else {
            Booking *current = head;
            while(current->next != NULL && insert != 1){
                if(strcmp(newBooking->person_information->name,current->person_information->name) < 0){
                    insert = 1;
                    Booking *temp = current;
                    current = newBooking;
                    temp->next = current;
                }
                current= current->next;
            }
        }

        total(newBooking);
    }
}

void totalForEachBooking(){
    Booking *current = head;
    while(current != NULL){
        total(current);
        current = current->next;
    }
}

void total(Booking *aBooking){
    double total = 0;
    total += aBooking->cabin == 'T' ? CAMPING_TEND : CARAVAN;
    total += aBooking->vehicle == 'M' ? MOTORBYKE : CAR;
    total += (PERSON_PRICE * aBooking->people_number);
    total *= aBooking->days;

    printf("Il totale per persona: %.2f \n", (total / aBooking->people_number) / 100);
    printf("Il totale per gruppo: %.2f \n", total/ 100);
}


Person registry(){
    Person *person = malloc(sizeof(Person));

    char *name;

    printf("NAME: \n");
    scanf("%s[a-zA-Z]",&name);
   // scanf(" %s",person->name);
    person->name = name;
    char *surname;
    printf("SURNAME: \n");
    //scanf(" %s",person->surname);
    scanf("%s[a-zA-Z]",&surname);
    person->surname = surname;
    int age;
    do{
        printf("AGE: \n");
        scanf("%i",&age);
    }while (age < 18);
    person->age = age;
    long phone_number;
    printf("PHONE NUMBER: \n");
    scanf("%d[0-9]",&phone_number);
    //oppure prendere il numero come long e salvarlo come string
    //ho notato ch eprendendo una stringa solo numerica mi crasha
    person->phone_number = phone_number;
    return *person;
}


void orderByName(){

}

void orderByEndTime(){

}


int hasBooking(Booking *head, char *name){
    Booking *currentCheck = head;
    if (head == NULL){
        return 0;
    } else{
        while (currentCheck->next != NULL){
            if(strcmp(currentCheck->person_information->name,name) == 0){
                return 1;
            }
            currentCheck = currentCheck->next;
        }
        return 0;
    }
}