#include <iostream>
#include <queue>

using namespace std;

int vis[1000][1000];
int board[1000][1000];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int main() {
	int m, n;
	int md = 1; // max_date, temp_date
	int nx, ny; // next_x, next_y
	int nonRipeTomataCount = 0;
	cin >> m >> n;
	
	queue<pair<int, int> > Q;
	pair<int, int> curpos;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) {
				Q.push(make_pair(j, i));
				vis[i][j] = 1;
			}
			else if(board[i][j] == 0) {
				nonRipeTomataCount++;
			}
		}
	}
	// cout << "non : " << nonRipeTomataCount << "\n";

	while (!Q.empty()) {
		curpos = Q.front(); Q.pop();
		for (int i = 0; i < 4; i++) {
			nx = curpos.first + dx[i];
			ny = curpos.second + dy[i];
			if (nx < 0 || nx >= m) continue;
			if (ny < 0 || ny >= n) continue;
			if (vis[ny][nx] == 0 && board[ny][nx] == 0) {
				Q.push(make_pair(nx, ny));
				vis[ny][nx] = vis[curpos.second][curpos.first] + 1;
				md = vis[ny][nx];
				nonRipeTomataCount--;
			}
		}
	}
	if (nonRipeTomataCount > 0) {
		cout << "-1";
		return 0;
	}
	cout << md - 1;

	return 0;
}
