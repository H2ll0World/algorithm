/* 
    2217 로프
    1~100,000개의 로프
    각 로프는 1~10000까지의 무게를 들 수 있음
*/
#include <iostream>
using namespace std;

int rope[10001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, input;
    int notUse = 0;
    int mw = 0;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> input;
        rope[input]++;
    }

    // 앞에서 부터 봄 => corner case존재, 5가지 입력 : 5, 6, 100, 100, 100
    // 뒤에서 부터 봄 => corner case존재, 5가지 입력 : 5, 5, 5, 6, 13
    // greedy로 풀 수 있음? => 전부다 봐야하는 거 아님? 전부다 봐도 O(N)에 가능할 것 같은데
    
    for(int i = 1; i < 10001; i++){
        mw = max(mw, i * (n - notUse));
        notUse += rope[i];
    }
    cout << mw << '\n';

    return 0;
}
