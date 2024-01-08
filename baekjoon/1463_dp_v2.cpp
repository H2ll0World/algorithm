/*
    1463 // dp로 풀기
    3가지 연산 가능
        1. 3으로 나누기
        2. 2으로 나누기
        3. 1을 빼기

    최종적으로 1을 만드는 최소연산을 출력

*/
#include <iostream> 
using namespace std;

int d[1000001]; // dp에 사용하는 table // 해당연산을 몇번했는지 저장

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    d[1] = 0;
    for(int i = 2; i <= n; i++){
        if(i % 3 == 0){
            d[i] = min(d[i/3] + 1, d[i - 1] + 1);
        }else if(i % 2 == 0){
            d[i] = min(d[i/2] + 1, d[i-1] + 1);
        }else {
            d[i] = d[i - 1] + 1;
        }
    }

    cout << d[n] << '\n';

    return 0;
}
