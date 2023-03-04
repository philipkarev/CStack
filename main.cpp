#include "CStack.h"
//#include "CData.h"

int main() {

//    CData0 data0;

//    cout << data0.output() << endl;

    CStack s1(7);
    for(size_t i = 0; i < 7; ++i)
        s1.push(i);

    CStack s2(s1);
    CStack s3(CStack(2));

//    int tmp; int& ref_tmp = tmp;
//    s3.pop(ref_tmp);
//    s2.pop(ref_tmp);

//    s1.push(17); s1.push(19);

//    CStack s4 = s1 + s2;

//    cout << (s1 + s2).size() << endl;
    cout << "s1 = " << s1 << endl;
    cout << "s3 = " << s3 << endl;
    cout << "s1 + s1 = " << s1 + s3 << endl;

    return 0;
}

