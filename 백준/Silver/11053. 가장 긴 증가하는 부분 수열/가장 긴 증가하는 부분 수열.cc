#define MAX 1000
#define MOD 9901
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

int N;
int arr[MAX];
int dp[MAX + 1];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
        dp[i+1] = INF;
    }

    for(int i = 0; i < N; i++){
        int idx = lower_bound(dp, dp + N + 1, arr[i]) - dp;
        dp[idx] = arr[i];
    }

    for(int i = N; i > 0; i--){
        if(dp[i] == INF){
            continue;
        }
        cout << i;
        break;
    }
    
    
    return 0;
}