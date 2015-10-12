#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16

/* Data node */
typedef struct __PHONE_BOOK_ENTRY {
    char lastName[MAX_LAST_NAME_SIZE];
    char firstName[16];
    char email[16];
    char phone[10];
    char cell[10];
    char addr1[16];
    char addr2[16];
    char city[16];
    char state[2];
    char zip[5];
    struct __PHONE_BOOK_ENTRY *pNext;
} data;

/* Heads */
typedef struct __PHONE_BOOK_HEAD {
    data *pChild;
    //struct __PHONE_BOOK_HEAD *pNext;
} entry;

unsigned int hash(char *str);
data *findName(char lastname[], entry *pHead);
entry *append(char lastName[], entry *e);

#endif