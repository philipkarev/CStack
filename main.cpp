//
// Created by phlilp on 22.02.23.
//
#include "CStack.h"
//#include <stddef.h>

int main() {

    CStack s1(5);
    for (int i = 0; i < 5; ++i)
        s1.push(3);
    CStack s2 = s1; // testing copy constructor
//    cout << s2 << endl;
//    cout << endl;
//    CStack* s = new CStack(5);

//    s2--; --s2; s2--;
//    cout << s2 << endl;
//    cout << s2++ << endl;
//    cout << s2 << endl;

//    cout << s2-- << endl;
//    cout << s2-- << endl;
//    cout << s2 << endl;
//    cout << s2-- << endl;
//    cout << s2 << endl;
    // testing incorrect input data
//    CStack s3(-3);
//    CStack s4 = s3;
//    s4.push(17);
//    s4.push(17);
//    s4.push(17);
//    cout << s4 << endl;
//    s4.pop();

    return 0;
}

