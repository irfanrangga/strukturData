#include "SLL.h"

int main(){
    List L;
    infotype x;
    address P;

    createList(L);
    for(int i = 0; i < 3; i++){
        cin >> x.author;
        cin >> x.title;
        cin >> x.yearRelease;
        P = newElm(x);
        insertLast(L, P);
    }

    printList(L);
    deleteFirst(L, P);
    printList(L);
    deleteLast(L, P);
    printList(L);
    return 0;
}
