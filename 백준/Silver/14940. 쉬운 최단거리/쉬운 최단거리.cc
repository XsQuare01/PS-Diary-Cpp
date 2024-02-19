#define MAX 1000
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

int n, m;
int arr[MAX][MAX];
int res[MAX][MAX];
int darr[][2]{
    {-1, 0},
    {0, -1},
    {1, 0},
    {0, 1}
};
pair<int, int> st;

inline bool InBoundary(int y, int x){
    return y >= 0 && x >= 0 && y < n && x < m && arr[y][x] == 1;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 2){
                st = {i, j};
            }
        }
    }

    queue<pair<pair<int, int>, int>> q;
    q.push({st, 0});

    while(!q.empty()){
        auto a = q.front();
        q.pop();
        int y = a.first.first;
        int x = a.first.second;
        int w = a.second;

        for(auto [dy, dx]: darr){
            int ty = y + dy;
            int tx = x + dx;

            if(!InBoundary(ty, tx)){
                continue;
            }

            if(ty == st.first && tx == st.second){
                continue;
            }

            if(res[ty][tx]){
                continue;
            }

            res[ty][tx] = w + 1;
            q.push({{ty, tx}, w + 1});
        }

    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int v = res[i][j];
            if(res[i][j] == 0 && arr[i][j] == 1){
                v = -1;
            }
            cout << v << " ";
        }
        cout << "\n";
    }
    return 0;
}