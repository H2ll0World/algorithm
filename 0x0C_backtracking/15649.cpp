// https://www.acmicpc.net/problem/15649
#include <iostream>
#include <memory.h>
using namespace std;

int N, M;
int board[10];
bool used[10];

void backtracking(int idx){
    if(idx == M){
        for(int i = 0; i < M; i++){
            cout << board[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i = 1; i <= N; i++){
        if(used[i] == 1) continue;
        used[i] = 1;
        board[idx] = i;
        backtracking(idx + 1);
        used[i] = 0;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(used, 0, sizeof used);
    
    cin >> N >> M;
    backtracking(0);


    return 0;
}
