#define MAX 2222
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

int N;
int arr[MAX][MAX];
int res[MAX][MAX];
int darr[][2] = {
    {1, 0},
    {0, 1}
};

queue<pair<pair<int, int>, int>> q;

inline bool InBoundary(int y, int x){
    return y >= 0 && x >= 0 && y < N && x < N;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 

    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> arr[i][j];
            res[i][j] = INF;
        }
    }
    q.push({{0, 0}, 0});
    while(!q.empty()){
        int y = q.front().first.first;
        int x = q.front().first.second;
        int w = q.front().second;
        q.pop();

        if(res[y][x] < w){
            continue;
        }
        res[y][x] = w;

        for(auto [dy, dx]: darr){
            int ty = y + dy;
            int tx = x + dx;
            if(!InBoundary(ty, tx)){
                continue;
            }

            int tw  = w + (arr[y][x] > arr[ty][tx] ? 0 : arr[ty][tx] - arr[y][x] + 1);
            if(res[ty][tx] <= tw){
                continue;
            }

            res[ty][tx] = tw;
            q.push({{ty, tx}, tw});
        }
    }

    cout << res[N-1][N-1];
    return 0;
}