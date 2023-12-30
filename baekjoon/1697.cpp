#include <queue>
#include <iostream>

using namespace std;

int vis[100001];

int main() {
	int h, c;//hider, catcher;
	cin >> c >> h;
	queue<int> Q;
	int temp;


	Q.push(c);
	vis[c] = 1; // 나중에 -1 해주기
	while (!Q.empty()) {
		temp = Q.front(); Q.pop();
		if (temp == h) {
			cout << vis[temp] - 1; 
			return 0;
		}
		
		if (temp + 1 <= 100000 && vis[temp+1] == 0) {
			Q.push(temp + 1);
			vis[temp + 1] = vis[temp] + 1;
		}
		if (temp - 1 >= 0 && vis[temp-1] == 0) {
			Q.push(temp - 1);
			vis[temp - 1] = vis[temp] + 1;
		}
		if (temp * 2 <= 100000 && vis[temp * 2] == 0) {
			Q.push(temp * 2);
			vis[temp * 2] = vis[temp] + 1;
		}
	}

	return 0;
}
