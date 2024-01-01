/*
    1074_Z_recursion
*/

#include <iostream>

using namespace std;

int rarr[16], carr[16];

int pow(int a, int b){
    int result = 1;
    while(b-- > 0){
        result = result * a;
    }
    return result;
}

// 2^n x 2^n 
int func(int n, int r, int c){
    int cmp = 0;
    
    if(n <= 1){
        return r * 2 + c + 1;
    }

    cmp = pow(2, n - 1);

    if(cmp * 2 == r && r == c){ 
        return cmp * cmp * 4;
    }
    
    if(cmp <= 0) cout << "pow error!\n";
    if(cmp > r && cmp > c){
        return func(n-1, r,  c);
    }else if(cmp > r && cmp <= c){ 
        return cmp * cmp + func(n-1, r, c - cmp);
    }else if(cmp <= r && cmp > c){
        return cmp * cmp * 2 + func(n-1, r - cmp, c);
    }else{
        return cmp * cmp * 3 + func(n-1, r-cmp, c - cmp);
    }
}

int main(){
    int N, r, c;
    cin >> N >> r >> c;

    cout << func(N, r, c) - 1 << "\n";

    return 0;
}
