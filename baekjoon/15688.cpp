// 15688 , counting sort

#include <iostream>
using namespace std;

int arr[2000001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    int temp;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> temp;
        arr[temp + 1000000]++;
    }

    for(int i = 0; i < 2000001; i++){
        while(arr[i]-- > 0){
            cout << i - 1000000 << '\n';
        }
    }

    return 0;
}
