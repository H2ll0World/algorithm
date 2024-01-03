// 1431, sort
/*
    1. 길이 비교
    2. 숫자 자리수의 합, 숫자인 것만 더함
    3. 알파벳 사전순 비교, 숫자는 알파벳보다 사전순으로 작음
*/


#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(string &a, string &b){
    // 1. 길이가 다른 경우
    if(a.length() != b.length()) return a.length() < b.length();
    
    // 2. 숫자 자리수의 합
    int ta = 0, tb = 0;
    for(int i = 0; i < a.length(); i++){ // 자리수가 같으므로 
        if(isdigit(a[i])){ // digit인 경우 1, non-digit인 경우 0
            //cout << "a[i] " << a[i] << '\n';
            ta = ta + a[i] - 48;
        }
        if(isdigit(b[i])){
            //cout << "b[i] " << b[i] << '\n';
            tb = tb + b[i] - 48;
        }
    }
    if(ta != tb) {
        //cout << "ta != tb\n";
        //cout << ta << ' ' << tb <<'\n';
        return ta < tb;
    }
    // 3. 알페벳 사전순으로 비교, 
    //      1. 알바벳 직접비교
    //      2. 아스키 코드바교
    for(int i = 0; i < a.length(); i++){
        if(a[i] == b[i]) continue;
        //cout << "a[i], b[i], i : " << a[i]<<' '<<b[i]<<' '<<i <<'\n';
        return a[i] < b[i];
    }
    // 3가지 경우다 같은 경우
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; // 50이하
    string sn[51];

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> sn[i];
    }

    sort(sn, sn + N, cmp);
    sn[1].length();

    for(int i = 0; i < N; i++){
        cout << sn[i] << '\n';
    }

    return 0;
}
