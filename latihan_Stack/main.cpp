#include "Stack.h"

int main(){
    Stack S;
    infotype P;

    createStack();
    cout << isEmpty(S) << endl;
    cout << isFull(S) << endl;
    cout << endl;
    Push(S, 'T');
    Push(S, 'U');
    Push(S, 'P');
    Push(S, 'M');
    Push(S, 'U');
    Push(S, 'R');
    printStack(S);
    cout << endl;
    Pop(S);
    Pop(S);
    printStack(S);
    return 0;
}
