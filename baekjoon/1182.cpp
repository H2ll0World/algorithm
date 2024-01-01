// 1182, 부분수열의 합

#include <iostream>
using namespace std;

int input[20];
bool isused[20]; // bool은 0으로 초기화
int totalNum = 0;

void func(int k, int result, const int N, const int S){
    if(k == N - 1){ // N - 1 이 맞나?
        if(result + input[k] == S) totalNum++;
        if(result == S) totalNum++;
        return;
    }
    isused[k] = true;
    func(k+1, result + input[k], N, S);
    isused[k] = false;
    func(k+1, result, N, S);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, S;
    cin >> N >> S;
    for(int i = 0; i < N; i++){
        cin >> input[i];
    }
    func(0, 0, N, S);
    if(S == 0) totalNum--;
    cout << totalNum << "\n";

    return 0;
}
