/*
	11729 하노이 탑 Tower of Hanoi
*/

#include <iostream>
#include <stack>

using namespace std;

stack<int> s[3];

void func1(int origin, int n, stack<int> s[3]) {
	int start = -1, end = 0, cur = 0;
    //cout << "cur state : " << n << "\n";
	if (n == 1) { // base condition
		for (int i = 0; i < 3; i++) {
			if (s[i].top() == 1) {
				start = i;
                s[i].pop();
			}
		}
        if((origin + n) % 2 == 0){
            end = (start + 2) % 3 + 1;
        }else{
            end = (start + 1) % 3 + 1;
        }
        s[end-1].push(1);
        cout << start + 1 << " " << end << "\n";
        // 1을 어디로 옮길지 정해주고 종료해야 함
        return;
	}
    func1(origin, n-1, s);
	// 옮기는 것
    for(int i = 0; i < 3; i++){
        if(s[i].top() == n) start = i;
    }
    for(int i = 0; i < 3; i++){
        if(i != start && s[i].top() > n) end = i;
    }
    if(start == -1){
        cout << "start error at : "<< n << "\n";
    }
    s[start].pop();
    s[end].push(n);
    cout << start+1 << " " << end + 1 << "\n";
    func1(origin, n-1, s);
}

int main() {
	int N;
	int result = 1;
	cin >> N;
    for(int i = 0; i < 3; i++){
        s[i].push(100);
    }
	for (int i = 0; i < N; i++) {
		result = result * 2;
        s[0].push(N-i);
	}
	cout << result - 1 << "\n";
	func1(N, N, s);


	return 0;
}
