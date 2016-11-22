//
// Created by clemente on 16/11/16.
//

#include <memory.h>
#include <stdlib.h>
#include "bancomatfunction.h"

void menu(){
    printf("Selezionare l'operazione desiderata \n");
    printf("1. Prelievo \n");
    printf("2. Versamento \n");
    printf("3. Estratto conto \n");
    printf("0. Exit \n");
}

void withdrawal(operationNode * head, int * aBalance){
    printf("Hai selezionato prelievo \n");
    printf("Attendere... \n");

    int vAmount = 0;

    do{
        printf("Inserire l'importo da prelevare \n");
        scanf("%i", &vAmount);
        if (vAmount <= 0) {
            printf("Hai inserito un importo errato \n");
        }
    }while(vAmount <= 0);

    if (vAmount > *aBalance){
        printf("Non e' possibile prelevare poiche' ha inserito un importo maggiore rispetto al suo saldo \n");
    } else {
        *aBalance -= vAmount;
        struct operation * withdrawal_operation = malloc(sizeof(struct operation));

        withdrawal_operation->amount = vAmount;
        withdrawal_operation->current_time = time(NULL);
        withdrawal_operation->operationType = WITHDRAWAL;

        saveOperation(head, *withdrawal_operation);

        printf("Importo: %i \n", withdrawal_operation->amount);
        printf("Data:  %s \n", ctime(&withdrawal_operation->current_time));
        printf("Tipo Operazione: %s \n", withdrawal_operation->operationType);

        free(withdrawal_operation);
    }
    endOperationMessages();
}


void deposit(operationNode * head, int * aBalance){
    printf("Hai selezionato deposito \n");
    printf("Attendere... \n");

    int vAmount;
    printf("Inserire l'importo da versare \n");
    scanf("%i", &vAmount);

    *aBalance += vAmount;

    struct operation * deposit_operation = malloc(sizeof(struct operation));
    deposit_operation->amount = vAmount;
    deposit_operation->current_time = time(NULL);
    deposit_operation->operationType = DEPOSIT;

    saveOperation(head, *deposit_operation);

    printf("Saldo corrente: %i \n", *aBalance);

    free(deposit_operation);
    endOperationMessages();
}

void bankStatement(operationNode * head, int * aBalance){
    printf("Hai selezionato estratto conto \n");
    printf("Attendere... \n");

    operationNode * current = head;
    while (current->next != NULL) {
        printf("     Tipo operazione %s \n", current->operation.operationType);
        printf("     Importo %d € \n",current->operation.amount);
        printf("     Data : %s \n", ctime(&current->operation.current_time));
        printf("     ---------------- \n");
        current = current->next;
    }
    printf("Saldo corrente: %d \n", *aBalance );

    endOperationMessages();
}

void endOperationMessages(){
    printf("Operazione terminata \n");
    printf("Reindirizzamento al menu' principale. Attendere... \n");
    printf("-----------------  \n");
}


void saveOperationToFile(struct operation *aOperation){
    char *filename = "Operation";

    FILE *mFile = fopen(filename,"a+");
    if (!filename==NULL){
        char str[15];
        sprintf(str, "%d", aOperation->amount);
        char* s = concat("",str);
        s = concat(s,"-");
        s = concat(s,aOperation->operationType);
        s = concat(s,"-");
        char buffer [50];
        unsigned long a = (unsigned long) aOperation->current_time;
        sprintf (buffer, "%lu", a);
        s = concat(s,buffer);
        fprintf(mFile, "%s\n",s);
        free(s);
    }



    fclose(mFile);
}
char* concat(const char *s1, const char *s2)
{
    char *result = malloc(strlen(s1)+strlen(s2)+1);
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

void saveOperation(operationNode * head, struct operation aOperation){
    operationNode * newOperationNode;
    newOperationNode = malloc(sizeof(operationNode));
    newOperationNode->operation = head->operation;
    newOperationNode->next = head->next;
    head->operation = aOperation;
    head->next = newOperationNode;

    saveOperationToFile(&aOperation);
    printf(" \n Operazione avvenuta con successo \n");
}


void loadOperations(operationNode * head, int *balance){
    char *filename = "./Operation";
    char string[10000];
    FILE *file;
    file = fopen(filename, "r");
    char * pch;
    if(file != NULL) {
        while(!feof(file)){
            fscanf(file, "%s",string);
            pch = strtok(string,"-");
            int amount = 0;
            char *type = NULL;
            time_t date;
            int count = 1;
            char buf[300];
            while (pch != NULL) {
                switch (count){
                    case 1:
                        amount = atoi(pch);
                        break;
                    case 2:
                        type = pch;
                        break;

                    case 3:;
                        date = atol(pch);
                        struct operation *saved_operation = malloc(sizeof(struct operation));
                        saved_operation->amount = amount;
                        saved_operation->current_time = date;
                        saved_operation->operationType = type;


                        operationNode * newOperationNode;
                        newOperationNode = malloc(sizeof(operationNode));
                        newOperationNode->operation = head->operation;
                        newOperationNode->next = head->next;


                        head->operation = *saved_operation;
                        head->next = newOperationNode;


                        //aggiornamento bilancio
                        if (strstr(saved_operation->operationType, WITHDRAWAL) != NULL){
                            *balance -= amount;
                        } else {
                            *balance += amount;
                        }

                        break;

                    default:
                        printf("Errore \n");
                        break;
                }
                count++;
                pch = strtok (NULL, "-");
                if (count > 3){
                    count = 1;
                }
            }
        }
    } else {
        printf("nuuuuuuuuulll");
    }

    fclose(file);

}

void ReadFile(operationNode *head, char *filename)
{
//
//    char *buffer = NULL;
//    int string_size, read_size;
//    FILE *handler = fopen(filename, "r");
//
//    if (handler)
//    {
//        // Seek the last byte of the file
//        fseek(handler, 0, SEEK_END);
//        // Offset from the first to the last byte, or in other words, filesize
//        string_size = ftell(handler);
//        // go back to the start of the file
//        rewind(handler);
//
//        // Allocate a string that can hold it all
//        buffer = (char*) malloc(sizeof(char) * (string_size + 1) );
//
//        // Read it all in one operation
//        read_size = fread(buffer, sizeof(char), string_size, handler);
//
//        // fread doesn't set it so put a \0 in the last position
//        // and buffer is now officially a string
//        buffer[string_size] = '\0';
//
//        if (string_size != read_size)
//        {
//            // Something went wrong, throw away the memory and set
//            // the buffer to NULL
//            free(buffer);
//            buffer = NULL;
//        }
//
//        // Always remember to close the file.
//        fclose(handler);
//    }
//
//    return buffer;



}