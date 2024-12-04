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
    if(last(L) == nil){
        first(L) = P;
        last(L) = P;
    } else {
        next(last(L)) = P;
        prev(P) = last(L);
        last(L) = P;
    }
}

void deleteFirst(List &L){
    first(L) = next(first(L));
    prev(first(L)) = nil;
}

void deleteLast(List &L){
    last(L) = prev(last(L));
    next(last(L)) = nil;
}

void printInfo(List L){
    address P = first(L);
    while(P != nil){
        cout << info(P) << " " << endl;
        P = next(P);
    }
}

bool searchInfo(List L, infotype x){
    address P = first(L);
    while(P != nil){
        if(info(P) == x){
            return true;
        }
        P = next(P);
    }
    return false;
}

void sortAscending(List &L){
    address P = first(L);
    int temp;
    while(P != last(L)){
        if(info(P) > info(next(P))){
            temp = info(P);
            info(P) = info(next(P));
            info(next(P)) = temp;
        }
        P = next(P);
    }
}
