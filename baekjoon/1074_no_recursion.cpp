/*
    1074_Z_recursion
*/

#include <iostream>

using namespace std;

int rarr[16];
int carr[16];

int main(){
    int N, r, c;
    int pow = 1;
    int rval = 0, cval = 0;
    cin >> N >> r >> c;
    // 32 = 100000,
    // 4 = 100
    // 10진수 to 2진수
    for(int i = 0; i < 16; i++){
        rarr[i] = r % 2;
        r = r / 2;

        carr[i] = c % 2;
        c = c / 2;
    }
    for(int j = 0; j < 16; j++){
        rval = rval + rarr[j] * pow * pow * 2;
        
        cval = cval + carr[j] * pow * pow;
        pow = pow * 2;
    }
    cout << rval + cval;

    return 0;
}
