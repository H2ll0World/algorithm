/*
    prefix sum  
    https://san-tiger.tistory.com/entry/Prefix-sum-알고리즘이란
    11659. 수 N개가 주어진 경우 i부터 j까지의 합을 구하는 프로그램을 작성

    input : N M : N(주어지는 수의 개수), M(합을 구해야 하는 개수)
    M개의 i j가 주어짐 1 <= i <= j <= N

    1 <= n <= 100,000 // N이 5,000이하일 때는 N^2도 가능
    1 <= m <= 100,000 

    output : M번의 출력을 함
*/
#include <iostream>
using namespace std;

int result[100000];
int prefixSums[100001]; // 1,000 * 100,000 == 1억 이므로 int로 표현가능

int main(){
    int N, M;
    int i, j;
    int input;
    cin >> N >> M;

    cin >> prefixSums[1];
    for(int k = 2; k < N + 1; k++){
        cin >> input;
        prefixSums[k] = prefixSums[k-1] + input;
    }

    for(int k = 0; k < M; k++){
        cin >> i >> j;
        result[k] = prefixSums[j] - prefixSums[i - 1];
    }

    for(int k = 0; k < M; k++){
        cout << result[k] << '\n';
    }

    return 0;
}
