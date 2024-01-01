/*
	11729 하노이 탑 Tower of Hanoi
*/

#include <iostream>
#include <stack>

using namespace std;

// n번째 일때 a기둥에서 b기둥으로 옮겨줌
void func(int a, int b, int n){
    if(n == 1){ // base case
        cout << a << " " << b << "\n";
        return;
    }
    // 1 + 2 + 3 == 6, 6 - a - b : 1,2,3중 a,b에 해당하지 않는 것
    func(a, 6 - a - b, n - 1);
    cout << a << " " << b << "\n";
    func(6- a - b ,b ,n-1);
}

int main(){
    int N;
    cin >> N;

    cout << (1<<N)-1 << "\n";
    func(1, 3, N);
    

    return 0;
}
