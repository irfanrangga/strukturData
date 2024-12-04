#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include <iostream>
using namespace std;

const int MAXSTACK = 10;
typedef char infotype;
typedef int address;

struct Stack{
    infotype T[MAXSTACK];
    address Top;
};

bool isEmpty(Stack S);
bool isFull(Stack S);
Stack createStack();
void Push(Stack &S, infotype P);
infotype Pop(Stack &S);
void printStack(Stack S);

#endif // STACK_H_INCLUDED
