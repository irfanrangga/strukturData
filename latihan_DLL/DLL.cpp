#include "DLL.h"

void createList(List &L){
    first(L) = nil;
    last(L) = nil;
}

address newElm(infotype x){
    address P = new elmList;
    info(P) = x;
    next(P) = nil;
    prev(P) = nil;

    return P;
}

void insertFirst(List &L, address P){
    if(first(L) == nil){
        first(L) = P;
        last(L) = P;
    } else {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void insertLast(List &L, address P){
    next(last(L)) = P;
    prev(P) = last(L);
    last(L) = P;
}

void deleteFirst(List &L, address P){
    P = first(L);
    first(L) = next(P);
    prev(P) = first(L);
    next(P) = nil;
}

void deleteLast(List &L, address P){
    P = last(L);
    last(L) = prev(P);
    prev(P) = nil;
    next(last(L)) = nil;
}

void printInfo(List L){
    address P = first(L);
    cout << endl;
    while(P != nil){
        cout << info(P) << " ";
        P = next(P);
    }
}
