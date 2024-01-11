/*
    1026. 보물 // 최솟값만 구할 거면 B도 재배열해도 상관없는 거 아님?
    길이가 N인 배열 A, B
    S = A[0] * B[0] + A[1] * B[1] + ... + A[N-1] * B[n-1]
    S를 가장 작게 만들기 위해 A를 재배열, 단 B를 건들면 x

    조건
    A, B의 각 원소는 0 ~ 100 정수
    N은 50이하의 자연수
    
    N 가 주어짐
    A
    B
    
    S의 최솟값 출력
*/
#include <iostream>
#include <algorithm>
using namespace std;

int A[50];
int B[50];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int sum = 0;
    int N;
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    for(int i = 0; i < N; i++){
        cin >> B[i];
    }
    sort(A, A + N);
    sort(B, B + N);

    for(int i = 0; i < N; i++){
        sum += A[i]*B[N-1-i];
    }

    cout << sum << '\n';

    return 0;
}
