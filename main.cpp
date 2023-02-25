#include "CStack.h"
#include "CData.h"

int main() {

    CStack s1(7);
    for (int i = 0; i < 5; ++i)
        s1.push(3);
    CStack s2 = CStack(5); // 1) constr; 2) move constr
    CStack s3(CStack(1)); // 1) constr; 2) move constr

    cout << (s1 + s2).size() << endl;
    cout << s1 + s2 << endl;

    return 0;
}

