#define MAX 1000
#define MOD 9901
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

int N;
char arr[MAX][MAX];
int darr[][2] = {
    {-1, 0},
    {0, -1},
    {0, 1},
    {1, 0}
};
int farr[MAX][MAX] = {0, };
int flag = 1;

inline bool InBoundary(int y, int x, char c1, char c2){
    return y >= 0 && x >= 0 && y < N && x < N && (arr[y][x] == c1 || arr[y][x] == c2)  && farr[y][x] == 0;
}

void Init(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            farr[i][j] = 0;
        }
    }
}

void BFS(int y, int x, char c1, char c2){
    queue<pair<int, int>> q;
    q.push({y, x});

    while(!q.empty()){
        auto a = q.front();
        q.pop();

        int y = a.first;
        int x = a.second;

        for(auto [dy, dx]: darr){
            int ty = y + dy;
            int tx = x + dx;

            if(!InBoundary(ty, tx, c1, c2)){
                continue;
            }

            farr[ty][tx] = flag;
            q.push({ty, tx});
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        for(int j = 0; j < N; j++){
            arr[i][j] = s[j];
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(farr[i][j]){
                continue;
            }

            BFS(i, j, arr[i][j], arr[i][j]);
            flag++;
        }
    }

    cout << flag-1 << " ";
    flag = 1;
    Init();
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(farr[i][j]){
                continue;
            }

            char c;
            switch(arr[i][j]){
                case 'R':
                    c = 'G';
                    break;
                case 'G':
                    c = 'R';
                    break;
                default:
                    c = 'B';
                    break;
            }   

            BFS(i, j, arr[i][j], c);
            flag++;
        }
    }
    cout << flag-1;


    return 0;
}