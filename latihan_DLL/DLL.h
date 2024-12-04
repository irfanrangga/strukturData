#ifndef DLL_H_INCLUDED
#define DLL_H_INCLUDED
#include <iostream>
#define first(L) L.first
#define last(L) L.last
#define info(P) P->info
#define next(P) P->next
#define prev(P) P->prev
#define nil NULL
using namespace std;

typedef int infotype;
typedef struct elmList *address;

struct elmList{
    infotype info;
    address next;
    address prev;
};

struct List{
    address first;
    address last;
};

void createList(List &L);
address newElm(infotype x);
void insertFirst(List &L, address P);
void insertLast(List &L, address P);
void deleteFirst(List &L, address P);
void deleteLast(List &L, address P);
void printInfo(List L);


#endif // DLL_H_INCLUDED
