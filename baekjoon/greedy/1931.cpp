/*
    1931번
    회의실 배정
    N개의 회의에 대한 회의실 사용표를 만들려고 함
    회의실은 1개
    각 회의 I에 대해 시작시간과 끝나는 시간이 주어짐
    회의실이 겹치지 않게 하면서 회의실을 사용할 수 있는 회의의 최대 개수는?

    단, 회의의 시작과 끝이 같을 수 있음 => 이 경우 시작하자마자 끝나는 것으로 간주

    1 <= N <= 100,000  100000개의 int 
    512MB가 1.2억개의 int 가능
    128MB == 3천만 개의 int 가능

    greedy로 풀 수 있나?

    algorithm시간에 배운 activity selection problem 참고하여 품
    모든 optimal한 답을 구할순 없지만 해당 선택이 optimal중의 하나인 optimal임은 증명가능
    proof by contradiction으로
*/
#include <iostream>
#include <algorithm> // sort함수의 사용을 위해서
using namespace std;

#define start first
#define end second

pair<int, int> meeting[100000];

// pair도 STL
bool cmp(pair<int, int> &a, pair<int, int> &b){// 비교함수의 인수로 STL, class인자 전달시 reference사용
    if(a.end == b.end){
        return a.start < b.start;
    }
    return a.end < b.end; // sort에서 cmp함수는 두 인자의 우선순위가 같을때 false반환 
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; // 회의의 개수
    int max = 0;
    int idx = 0;
    int temp = 0;
    cin >> N;

    for(int k = 0; k < N; k++){
        cin >> meeting[k].start >> meeting[k].end;
    }
    
    // pair<int, int> 의 2번째 인자인 end를 기준으로 정렬되어 있음
    sort(meeting, meeting + N , cmp); // NlogN 의 시간복잡도 : N은 최대 백만까지 가능 1초일떄
    /*
    for(int i = 0; i < N; i++){
        cout << " sort[" << i << "] " << meeting[i].first << ' ' << meeting[i].end << '\n';
    }
    */
    // 예외처리 start와 end가 같은 경우도 고려해야 함
    for(int i = 0; i < N; i++){ // O(N)으로 해결 가능 
        if(temp <= meeting[i].first){ 
            temp = meeting[i].end;
            max++;
            //cout << "start : " << meeting[i].first << " end : " << meeting[i].second << '\n';
        }
    }

    cout << max << '\n';

    return 0;
}
