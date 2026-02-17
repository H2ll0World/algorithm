// https://www.acmicpc.net/problem/1759
// 암호 만들기

#include <iostream>
#include <algorithm>
using namespace std;

int L, C; // L : 암호 길이, C : 사용 문자 종류
char board[15];

char answer[15];
int a; // 모음의 수, 1개 이상
int b; // 자음의 수, 2개 이상

bool check(char ch){
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return 1;
    return 0;
}

void func(int idx, int pre){
    if(idx == L){
        if(a == 0 || b < 2) return;
        for(int i = 0; i < L; i++)
            cout << answer[i];
        cout << "\n";
        return;
    }

    for(int i = pre + 1; i < C; i++){
        answer[idx] = board[i];
        if(check(board[i]) == 1) ++a;
        else ++b;

        func(idx + 1, i);
        
        if(check(board[i]) == 1) --a;
        else --b;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    a = 0; b = 0;
    cin >> L >> C;
    for(int i = 0; i < C; i++)
        cin >> board[i];

    sort(board, board + C);

    func(0, -1);

    return 0;
}
