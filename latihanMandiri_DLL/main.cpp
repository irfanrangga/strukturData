#include "DLL.h"

int main()
{
    List L;
    infotype x;

    createList(L);
    newElm(1);
    newElm(4);
    newElm(8);
    newElm(12);
    newElm(15);
    insertFirst(L, newElm(1));
    insertFirst(L, newElm(4));
    insertLast(L, newElm(8));
    insertFirst(L, newElm(12));
    insertLast(L, newElm(15));
    cout << "List awal:" << endl;
    printInfo(L);
    cout << "\nList setelah diurutkan: " << endl;
    sortAscending(L);
    printInfo(L);
    cout << "\nList setelah delete first: " << endl;
    deleteFirst(L);
    printInfo(L);
    cout << "\nList setelah delete last: " << endl;
    deleteLast(L);
    printInfo(L);
    cout << "\nMencari bilangan dalam list" << endl;
    cout << "Masukkan bilangan yang ingin dicari: ";
    cin >> x;
    if(searchInfo(L, x)){
        printf("Bilangan %d ada dalam list\n", x);
    } else {
        printf("Tidak ada bilangan %d dalam list\n", x);
    }
    return 0;
}
