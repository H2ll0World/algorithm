/*
    1463, backtracking, Dynamic Programming 둘다로 풀 수 있을 듯...

    N : 1 ~ 1000000

    3가지 연산 가능
    1. 3으로 나누어 떨어지면 3으로 나눔
    2. 2로 나누어 떨어지면 2로 나눔
    3. 1을 뺌

    위 3가지 연산을 적절히 활용해 1을 만들떄, 필요한 최소한의 연산은 ?
*/
#include <iostream>
using namespace std;

int d[1000001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    d[1] = 0;
    for(int i = 2; i <= N; i++){
        d[i] = d[i-1] + 1;
        if(i % 2 == 0) d[i] = min(d[i], d[i/2] + 1);
        if(i % 3 == 0) d[i] = min(d[i], d[i/3] + 1);
    }
    cout << d[N] << '\n';

    return 0;
}
