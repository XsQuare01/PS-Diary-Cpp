#define MAX 1000

#include<bits/stdc++.h>

using namespace std;

int n, m;
char arr[MAX][MAX];
int darr[][2] = {
    {-1, 0},
    {0, -1},
    {1, 0},
    {0, 1}
};
vector<pair<int, int>> fvector;
int fire[MAX][MAX] = {0, };
int jihun[MAX][MAX] = {0, };

inline bool InBoundary(int y, int x){
    return y >= 0 && x >= 0 && y < n && x < m;
}

void FireBFS(){
    queue<pair<int, int>> q;
    for(auto a: fvector){
        q.push({a.first, a.second});
        fire[a.first][a.second] = 1;
    }
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        int ty, tx;
        for(auto [dy, dx] : darr){
            ty = y + dy;
            tx = x + dx;

            if(!InBoundary(ty, tx) || fire[ty][tx] || arr[ty][tx] == '#'){
                continue;
            }

            fire[ty][tx] = fire[y][x] + 1;
            q.push({ty, tx});
        }
    }
}

int JihunBFS(int y, int x){
    queue<pair<int, int>> q;
    q.push({y, x});
    jihun[y][x] = 1;

    while(!q.empty()){
        y = q.front().first;
        x = q.front().second;
        q.pop();

        int ty, tx;
        for(auto [dy, dx]: darr){
            ty = y + dy;
            tx = x + dx;

            if(arr[ty][tx] == '#' || jihun[ty][tx]){
                continue;
            }

            if(!InBoundary(ty, tx)){
                return jihun[y][x];
            }

            jihun[ty][tx] = jihun[y][x] + 1;

            if(jihun[ty][tx] < fire[ty][tx] || fire[ty][tx] == 0){
                q.push({ty, tx});
            }
        }
    }

    return -1;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    cin >> n >> m;

    pair<int, int> ji;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];

            if(arr[i][j] == 'J'){
                ji = {i, j};
            }

            if(arr[i][j] == 'F'){
                fvector.push_back({i, j});
            }
        }
    }

    FireBFS();
    int res = JihunBFS(ji.first, ji.second);
    
    if(res == -1){
        cout << "IMPOSSIBLE";
        return 0;
    }
    cout << res;
    return 0;
}