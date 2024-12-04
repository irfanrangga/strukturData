#include "DLL.h"
int main(){
    List L;
    infotype x;
    address P;

    createList(L);
    newElm(3);
    insertFirst(L, newElm(3));
    for(int i = 0; i < 3; i++){
        cin >> x;
        P = newElm(x);
        insertLast(L, P);
    }
    printInfo(L);
    deleteFirst(L, P);
    printInfo(L);
    deleteLast(L, P);
    printInfo(L);
    deleteFirst(L, P);
    printInfo(L);
    return 0;
}
