#ifndef DLL_H_INCLUDED
#define DLL_H_INCLUDED
#define first(L) L.first
#define info(P) P->info
#define next(P) P->next
#define prev(P) P->prev

typedef int infotype;
typedef struct elmList *address;

struct elmList{
    infotype info;
    address next;
    address prev;
};

struct List{address first;};


void createList(List &L);
address newElm(infotype x);
void insertAfter(List &L, address Prec, address P);
#endif // DLL_H_INCLUDED
