#include "CStack.h"


CStack::CStack()
    : container(nullptr)
    , capacity(0)
    , top(-1) {

    cout << this << " - called default constructor " << endl;
}


CStack::CStack(size_t length)
    : container(new int[length])
    , capacity(length)
    , top(-1) {

    cout << this << " - called constr " << endl;
}


CStack::~CStack() {

    cout << this << " - called destr" << endl;
    delete [] container;
}


CStack::CStack(const CStack& other)
    : container(new int[other.capacity])
    , capacity(other.capacity)
    , top(-1)
{

    cout << this << " - called copy constr" << endl;
    for (int i = 0; i < other.top + 1; ++i)
        push(other.container[i]);
}


CStack::CStack(CStack&& other) noexcept {

    cout << this << " - called move constr " << endl;

    container = other.container;
    capacity = other.capacity;
    top = other.top;

    other.container = nullptr;
    other.capacity = 0;
    other.top = -1;
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


int CStack::peek(int& result) {

    if (isEmpty()) {
        cout << "Cannot peek" << endl;
        return 0;
    }
    result = container[top];
    return 1;
}


size_t CStack::size() {

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


CStack& CStack::operator=(const CStack& other) {

    cout << this << " - called copy oper=" << endl;

    container = new int[other.capacity];
    capacity = other.capacity;
    top = -1;
    for (size_t i = 0; i < capacity; ++i) {
        push(other.container[i]);
    }
    return (*this);
}


CStack& CStack::operator=(CStack&& other) {

    cout << this << " - called copy oper=" << endl;

    if (this != &other) {
        delete[] container;

        container = other.container;
        capacity = other.capacity;
        top = other.top;

        other.container = nullptr;
        other.capacity = 0;
        other.top = -1;
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


CStack CStack::operator+(const CStack& s) {

    CStack result(capacity + s.capacity);

    for (size_t i = 0; i < capacity; ++i)
        result.push(container[i]);
    for (size_t i = 0; i < s.capacity; ++i)
        result.push(s.container[i]);

    return result;
}


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