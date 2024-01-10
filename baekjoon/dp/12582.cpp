/*
    n == 1인 경우 예외처리 안해줘서 틀림
    12582
    1로 만들기 ver2
        x가 3으로 나누어 떨어지면 3으로나눔
        x가 2로 나누어 떨어지면 2로 나눔
        1을 뺌
    연산을 사용하는 최솟값을 구하여라

    출력 
        N을 1로 만드는 방법의 경로를 출력, 여러가지인 경우 아무거나 출력

    1 <= N <= 1,000,000
*/
#include <iostream>
using namespace std;

#define opNum first
#define preNum second

pair<int, int> d[1000001]; // first : 연산의 횟수, second : 이전의 idx linked list방식으로 경로 추적

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    if(n == 1){
        cout << 0 << '\n' << 1 << '\n';   
        return 0;
    }
    
    d[1].opNum = 0;
    d[1].preNum = 1;
    for(int i = 2; i < n + 1; i++){
        d[i].opNum = d[i-1].opNum + 1;
        d[i].preNum = i-1;
        if(i % 3 == 0){
            if(d[i/3].opNum + 1 < d[i].opNum){
                d[i].opNum = d[i/3].opNum + 1;
                d[i].preNum = i/3;
            }
        }
        if(i % 2 == 0){
            if(d[i/2].opNum + 1 < d[i].opNum){
                d[i].opNum = d[i/2].opNum + 1;
                d[i].preNum = i / 2;
            }
        }
    }
    cout << d[n].opNum << '\n' << n << ' ';
    int i = n;
    while(true){
        cout << d[i].preNum << ' ';
        i = d[i].preNum;
        if(i == 1){
            break;
        }
    }
    cout << '\n';

    return 0;
}
