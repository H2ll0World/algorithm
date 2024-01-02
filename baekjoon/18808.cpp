// 18808

#include <iostream>
using namespace std;

int sticker[100][10][10]; // 10000개의 int
int board[40][40];
pair<int, int> sticker_size[100];

int func(const int num, const int N, const int M){
    int tx = 0, ty = 0;
    int check = 0;
    while(1){
        if(sticker_size[num].first > M) break;
        if(sticker_size[num].second > N) break;
        for(int i = 0; i < sticker_size[num].second; i++){
            for(int j = 0; j < sticker_size[num].first; j++){
                if(board[ty+i][tx+j] + sticker[num][i][j] == 2){
                    check = 1;
                    break;
                }
            }
            if(check == 1) break;
        }
        if(check == 0){ //자리를 찾은 경우
            //cout << "at check : tx, ty : " << tx <<','<< ty << "row : "<<sticker_size[num].second << '\n';
            //cout << num <<"번째 스티커 \n";
            for(int i = 0; i < sticker_size[num].second; i++){
                for(int j = 0; j < sticker_size[num].first; j++){
                    if(sticker[num][i][j] == 1){
                        board[ty+i][tx+j] = 1;
                    }
                }
            }
            return 1;
        }
        check = 0;
        tx++;
        if(tx > M - sticker_size[num].first){
            tx = 0;
            ty++;
            //cout << "inner tx > M - sticker_size[num].second\n";
        }
        if(ty > N - sticker_size[num].second){ // 왜 안걸리지?
            //cout << "ty > N \n";
            return 0; // 못한 경우;
        }
    }
    return 0;
}

void rotate(const int k){ // k번째 스티커를 시계방향으로 90도 회전
    int row = sticker_size[k].second;
    int col = sticker_size[k].first;
    int temp_sticker[10][10];

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            temp_sticker[j][-i + row - 1] = sticker[k][i][j];
        }
    }
    for(int i = 0; i < col; i++){
        for(int j = 0; j < row; j++){
            sticker[k][i][j] = temp_sticker[i][j];
        }
    }
    sticker_size[k].first = row;
    sticker_size[k].second = col;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,M,K;
    int result = 0;
    int tc, tr;
    cin >> N >> M >> K; // 스티커는 vector로, vector사용법?
    // N : 노트북의 세로길이, M : 노트북의 가로길이, K : 스티커의 개수
    for(int i = 0; i < K; i++){
        cin >> sticker_size[i].second >> sticker_size[i].first;
        for(int j = 0; j < sticker_size[i].second; j++){
            for(int l = 0; l < sticker_size[i].first; l++){
                cin >> sticker[i][j][l];
            }
        }
    }

    for(int i = 0; i < K; i++){
        for(int j = 0; j < 4; j++){
            tr = sticker_size[i].second;
            tc = sticker_size[i].first;
            //스티커 사이즈가 노트북보다 큰 경우도 고려해야함
            if(tr > N && tr > M) break;
            if(tc > N && tc > M) break;
            if((tr > N && tc > M) && (tr > M && tc > N)) break;

            if(func(i, N, M) == 1) break;
            if(j == 3) break;
            //cout << i <<"번째 스티커 " << j+1 << "번째 회전\n";
            rotate(i); // 스티커를 시계방향으로 90도 회전
        }
    }
    //cout << '\n';
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            //cout << board[i][j] << ' ';
            result = result + board[i][j];
        }
        //cout << '\n';
    }
    //cout << '\n';
    cout << result << '\n';

    return 0;
}
