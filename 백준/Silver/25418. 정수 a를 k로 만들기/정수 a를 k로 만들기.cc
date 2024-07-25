#define MAX 1000000
#define INF 2147483647

#include <bits/stdc++.h>

using namespace std;

int A, K;
int dp[2*MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for(int i = 1; i < 2*MAX; i++){
        dp[i] = INF;
    }

    cin >> A >> K;
    dp[A] = 0;
    for(int i = A; i < K; i++){
        dp[i+1] = min(dp[i] + 1, dp[i+1]);
        dp[2*i] = min(dp[i] + 1, dp[2*i]);
        
    }
    cout << dp[K];
    return 0;
}   