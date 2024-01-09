/*
    11726. 2 x n 타일링, dp로 푸는 경우 
    2 x n 의 타일을 1 x 2, 2 x 1 타일로 채우는 방법

    1 <= n <= 1000

    review : int 범위, long long 범위 때문에 계속틀림 + 10007로 나눠야 되는 거(문제 잘 읽기)
*/

#include <iostream>
using namespace std;

long long d[1001][3]; // 1 : right most가 1인경우, 2 : right most가 2인경우

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    d[1][1] = 1;
    d[1][2] = 0;
    d[2][1] = 1;
    d[2][2] = 1;

    for(int i = 3; i <= n; i++){
        if(d[i-1][1] + d[i-1][2] >= 10007){
            d[i][1] = (d[i-1][1] + d[i-1][2]) % 10007;
        }else{
            d[i][1] = d[i-1][1] + d[i-1][2];
        }
        if(d[i-2][1] + d[i-2][2] >= 10007){
            d[i][2] = (d[i-2][1] + d[i-2][2]) % 10007;
        }else{
            d[i][2] = d[i-2][1] + d[i-2][2];
        }
    }

    cout << (d[n][1] + d[n][2]) % 10007 << '\n';

    return 0;
}
