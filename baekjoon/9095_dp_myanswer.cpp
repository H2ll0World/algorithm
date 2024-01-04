/*
    9095
    정수 n이 주어졌을 떄, n을 1, 2, 3의 합으로 나타내는 법

    testcase num T의 범위x => 벡터로
    N의 범위는 양수, 10이하
*/
#include <iostream>
#include <vector>
using namespace std;

int d[11];
int d_element[11][3]; // 1, 2 ,3;

int per(int a, int b){
    long long total = 1;
    for(int i = 0; i < a; i++){
        total = total * (a + b - i);
    }
    for(int i = 0; i < a; i++){
        total = total / (i + 1);
    }
    return total;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    int tem;
    vector<int> arr;
    cin >> T;
    
    for(int i = 0; i < T; i++){
        cin >> tem;
        arr.push_back(tem);
    }
    
    

    d[1] = 1;
    int tarr[3];
    int num;
    // n의 개수가 적으므로 3중 for문 가능?
    for(int i = 2; i < 11; i++){
        num = 0;
        //arr[0] = 0; arr[1] = 0; arr[2] = 0;
        for(int j = 0; j < 4; j++){ // 3
            for(int k = 0; k < 6; k++){ // 2
                for(int z = 0; z < 11; z++){
                    if(3*j + 2*k + z > i){
                        break;
                    }
                    if(3*j + 2*k + z == i){
                        num = num + per(j, k + z) * per(k, z);
                        break;
                    }
                }
            }
        }
        d[i] = num;
    }

    for(int i = 0; i < T; i++){
        cout << d[arr[i]] << '\n';
    }


    return 0;
}
