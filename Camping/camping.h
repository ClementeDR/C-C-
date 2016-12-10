//
// Created by clemente on 29/11/16.
//

#ifndef CAMPING_CAMPING_H
#define CAMPING_CAMPING_H
//tutto in centesimi

#include <time.h>

#define FOUR_PERSON 4
#define TWO_PERSON 2
#define PERSON_PRICE 500
#define CAMPING_TEND 400
#define CARAVAN 450
#define CAR 550
#define MOTORBYKE 350

#define BIG_ROOM "BigRoom"
#define SMALL_ROOM "SmallRoom"

typedef struct booking{
    int people_number;
    int days;
    char cabin;
    char vehicle;
    time_t start_time;
    time_t end_time;
    char *type_room;
    struct booking *next;
    struct person *person_information;
} Booking;

typedef struct person{
    char *fiscal_code;
    char *name;
    char *surname;
    int age;
    long phone_number;
}Person;




void makeBooking();

void totalForEachBooking();

void total(Booking *aBooking);

Person registry();

#endif //CAMPING_CAMPING_H
