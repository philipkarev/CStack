//
// Created by phlilp on 22.02.23.
//
#include "CStack.h"


CStack::CStack(int n) {

    a = new int[n];
    t = -1;
    c = n;
}


CStack::~CStack() {

    delete [] a;
}


CStack::CStack(const CStack& s) {

    c = s.c;
    a = new int[c];
    t = -1;
    for (int i = 0; i < c; ++i) {
        push(s.a[i]);
    }
}


int CStack::push(int x) {

    if (isFull()) {
        cout << "Impossible to push value" << endl;
        return 0;
    }
    a[++t] =x;
    return 1;
}


int CStack::pop() {

    if (isEmpty()) {
        cout << "Cannot pop" << endl;
        return 0;
    }
    return a[t--];
}


int CStack::peek() {

    if (isEmpty()) {
        cout << "Cannot peek" << endl;
        return 0;
    }
    return a[t];
}


int CStack::size() {

    return t + 1;
}


int CStack::isEmpty() {

    if (t == -1) {
        cout << "Stack is empty" << endl;
        return 1;
    }
    return 0;
}


int CStack::isFull() {

    if (size() == c) {
        cout << "Stack is full" << endl;
        return 1;
    }
    return 0;
}


CStack& CStack::operator=(const CStack& s) {

    c = s.c;
    a = new int[c];
    t = -1;
    for (int i = 0; i < c; ++i) {
        push(s.a[i]);
    }
    return (*this);
}