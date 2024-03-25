#define MAX 200
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

int N, K, S;
int arr[MAX+2][2];
int dp[MAX+1][3][MAX+1];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    for(int i = 1; i <= N+1; i++){
        cin >> arr[i][0] >> arr[i][1];
        S += (arr[i][0] + arr[i][1]);
    }
    
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= K; j++){
            dp[i][0][j] = INF;
            dp[i][1][j] = INF;
            dp[i][2][j] = INF;
        }
    }

    for(int i = 1; i <= N; i++){
        for(int j = i; j > 1; j--){
            dp[i][0][j] = min(dp[i-1][0][j-1], dp[i-1][2][j-1]) + arr[i][0];
            dp[i][1][j] = min(dp[i-1][1][j-1], dp[i-1][2][j-1]) + arr[i][1];
            dp[i][2][j] = min(min(dp[i-1][0][j], dp[i-1][1][j]), dp[i-1][2][j]);
        }
        dp[i][0][1] = arr[i][0];
        dp[i][1][1] = arr[i][1];
        dp[i][2][1] = min(min(dp[i-1][0][1], dp[i-1][1][1]), dp[i-1][2][1]);

    }

    int t = min(min(dp[N][0][K], dp[N][1][K]), dp[N][2][K]);
    if(t >= INF){
        t = 0;
    }
    cout << S - t;

    return 0;
}
