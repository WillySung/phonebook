#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_opt_hash_djb2.h"

/* Hash function */
unsigned int hash(char *str)
{
    unsigned int hash = 5381;
    int c;

    while (c = *str++) {
        hash = ((hash << 5) + hash) + c;  // hash * 33 + c
    }

    return hash%26;                   // 26 alphebets
}

/* FILL YOUR OWN IMPLEMENTATION HERE! */
data *findName(char lastname[], entry *pHead)
{
    int key=hash(lastname);
    data *cur = pHead[key].pChild;
    while(cur!=NULL) {
        if(!strcmp(cur->lastName,lastname)) {
            return cur;
        }
        cur = cur->pNext;
    }
    return NULL;
}

entry *append(char lastName[], entry *e)
{
    int key=hash(lastName);
    data *newData = (data *)malloc(sizeof(data));
    strcpy(newData->lastName, lastName);
    newData->pNext = e[key].pChild;
    e[key].pChild = newData;
    return e;
}