#include "CStack.h"

int main() {

    CStack s1(7);
    for (int i = 0; i < 5; ++i)
        s1.push(3);
    CStack s2 = CStack(5); // 1) constr; 2) move constr
    CStack s3(CStack(1)); // 1) constr; 2) move constr

    return 0;
}

