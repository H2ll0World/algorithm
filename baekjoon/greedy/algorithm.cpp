/*
    N종류의 동전을 가지고 있음
    동전을 적절히 사용하여 그 값을 K로 만들려고 함

    input 첫 줄에 N K가 주어짐, 각각의 동전은 매우 많음
    둘째 줄부터 N개의 줄에 동전의 가치 Ai가 오름차순으로 주어짐
    1 <= K <= 100,000,000 : int는 21억 까지
    1 <= N <= 10
    1 <= Ai <= 1,000,000
*/
#include <iostream>
using namespace std;

int coin[10];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K, idx, total;
    idx = -1;
    total = 0;
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> coin[i];
        if(coin[i] <= K) idx++;
    }
    for(int i = 0; i < idx + 1; i++){
        total = total + K / coin[idx - i];
        K = K % coin[idx - i];
        if(K == 0) break;
    }

    cout << total << '\n';

    return 0;
}