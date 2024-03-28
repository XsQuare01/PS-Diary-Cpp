#pragma GCC optimize("Ofast")
#define MAX 1500000
#define INF 987654321

#include<bits/stdc++.h>

using namespace std;

int N;
pair<int, int> arr[MAX + 2];
int dp[MAX + 2];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for(int i = 1; i <= N; i++){
        int tn, tp;
        cin >> tn >> tp;
        arr[i] = {tn, tp};
    }

    for(int i = 1; i <= N; i++){
        dp[i] = max(dp[i-1], dp[i]);
        int t = arr[i].first;
        int p = arr[i].second;
        if(i + t > N + 1){
            continue;
        }
        dp[i+t] = max(dp[i+t], dp[i] + p);
    }
    cout << max(dp[N], dp[N+1]);

    return 0;
}
