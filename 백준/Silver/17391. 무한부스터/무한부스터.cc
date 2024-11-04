#define MAX 300
#define MOD 1000000007
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

int N, M;
int arr[MAX][MAX];
int farr[MAX][MAX];
int darr[][2] = {
    {1, 0},
    {0, 1}
};
queue<pair<pair<int, int>, int>> q;

inline bool InBoundary(int y, int x){
    return y >= 0 && x >= 0 && y < N && x < M;
}

void BFS(){
    while(!q.empty()){
        auto a = q.front();
        q.pop();

        int y = a.first.first;
        int x = a.first.second;
        int cnt = a.second;

        for(auto [dy, dx]: darr){
            for(int i = 1; i <= arr[y][x]; i++){
                int ty = y + dy * i;
                int tx = x + dx * i;

                if(!InBoundary(ty, tx)){
                    continue;
                }

                if(farr[ty][tx] <= cnt + 1){
                    continue;
                }
                farr[ty][tx] = cnt + 1;
                q.push({{ty, tx}, cnt + 1});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> arr[i][j];
            farr[i][j] = INF;
        }
    }

    q.push({{0, 0}, 0});
    farr[0][0] = 0;
    BFS();

    cout << farr[N-1][M-1];

    return 0;
}