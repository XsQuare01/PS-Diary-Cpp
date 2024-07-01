#define MAX 1000

#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[MAX][MAX];
int darr[][2] = {
    {-1, 0},
    {0, -1},
    {1, 0},
    {0, 1}
};
int color = 2;
queue<pair<int, int>> q;

void BFS(int y, int x, int color){
    q.push({y, x});
    while(!q.empty()){
        auto a = q.front();
        q.pop();
        int ty = a.first;
        int tx = a.second;

        if(arr[ty][tx]){
            continue;
        }
        arr[ty][tx] = color;

        for(auto [dy, dx]: darr){
            int tty = (N+ty+dy) % N;
            int ttx = (M+tx+dx) % M;

            if(arr[tty][ttx]){
                continue;
            }
            q.push({tty, ttx});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> arr[i][j];
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(arr[i][j]){
                continue;
            }
            BFS(i, j, color++);
        }
    }
    cout << color - 2;

    return 0;
}