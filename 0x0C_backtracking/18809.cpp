// https://www.acmicpc.net/problem/18809
// Gaaaaaaaaaarden
#include <iostream>
#include <vector>
#include <memory.h>
#include <algorithm>
#include <queue>
#include <tuple>

// #include <fstream> // 파일 입출력을 위한 헤더
using namespace std;

int N, M; // 행, 열
int G, R;

int board[50][50];
vector<pair<int, int> > vec; // 씨앗을 심을 수 있는 위치
int mx = 0;

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

// 색, turn
pair<int, int> seed[50][50];
vector<int> pos;
bool vis[3][50][50];

// 합쳐질 경우 꽃이 되므로 한 턴이 끝나고 bfs를 수행해야 함
void cal(){
    memset(seed, 0, sizeof seed);
    memset(vis, 0, sizeof vis);
    int tMx = 0;

    // y, x, turn, color
    queue<tuple<int, int, int, int> > q;
    queue<tuple<int, int, int, int> > aq; // after queue
    for(int i = 0; i < pos.size(); i++){
        if(pos[i] == 0) continue;
        q.push(make_tuple(vec[i].first, vec[i].second, 1, pos[i]));
        // cout << "--- " << vec[i].first << ", " <<  vec[i].second << ", " << 1 << ", " << pos[i] << "\n";
    }

    // bfs
    int y, x, turn, color;
    int ny, nx;

    int gT = 1; // global turn
    while(!q.empty() || !aq.empty()){
        while(!q.empty()){
            tie(y, x, turn, color) = q.front(); 
            if(seed[y][x].first == 0){ // 처음 방문
                seed[y][x].first = color;
                seed[y][x].second = turn;
                aq.push(q.front()); q.pop();
                continue;
            }
            
            // 이미 방문한 경우
            if(seed[y][x].first != color && seed[y][x].second == turn){
                seed[y][x].first = 3; // 꽃
                seed[y][x].second = turn;
                tMx++;
            }else{
                // cout << "error\n";
            }
            
            q.pop();
        }
        
        // bfs
        while(!aq.empty()){
            tie(y, x, turn, color) = aq.front(); aq.pop();
            if(seed[y][x].first == 3) continue; // 꽃

            for(int i = 0; i < 4; i++){
                ny = y + dy[i]; nx = x + dx[i];
                if(ny == -1 || ny == N || nx == -1 || nx == M) continue; // OOB
                if(board[ny][nx] == 0) continue; // 호수
                if(seed[ny][nx].first != 0) continue; // 다른 것이 존재
                if(vis[color][ny][nx] == 1) continue; vis[color][ny][nx] = 1;

                q.push(make_tuple(ny, nx, turn + 1, color));
            }
        }
    }

    // cout << "seed\n";
    // for(int i = 0; i < N; i++){
    //     for(int j = 0; j < M; j++){
    //         cout << "(" << seed[i][j].first << "," << seed[i][j].second << ")" << " ";
    //     }
    //     cout << '\n';
    // }

    // cout << "tMX : " << tMx << "\n\n";

    if(mx < tMx) mx = tMx;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // // 1. 출력을 저장할 파일 스트림 생성
    // std::ofstream out("output.txt");

    // // 2. 원래 cout이 가리키던 버퍼(모니터) 주소를 보관
    // std::streambuf* coutbuf = std::cout.rdbuf();

    // // 3. cout의 버퍼를 파일 스트림의 버퍼로 변경
    // std::cout.rdbuf(out.rdbuf());

    cin >> N >> M;
    cin >> G >> R;

    // 0 : 호수
    // 1 : 배양액 X
    // 2 : 배양액 O
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++){
            cin >> board[i][j];
            if(board[i][j] == 2){
                vec.push_back(make_pair(i, j));
            }
        }
            
    // 배양액 위치
    for(int i = 0; i < (vec.size() - G - R); i++)
        pos.push_back(0);
    for(int i = 0; i < G; i++)
        pos.push_back(1);
    for(int i = 0; i < R; i++)
        pos.push_back(2);

    // for(auto iter : vec){
    //     cout << iter.first << "," << iter.second << ";\n";
    // }
    // cout << "\n";

    // for(auto iter : pos){
    //     cout << iter << ", ";
    // }
    // cout << "\n";

    // while 문으로 하면 안돼나?
    do{
        cal();
        // cout << "nxt\n\n";
    }while(next_permutation(pos.begin(), pos.end()));

    cout << mx << "\n";

    // 4. (중요) 작업이 끝나면 원래대로 복구 (안 하면 프로그램 종료 시 문제 생길 수 있음)
    // std::cout.rdbuf(coutbuf);

    return 0;
}
