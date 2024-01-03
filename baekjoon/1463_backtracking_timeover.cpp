/*
    1463, backtracking, Dynamic Programming 둘다로 풀 수 있을 듯...

    3가지 연산 가능
    1. 3으로 나누어 떨어지면 3으로 나눔
    2. 2로 나누어 떨어지면 2로 나눔
    3. 1을 뺌

    위 3가지 연산을 적절히 활용해 1을 만들떄, 필요한 최소한의 연산은 ?
*/
#include <iostream>
using namespace std;

int mini = 1000000000;

void func(int N, int operation_num){
    if(N == 1){ // base case;
        if(operation_num < mini) mini = operation_num;
        return;
    }
    if(N % 3 == 0) func(N/3, operation_num + 1);
    if(N % 2 == 0) func(N/2, operation_num + 1);
    func(N-1, operation_num + 1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    func(N, 0);

    cout << mini << '\n';

    return 0;
}
