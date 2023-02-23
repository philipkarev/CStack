//
// Created by phlilp on 22.02.23.
//
#ifndef CSTACK_CSTACK_H
#define CSTACK_CSTACK_H

#include <iostream>
using namespace std;

class CStack {
    int* container; // array of integers
    int capacity; // capacity of stack
    int top; // top element
public:
    CStack(int);
    ~CStack();
    CStack(const CStack&);

    int push(int);
    int pop(); // how it works? what means condition?
    int peek();
    int size();
    int isEmpty();
    int isFull();

    CStack& operator=(const CStack&);
    CStack& operator++(); // how it works?
    CStack& operator--();
    CStack operator++(int); // how it works?
    CStack operator--(int);
    CStack operator+(const CStack&); // how it works?
    friend ostream &operator<<(ostream&, const CStack&);
};

#endif //CSTACK_CSTACK_H
