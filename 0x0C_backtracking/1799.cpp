// https://www.acmicpc.net/problem/1799

#include <iostream>
#include <memory.h>
#include <vector>
using namespace std;

int N;
int board[10][10];
bool used[2][20];
vector<pair<int, int> > vec;
int sz;

int mx1 = 0;
int mx2 = 0;
// int cnt= 0;

// bool fin;
// void backtracking(int k, int curMx, int target){
//     if(fin == 1) return;
//     if(k == sz){
//         if(curMx == target) fin = 1;
//         return;
//     }

//     if(target - curMx > sz - k) return; // 끝까지 봐도 의미 없는 경우

//     if(curMx == target){
//         fin = 1;
//         return;
//     }

//     backtracking(k + 1, curMx, target); // 이번거는 넘어감

//     if(used[0][(vec[k].first + vec[k].second)] == 0 && used[1][(vec[k].first - vec[k].second + 10)] == 0){
//         used[0][(vec[k].first + vec[k].second)] = 1;
//         used[1][(vec[k].first - vec[k].second + 10)] = 1;

//         backtracking(k + 1, curMx + 1, target);

//         used[0][(vec[k].first + vec[k].second)] = 0;
//         used[1][(vec[k].first - vec[k].second + 10)] = 0;
//     }
// }

// bool sol(int target){
//     memset(used, 0, sizeof used);
//     fin = 0;
//     backtracking(0, 0, target);

//     if(fin) return 1;
//     return 0;
// }

// void binarySearch(int st, int en){
//     int mid;

//     while(st < en){
//         mid = (st + en + 1) / 2;

//         if(sol(mid)){ // 가
//             st = mid;
//         }else{ // 불가능
//             en = mid - 1;
//         }
//     }

//     if(st > mx) mx = st;
// }

// void func(int k, int cur){
//     if(k == sz){
//         if(cur > mx) mx = cur;
//         return;
//     }

//     if(sz - k + cur <= mx) return; // 나머지가 다 되도 의미X

//     func(k + 1, cur);
//     if(used[0][(vec[k].first + vec[k].second)] == 0 && used[1][(vec[k].first - vec[k].second + 10)] == 0){
//         used[0][(vec[k].first + vec[k].second)] = 1;
//         used[1][(vec[k].first - vec[k].second + 10)] = 1;

//         func(k + 1, cur + 1);

//         used[0][(vec[k].first + vec[k].second)] = 0;
//         used[1][(vec[k].first - vec[k].second + 10)] = 0;
//     }
// }
// 1,000,000,000,000,000,000,000,000,000,000

void func1(int k, int cur){
    if(k == sz){
        if(cur > mx1) mx1 = cur;
        return;
    }
    
    if(sz - k + cur <= mx1) return; // 나머지가 다 되도 의미X
    func1(k + 1, cur);

    if((vec[k].first + vec[k].second) % 2 == 0){
        return;
    }

    if(used[0][(vec[k].first + vec[k].second)] == 0 && used[1][(vec[k].first - vec[k].second + 10)] == 0){
        used[0][(vec[k].first + vec[k].second)] = 1;
        used[1][(vec[k].first - vec[k].second + 10)] = 1;

        func1(k + 1, cur + 1);

        used[0][(vec[k].first + vec[k].second)] = 0;
        used[1][(vec[k].first - vec[k].second + 10)] = 0;
    }
}

void func2(int k, int cur){
    if(k == sz){
        if(cur > mx2) mx2 = cur;
        return;
    }
    
    if(sz - k + cur <= mx2) return; // 나머지가 다 되도 의미X
    func2(k + 1, cur);

    if((vec[k].first + vec[k].second) % 2 == 1){
        return;
    }

    if(used[0][(vec[k].first + vec[k].second)] == 0 && used[1][(vec[k].first - vec[k].second + 10)] == 0){
        used[0][(vec[k].first + vec[k].second)] = 1;
        used[1][(vec[k].first - vec[k].second + 10)] = 1;

        func2(k + 1, cur + 1);

        used[0][(vec[k].first + vec[k].second)] = 0;
        used[1][(vec[k].first - vec[k].second + 10)] = 0;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(used, 0, sizeof used);

    cin >> N;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++){
            cin >> board[i][j]; // 0 : 비솝이 못 존재
            if(board[i][j] == 1) vec.push_back(make_pair(i, j));
        }
    sz = vec.size();
    
    func1(0, 0);
    func2(0, 0);
    // binarySearch(0, sz);
    cout << mx1 + mx2 << '\n';

    return 0;
}
