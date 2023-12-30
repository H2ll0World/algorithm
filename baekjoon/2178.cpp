/*
	미로에서 1은 이동할수있는 칸 0은 이동X, (1,1)에서 출발하여 (N,M)의 위치로 이동할 때 지나야 하는 최소의 칸수
*/
#include <queue>
#include <iostream>

using namespace std;

int board[100][100];
int vis[100][100];

const int dx[4] = { 1, -1, 0,0 };
const int dy[4] = { 0,0,1,-1 };

int main() {
	int n, m;
	string t_input;
	int tx, ty;
	cin >> n;
	cin >> m;
	for (int i = 0; i < n; i++) {
		cin >> t_input;
		int j = 0;
		for (char digit : t_input) {
			board[i][j] = digit - 48;
			j++;
		}
	}
	// BFS
	queue<pair<int, int> > Q;
	Q.push({ 0,0 });
	vis[0][0] = 1;
	int idx = 0;
	pair<int, int> curpos;
	while (!Q.empty()) {
		curpos = Q.front();
		Q.pop();
		for (int i = 0; i < 4; i++) {
			tx = curpos.first + dx[i];
			ty = curpos.second + dy[i];
			if (tx < 0 || tx >= m) continue;
			if (ty < 0 || ty >= n) continue;
			if (vis[ty][tx] == 0 && board[ty][tx] == 1) {
				Q.push(make_pair(tx, ty));
				vis[ty][tx] = vis[curpos.second][curpos.first] + 1;
			}
		}
	}
	cout << vis[n - 1][m - 1];



	return 0;
}
