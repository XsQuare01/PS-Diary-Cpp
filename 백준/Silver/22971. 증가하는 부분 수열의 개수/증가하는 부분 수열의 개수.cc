#include <bits/stdc++.h>
#define MAX 5000
#define INF 2100000000
#define MOD 998244353

using namespace std;

int N;
int arr[MAX];
long long dp[MAX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    for(int i = 0; i < N; i++){
        int t = arr[i];
        long long sum = 0;
        for(int j = 0; j < i; j++){
            if(t <= arr[j]){
                continue;
            }
            sum = (sum + dp[j]) % MOD;
        }

        dp[i] = (sum + 1) % MOD;
        cout << dp[i] << " ";
    }

    return 0;
}
