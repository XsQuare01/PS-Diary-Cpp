#define MAX 5
#define MOD 1000000007
#define INF 64

#include<bits/stdc++.h>

using namespace std;

int arr[MAX][MAX];
int R, C;
int darr[][2] = {
    {-1, 0},
    {0, -1},
    {1, 0},
    {0, 1}
};
queue<tuple<int, int, int, int>> q; // {x, y, hash, count}

bool inline InBoundary(int y, int x){
    return y >= 0 && x >= 0 && y < MAX && x < MAX && arr[y][x] != -1;
}

bool inline AlreadyVisited(int target, int index){
    return (target &(1 << (index - 1))) == 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            cin >> arr[i][j];
        }
    }
    cin >> R >> C;
    
    q.push({R, C, 0, 0});
    while(!q.empty()){
        auto a = q.front();
        q.pop();

        int cnt = get<3>(a);
        if(cnt > 13){
            continue;
        }
        int y = get<0>(a);
        int x = get<1>(a);
        int p_hash = get<2>(a);

        for(auto [dy, dx]: darr){
            int ty = y + dy;
            int tx = x + dx;

            // 범위 밖
            if(!InBoundary(ty, tx)){
                continue;
            }
            
            // 이미 밟은 숫자
            if(arr[ty][tx] == 0 || !AlreadyVisited(p_hash, arr[ty][tx])){
                q.push({ty, tx, p_hash, cnt+1});
                continue;
            }

            int n_hash = p_hash + pow(2, arr[ty][tx]-1);
            
            if(n_hash == 63){
                cout << cnt + 1;
                return 0;
            }
            q.push({ty, tx, n_hash, cnt+1});
        }
    }

    cout << -1;
    return 0;
}