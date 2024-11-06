#define MAX 200
#define MOD 1000000007
#define INF 1000

#include<bits/stdc++.h>

using namespace std;

int N, K, S, X, Y;
int arr[MAX + 1][MAX + 1];
queue<pair<int, int>> parr[INF  + 1];
int darr[][2] = {
    {-1, 0},
    {0, -1},
    {1, 0},
    {0, 1}
};

inline bool InBoundary(int y, int x){
    return y >= 0 && x >= 0 && y < N && x < N && arr[y][x] == 0;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            int t;
            cin >> t;
            parr[t].push({i, j});
            arr[i][j] = t;
        }
    }

    cin >> S >> X >> Y;

    // 탐색 횟수
    for(int i = 0; i < S; i++){
        bool change_flag = false;

        // 바이러스 번호
        for(int j = 1; j <= K; j++){
            int len = parr[j].size();
            
            // 바이러스 방이 있는 길이
            for(int k = 0; k < len; k++){

                auto a = parr[j].front();
                parr[j].pop();

                int y = a.first;
                int x = a.second;

                for(auto [dy, dx]: darr){    
                    int ty = y + dy;
                    int tx = x + dx;
                    if(!InBoundary(ty, tx)){
                        continue;
                    }

                    arr[ty][tx] = j;
                    parr[j].push({ty, tx});
                    change_flag = true;
                }
            }
        }

        if(!change_flag){
            break;
        }
    }

    //Debug
    // for(int i = 0; i < N; i++){
    //     for(int j = 0; j < N; j++){
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    cout << arr[X-1][Y-1];    

    return 0;
}