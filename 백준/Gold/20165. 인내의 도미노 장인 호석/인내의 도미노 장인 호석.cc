#define MAX 100
#define MOD 1000000007
#define INF 10000000

#include<bits/stdc++.h>

using namespace std;

int N, M, R, res = 0;
int arr[MAX][MAX];
int farr[MAX][MAX] = {0, }; // 0: S, 1: F
int darr[][2] = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}
};

inline bool InBoundary(int y, int x){
    return y >= 0 && x >= 0 && y < N && x < M;
}

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    cin >> N >> M >> R;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < R; i++){
        int X, Y, idx, A, B;
        char D;
        cin >> Y >> X >> D >> B >> A;
        Y -= 1;
        X -= 1;

        A -= 1;
        B -= 1;
        
        if(farr[Y][X]){ // 1: 넘어짐
            continue;
        }
        farr[Y][X] = 1;
        res++;

        switch(D){
            case 'N':
                idx = 0;
            break;
            case 'S':
                idx = 1;
            break;
            case 'W':
                idx = 2;
            break;
            case 'E':
                idx = 3;
            break;
        }
        
        int dy = darr[idx][0];
        int dx = darr[idx][1];

        for(int cnt = arr[Y][X]-1; cnt > 0; cnt--){
            Y += dy;
            X += dx;

            if(!InBoundary(Y, X)){
                break;
            }

            if(farr[Y][X]){
                continue;
            }
            res++;
            farr[Y][X] = 1;

            cnt = max(cnt, arr[Y][X]);
        }
        farr[B][A] = 0; // 세움
    }

    cout << res << "\n";
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(!farr[i][j]){
                
                cout << "S ";
            }
            else{
                cout << "F ";
            }
        }
        cout << "\n";
    }

    return 0;
}