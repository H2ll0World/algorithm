/*
    1149. RGE거리
    1 ~ N 의 집이 존재
    RGB중 하나로 칠해야함
    이웃한 집까리는 색깔이 다르다

    2 <= N <= 1000
    R G B 비용이 나열됨
*/

#include <iostream>
using namespace std;

int d[1000][3]; // R : 1, G : 2, B : 3
int rgb[1000][3]; // 0 : R로 칠헀을때 최소, 1 : G로 칠했을때 최소, 2 : B로 칠했을 때 최소비용

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> rgb[i][0] >> rgb[i][1] >> rgb[i][2];
    }

    d[0][0] = rgb[0][0];
    d[0][1] = rgb[0][1];
    d[0][2] = rgb[0][2];

    for(int i = 1; i < N; i++){
        for(int j = 0; j < 3; j++){
            d[i][j] = min(d[i-1][(j+1)%3], d[i-1][(j+2)%3]) + rgb[i][j];
        }
    }

    cout << min(min(d[N-1][0], d[N-1][1]), d[N-1][2]) << '\n';

    return 0;
}
