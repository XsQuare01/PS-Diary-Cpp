#define MAX 1000
#define WMAX 30
#define INF 2000000000

#include<bits/stdc++.h>

using namespace std;

int n, w;
int arr[MAX + 1][3];
int dp[MAX + 1][3][WMAX + 1];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> w;
    for(int i = 1; i <= n; i++){
        int t;
        cin >> t;
        arr[i][t] = 1;
    }

    dp[0][2][0] = -INF;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < w; j++){
            dp[i+1][1][j] = max(dp[i+1][1][j], dp[i][1][j] + arr[i+1][1]);
            dp[i+1][2][j+1] = max(dp[i+1][2][j+1], dp[i][1][j] + arr[i+1][2]);

            dp[i+1][1][j+1] = max(dp[i+1][1][j+1], dp[i][2][j] + arr[i+1][1]);
            dp[i+1][2][j] = max(dp[i+1][2][j], dp[i][2][j] + arr[i+1][2]);
        }
        dp[i+1][1][w] = max(dp[i+1][1][w], dp[i][1][w] + arr[i+1][1]);
        dp[i+1][2][w] = max(dp[i+1][2][w], dp[i][2][w] + arr[i+1][2]);
    }
    int res = 0;
    for(int i = 0; i <= w; i++){
        res = max(res, dp[n][1][i]);
        res = max(res, dp[n][2][i]);
    }
    cout << res;
    return 0;   
}
