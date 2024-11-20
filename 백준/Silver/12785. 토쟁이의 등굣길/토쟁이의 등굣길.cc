#define MAX 200
#define MOD 1000007
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

int W, H, X, Y;

long long arr[MAX+1][MAX+1];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> W >> H >> X >> Y;

    for(int i = 1; i <= Y; i++){
        arr[i][1] = 1;
    }
    for(int i = 1; i <= X; i++){
        arr[1][i] = 1;
    }

    for(int i = 2; i <= Y; i++){
        for(int j = 2; j <= X; j++){
            arr[i][j] = (arr[i][j-1] + arr[i-1][j]) % MOD;
        }
    }

    for(int i = Y; i <= H; i++){
        arr[i][X] = arr[Y][X];
    }
    for(int i = X; i <= W; i++){
        arr[Y][i] = arr[Y][X];
    }

    for(int i = Y+1; i <= H; i++){
        for(int j = X+1; j <= W; j++){
            arr[i][j] = (arr[i][j-1] + arr[i-1][j]) % MOD;
        }
    }

    cout << arr[H][W];
    return 0;
}