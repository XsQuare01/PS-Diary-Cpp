#define MAX 100
#define MOD 9901
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

int R, C;
char arr[MAX][MAX];
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

inline bool InBoundary(int y, int x){
    return y >= 0 && y < R && x >= 0 && x < C;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while(true){
        cin >> R >> C;
        if(R == 0 && C == 0){
            break;
        }
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                cin >> arr[i][j];
            }
        }

        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                if(arr[i][j] == '*'){
                    cout << '*';
                    continue;
                }

                int cnt = 0;
                for(auto [dy, dx]: darr){
                    int ty = i + dy;
                    int tx = j + dx;

                    if(!InBoundary(ty, tx)){
                        continue;
                    }

                    if(arr[ty][tx] == '*'){
                        cnt++;
                    }
                }
                cout << cnt;
            }
            cout << '\n';
        }
    }
    return 0;
}