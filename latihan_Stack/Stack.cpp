#include "Stack.h"

bool isEmpty(Stack S){
    if(S.Top == 0){
        return true;
    } else {
        return false;
    }
}

bool isFull(Stack S){
    if(S.Top == MAXSTACK){
        return true;
    } else {
        return false;
    }
}

Stack createStack(){
    Stack S;
    S.Top = 0;

    return S;
}

void Push(Stack &S, infotype P){
    if(isFull(S)){
        cout << "Stack Penuh" << endl;
    } else {
        S.Top += 1;
        S.T[S.Top] = P;
    }
}

infotype Pop(Stack &S){
    infotype P;
    if(isEmpty(S)){
        cout << "Stack Kosong";
    } else {
        P = S.T[S.Top];
        S.Top -= 1;
    }

    return P;
}

void printStack(Stack S){
    for(int i = S.Top; i > 0; i--){
        cout << S.T[i] << endl;
    }
}
