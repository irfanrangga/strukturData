#include "DLL.h"

void createList(List &L){
    first(L) = nullptr;
}

address newElm(infotype x){
    address P = new elmList;
    info(P) = x;
    next(P) = nullptr;
    prev(P) = nullptr;

    return P;
}

void insertAfter(List &L, address Prec, address P){
    //Prec = prev(P)
    next(P) = next(Prec);
    next(Prec) = P;
}
