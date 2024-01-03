/*
    11652,
    -2^62 ~ 2^62의 범위의 숫자가 카드에 적혀있음
    N은 카드의 개수 1 <= N <= 100000

    가장 많이 가지고 있는 정수 출력
*/

#include <iostream>
#include <algorithm>
#define num first 
#define total second 
using namespace std;

long long cards[100000];

int main(){
    ios::sync_with_stdio(0);
    pair<long long, int> max;
    pair<long long, int> cur;
    cin.tie(0);

    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> cards[i];
    }
    sort(cards, cards + N);
    for(int i = 0; i < N; i++){
        if(cur.num != cards[i]) {
            if(max.total < cur.total){
                max.num = cur.num;
                max.total = cur.total;
            }
            cur.num = cards[i];
            cur.total = 0;
        }
        cur.total++;
        if(i == N - 1){
            if(max.total < cur.total){
                max.num = cur.num;
                max.total = cur.total;
            }
        }
    }

    cout << max.num << '\n';

    return 0;
}
