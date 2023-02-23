//
// Created by phlilp on 22.02.23.
//
#include "CStack.h"


CStack::CStack(int n) {

    if (n > 0) {
        capacity = n;
        container = new int[capacity];
        top = -1;
    } else {
        cout << "Incorrect input capacity of stack" << endl;
        capacity = 0;
        top = -1; // impossible to pop, push; prevent memory leak
    }
}


CStack::~CStack() {
    if (capacity > 0) {
        delete [] container;
    }
}


CStack::CStack(const CStack& s) {

    capacity = s.capacity;
    if (capacity > 0) {
        container = new int[capacity];
        top = -1;
        for (int i = 0; i < s.top + 1; ++i) {
            push(s.container[i]);
        }
    } else {
        cout << "Incorrect input capacity of stack" << endl;
        capacity = 0;
        top = -1;
    }
}


int CStack::push(int x) {

    if (isFull()) {
        cout << "Impossible to push value" << endl;
        return 0;
    }
    container[++top] = x;
    return 1;
}


int CStack::pop() {

    if (isEmpty()) {
        cout << "Cannot pop" << endl;
        return 0;
    }
    return container[top--];
}


int CStack::peek() {

    if (isEmpty()) {
        cout << "Cannot peek" << endl;
        return 0;
    }
    return container[top];
}


int CStack::size() {

    return top + 1;
}


int CStack::isEmpty() {

    if (top == -1) {
        cout << "Stack is empty" << endl;
        return 1;
    }
    return 0;
}


int CStack::isFull() {

    if (size() == capacity) {
        cout << "Stack is full" << endl;
        return 1;
    }
    return 0;
}


CStack& CStack::operator=(const CStack& s) {

    capacity = s.capacity;
    container = new int[capacity];
    top = -1;
    for (int i = 0; i < capacity; ++i) {
        push(s.container[i]);
    }
    return (*this);
}


//CStack& CStack::operator++() {}


CStack& CStack::operator--() { // prefix

    pop();
    return (*this);
}


//CStack CStack::operator++(int) {}


CStack CStack::operator--(int) {

    CStack tmp(*this);
    --(*this);
    return tmp;
}


//CStack operator+(const CStack&);


ostream &operator<<(ostream& stream, const CStack& s) {

    stream << "[";
    for (int i = 0; i < s.top + 1; i++) {
        if (i != 0) {
            stream << ", ";
        }
        stream << s.container[i];
    }
    stream << "]";
    return stream;
}