#define MAX 1000

#include<bits/stdc++.h>

using namespace std;

int N, M, R;
int arr[MAX][MAX];
int res[MAX][MAX];
int darr[][2] = {
    {-1, 0},
    {0, -1},
    {1, 0},
    {0, 1}

};
queue<pair<pair<int, int>, int>> q;


inline bool InBoundary(int y, int x){
    return y >= 0 && x >= 0 && y < N && x < M && res[y][x] == 0 && arr[y][x] != -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> M >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> arr[i][j];

            if(arr[i][j] == 1){
                q.push({{i, j}, 1});
            }
        }
    }

    while(!q.empty()){
        auto a = q.front();
        q.pop();

        int y = a.first.first;
        int x = a.first.second;
        int d = a.second;

        if(res[y][x]){
            continue;
        }

        res[y][x] = d;
        
        for(auto [dy, dx]: darr){
            int ty = y + dy;
            int tx = x + dx;

            if(!InBoundary(ty, tx)){
                continue;
            }

            q.push({{ty, tx}, d+1});
        }

    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(arr[i][j] == -1){
                continue;
            }

            if(res[i][j] == 0){
                cout << -1;
                return 0;
            }

            R = max(R, res[i][j]-1);
        }
    }

    cout << R;
    return 0;
}