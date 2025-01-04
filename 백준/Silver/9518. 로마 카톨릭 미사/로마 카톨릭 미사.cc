#include <bits/stdc++.h>
#define MAX 50
#define INF 10
#define MOD 987654321

using namespace std;

int R, S;
int arr[MAX][MAX];
int darr[][2] = {
    {-1, -1},
    {-1, 0},
    {-1, 1},
    {0, -1},
    {0, 1},
    {1, -1},
    {1, 0},
    {1, 1}
};
long long res = 0;
int empty_seat = 0;

inline bool inBoundary(int y, int x){
    return y >= 0 && x >= 0 && y < R && x < S;
}

void countShake(int y, int x){
    int cnt = 0;
    for(auto [dy, dx]: darr){
        int ty = y + dy;
        int tx = x + dx;

        if(!inBoundary(ty, tx)){
            continue;
        }

        if(arr[ty][tx] == (int)'o'){
            cnt++;
        }
    }

    if(arr[y][x] == (int)'.'){
        empty_seat = max(empty_seat, cnt);
    }
    else if(arr[y][x] == (int)'o'){
        res += cnt;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> R >> S;
    for(int i = 0; i < R; i++){
        string str;
        cin >> str;
        for(int j = 0; j < S; j++){
            arr[i][j] = str[j];
        }
    }

    
    for(int i = 0; i < R; i++){
        for(int j = 0; j < S; j++){
            countShake(i, j);
        }
    }

    cout << (res / 2) + empty_seat;


    return 0;
}
