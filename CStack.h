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
    CStack();
    CStack(int);
    ~CStack();
    CStack(const CStack&);
    CStack(CStack&&) noexcept;

    int push(int);
    int pop();
    int peek();
    int size();
    int isEmpty();
    int isFull();

    CStack& operator=(const CStack&);
    CStack& operator=(CStack&&);
    CStack& operator++();
    CStack& operator--();
    CStack operator++(int);
    CStack operator--(int);
    CStack operator+(const CStack&);
    friend ostream &operator<<(ostream&, const CStack&);
};

#endif //CSTACK_CSTACK_H
