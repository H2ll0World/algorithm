/* // baarkingdog_ver
    2579, 계단 오르기 
        https://www.acmicpc.net/problem/2579
        계단은 한번에 1칸 or 2칸
        연속된 3개의 계단을 밝을 수 x
        마지막 도착계단은 반드시 밟아야 함
        계단을 밝으면 해당 계단의 점수를 얻음

        얻을 수 있는 점수의 최대값?
*/

#include <iostream>
using namespace std;

int stairs[301];
int d[301][2];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i < n + 1; i++){
        cin >> stairs[i];
    }
    d[1][0] = stairs[1];
    d[1][1] = 0;
    d[2][0] = stairs[2];
    d[2][1] = d[1][0] + stairs[2];

    for(int i = 2; i < n + 1; i++){ // i == 1일떄, 필연적으로 오류가 발생
        d[i][0] = max(d[i-2][0], d[i-2][1]) + stairs[i]; 
        d[i][1] = d[i-1][0] + stairs[i];
    }

    cout << max(d[n][0], d[n][1]) << '\n';

    return 0;
}
