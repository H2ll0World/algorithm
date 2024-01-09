/*
    2579, 계단 오르기 // 여집합으로 풀어보기
        https://www.acmicpc.net/problem/2579
        계단은 한번에 1칸 or 2칸
        연속된 3개의 계단을 밝을 수 x

        여집합으로
            최소한의 점수를 얻어야 함
            마지막 계단은 밝지 x
            2칸 이동(2칸 => 2칸 이동)
            3칸 이동(2칸 => 1칸 + 1칸)
*/

#include <iostream>
using namespace std;

int stair[300];
int d[300]; // [i][0] : 2칸 이동, [i][1] : 3칸 이동

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int sum = 0;

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> stair[i];
        sum += stair[i];
    }
    d[0] = 0;
    d[1] = 0;
    for(int i = 0; i < n; i++){
        d[i] = min(d[i-3], d[i-2]) + stair[i]; // 마지막 계단은 밝으면 x
    }
    cout << sum - min(d[n-2], d[n-3]) << '\n';

    return 0;
}
