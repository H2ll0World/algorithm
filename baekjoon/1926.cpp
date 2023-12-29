#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int board[500][500];
int vis[500][500];
// cpp 에서 global var를 초기화하지 않은 경우, BSS영역에 자동으로 "0"으로 초기화
// 변하지 않는 값이므로 const로 선언하여 corruption 방지
// EWSN로 동작
const int dx[4] = { 1,-1,0,0 };
const int dy[4] = { 0,0,1,-1 };

int main() {
    int n, m;
    cin >> n;
    cin >> m;

    //동적배열
    //vector 자료구조이용
    // board 채우는 것
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    // BFS를 위한 queue
    // .push() : 큐에 넣어줌
    // .front() : 최상단 데이터 반환 
    // .back() : 제일 마지막 데이터 반환
    // .size() : 사이즈를 반환
    // .empty() : 큐가 비어있는 지 확인, 비어있는 경우 : , 차있는 경우 : 
    // swap(queue1, queue2)
    queue<pair<int, int> > Q;
    // 0은 공백, 1은 그림
    // 최대그림의 넓이+ 그림의 개수

    int ms = 0; // 최대 넓이
    int mc = 0; // 그림의 최대 개수
    int ts; // 현재 큐에 있는 그림의 넓이

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // 방문한 적이 없고, board가 그림이면
            if (vis[i][j] == 0 && board[i][j] == 1) {
                Q.push(make_pair(j, i));
                vis[i][j] = 1;
                ts = 1;
                // printf("mc x : %d, y : %d\n", j, i);
                mc++; // 방문한적 없는 그림에 방문 했으므로 그림의 수를 증가시킴
                while (!Q.empty()) {
                    pair<int, int> curpos;
                    curpos = Q.front();
                    Q.pop();
                    int tx, ty;
                    for (int k = 0; k < 4; k++) {
                        tx = curpos.first + dx[k];
                        // printf("tx : %d, first : %d, dx[%d] : %d ", tx, curpos.first, k, dx[k]);
                        ty = curpos.second + dy[k];
                        // printf("ty : %d, second : %d, dx[%d] : %d\n", ty, curpos.second, k, dy[k]);
                        if (tx < 0 || tx >= m) continue;
                        if (ty < 0 || ty >= n) continue;
                        if (vis[ty][tx] == 0 && board[ty][tx] == 1) {
                            Q.push(make_pair(tx, ty));
                            ts++;
                            // printf("i : %d, j : %d x : %d, y : %d\n",i,j, tx, ty);
                            vis[ty][tx] = 1;
                        }
                    }
                }
                if (ts > ms) ms = ts; //현재의 크기가 지금까지의 최대 크기 보다 큰 경우
            }
            vis[i][j] = 1;
        }
    }
    printf("%d\n%d", mc, ms); // max count

    return 0;
}
