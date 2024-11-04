#include "SLL.h"

void createList(List &L){
    first(L) = nil;
}

address newElm(infotype x){
    address P = new elmList;
    info(P).author = x.author;
    info(P).title = x.title;
    info(P).yearRelease = x.yearRelease;
    next(P) = nil;

    return P;
}

void insertFirst(List &L, address P){
    next(P) = first(L);
    first(L) = P;
}

void insertLast(List &L, address P){
    if(first(L) == nil){
        first(L) = P;
    } else {
        address Q = first(L);
        while(next(Q) != nil){
            Q = next(Q);
        }
        next(Q) = P;
    }
}

void deleteFirst(List &L, address P){
    P = first(L);
    first(L) = next(P);
    next(P) = nil;
}

void deleteLast(List &L, address P){
    address Q = first(L);
    if(next(Q) == nil){
        P = Q;
        first(L) = nil;
    } else {
        while(next(next(Q)) != nil){
            Q = next(Q);
        }
        P = next(Q);
        next(Q) = nil;
    }
}

void printList(List L){
    address P = first(L);
    cout << endl;
    while(P != nil){
        cout << info(P).title << " - " << info(P).author << " (" << info(P).yearRelease << ")" << endl;
        P = next(P);
    }
}

