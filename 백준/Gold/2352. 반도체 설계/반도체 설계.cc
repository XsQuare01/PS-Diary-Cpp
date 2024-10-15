#define MAX 40000
#define MOD 1000000007
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

int N;
int arr[MAX];
int dp[MAX + 1];

void init(){
    dp[0] = 0;
    for(int i = 1; i <= N; i++){
        dp[i] = INF;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    init();
    for(int i = 0; i < N; i++){
        int idx = upper_bound(dp, dp + N + 1, arr[i]) - dp;
        dp[idx] = arr[i];
    }
    for(int i = N; i > 0; i--){
        if(dp[i] != INF){
            cout << i;
            return 0;
        }
    }
    return 0;
}