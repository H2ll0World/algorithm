/*
    9095, 정수 n이 주어졌을 때 n을 1, 2, 3의 합으로 나타내는 방법의 수
*/

#include <iostream>
#include <vector>
using namespace std;

int d[11];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, n; // T의 범위 x => vector로 받아야지
    vector<int> vec;
    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> n; // n은 양수, 11보다 작음
        vec.push_back(n);
    }
    d[1] = 1;
    d[2] = 2;
    d[3] = 4;
    for(int i = 1; i < 8; i++){
        d[i + 3] = d[i + 2] + d[i + 1] + d[i];
    }
    for(int i = 1; i < T; i++){
        cout << d[vec[i]] << '\n';
    }

    return 0;
} 
