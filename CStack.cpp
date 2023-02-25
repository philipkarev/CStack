//
// Created by phlilp on 22.02.23.
//
#include "CStack.h"


CStack::CStack()
    : capacity(0)
    , top(-1) {
    cout << "called default constructor ";
    cout << this << endl;
}


CStack::CStack(int n) {

    cout  << "called constr ";
    cout << this << endl;
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

    cout << "called destr ";
    cout << this << endl;

    if (capacity >= 0) {
        delete [] container;
    }
}


CStack::CStack(const CStack& s) {

    cout << "called copy constr";
    cout << this << endl;

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


CStack::CStack(CStack&& s) noexcept {

    cout << "called move constr ";
    cout << this << endl;

    container = s.container;
    capacity = s.capacity;
    top = s.top;

    s.capacity = 0;
    s.top = -1;
}


/*CStack::CStack(CStack&& s) noexcept
    : capacity(0)
    , top(1) {
    cout << "called move constr" << endl;
    (*this) = move(s);
}*/


int CStack::push(int x) {

    if (isFull()) {
        cout << "Impossible to push value" << endl;
        return 1;
    }
    container[++top] = x;
    return 0;
}


int CStack::pop(int& result) {

    if (isEmpty()) {
        cout << "Cannot pop" << endl;
        return 0;
    }
    result = container[top--];
    return 1;
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


bool CStack::isEmpty() {

    if (top == -1) {
        cout << "Stack is empty" << endl;
        return true;
    }
    return false;
}

 bool CStack::isFull() {

    if (size() == capacity) {
        cout << "Stack is full" << endl;
        return true;
    }
    return false;
}


CStack& CStack::operator=(const CStack& s) {

    cout << "called copy =" << endl;
    cout << this << endl;
    cout << endl;
    capacity = s.capacity;
    container = new int[capacity];
    top = -1;
    for (int i = 0; i < capacity; ++i) {
        push(s.container[i]);
    }
    return (*this);
}


CStack& CStack::operator=(CStack&& s) {

    cout << "called move =" << endl;
    cout << this << endl;
    cout << endl;
    if (this != &s) {
        if (capacity > 0) {
            delete[] container;
        }
        container = s.container;
        capacity = s.capacity;
        top = s.top;
        s.capacity = 0;
        s.top = -1;
    }
    return (*this);
}


CStack& CStack::operator++() { // prefix increment

    push(0);
    return (*this);
}


CStack& CStack::operator--() { // prefix decrement

    int tmp;
    int& ref_tmp = tmp;
    pop(ref_tmp);
    return (*this);
}


CStack CStack::operator++(int) {

    CStack tmp(*this);
    ++(*this);
    return tmp;
}


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