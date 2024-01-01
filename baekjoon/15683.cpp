// 15683
// cctv 사각지대의 최소 크기를 구하는 프로그램 작성

#include <iostream>
using namespace std;

int board[8][8];
int watching[8][8];
int cctvPos[8][3]; // 종류, 세로, 가로, 방향
int cctvDir[8]; // 0 : 12, 1 : 3, 2 : 6, 3 : 9
int cctvNum = 0;
int wall = 0;
int ms = 0;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int cal(const int N, const int M){ // cctv의 시야를 계산
    int tempBoard[8][8];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            tempBoard[i][j] = 0;
        }
    }
    int y, x, dir, kind;
    int y1, x1;
    int result = 0;

    for(int i = 0; i < cctvNum; i++){
        y = cctvPos[i][1];
        x = cctvPos[i][2];
        kind = cctvPos[i][0];
        dir = cctvDir[i];
        tempBoard[y][x] = 1;
        if(kind == 1){
            while(true){
                y = y + dy[dir];
                x = x + dx[dir];
                if(y < 0 || y >= N) break;
                if(x < 0 || x >= M) break;
                if(board[y][x] == 6) break;
                tempBoard[y][x] = 1;
            }
        }else if(kind == 2){ // dir 
            y1 = y; x1 = x;
            while(true){
                y1 = y1 + dy[dir];
                x1 = x1 + dx[dir];
                if(y1 < 0 || y1 >= N) break;
                if(x1 < 0 || x1 >= M) break;
                if(board[y1][x1] == 6) break;
                tempBoard[y1][x1] = 1;
            }
            y1 = y; x1 = x;
            while(true){
                y1 = y1 + dy[dir+2];
                x1 = x1 + dx[dir+2];
                if(y1 < 0 || y1 >= N) break;
                if(x1 < 0 || x1 >= M) break;
                if(board[y1][x1] == 6) break;
                tempBoard[y1][x1] = 1;
            }
        }else if(kind == 3){
            y1 = y; x1 = x;
            while(true){
                y1 = y1 + dy[dir];
                x1 = x1 + dx[dir];
                if(y1 < 0 || y1 >= N) break;
                if(x1 < 0 || x1 >= M) break;
                if(board[y1][x1] == 6) break;
                tempBoard[y1][x1] = 1;
            }
            y1 = y; x1 = x;
            while(true){
                y1 = y1 + dy[(dir+1)%4];
                x1 = x1 + dx[(dir+1)%4];
                if(y1 < 0 || y1 >= N) break;
                if(x1 < 0 || x1 >= M) break;
                if(board[y1][x1] == 6) break;
                tempBoard[y1][x1] = 1;
            }
        }else if(kind == 4){
            //cout << "1in cal() kind == 4\n";
            y1 = y; x1 = x;
            while(true){
                y1 = y1 + dy[dir];
                x1 = x1 + dx[dir];
                if(y1 < 0 || y1 >= N) break;
                if(x1 < 0 || x1 >= M) break;
                if(board[y1][x1] == 6) break;
                tempBoard[y1][x1] = 1;
            }
            //cout << "2in cal() kind == 4\n";
            y1 = y; x1 = x;
            while(true){
                y1 = y1 + dy[(dir+1)%4];
                x1 = x1 + dx[(dir+1)%4];
                if(y1 < 0 || y1 >= N) break;
                if(x1 < 0 || x1 >= M) break;
                if(board[y1][x1] == 6) break;
                tempBoard[y1][x1] = 1;
            }
            //cout << "3in cal() kind == 4\n";
            y1 = y; x1 = x;
            while(true){
                y1 = y1 + dy[(dir+2)%4];
                x1 = x1 + dx[(dir+2)%4];
                if(y1 < 0 || y1 >= N) break;
                if(x1 < 0 || x1 >= M) break;
                if(board[y1][x1] == 6) break;
                tempBoard[y1][x1] = 1;
            }
            //cout << "4in cal() kind == 4\n";
        }else if(kind == 5){
            y1 = y; x1 = x;
            while(true){
                y1 = y1 + dy[0];
                x1 = x1 + dx[0];
                if(y1 < 0 || y1 >= N) break;
                if(x1 < 0 || x1 >= M) break;
                if(board[y1][x1] == 6) break;
                tempBoard[y1][x1] = 1;
            }
            y1 = y; x1 = x;
            while(true){
                y1 = y1 + dy[1];
                x1 = x1 + dx[1];
                if(y1 < 0 || y1 >= N) break;
                if(x1 < 0 || x1 >= M) break;
                if(board[y1][x1] == 6) break;
                tempBoard[y1][x1] = 1;
            }
            y1 = y; x1 = x;
            while(true){
                y1 = y1 + dy[2];
                x1 = x1 + dx[2];
                if(y1 < 0 || y1 >= N) break;
                if(x1 < 0 || x1 >= M) break;
                if(board[y1][x1] == 6) break;
                tempBoard[y1][x1] = 1;
            }
            y1 = y; x1 = x;
            while(true){
                y1 = y1 + dy[3];
                x1 = x1 + dx[3];
                if(y1 < 0 || y1 >= N) break;
                if(x1 < 0 || x1 >= M) break;
                if(board[y1][x1] == 6) break;
                tempBoard[y1][x1] = 1;
            }
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            result = result + tempBoard[i][j];
            //cout << tempBoard[i][j] << ' ';
        }
        //cout << '\n';
    }
    //cout << '\n';
    return result;
}

void func(int k, const int N, const int M){
    //cout << "k : " << k << "\n";
    if(cctvNum == 0){
        ms = cal(N,M);
        return;
    }
    int kind = cctvPos[k][0];
    if(k == cctvNum - 1){ // base case
        //cout << "base case : k : " << k << " kind : " << kind << '\n';
        if(kind == 2){
            cctvDir[k] = 0;
            if(ms < cal(N,M)) ms = cal(N,M);
            cctvDir[k] = 1;
            if(ms < cal(N,M)) ms = cal(N,M);
            return;
        }else if(kind == 5){
            if(ms < cal(N,M)) ms = cal(N,M);
            return;
        }
        for(int i = 0; i < 4; i++){
            cctvDir[k] = i;
            //cout << "1in basecase in for loon, i : "<<i<<'\n';
            if(ms < cal(N,M)) ms = cal(N,M);
            //cout << "2in basecase in for loon, i : "<<i<<'\n';
        }
        return;
    }
    if(kind == 5){
        func(k+1, N, M);
        return;
    }else if(kind == 2){
        cctvDir[k] = 0;
        func(k+1, N, M);
        cctvDir[k] = 1;
        func(k+1, N, M);
        return;
    }
    for(int i = 0; i < 4; i++){
        cctvDir[k] = i;
        func(k+1, N, M);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, temp = 0;
    cin >> N >> M;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> board[i][j];
            temp = board[i][j];
            if(temp > 0 && temp < 6) {
                cctvPos[cctvNum][0] = temp;
                cctvPos[cctvNum][1] = i;
                cctvPos[cctvNum][2] = j;
                cctvNum++;
            }else if(temp == 6){
                wall++;
            }
        }
    }
    //cout << "before func() \n";
    func(0, N, M);
    //cout << "ms : " << ms << '\n';
    //cout << "wall : " << wall << '\n';
    cout << N * M  - ms - wall << '\n';

    return 0;
}
