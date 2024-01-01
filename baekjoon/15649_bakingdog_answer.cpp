#include <iostream>
using namespace std;

int arr[10];
bool isused[10];

// k번째 일때
void func(int k, const int N, const int M){
    if(k == M){ 
        for(int i = 0; i < M; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i = 1; i <= N; i++){
        if(!isused[i]){
            arr[k] = i;
            isused[i] = 1;
            func(k+1, N, M);
            isused[i] = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,M;
    cin >> N >> M; // M개 선택

    func(0, N, M);

    return 0;
}
