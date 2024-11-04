#ifndef SLL_H_INCLUDED
#define SLL_H_INCLUDED
#include <iostream>
#include <cstdio>
#define first(L) L.first
#define info(P) P->info
#define next(P) P->next
#define nil NULL
using namespace std;

struct lagu{
    string title;
    string author;
    int yearRelease;
};

typedef lagu infotype;
typedef struct elmList *address;

struct elmList{
    infotype info;
    address next;
};

struct List{
    address first;
};

void createList(List &L);
address newElm(infotype x);
void insertFirst(List &L, address P);
void insertLast(List &L, address P);
void deleteFirst(List &L, address P);
void deleteLast(List &L, address P);
void printList(List L);

#endif // SLL_H_INCLUDED
