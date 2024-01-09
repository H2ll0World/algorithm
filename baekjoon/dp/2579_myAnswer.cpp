/*
    2579, 계단 오르기
        https://www.acmicpc.net/problem/2579
        계단은 한번에 1칸 or 2칸
        연속된 3개의 계단을 밝을 수 x
        마지막 도착계단은 반드시 밟아야 함
        계단을 밝으면 해당 계단의 점수를 얻음

        얻을 수 있는 점수의 최대값?
*/

#include <iostream>
#include <vector>
using namespace std;

#define score first 
#define seq second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, input, tmax;
    cin >> n;
    int *arr = new int[sizeof(int) * n];
    pair<int, int> * d = new pair<int, int>[sizeof(int) * 2 * n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        d[i].score = 0;
        d[i].seq = 0;
    }

    // 시작에서 바로 2칸 뛸 수 도 있네;;

    d[0].score = arr[0];
    d[0].seq = 1;
    d[1].score = arr[0] + arr[1];
    d[1].seq = 2;
    if(arr[1] > arr[0]){
        d[2].score = arr[1] + arr[2];
        d[2].seq = 2;
    }else{
        d[2].score = arr[0] + arr[2];
        d[2].seq = 1;
    }
    for(int i = 3; i < n; i++){
        if(d[i-1].seq != 2){
            if(d[i-1].score > d[i-2].score){
                d[i].score = d[i-1].score + arr[i];
                d[i].seq = 2;
            }else{
                d[i].score = d[i-2].score + arr[i];
                d[i].seq = 1;
            }
        }else{ // d[i-1].seq == 2 인 경우
            if(d[i-2].score < d[i-3].score + arr[i-1]){
                d[i].score = d[i-3].score + arr[i-1] + arr[i];
                d[i].seq = 2;
            }else{
                d[i].score = d[i-2].score + arr[i];
                d[i].seq = 1;
            }
        }
    }

    cout << d[n-1].score << '\n';

    return 0;
} 
