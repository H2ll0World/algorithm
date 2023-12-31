/*
	11729 하노이 탑 Tower of Hanoi
*/

#include <iostream>
#include <stack>

using namespace std;

int line[3][20];
stack<int> s[3];

void func1(int n, int start, int end, int odd_even) {
	if (n == 1) {
		cout << start << " " << end << "\n";
		return;
	}
	func1(n - 1, start, end % 2 + 2, odd_even);
	cout << start << " " << (n % 3 + 1) << "\n";
	func1(n - 1, n % 3 + 1, n % 3 + 1, odd_even);
}

void func1(int n, stack<int> s[3]) {
	int start = 0, end = 0;
	if (n == 1) {
		for (int i = 0; i < 3; i++) {
			if (s[i].top() == 1) {
				start = i;
			}
		}
	}
	// 옮기는 것
	
}

int main() {
	int N;
	int result = 1;
	cin >> N;
	for (int i = 0; i < N; i++) {
		result = result * 2;
	}
	cout << result - 1 << "\n";
	func1(N, 1, 3, N % 2);


	return 0;
}
