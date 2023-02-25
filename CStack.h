#ifndef CSTACK_CSTACK_H
#define CSTACK_CSTACK_H

#include <iostream>
using namespace std;

class CStack {
    int* container; // array of integers
    size_t capacity; // capacity of stack
    int top; // top element
public:
    CStack();
    CStack(size_t);
    ~CStack();
    CStack(const CStack&);
    CStack(CStack&&) noexcept;

    int push(int);
    int pop(int&);
    int peek(int&);
    size_t size();
    bool isEmpty();
    bool isFull();

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
