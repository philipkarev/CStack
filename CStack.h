//
// Created by phlilp on 22.02.23.
//
#ifndef CSTACK_CSTACK_H
#define CSTACK_CSTACK_H

#include <iostream>
using namespace std;

class CStack {
    int* a; // array of integers
    int c; // capacity of stack
    int t; // top element
public:
    CStack(int);
    ~CStack();
    CStack(const CStack&);

    int push(int);
    int pop();
    int peek();
    int size();
    int isEmpty();
    int isFull();

    CStack& operator=(const CStack&);
};

#endif //CSTACK_CSTACK_H
